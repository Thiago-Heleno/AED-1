#include <stdio.h>
#include <stdlib.h>

void printVetor(int v[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", v[i]);
  }
  printf("\n");
}

int insertion(int v[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int j = i - 1;
    int chave = v[i];
    while (j >= 0 && v[j] > chave)
    {
      // j + 1 = i
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = chave;
  }
}

void merge(int v[], int l, int m, int r)
{
  int n1 = m - l + 1;
  int n2 = r - m;

  int *v1 = (int *)malloc(n1 * sizeof(int));
  int *v2 = (int *)malloc(n2 * sizeof(int));

  for (int i = 0; i < n1; i++)
  {
    v1[i] = v[l + i];
  }
  for (int i = 0; i < n2; i++)
  {
    v2[i] = v[m + 1 + i];
  }

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2)
  {
    if (v1[i] <= v2[j])
    {
      v[k] = v1[i];
      i++;
    }
    else
    {
      v[k] = v2[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    v[k] = v1[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    v[k] = v2[j];
    j++;
    k++;
  }

  free(v1);
  free(v2);
}

void dividirVetor(int v[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;

    dividirVetor(v, l, m);
    dividirVetor(v, m + 1, r);

    merge(v, l, m, r);
  }
}

void merge_sort(int v[], int n)
{
  dividirVetor(v, 0, n - 1);
}

int partition(int v[], int n, int left, int right)
{
  int pivot = v[right];
  int i = left - 1;

  for (int j = left; j < right; j++)
  {
    if (v[j] <= pivot)
    {
      i++;
      int temp = v[i];
      v[i] = v[j];
      v[j] = temp;
    }
  }
  int temp = v[i + 1];
  v[i + 1] = v[right];
  v[right] = temp;
  return i + 1;
}

void quick_sort(int v[], int n, int left, int right)
{
  if (left < right)
  {
    int pivot = partition(v, n, left, right);
    quick_sort(v, n, left, pivot - 1);
    quick_sort(v, n, pivot + 1, right);
  }
}