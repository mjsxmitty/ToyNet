#include <cstdio>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <poll.h>
#include <errno.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	//类似iocp的重叠结构
	struct FResponseEvents
	{
		int mysocket;
		uint32_t event;
		char data[255];
		int len;
		int offset;
	};

	auto ResetEpollContext = [](int inepfd,int inop,int insocket,uint32_t ev,void *indata) ->bool
	{
		epoll_event myevent;
		myevent.events = ev;
		myevent.data.ptr = indata;
		if (epoll_ctl(inepfd,inop, insocket,&myevent) == -1)
		{
			printf("create epoll failed [%s]", strerror(errno));
			return -1;
		}

		return 0;
	};

	printf("hello from %s!\n", "server");

	int listensocket = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
	if (listensocket == -1)
	{
		printf("socket error \n");

		return -1;
	}
	sockaddr_in listenaddr;
	listenaddr.sin_family = AF_INET;
	listenaddr.sin_port = htons(8890);
	listenaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	int open;
	setsockopt(listensocket, SOL_SOCKET, SO_REUSEADDR, &open, sizeof(open));
	if (bind(listensocket, (sockaddr*)&listenaddr, sizeof(listenaddr)) == -1)
	{
		printf("bind error");

		return -1;
	}

	if (listen(listensocket, 5) == -1)
	{
		printf("bind error");

		return -1;
	}

	int epfd = epoll_create(1000);
	if (epfd == -1)
	{
		printf("create epoll failed [%s]",strerror(errno));
		return -1;
	}

	if (ResetEpollContext(epfd,EPOLL_CTL_ADD, listensocket,EPOLLIN,&listensocket) == -1)
	{
		printf("create epoll failed [%s]", strerror(errno));
		return -1;
	}

	auto Do = [&](FResponseEvents* REvent)
	{
		if (REvent)
		{
			if (REvent->event == EPOLLIN) //有数据在内核
			{
				int readnum = read(REvent->mysocket, REvent->data, 255);
				if (readnum == 0)
				{
					printf("当前 客户端关闭.");
					close(REvent->mysocket);
					free(REvent);
				}
				else if (readnum == -1)
				{
					printf("当前 客户端出错.");
					close(REvent->mysocket);
					free(REvent);
				}
				else
				{
					REvent->len = readnum;

					//处理数据
					printf("%s", REvent->data);

					ResetEpollContext(epfd, EPOLL_CTL_ADD, REvent->mysocket, EPOLLOUT, REvent);
				}
			}
			else if (REvent->event == EPOLLOUT)
			{
				int writenum = write(REvent->mysocket, REvent->data + REvent->offset, REvent->len);
				if (writenum == -1)
				{
					close(REvent->mysocket);
					free(REvent);
				}
				//数据是不是还在发送中 或者数据是不是已经发送完毕
				else if (errno == EINTR || writenum < REvent->len)
				{
					ResetEpollContext(epfd, EPOLL_CTL_ADD, REvent->mysocket, EPOLLOUT, REvent);
					if (writenum != -1)
					{
						REvent->len = REvent->len - writenum;
						REvent->offset = REvent->offset + writenum;

						if (REvent->len = 0)
						{
							printf("数据发送完毕 \n");
						}
					}
				}
				else
				{
					ResetEpollContext(epfd, EPOLL_CTL_ADD, REvent->mysocket, EPOLLIN, REvent);
				}
			}
		}
	};

	epoll_event events[500];
	while (true)
	{
		int epwaitnum = epoll_wait(epfd, events, 500, -1);
		if (epwaitnum == -1)
		{
			printf("epoll_wait failed [%s]", strerror(errno));
			return -1;
		}

		int i = 0;
		for (i = 0; i < epwaitnum;i++)
		{
			if (events[i].data.ptr == &listensocket) //服务器响应 接受投递
			{
				//EPOLLHUP 读写都关闭了
				//EPOLLERR 出错了
				if (events[i].events & EPOLLHUP || events[i].events & EPOLLERR)
				{
					close(listensocket);
					return -1;
				}

				sockaddr_in clientaddr;
				socklen_t clientlen = sizeof(sockaddr_in);
				int clientsocket = accept(listensocket, (sockaddr*)&clientaddr,&clientlen);
				if (clientsocket == -1)
				{
					printf("epoll_wait failed [%s]", strerror(errno));
					return -1;
				}
				else
				{
					//
					int flags = fcntl(clientsocket, F_GETFL, NULL);
					if (flags == -1)
					{
						printf("fcntl F_GETFL [%s]", strerror(errno));
						return -1;
					}

					flags |= O_NONBLOCK;
					if (fcntl(clientsocket, F_SETFL, flags))
					{
						printf("fcntl F_SETFL [%s]", strerror(errno));
						return -1;
					}

					FResponseEvents* REvents = (FResponseEvents*)calloc(1, sizeof(FResponseEvents));
					REvents->mysocket = clientsocket;

					//添加读取事件
					ResetEpollContext(epfd, EPOLL_CTL_ADD, REvents->mysocket, EPOLLIN, REvents);
				}
			}
			else
			{
				if (events[i].events & EPOLLHUP || events[i].events & EPOLLERR)
				{
					FResponseEvents *REvent = (FResponseEvents*)events[i].data.ptr;
					printf("client [%s]", strerror(errno));
					close(REvent->mysocket);
					free(REvent);
				}
				else if(events[i].events == EPOLLIN)
				{
					FResponseEvents* REvent = (FResponseEvents*)events[i].data.ptr;
					REvent->event = EPOLLIN;

					ResetEpollContext(epfd, EPOLL_CTL_DEL, REvent->mysocket, 0, 0);
				
					//处理信息
					Do(REvent);
				}
				else if (events[i].events == EPOLLOUT)
				{
					FResponseEvents* REvent = (FResponseEvents*)events[i].data.ptr;
					REvent->event = EPOLLOUT;

					ResetEpollContext(epfd, EPOLL_CTL_DEL, REvent->mysocket, 0, 0);

					//处理信息
					Do(REvent);
				}
			}
		}
	}

	return 0;
}