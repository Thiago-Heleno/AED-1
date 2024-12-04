#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a = 92;
  int *p = &a;
  int **pp = &p;
  printf("Endereco do Ponteiro na memoria -> %d\nValor na memoria do endereco do ponteiro -> %d", *pp, **pp);
  return 0;
}