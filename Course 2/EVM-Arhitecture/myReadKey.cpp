#include "SCLib.h"

struct termios termState;
struct termios termDefault;
struct termios termTemp;

int rk_readkey(enum keys *key)
{
    char buffer;
    rk_mytermregime(0, 0, 1, 0, 1);
    read(1, &buffer, 1);

    switch (buffer)
    {
        case 'q':
            *key = EXIT;
            break;
        case 'l':
            *key = LOAD;
            break;
        case 's':
            *key = SAVE;
            break;
        case 'r':
            *key = RUN;
            break;
        case 't':
            *key = STEP;
            break;
        case 'i':
            *key = RESET;
            break;
        case 'e':
            *key = ENTER;
            break;
        case '\E':
            read(1, &buffer, 1);
            read(1, &buffer, 1);
            switch (buffer)
            {
                case 65:
                    *key  = UP;
                    break;
                case 66:
                    *key = DOWN;
                    break;
                case 67:
                    *key = RIGHT;
                    break;
                case 68:
                    *key = LEFT;
                    break;
                case '1':
                    read(1, &buffer, 1);
                    if(buffer == '5')
                    {
                        read(1, &buffer, 1);
                        if(buffer == '~')
                            *key = F5;
                    }
                    if(buffer == '7')
                    {
                        read(1, &buffer, 1);
                        if(buffer == '~')
                            *key = F6;
                    }
                    break;
                default:
                    *key = ERROR;
            }
            break;
        default:
            *key = ERROR;
            break;
    }
    tcsetattr(0, TCSANOW, &termDefault);
    return 0;
}

int rk_mytermsave()
{
    return tcgetattr(0, &termTemp);
}

int rk_mytermrestore()
{
    return tcsetattr(0, TCSANOW, &termTemp);
}

int rk_mytermregime(int regime, int vtime, int vmin, int echo, int sigint)
{
    if(regime < 0 || regime > 1 || echo < 0 || echo > 1 || sigint < 0 || sigint > 1)
        return -1;
    rk_mytermsave();
    tcgetattr(0, &termDefault);
    termState = termDefault;
    if(regime == 1)
        termState.c_lflag |= ICANON;
    else
        termState.c_lflag &= ~ICANON;

    if(echo == 1)
        termState.c_lflag |= ECHO;
    else
        termState.c_lflag &= ~ECHO;

    if(sigint == 1)
        termState.c_lflag |= ISIG;
    else
        termState.c_lflag &= ~ISIG;

    termState.c_cc[VMIN] = vmin;
    termState.c_cc[VTIME] = vtime;
    tcsetattr(0, TCSANOW, &termState);
    return 0;
}
