#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "board_print.h"

void makeboard (char a[][9])
{
    int i, j;
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
			a[i][j] = ' ';
		}	
	}	
	a[0][0]='8';
	a[1][0]='7';
	a[2][0]='6';
	a[3][0]='5';
	a[4][0]='4';
	a[5][0]='3';
	a[6][0]='2';
	a[7][0]='1';

	a[0][1]='r';
	a[0][2]='n';
	a[0][3]='b';
	a[0][4]='q';
	a[0][5]='k';
	a[0][6]='b';
	a[0][7]='n';
	a[0][8]='r';

	a[1][1]='p';
	a[1][2]='p';
	a[1][3]='p';
	a[1][4]='p';
	a[1][5]='p';
	a[1][6]='p';
	a[1][7]='p';
	a[1][8]='p';

	a[6][1]='P';
	a[6][2]='P';
	a[6][3]='P';
	a[6][4]='P';
	a[6][5]='P';
	a[6][6]='P';
	a[6][7]='P';
	a[6][8]='P';

	a[7][1]='R';
	a[7][2]='N';
	a[7][3]='B';
	a[7][4]='Q';
	a[7][5]='K';
	a[7][6]='B';
	a[7][7]='N';
	a[7][8]='R';

	a[8][1]='a';
	a[8][2]='b';
	a[8][3]='c';
	a[8][4]='d';
	a[8][5]='e';
	a[8][6]='f';
	a[8][7]='g';
	a[8][8]='h';
}

bool isEmpty(char a)
{
	if(a == ' ')
		return true;
	else return false;
}

bool moveboard (char a[][9], char str[])
{
    FILE *fw = fopen("board.txt", "wt");
    char temp;
    char sym[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    char num[] = {'1', '2', '3', '4', '5', '6', '7', '8'};
    int i, j, d, y;
    while(1)
    {
		fprintf(fw, "%s\n", str);
        if ((int)str[0] >= 97 && (int)str[0] <= 104)
        {
            for(int m = 0; m < 8; m++)
            {
                if(str[0] == sym[m])
                    j = 1 + m;
                if(str[1] == num[m])
                    i = 7 - m;
                if(str[3] == sym[m])
                    d = 1 + m;
                if(str[4] == num[m])
                    y = 7 - m;
            }
            if(!(j < 8 && j >= 0 && i < 8 && i >= 0 && d < 8 && d >= 0 && y < 8 && y >= 0))
                return false;
            else if((isEmpty(a[y][d]) && str[2] != '-') || (!(isEmpty(a[y][d])) &&
				str[2] != 'x') || (a[i][j] != 'P' && a[i][j] != 'p'))
				return false;
        else
        {
			if(str[2] == 'x')
			{
				a[y][d] = a[i][j];
				a[i][j] = ' ';
			}
			else
			{
				temp = a[i][j];
			    a[i][j] = a[y][d];
			    a[y][d] = temp;
		    }

		    j = 10; i = 10; d = 10; y = 10;
		    printboard(a); return true;}
		}
    else
    {
    	for(int m = 0; m < 8; m++)
	    {
	      if(str[1] == sym[m])
            j = 1 + m;
	      if(str[2] == num[m])
	        i = 7 - m;
	      if(str[4] == sym[m])
	        d = 1 + m;
	      if(str[5] == num[m])
	        y = 7 - m;
	    }
	    if(!(j < 8 && j >= 0 && i < 8 && i >= 0 && d < 8 && d >= 0 && y < 8 && y >= 0))
	      return false;
	    else if((isEmpty(a[y][d]) && str[3] != '-') || (!(isEmpty(a[y][d])) &&
				str[3] != 'x'))

			return false;

	    else if(((int)a[i][j] != ((int)str[0] + 32) && a[i][j] != str[0]) || a[i][j] == 'P' || a[i][j] == 'p') return false;
	    else
			{
			    if(str[3] == 'x')
                {
                    a[y][d] = a[i][j];
                    a[i][j] = ' ';
                }
                else
                {
                    temp = a[i][j];
                    a[i][j] = a[y][d];
                    a[y][d] = temp;
                    for(i = 0; i < 9; i++)
                    {
                        for(j = 0; j < 9; j++)
                        fprintf(fw, "%c ", a[i][j]);
                        fprintf(fw, "\n");
                    }
                }
                j = 10; i = 10; d = 10; y = 10;
                printboard(a); return true;
            }
    }

    }
    fclose(fw);
}

