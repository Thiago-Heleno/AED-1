#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);
  int ano, mes, dia;
  ano = n / 365;
  mes = (n % 365) / 30;
  dia = (n % 365) % 30;
  printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", ano, mes, dia);
  return 0;
}