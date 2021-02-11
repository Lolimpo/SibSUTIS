#ifndef SCLIB_H
#define SCLIB_H

#include <termios.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <sys/time.h>

#define OUT_OF_MEMORY_BOUNDS 1
#define WRONG_FLAG 2
#define INCORRECT_COMMAND 3
#define IGNORE_TIMER 4
#define WRONG_ACCUMULATOR 5

using namespace std;

enum colors {Dark, Red, Green, Yellow, Blue, Black, Cyan, White, Standart = 9};
enum keys {UP, RIGHT, DOWN, LEFT, LOAD, SAVE, RESET, RUN, STEP, ENTER, F5, F6, EXIT, ERROR};
extern int cell;

int sc_memoryInit();
int sc_memorySet(int address, int value);
int sc_memoryGet(int address, int * value);
int sc_memorySave(char * filename);
int sc_memoryLoad(char * filename);
int sc_regInit();
int sc_regSet(int regist, int value);
int sc_regGet(int regist, int * value);
int sc_commandEncode(int command, int operand, int * value);
int sc_commandDecode(int value, int * command, int * operand);
bool check_command(int command);

int mt_clrscr();
int mt_gotoXY(int X, int Y);
int mt_getscreensize(int *rows, int *cols);
int mt_setfgcolor(enum colors colour);
int mt_setbgcolor(enum colors colour);

int bc_printA(char * str);
int bc_box(int x1, int y1, int x2, int y2);
int bc_printbigchar(int A[2], int x, int y, enum colors TColor, enum colors BGColor);
int bc_setbigcharpos(int * big, int x, int y, int value);
int bc_getbigcharpos(int * big, int x, int y, int *value);
int bc_bigcharwrite(int fd, int * big, int count);
int bc_bigcharread(int fd, int * big, int need_count, int * count);

void printboxes();
void printmemory(int);
void printBig(int);
void printflags();
void changeAccumulator(int);
void bc_pickChar(int *, int);
void PrintOperation();

int rk_readkey(enum keys *key);
int rk_mytermsave();
int rk_mytermrestore();
int rk_mytermregime(int regime, int vtime, int vmin, int echo, int sigint);

void signalhandler(int);
void sighandler(int);
int Signal();
void Timer();

int CU();
int ALU(int, int);
#endif
