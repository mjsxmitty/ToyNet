#define _CRT_SECURE_NO_WARNINGS
#include <WinSock2.h>
#include <list>
#include <process.h>

#pragma comment(lib,"ws2_32.lib") 

struct IoData
{
	IoData()
	{
		ZeroMemory(this,sizeof(IoData));
	}

	OVERLAPPED OverL;
	CHAR buffer[1024];
	BYTE Type;
	DWORD Len;
	WSABUF wsabuffer;
};

class FClient
{
public:
	FClient(SOCKET S, SOCKADDR_IN InSin);
	virtual ~FClient(){}

	BOOL Recv();
	BOOL Send();

public:
	SOCKET ClientSokcet;
	SOCKADDR_IN Sin;
	IoData Data;
};

FClient::FClient(SOCKET S, SOCKADDR_IN InSin)
	:ClientSokcet(S)
	,Sin(InSin)
{

}

BOOL FClient::Recv()
{
	DWORD Flag = 0;
	DWORD Len = 0;
	Data.Type = 0;
	Data.wsabuffer.buf = Data.buffer;
	Data.wsabuffer.len = 1024;
	if (WSARecv(ClientSokcet,
		&Data.wsabuffer,
		1,
		&Len,&Flag,&Data.OverL,NULL) == SOCKET_ERROR)
	{
		if (WSAGetLastError() != ERROR_IO_PENDING)//GetOverlappedResult
		{
			return FALSE;
		}
	}

	return TRUE;
}

BOOL FClient::Send()
{
	DWORD Flag = 0L;
	DWORD Len = 0L;
	Data.Type = 1;
	Data.wsabuffer.buf = Data.buffer;
	Data.wsabuffer.len = strlen(Data.buffer);
	if (WSASend(ClientSokcet,
		&Data.wsabuffer,
		1,
		&Len, Flag, (LPOVERLAPPED)&Data.OverL, NULL) == SOCKET_ERROR)
	{
		if (WSAGetLastError() != ERROR_IO_PENDING)//GetOverlappedResult
		{
			return FALSE;
		}
	}

	return TRUE;
}

std::list<FClient*> ClientList;

void ListRemove(FClient *C)
{
	for (std::list<FClient*>::iterator iter = ClientList.begin();iter != ClientList.end();++iter)
	{
		if (C == (*iter))
		{
			ClientList.erase(iter);
			break;
		}
	}
}

HANDLE Cp = NULL;
unsigned int __stdcall Run(void* Content)
{
	for (;;)
	{
		Sleep(1000);
		DWORD IOSize = -1;
		LPOVERLAPPED lpOverlapped = NULL;
		FClient* Client = NULL;

		bool Ret = GetQueuedCompletionStatus(Cp, &IOSize, (LPDWORD)&Client, &lpOverlapped, INFINITE);
		if (Client == NULL && lpOverlapped == NULL)
		{
			break;
		}

		if (Ret)
		{
			if (IOSize == 0)
			{
				ListRemove(Client);
				continue;
			}

			IoData* pData = CONTAINING_RECORD(lpOverlapped, IoData, OverL);
			switch (pData->Type)
			{
				case 0://接受 客户端发送的消息
				{
					Client->Data.Len = IOSize;
					Client->Data.buffer[IOSize] = '\0';
					printf(Client->Data.buffer);

					char buffer[1024] = { 0 };

					sprintf_s(buffer, 1024, "hi I ma Server (%d)", Client->ClientSokcet);
					strcpy(Client->Data.buffer, buffer);
					Client->Send();
					break;
				}
				
				case 1://发送
				{
					printf(Client->Data.buffer);
					Client->Data.Len = 0;
					if (!Client->Recv())
					{
						ListRemove(Client);
					}

					break;
				}
			}
		}
		else
		{
			DWORD Msg = GetLastError();
			if (Msg == WAIT_TIMEOUT)
			{
				continue;
			}
			else if (lpOverlapped != NULL)
			{
				ListRemove(Client);
			}
			else
			{
				break;
			}
		}
	}

	return 0;
}

int main()
{
	//线程的返回句柄
	HANDLE hThreadHandle[32];

	if ((Cp = CreateIoCompletionPort(
		INVALID_HANDLE_VALUE,//打开的文件句柄
		NULL,//
		0,
		0)) == NULL)
	{
		//GetLastError();
		printf("创建完成端口失败 ~~ \n");
		return -1;
	}
	SYSTEM_INFO SystemInfo;
	GetSystemInfo(&SystemInfo);
	DWORD CPUNumber = SystemInfo.dwNumberOfProcessors;//CPU数量

	for (int i =0 ;i < CPUNumber * 2 ;i++)
	{
		hThreadHandle[i] = (HANDLE)_beginthreadex(
			NULL,// 安全属性， 为NULL时表示默认安全性
			0,// 线程的堆栈大小， 一般默认为0
			Run, // 所要启动的线程函数
			Cp, // 线程函数的参数， 是一个void*类型， 传递多个参数时用结构体
			0,// 新线程的初始状态，0表示立即执行，CREATE_SUSPENDED表示创建之后挂起
			NULL);   // 用来接收线程ID
	}

	WSADATA WsaData;
	int Ret = 0;
	if ((Ret = WSAStartup(MAKEWORD(2, 1), &WsaData)) != 0)
	{
		return -1;
	}

	//创建Socket
	SOCKET Listen = INVALID_SOCKET;
	if ((Listen = WSASocket(
		AF_INET,//
		SOCK_STREAM, //TCP  SOCK_DGRAM
		0, //协议
		NULL,//
		0, 
		WSA_FLAG_OVERLAPPED//
		)) == INVALID_SOCKET)
	{
		WSACleanup();
		return -1;
	}
	SOCKADDR_IN Sin;
	Sin.sin_family = AF_INET;//IPV4互联网协议族
	Sin.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//0.0.0.0 所以地址、
	Sin.sin_port = htons(98592);

	if (bind(Listen, (SOCKADDR*)&Sin,sizeof(Sin)) == SOCKET_ERROR)
	{
		closesocket(Listen);
		WSACleanup();
		return -1;
	}

	if (listen(Listen, SOMAXCONN))
	{
		closesocket(Listen);
		WSACleanup();
		return -1;
	}

	//iocp的投递
	SOCKET ClientAccept = INVALID_SOCKET;
	SOCKADDR_IN ClientAddr;
	int ClientAddrLen = sizeof(ClientAddr);

	// 看看有没有客户端连接
	for (;;)
	{
		if ((ClientAccept = WSAAccept(//阻塞程序
			Listen,
			(SOCKADDR*)&ClientAddr,
			&ClientAddrLen,
			NULL,
			0))== SOCKET_ERROR)
		{
			break;
		}
		FClient *InClient = new FClient(ClientAccept, ClientAddr);
		ClientList.push_back(InClient);

		//绑定完成端口
		if (CreateIoCompletionPort(
			(HANDLE)ClientAccept,
			Cp, 
			(DWORD)InClient,0) == NULL)
		{
			break;
		}

		if (!InClient->Recv())
		{
			ListRemove(InClient);
		}
	}

	//销毁线程池
	for (int i = 0; i < CPUNumber * 2; i++)
	{
		PostQueuedCompletionStatus(Cp, 0, NULL, NULL);
		CloseHandle(hThreadHandle[i]);
	}

	WaitForMultipleObjects(CPUNumber * 2, hThreadHandle, TRUE, INFINITE);

	return 0;
}