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

void function(mg_connection* c, int ev, void* ev_data, void* function_data)
{
	if (ev == MG_EV_WS_MSG)
	{
		
	}
	else if(ev == MG_EV_WS_OPEN)
	{

	}
}

int main()
{
	const char URL[] = "http://localhost:8999/hello";
	mg_mgr mgr;
	bool StopWhile = false;
	mg_mgr_init(&mgr);
	mg_connection* C = mg_ws_connect(&mgr, URL, function, &StopWhile,nullptr);
	if (C)
	{
		while (C && StopWhile == false)
		{
			mg_mgr_poll(&mgr, 500);
		}
	}

	mg_mgr_free(&mgr);

	return 0;
}