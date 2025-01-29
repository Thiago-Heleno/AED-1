// Nao esta completo

#include <stdio.h>

#define MAX 50

int main()
{
  // M vertices - N arestas
  int m, n;
  int grafo[MAX][MAX] = {0};
  scanf("%d %d", &m, &n);
  for (int i = 0; i < n; i++)
  {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    grafo[x][y] = z;
  }
  scanf("%d %d");
  return 0;
}