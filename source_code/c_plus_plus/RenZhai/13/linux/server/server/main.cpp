#include <cstdio>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
    printf("hello from %s!\n", "server");

   int listensocket = socket(AF_INET, SOCK_STREAM, 0);

   sockaddr_in listenaddr;
   listenaddr.sin_family = AF_INET;
   listenaddr.sin_port = htons(8888);
   listenaddr.sin_addr.s_addr = htonl(INADDR_ANY);

   int open;
   setsockopt(listensocket, SOL_SOCKET, SO_REUSEADDR, &open, sizeof(open));
   if (bind(listensocket,(sockaddr *)&listenaddr,sizeof(listenaddr)) == -1)
   {
	   printf("bind error");

       return -1;
   }

   if (listen(listensocket,5) == -1)
   {
	   printf("bind error");

	   return -1;
   }

   while (true)
   {
	  sockaddr_in clientaddr;
	  socklen_t clientaddrlen;
	  int clientsocket = accept(listensocket, (sockaddr*)&clientaddr, &clientaddrlen);
	  if (clientsocket == -1)
	  {
		  printf("bind error");

		  return -1;
	  }
	  else
	  {
		  int error = send(clientsocket,"I m server",strlen("I m server"),0);
	  }
   }

   return 0;
}