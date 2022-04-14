#include <iostream>
#ifdef __cplusplus
extern "C"
{
#endif
#include "mongoose.h"
#pragma comment(lib,"ws2_32.lib")
#ifdef __cplusplus
}
#endif

void function(mg_connection *c,int ev,void *ev_data,void *function_data)
{
	if (ev == MG_EV_HTTP_MSG)
	{

	}
	else if (ev == MG_EV_WS_MSG)
	{

	}
	else if (ev == MG_EV_CONNECT)
	{

	}
	else if(ev == MG_EV_READ)
	{
		//½âÎö
	}
	else if (ev == MG_EV_WRITE)
	{

	}
}

int main()
{
	mg_mgr mgr;
	const char listen_addr[] = "http://127.0.0.1:8999/";
//	const char listen_addr[] = "http://localhost:8999/";

	mg_mgr_init(&mgr);
	mg_http_listen(&mgr, listen_addr, function, NULL);
	while (true)
	{
		mg_mgr_poll(&mgr,500);
	}

	mg_mgr_free(&mgr);
	return 0;
}