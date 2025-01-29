#include <stdio.h>

int main()
{
  int N;
  scanf("%d", &N); // Lê o tempo em segundos

  int horas = N / 3600;          // Divide por 3600 para obter as horas
  int minutos = (N % 3600) / 60; // Obtém os minutos restantes
  int segundos = N % 60;         // Obtém os segundos restantes

  // Imprime o tempo no formato horas:minutos:segundos
  printf("%d:%d:%d\n", horas, minutos, segundos);

  return 0;
}
