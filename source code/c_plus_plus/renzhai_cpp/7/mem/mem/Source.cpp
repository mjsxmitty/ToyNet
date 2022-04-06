#include "iostream"
#include <csignal>

using namespace std;

void Signal_Function(int InSignal)
{
	cout<< InSignal <<endl;
}

void Signal_Function1(int InSignal)
{
	cout << InSignal << endl;
}

void Signal_Function2(int InSignal)
{
	cout << InSignal << endl;
}

int main()
{
	//◊¢≤·
	signal(SIGFPE,Signal_Function);
	signal(SIGINT, Signal_Function1);
	signal(SIGSEGV, Signal_Function2);

	for (int i = 0;;i++)
	{
		if (i >= 85) //’‚ «¥ÌŒÛ
		{
			raise(SIGFPE);
			raise(SIGINT);
			raise(SIGSEGV);
			break;
		}
	}

	return 0;
}