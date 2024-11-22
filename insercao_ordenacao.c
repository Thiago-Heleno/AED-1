#include <stdio.h>

void insercao(int n, int v[])
{
  int i, j, x;
  for (j = 1; j < n; j++)
  {
    x = v[j];
    for (i = j - 1; i >= 0 && v[i] > x; i--)
      v[i + 1] = v[i];
    v[i + 1] = x;
  }
}

int main()
{
  int n = 10;
  int v[10] = {1, 5, 4, 3, 7, 6, 8, 9, 2, 5};
  insercao(n, v);
  for (int i = 0; i < n; i++)
  {
    printf("%d ", v[i]);
  }

  return 0;
}