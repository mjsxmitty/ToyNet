#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>  

#pragma comment(lib,"ws2_32.lib")   
using namespace std;

#define INDEX_NONE -1

int main()
{
	WSADATA WsaData;
	//1.初始化库
	if (WSAStartup(MAKEWORD(4,3),&WsaData) != 0)
	{
		return INDEX_NONE;
	}

	//2.创建Socket
	//AF_INET6 
	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ListenSocket == INVALID_SOCKET)
	{
		cout << "创建失败" << endl;
		WSACleanup();
		return INDEX_NONE;
	}

	//3.设置IP和端口
	sockaddr_in ServerAddr;
	ServerAddr.sin_family = AF_INET;//ipv4
	ServerAddr.sin_port = htons(12341);
	ServerAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	if (bind(ListenSocket,(SOCKADDR*)&ServerAddr,sizeof(ServerAddr)) == SOCKET_ERROR)
	{
		cout << "绑定失败" << endl;
		closesocket(ListenSocket);
		WSACleanup();
		return INDEX_NONE;
	}
	
	//4.启动监听
	if (listen(ListenSocket,5) == SOCKET_ERROR)
	{
		cout << "监听失败" << endl;
		closesocket(ListenSocket);
		WSACleanup();
		return INDEX_NONE;
	}

	sockaddr_in ClientAddr;
	int ClientAddrLen = sizeof(ClientAddr);
	cout << "等待连接..." << endl;

	//5.接受连接
	SOCKET RevSocket = accept(ListenSocket, (SOCKADDR*)&ClientAddr, &ClientAddrLen);
	if (RevSocket == INVALID_SOCKET)
	{
		cout << "客户端发出请求 服务端接受失败" << endl;
		closesocket(ListenSocket);
		WSACleanup();
		return INDEX_NONE;
	}
	else
	{
		cout << "客户端发出请求 服务端接受成功" << endl;
		cout << "客户端的地址 :"<< inet_ntoa(ClientAddr.sin_addr) << endl;
		cout << "客户端的端口 :" << ClientAddr.sin_port << endl;
	}

	//6.接受客户端信息
	char BufferData[1024] = { 0 };
	int Res = recv(RevSocket, BufferData, 1024, 0);
	if (Res == 0)
	{
		cout << "连接关闭" << endl;
	}
	else if (Res > 0)
	{
		cout << "客户端发送的数据是 ："<< BufferData << endl;
		cout << "客户端发送的数据的大小是 ：" << Res << endl;
	}
	else
	{
		cout << "接受失败: ：" << WSAGetLastError() << endl;
	}

	memset(BufferData, 0, 1024);
	strcpy(BufferData, "Server Hello~");

	send(RevSocket, BufferData,strlen(BufferData),0);

	closesocket(ListenSocket);
	WSACleanup();

	return 0;
}