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
    long int rec_buff = 0;
    key_t key;
    key = ftok("/home/", 'a');
    struct mesg_q msgq;
    msgid = msgget(key, 0666 | IPC_CREAT);

    if(msgid == -1)
    {
        printf("Message failed\n");
        return -1;
    }

    while(1)
    {
        if(msgrcv(msgid, &msgq,100, rec_buff,0) == -1)
        {
            printf("Message recv failed\n");
            return -1;
        }
        else
        {
            printf("Message received successfully!\n");
        }
        printf("Received message = %s\n", msgq.msg_txt);
    }
}