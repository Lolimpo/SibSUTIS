#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFLEN 512
#define PORT 8888

void die(char *s)
{
    perror(s);
    exit(1);
}

int main()
{
    struct sockaddr_in si_me, si_other;
    int s, i, slen = sizeof(si_other), recv_len;
    char buf[BUFLEN];

    if((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
        die(" Failed to create a socket");

    memset((char *) &si_me, 0, sizeof(si_me));
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(PORT);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(s, (struct sockaddr*) &si_me, sizeof(si_me)) == -1)
        die("Can't bind()");
    while (1)
    {
        printf("Waiting for some data...");
        fflush(stdout);
        if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen)) == -1)
            die("Can't revfrom()");

        printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
        printf("Data: %s\n" , buf);

        if (sendto(s, buf, recv_len, 0, (struct sockaddr*) &si_other, slen) == -1)
        {
            die("Can't sendto()");
        }
    }
    close(s);
    return  0;
}