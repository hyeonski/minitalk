
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void signal_handle(int signo)
{
	printf("signal!\n");
}

int main()
{
	signal(SIGINT, signal_handle);
	while (1)
	{
		printf("before!\n");
		pause();
		printf("after!\n");
	}
}