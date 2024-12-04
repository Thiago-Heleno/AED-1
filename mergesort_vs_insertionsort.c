#include <stdio.h>
#include <time.h>
#include "mergesort.h"
#include "insertionsort.h"

#define TAM 400000

// Função para imprimir o array
void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main()
{
  clock_t start, end;
  double elapsed;

  // Aloca os arrays dinamicamente para aumentar o maximo de MAX
  int *arr = (int *)malloc(TAM * sizeof(int));
  int *arr2 = (int *)malloc(TAM * sizeof(int));
  int size = TAM;

  // semente de aleatoriedade
  srand((unsigned)time(NULL));

  // geração aleatório dos valores do vetor
  for (int a = 0; a < TAM; a++)
  {
    arr[a] = rand() % TAM;
    arr2[a] = arr[a];
  }

  // Marca o início do tempo
  start = clock();

  // Algoritmo MergeSort
  mergeSort(arr, 0, size - 1);

  // Marca o fim do tempo
  end = clock();

  // Calcula o tempo decorrido em milissegundos
  elapsed = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

  printf("[MergeSort] Tempo de execucao: %.3f ms\n", elapsed);
  // printArray(arr, TAM);

  // Marca o início do tempo
  start = clock();

  // Algoritmo InsertionSort
  insertionSort(arr2, size);

  // Marca o fim do tempo
  end = clock();

  // Calcula o tempo decorrido em milissegundos
  elapsed = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

  printf("[InsertionSort] Tempo de execucao: %.3f ms\n", elapsed);

  return 0;
}