#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <Winsock2.h>
#include <stdio.h>
#include <iostream>
#pragma comment(lib,"ws2_32.lib")   

using namespace std;
int main()
{
	WSADATA wsaData;
	int ret = 0;
	if ((ret = WSAStartup(MAKEWORD(2, 1), &wsaData)) != 0)
	{
		return -1;
	}

	SOCKET InSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	SOCKADDR_IN Addr;
	Addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	Addr.sin_family = AF_INET;
	Addr.sin_port = htons(45632);
	//ÓµÈû¿ØÖÆ
	sendto(InSocket, "Hello i 'ma client", strlen("Hello i 'ma client"), 0, (SOCKADDR*)&Addr, sizeof(SOCKADDR));
	int len = sizeof(SOCKADDR);
	char buffer[1024] = { 0 };

	recvfrom(InSocket, buffer, 1024, 0, (SOCKADDR*)&Addr, &len);
	printf(buffer);

	closesocket(InSocket);
	WSACleanup();


	return 0;
}