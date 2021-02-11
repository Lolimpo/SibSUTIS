#include "SCLib.h"

int bc_printA(char * str)
{
    cout << "\E[11m" << str << "\E[10m";
    return 0;
}

int bc_box(int x1, int y1, int x2, int y2)
{
    if(x1 >= x2 || y1 >= y2)
        return -1;
    mt_gotoXY(x1, y1);
    for(int i = 1; i <= x2 - x1; i++)
    {
        mt_gotoXY(x1 + i, y1);
        cout << "\u2500";
        mt_gotoXY(x1 + i, y2);
        cout << "\u2500";
    }
    for(int i = 1; i <= y2 - y1; i++)
    {
        mt_gotoXY(x1, y1 + i);
        cout << "\u2502";
        mt_gotoXY(x2, y1 + i);
        cout << "\u2502";
    }
    mt_gotoXY(x1, y1);
    cout << "\u250C";
    mt_gotoXY(x1, y2);
    cout << "\u2514";
    mt_gotoXY(x2, y1);
    cout << "\u2510";
    mt_gotoXY(x2, y2);
    cout << "\u2518";
    return 0;
}

int bc_printbigchar(int * big, int x, int y, enum colors TColor, enum colors BGColor)
{
    mt_gotoXY(x, y);
    mt_setfgcolor(TColor);
    mt_setbgcolor(BGColor);
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(big[0] % 2 == 1)
                cout << "\u2588";
            else
                cout << " ";
            big[0] = big[0] >> 1;
        }
        mt_gotoXY(x, y + i + 1);
    }
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(big[1] % 2 == 1)
                cout << "\u2588";
            else
                cout << " ";
            big[1] = big[1] >> 1;
        }
        mt_gotoXY(x, y + i + 5);
    }
    mt_setbgcolor(Standart);
    mt_setfgcolor(Standart);
    return 0;
}

int bc_setbigcharpos(int * big, int x, int y, int value)
{
    if((value != 0 && value != 1) || x < 1 || x > 8 || y < 1 || y > 8)
        return -1;
    if(value == 1)
    {
        big[y/5] |= 1 << ((y - 1) * 8 + x -1);
        return 0;
    }
    if(value == 0)
    {
        big[y/5] &= ~(1 << ((y - 1) * 8 + x - 1));
        return 0;
    }
    return -1;
}

int bc_getbigcharpos(int * big, int x, int y, int *value)
{
    if(x < 1 || x > 8 || y < 1 || y > 8)
        return -1;
    *value = (big[y/5] >> ((y - 1) * 8 + x - 1)) & 0x1;
    return 0;
}

int bc_bigcharwrite(int fd, int * big, int count)
{
    write(fd, big, sizeof(count) * 2 * count);
    close(fd);
    return 0;
}

int bc_bigcharread(int fd, int * big, int need_count, int * count)
{
    *count = read(fd, big, sizeof(need_count) * 2 * need_count) / 8;
    if(*count == 0)
        return -1;
    close(fd);
    return 0;
}

void printBig(int cell)
{
  int A[2] = {0};
  int value;
	sc_memoryGet(cell, &value);
	stringstream sstream;
	sstream << setw(4) << setfill('0') << hex << value  << dec;
	string str = sstream.str();
	bc_pickChar(A, '+');
	bc_printbigchar(A, 2, 14, Standart, Blue);
	bc_pickChar(A, str[0]);
	bc_printbigchar(A, 11, 14, Standart, Blue);
	bc_pickChar(A, str[1]);
	bc_printbigchar(A, 20, 14, Standart, Blue);
	bc_pickChar(A, str[2]);
	bc_printbigchar(A, 29, 14, Standart, Blue);
	bc_pickChar(A, str[3]);
	bc_printbigchar(A, 38, 14, Standart, Blue);
	mt_gotoXY(1, 23);
}

void printboxes()
{
  bc_box(1, 1, 62, 12);
	mt_gotoXY(30, 1);
	cout << " Memory ";
	bc_box(63, 1, 84, 3);
	mt_gotoXY(67, 1);
	cout << " accumulator ";
	bc_box(63, 4, 84, 6);
	mt_gotoXY(64, 4);
	cout << " instructionCounter ";
	bc_box(63, 7, 84, 9);
	mt_gotoXY(69, 7);
	cout << " Operation ";
	bc_box(63, 10, 84, 12);
	mt_gotoXY(69, 10);
	cout << " Flags ";
	bc_box(1, 13, 46, 22);
	bc_box(47, 13, 84, 22);
	mt_gotoXY(48, 13);
	cout << " Keys: ";
  mt_gotoXY(48, 14);
  cout << "e\t-\tenter";
  mt_gotoXY(48, 15);
  cout << "l\t-\tload";
  mt_gotoXY(48, 16);
  cout << "s\t-\tsave";
  mt_gotoXY(48, 17);
  cout << "r\t-\trun";
  mt_gotoXY(48, 18);
  cout << "t\t-\tstep";
  mt_gotoXY(48, 19);
  cout << "i\t-\treset";
  mt_gotoXY(48, 20);
  cout << "F5\t-\taccumulator";
  mt_gotoXY(48, 21);
  cout << "F6\t-\tinstructionCounter";
  mt_gotoXY(1, 23);
}

