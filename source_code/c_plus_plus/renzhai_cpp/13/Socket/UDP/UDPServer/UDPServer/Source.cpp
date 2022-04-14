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
	Addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	Addr.sin_family = AF_INET;
	Addr.sin_port = htons(45632);
	bind(InSocket, (SOCKADDR*)&Addr, sizeof(SOCKADDR));

	SOCKADDR_IN AddrClient;
	int ClientAddrLen = sizeof(SOCKADDR_IN);

	char RecvBuff[1024] = {0};
	recvfrom(InSocket, RecvBuff,1024,0, (SOCKADDR*)&AddrClient,&ClientAddrLen);
	printf(RecvBuff);

	memset(RecvBuff, 0, 1024);
	sprintf_s(RecvBuff, 1024, "Hello i ' am server \n");
	sendto(InSocket, RecvBuff, 1024, 0, (SOCKADDR*)&AddrClient, sizeof(SOCKADDR));

	closesocket(InSocket);
	WSACleanup();

	return 0;
}