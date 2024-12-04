#include <stdio.h>

// Função que implementa o algoritmo Insertion Sort
void insertionSort(int arr[], int size)
{
  // Itera sobre cada elemento do array, começando do segundo
  for (int i = 1; i < size; i++)
  {
    int key = arr[i]; // Armazena o elemento atual (chave)
    int j = i - 1;    // Índice do elemento anterior

    // Move os elementos do array que são maiores que a chave
    // para uma posição à frente de sua posição atual
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j]; // Desloca o elemento para a direita
      j--;                 // Move o índice para o próximo elemento à esquerda
    }

    // Insere a chave na posição correta
    arr[j + 1] = key;
  }
}