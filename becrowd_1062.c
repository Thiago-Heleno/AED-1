#include <stdio.h>

#define MAX 1000

void push(int stack[], int x)
{
  int i = 0;
  while (stack[i] != 0)
  {
    i++;
  }
  stack[i] = x;
  return;
}

void pop(int stack[]){
  int i = 0, j = 1;
  while(j != 0){
    i++;
    j++;
  }
  stack[i] = 0;
  return;
}

int main()
{
  int n, block, x;
  scanf("%d", &n);

  int stack[MAX] = {0};

  for(int i = 0; i < n; i++){
    scanf("%d", &x);
  }

  return 0;
}