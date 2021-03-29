#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

int main(int argc, char* argv[])
{
	int sock;
	struct sockaddr_in servAddr;
	
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0) {
		printf("Error in connection.\n");
		exit(1);
	}
	printf("Client socket is created.\n");
	
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(PORT);
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if(connect(sock, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0) {
		perror("Error in connection.\n");
        exit(1);
    }
	printf("Connected to the Server.\n");
	
	int time = atoi(argv[1]);
	for(int i = 0; i < 60; i++)
	{
		send(sock, &time, 4, 0);
		sleep(time);
	}
	close(sock);
	
	exit(0);
}

