#include <stdio.h>
#include <stdlib.h>

// Função para mesclar dois subarrays ordenados
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // Tamanho do subarray esquerdo
    int n2 = right - mid;    // Tamanho do subarray direito

    // Arrays temporários para armazenar os valores
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copia os dados para os arrays temporários
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Índices iniciais dos subarrays e do array principal
    int i = 0, j = 0, k = left;

    // Mescla os subarrays no array principal
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes do subarray esquerdo (se houver)
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes do subarray direito (se houver)
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Libera a memória alocada para os arrays temporários
    free(L);
    free(R);
}

// Função recursiva para dividir o array e aplicar o merge sort
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // Calcula o ponto médio do array
        int mid = left + (right - left) / 2;

        // Ordena a metade esquerda
        mergeSort(arr, left, mid);

        // Ordena a metade direita
        mergeSort(arr, mid + 1, right);

        // Mescla as duas metades ordenadas
        merge(arr, left, mid, right);
    }
}
