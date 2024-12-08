#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sorting_algorithms.h"

#define TAM 400000

int main()
{
  clock_t start, end;
  double elapsed;

  // Aloca os arrays dinamicamente para aumentar o maximo de MAX
  int *arr = (int *)malloc(TAM * sizeof(int));
  int *arr2 = (int *)malloc(TAM * sizeof(int));
  int *arr3 = (int *)malloc(TAM * sizeof(int));

  if (arr == NULL || arr2 == NULL || arr3 == NULL)
  {
    fprintf(stderr, "Erro ao alocar memória\n");
    return 1;
  }

  int n = TAM;
  printf("[Tamanho] %d\n", TAM);

  // semente de aleatoriedade
  srand((unsigned)time(NULL));

  // geração aleatório dos valores do vetor
  for (int a = 0; a < TAM; a++)
  {
    arr[a] = rand() % TAM;
    arr2[a] = arr[a];
    arr3[a] = arr[a];
  }

  // Marca o início do tempo
  start = clock();

  quick_sort(arr, n, 0, n - 1);

  end = clock();

  // Calcula o tempo decorrido em milissegundos
  elapsed = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

  printf("[QuickSort] Tempo de execucao: %.3f ms\n", elapsed);

  // Marca o início do tempo
  start = clock();

  merge_sort(arr2, n);

  end = clock();

  // Calcula o tempo decorrido em milissegundos
  elapsed = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

  printf("[MergeSort] Tempo de execucao: %.3f ms\n", elapsed);

  // Marca o início do tempo
  start = clock();

  insertion(arr3, n);

  end = clock();

  // Calcula o tempo decorrido em milissegundos
  elapsed = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

  printf("[InsertionSort] Tempo de execucao: %.3f ms\n", elapsed);

  free(arr);
  free(arr2);
  free(arr3);

  return 0;
}