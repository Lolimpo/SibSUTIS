#include "SCLib.h"

enum keys key;
int cell = 0;
int value;
int accumulator = 0;
int instructionCounter = 0;

int main()
{
	setbuf(stdout, NULL);
	sc_memoryInit();
	sc_regInit();
	mt_clrscr();
	printboxes();
	printflags();
  PrintOperation();
	printmemory(cell);
	printBig(cell);
  changeAccumulator(accumulator);
	while(key != EXIT)
	{
		rk_readkey(&key);
		switch(key)
		{
			case UP:
				if(!(cell - 10 < 0))
				{
					cell -= 10;
					printflags();
					printmemory(cell);
					printBig(cell);
					PrintOperation();
				}
				break;
			case DOWN:
				if(!(cell + 10 > 99))
				{
					cell += 10;
					printflags();
					printmemory(cell);
					printBig(cell);
					PrintOperation();
				}
				break;
			case LEFT:
				if(!(cell - 1 < 0))
				{
					cell--;
					printflags();
					printmemory(cell);
					printBig(cell);
					PrintOperation();
				}
				break;
			case RIGHT:
				if(!(cell + 1 > 99))
				{
					cell++;
					printflags();
					printmemory(cell);
					printBig(cell);
					PrintOperation();
				}
				break;
			case SAVE:
				sc_memorySave("data");
        changeAccumulator(accumulator);
				printmemory(cell);
				printBig(cell);
				printflags();
				break;
			case LOAD:
				sc_memoryLoad("data");
				printmemory(cell);
				printBig(cell);
				printflags();
				break;
			case RUN:
				Timer();
				break;
			case STEP:
        signalhandler(SIGALRM);
        alarm(0);
				break;
			case RESET:
				Signal();
        accumulator = 0;
        changeAccumulator(accumulator);
				break;
			case ENTER:
				cin >> value;
				if(value > 32767 || value < 0)
        {
          value = 0;
          sc_regSet(OUT_OF_MEMORY_BOUNDS, 1);
        }
				sc_memorySet(cell, value);
				mt_clrscr();
				printboxes();
        PrintOperation();
				printmemory(cell);
				printBig(cell);
        changeAccumulator(accumulator);
				printflags();
				break;
      case F5:
        cin >> accumulator;
        if(accumulator > 32767 || accumulator < -32767)
        {
          accumulator = 0;
          sc_regSet(WRONG_ACCUMULATOR, 1);
        }
        mt_clrscr();
				printboxes();
        PrintOperation();
        changeAccumulator(accumulator);
				printmemory(cell);
				printBig(cell);
				printflags();
        break;
			case F6:
				cin >> instructionCounter;
        if(instructionCounter < 0 || instructionCounter  > 99)
        {
          sc_regSet(OUT_OF_MEMORY_BOUNDS, 1);
          instructionCounter = cell;
        }
        cell = instructionCounter;
        mt_clrscr();
        PrintOperation();
        printboxes();
        changeAccumulator(accumulator);
        printmemory(cell);
        printBig(cell);
        printflags();
				break;
			default:
				break;
		}
	}
	return 0;
}
