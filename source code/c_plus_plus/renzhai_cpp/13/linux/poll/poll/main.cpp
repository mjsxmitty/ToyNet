#include <cstdio>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <poll.h>
#include <errno.h>
#include <unistd.h>

int main()
{
	printf("hello from %s!\n", "server");

	int listensocket = socket(AF_INET, SOCK_STREAM, 0);

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

	pollfd client[1024];
	client[0].fd = listensocket;
	client[0].events = POLLRDNORM;
	for (int i = 1; i < 1024;i++)
	{
		client[i].fd = -1;
	}

	int max = 0; int i = 0;
	while (true)
	{
		int nnum = poll(client, max + 1, -1);
		if (client[0].revents & POLLRDNORM)//接受一个投递
		{
			sockaddr_in clientaddr;
			socklen_t clientLen = sizeof(sockaddr_in);
			int clientsocket = accept(listensocket, (sockaddr*)&clientaddr, &clientLen);
			if (clientsocket < 0)
			{
				continue;
			}

			for (i = 1;i < 1024;i++)
			{
				if (client[i].fd < 0)
				{
					client[i].fd = clientsocket;
					break;
				}
			}

			if (i == 1024)
			{
				printf("数量太多");
				continue;
			}

			client[i].events = POLLRDNORM;

			if (max < i)
			{
				max = i;
			}

			if (--nnum <= 0)
			{
				continue;
			}
		}

		//业务逻辑
		for (i = 1;i<1024;i++)
		{
			if (client[i].fd < 0)
			{
				continue;
			}

			if (client[i].revents & POLLRDNORM | POLLERR)
			{
				char buffer[1024] = { 0 };
				int recvnum = read(client[i].fd, buffer,1024);
				if (recvnum < 0)
				{
					if (errno == ECONNRESET) //重置连接
					{
						close(client[i].fd);
						client[i].fd = -1;
					}
					else
					{
						printf("read error");
					}
				}
				else if (recvnum == 0)
				{
					close(client[i].fd);
					client[i].fd = -1;
				}
				else
				{
					write(client[i].fd,buffer, recvnum);
				}

				if (--nnum <= 0)
				{
					continue;
				}
			}
		}
	}

	return 0;
}