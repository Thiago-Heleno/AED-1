#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
  int x;
  struct celula *prox;
} celula;

int main()
{
  celula vini;
  vini.x = 2; 
  vini.prox = NULL;
  return 0;
}