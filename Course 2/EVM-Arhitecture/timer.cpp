#include "SCLib.h"

void signalhandler(int signo)
{
	mt_gotoXY(1, 23);
	cout << "                                 ";
	mt_gotoXY(1, 23);
	if (CU() == -1)
	{
		alarm(0);
		sc_regSet(IGNORE_TIMER, 1);
		printflags();
		return ;
	}
  printflags();
  printmemory(cell);
  printBig(cell);
	PrintOperation();
	printBig(cell);
	cell++;
	if(cell > 99)
	{
		sc_regSet(IGNORE_TIMER, 1);
		sc_regSet(OUT_OF_MEMORY_BOUNDS, 1);
		alarm(0);
		printflags();
		return ;
	}
  printflags();
  printmemory(cell);
  printBig(cell);
	PrintOperation();
	printBig(cell);
	Timer();
}

void sighandler(int signo)
{
  cell = 0;
	alarm(0);
	mt_clrscr();
	sc_regInit();
	sc_memoryInit();
  printboxes();
  printflags();
  PrintOperation();
  printmemory(cell);
  printBig(cell);
}

int Signal(void)
{
	sc_regSet(IGNORE_TIMER, 0);
	signal(SIGUSR1, sighandler);
	raise(SIGUSR1);
	return 0;
}

void Timer(void)
{
	sc_regSet(IGNORE_TIMER, 1);
	struct itimerval newVal, oldVal;
	signal (SIGALRM, signalhandler);
	newVal.it_interval.tv_sec = 0;
 	newVal.it_interval.tv_usec = 100000;
 	newVal.it_value.tv_sec = 0;
 	newVal.it_value.tv_usec = 100000;
	setitimer(ITIMER_REAL, &newVal, &oldVal);
}
