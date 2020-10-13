#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define MSGSIZE 16ES

int main()
{
  int a = 10, b = 3;
  printf("Plus result: %d\n", plus(a, b));
  printf("Minus result: %d\n", minus(a, b));
  printf("Multiply result: %d\n", multi(a, b));
  printf("Div result: %d\n", div(a, b));
  printf("Mod result: %d\n", mod(a, b));
  return 0;
}

