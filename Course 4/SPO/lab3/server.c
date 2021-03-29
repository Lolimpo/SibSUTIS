#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

#define PORT 4444

int handler(int fd)
{
	int buffer;
	int nbytes;
	nbytes = recv(fd, &buffer, 4, 0);
	if(nbytes == 0) {
		return 0;
	}
	else {
		printf("%d\n", buffer);
		return 0;
	}
}


int main()
{
	int sockMain, sockClient, lng, child;
	fd_set rfds;
	fd_set afds;
	int fd, nfds;
	struct sockaddr_in servAddr;
	size_t size;
	
	if((sockMain = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("Cant open main socket");
		exit(1);
	}
	printf("Server Socket is created.\n");
	
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(PORT);
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if(bind(sockMain, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0) {
		perror("Error in binding.\n");
		exit(1);
	}
	printf("Bind sucessfull.\n");
	lng = sizeof(servAddr);

	if(listen(sockMain, 4) == 0)
        printf("Listening...\n");
    else
        perror("Error in binding.\n");
	
	int clientSock;
	struct sockaddr_in clientAddr;
	socklen_t clientAddr_lng = sizeof(clientAddr);

	FD_ZERO(&afds);
	FD_SET(sockMain, &afds);
	while(1) {
		rfds = afds;
		if(select(FD_SETSIZE, &rfds, NULL, NULL, NULL) < 0) {
			perror("select failed");
			exit(1);
		}
		for(int i = 0; i < FD_SETSIZE;++i)
			if(FD_ISSET(i, &rfds)) {
				if(i == sockMain) {
					int new;
					size = sizeof(servAddr);
					clientSock = accept(
						sockMain, 
						(struct sockaddr*)&clientAddr, 
						&clientAddr_lng
					);
					if(clientSock < 0) {
						perror("accept err");
						exit(1);
					}
					FD_SET(clientSock, &afds);
				}
				else {
					if(handler(i) < 0) {
						close(i);
						FD_CLR(i, &afds);
					}
				}
			}
	}
	return 0;
}

