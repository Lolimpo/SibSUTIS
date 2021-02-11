#include <string.h>
#include <stdio.h>
#include "board_print.h"
#include "board.h"

int main()
{
    char a[9][9];
    char str[7];
    makeboard (a);
    printboard (a);
    while (true)
    {
        scanf ("%s", str);
        if (strcmp(str, "stop") == 0) break;
        if (!moveboard (a, str)) printf ("Error!\n");
    }
    return 0;
}
