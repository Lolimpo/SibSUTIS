#include <conio.h>
#include <graphics.h>
#include <time.h>
#include "class.h"

using namespace std;
		
int main()
{
	
	srand(clock());
	initwindow (1000, 1000);
	tPoint var;
	var.create();
	var.random_move(); //tPoint[i].linear_move();
	getchar();
	closegraph();
	return 0;
}
