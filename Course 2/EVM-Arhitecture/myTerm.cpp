#include "SCLib.h"

int mt_clrscr()
{
    cout << "\E[H\E[2J";
    return 0;
}

int mt_gotoXY(int X, int Y)
{
    cout << "\E[" << Y << ";" << X << "H";
    return 0;
}

int mt_getscreensize(int *rows, int *cols)
{
    struct winsize ws;
    if(!ioctl(1, TIOCGWINSZ, &ws))
    {
        (*rows) = ws.ws_row;
        (*cols) = ws.ws_col;
        return 0;
    }
    else
        return -1;
}

int mt_setfgcolor(enum colors colour)
{
    cout << "\E[3" << colour << "m";
    return 0;
}

int mt_setbgcolor(enum colors colour)
{
    cout << "\E[4" << colour << "m";
    return 0;
}
