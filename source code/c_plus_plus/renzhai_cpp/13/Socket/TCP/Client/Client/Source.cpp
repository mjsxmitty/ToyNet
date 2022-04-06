#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>  

#pragma comment(lib,"ws2_32.lib")   
#define INDEX_NONE -1;
using namespace std;

int main()
{
	WSADATA WsaData;
	//1.初始化库
	if (WSAStartup(MAKEWORD(4, 3), &WsaData) != 0)
	{
		return INDEX_NONE;
	}

	//2.创建Socket
	//AF_INET6 
	SOCKET ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ClientSocket == INVALID_SOCKET)
	{
		cout << "创建失败" << endl;
		WSACleanup();
		return INDEX_NONE;
	}

	//3.设置服务器的IP和端口
	sockaddr_in ServerAddr;
	ServerAddr.sin_family = AF_INET;//ipv4
	ServerAddr.sin_port = htons(12341);
	ServerAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	if (connect(ClientSocket,(SOCKADDR*)&ServerAddr,sizeof(ServerAddr)) == SOCKET_ERROR)
	{
		cout << "创建套接字失败" << endl;
		closesocket(ClientSocket);
		WSACleanup();
		return INDEX_NONE;
	}
	else
	{
		cout << "创建套接字成功" << endl;
	}

	char BufferData[1024] = { 0 };
	strcpy(BufferData, "Hello Client");

	//4.发送
	int Res = send(ClientSocket, BufferData, strlen(BufferData), 0);
	if (Res == SOCKET_ERROR)
	{
		cout << "发送失败" << endl;
		closesocket(ClientSocket);
		WSACleanup();
		return INDEX_NONE;
	}
	else
	{
		cout << "发送成功" << endl;
	}

	memset(BufferData, 0, 1024);
	int res = recv(ClientSocket, BufferData, sizeof(BufferData), 0);
	if (Res == 0)
	{
		cout << "连接关闭" << endl;
	}
	else if (Res > 0)
	{
		cout << "服务端发送的数据是 ：" << BufferData << endl;
		cout << "服务端发送的数据的大小是 ：" << Res << endl;
	}
	else
	{
		cout << "接受失败: ：" << WSAGetLastError() << endl;
	}

	closesocket(ClientSocket);
	WSACleanup();

	return 0;
}