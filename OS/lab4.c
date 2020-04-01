#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>
#include <pthread.h>

int pook = 0;

char getch()
{
    char c;
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON & ~ISIG & ~ECHO;
    tcsetattr(0, TCSADRAIN, &term);
    read(STDIN_FILENO, &c, sizeof(char));
    term.c_lflag |= ICANON | ISIG | ECHO;
    tcsetattr(0, TCSADRAIN, &term);
    return  c;
}

void* printA(void *args)
{
    while(1)
    {
        sleep(1);
        if(pook == 0)
            printf("\nA\n");
    }
}

void* printB(void *args)
{
    while(1)
    {
        sleep(1);
        if(pook == 1)
            printf("\nB\n");
    }
}

int main()
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_create(&thread1, NULL, printA, NULL);
    pthread_create(&thread2, NULL, printB, NULL);
    int status_addr1, status_addr2;
    char c;
    while(1)
    {
        c = getch(); //or comment this and uncomment pooks above to show task 2.
        if(c == 'a')
            //pook = 0;
            sleep(5);
        else
            //pook = 1;
        	sleep(5);
    }
    return 0;
}

