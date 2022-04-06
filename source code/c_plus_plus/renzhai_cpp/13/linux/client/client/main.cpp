#include <cstdio>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h> 

int main()
{
    printf("hello from %s!\n", "client");

	int clienttsocket = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(8890);
	serveraddr.sin_addr.s_addr = inet_addr("192.168.31.178");

	if (connect(clienttsocket, (sockaddr*)&serveraddr, sizeof(sockaddr_in)) == -1)
	{
		printf("client error");
		return -1;
	}

	int error = send(clienttsocket, "I m client", strlen("I m client"), 0);

	char buff[1024] = { 0 };
	int recvnum = recv(clienttsocket, buff,1024,0);
	if (recvnum == -1)
	{
		printf("client error");
		return -1;
	}

	close(clienttsocket);
    return 0;
}