void printmemory(int cell)
{
    int value;
    for(int i = 0; i < 10; i++)
	  {
		   mt_gotoXY(2, 2 + i);
		   for(int j = 0; j < 10; j++)
		   {
			    cout.unsetf(ios::dec);
			    cout.setf(ios::hex);
          if(i * 10 + j == cell)
            mt_setbgcolor(Blue);
          else
            mt_setbgcolor(Standart);
			    sc_memoryGet(i*10 + j, &value);
			    cout << "+" << setw(4) << setfill('0') << value << " ";
			    cout.unsetf(ios::hex);
			    cout.setf(ios::dec);
		   }
	  }
    mt_gotoXY(70, 5);
    cout.unsetf(ios::dec);
    cout.setf(ios::hex);
    cout << "+" << setw(4) << setfill('0') << cell << " ";
    cout.unsetf(ios::hex);
    cout.setf(ios::dec);
    mt_gotoXY(1, 23);
}

void printflags()
{
  int value;
  mt_gotoXY(70, 11);
	sc_regGet(OUT_OF_MEMORY_BOUNDS, &value);
	if(value)
  {
    mt_setfgcolor(Red);
    cout << "M";
  }
  else
  {
    mt_setfgcolor(Green);
    cout << "M";
  }
  mt_gotoXY(72, 11);
	sc_regGet(WRONG_FLAG, &value);
	if(value)
  {
    mt_setfgcolor(Red);
    cout << "F";
  }
	else
  {
    mt_setfgcolor(Green);
    cout << "F";
  }
  mt_gotoXY(74, 11);
	sc_regGet(INCORRECT_COMMAND, &value);
	if(value)
  {
    mt_setfgcolor(Red);
    cout << "C";
  }
  else
  {
    mt_setfgcolor(Green);
    cout << "C";
  }
  mt_gotoXY(76, 11);
  sc_regGet(IGNORE_TIMER, &value);
  if(value)
  {
    mt_setfgcolor(Red);
    cout << "I";
  }
  else
  {
    mt_setfgcolor(Green);
    cout << "I";
  }
  mt_gotoXY(78, 11);
  sc_regGet(WRONG_ACCUMULATOR, &value);
  if(value)
  {
    mt_setfgcolor(Red);
    cout << "A";
  }
  else
  {
    mt_setfgcolor(Green);
    cout << "A";
  }
  mt_setfgcolor(Standart);
  mt_gotoXY(1, 23);
}

void changeAccumulator(int value)
{
  mt_gotoXY(70, 2);
  cout.unsetf(ios::dec);
  cout.setf(ios::hex);
  if(value < 0)
    cout << "-" << setw(4) << setfill('0') << abs(value) << " ";
  else
    cout << "+" << setw(4) << setfill('0') << value << " ";
  cout.unsetf(ios::hex);
  cout.setf(ios::dec);
  mt_gotoXY(1, 23);
}

void PrintOperation(void)
{
	mt_gotoXY(70, 8);
	std::cout << "        ";
	mt_gotoXY(70, 8);
	int value, command, operand;
	sc_memoryGet(cell, &value);
	sc_commandDecode(value, &command, &operand) == -1 ? std::cout << " " : std::cout << "+";
	std::cout << std::hex << command << " : " << operand << std::dec;
	mt_gotoXY(1, 23);
}

void bc_pickChar(int *A, int value)
{
    switch(value)
    {
        case '0':
            A[0] = 1111636992;
            A[1] = 1010975298;
            break;
        case '1':
            A[0] = 674242560;
            A[1] = 538976292;
            break;
        case '2':
            A[0] = 1078082560;
            A[1] = 2114060860;
            break;
        case '3':
            A[0] = 1078082560;
            A[1] = 1010974780;
            break;
        case '4':
            A[0] = 1111638528;
            A[1] = 1077967938;
            break;
        case '5':
            A[0] = 33717248;
            A[1] = 1044398140;
            break;
        case '6':
            A[0] = 37895168;
            A[1] = 1010975292;
            break;
        case '7':
            A[0] = 269491712;
            A[1] = 269488188;
            break;
        case '8':
            A[0] = 1111636992;
            A[1] = 1010975292;
            break;
        case '9':
            A[0] = 1111636992;
            A[1] = 1010974844;
            break;
        case 'a':
            A[0] = 1078082560;
            A[1] = 1010975356;
            break;
        case 'b':
            A[0] = 33686016;
            A[1] = 1044529726;
            break;
        case 'c':
            A[0] = 33700864;
            A[1] = 1006764546;
            break;
        case 'd':
            A[0] = 1077952512;
            A[1] = 2084717180;
            break;
        case 'e':
            A[0] = 1111636992;
            A[1] = 1010958910;
            break;
        case 'f':
            A[0] = 134770688;
            A[1] = 134744124;
            break;
        case '+':
            A[0] = 2115508224;
            A[1] = 1579134;
            break;
        default:
            A[0] = 0;
            A[1] = 0;
    }
}
