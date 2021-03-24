#include <sys/socket.h>
#include <iostream>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <unistd.h>

#define PORT 4444

int main()
{
    int serverSocket;

    sockaddr_in serverAddr;
    socklen_t serverAddr_size = sizeof(serverAddr);

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocket < 0){
		printf("Error in connection.\n");
		exit(1);
	}
	printf("Server Socket is created.\n");

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int ret = bind(serverSocket, (sockaddr*)&serverAddr, serverAddr_size);
    if(ret < 0)
    {
        printf("Error in binding.\n");
        exit(1);
    }

    if(listen(serverSocket, 3) == 0)
    {
        printf("Listening...\n");
    }
    else
    {
        printf("Error in binding.\n");
    }
    
    int clientSocket;

    sockaddr_in clientAddr;
    socklen_t clientAddr_size = sizeof(clientAddr);

    while(true)
	{
		clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientAddr_size);
		if(fork() == 0)
		{
			close(serverSocket);
			int buff;
            while(true)
            {
                int getBuff = recv(clientSocket, &buff, 4, 0);
                if(getBuff == 0)
                    break;
                printf("%d\n", buff);
            }
            exit(0);
			close(clientSocket);
		}
		else
		{
			close(clientSocket);
			int status;
			wait3(&status, WNOHANG, NULL);
		}
	}
    
    return 0;
}