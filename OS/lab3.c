#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int pid;
	printf("Luke, I'm your father!\n");
	pid = fork();
	if(pid == 0)
	{
		printf("Noooooo\n");
		printf("Contents of parent directory:\n");
		execl("/bin/ls", "-l"], "/", NULL);
		exit(pid);
	}
  	execl("/usr/bin/pstree", "/", NULL);
	return 0;
}
