#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int pipefd[2];
  pid_t cpid;
  char buf;
  char *str[10] = {" "};
  pipe(pipefd);
  if((cpid == fork()) == 0)
  {
      close(pipefd[1]);
      printf("Hello, I'm child\n");
      while(read(pipefd[0], &buf, 1) > 0)
          write(STDOUT_FILENO, &buf, 1);
      close(pipefd[0]);
      exit(0);
  }
  else
  {
      close(pipefd[0]);
      printf("Hello, I'm dad\n");
      scanf("%s", &str);
      write(pipefd[1], str, 10);
      close(pipefd[1]);
      exit(0);
  }
  return 0;
 }
