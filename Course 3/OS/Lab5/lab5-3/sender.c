#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct mesg_q
{
    char msg_txt[100];
    long msg_typ;
};

int main()
{
    int msgid;
    char buffer[100];
    struct mesg_q msgq;
    key_t key;
    key = ftok("/home/", 'a');
    msgid = msgget(key, 0666| IPC_CREAT);

    if(msgid == -1)
    {
        printf("Sending failed\n");
        return -1;
    }

    while(1)
    {
        printf("Write Message:\n");
        fgets(msgq.msg_txt,100, stdin);

        if(msgsnd(msgid,&msgq,100,0) == -1)
        {
            printf("Send failed :c\n");
            return -1;
        }
        else
        {
            printf("Message send!\n\n");
        }
    }
}