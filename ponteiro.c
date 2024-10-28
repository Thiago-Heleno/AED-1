#include <stdio.h>
#include <stdlib.h>

void inverterMatriz(int (*matrix)[2])
{
  int m2[2][2];
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      m2[i][j] = matrix[j][i];
    }
  }
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      matrix[i][j] = m2[i][j];
    }
  }
}

void teste()
{
  int *p;
  int a;
  scanf("%d", &a);
  p = &a;
  printf("%d", *p);
}

void crash()
{
  int *p;
  int a = 2;
  p = &a;
  for (int i = 0; i < 10000; i++)
  {
    p++;
    printf("%p\n", p);
    *p++;
  }
}

int main()
{
  // int m1[2][2] = {{1, 2}, {3, 4}};
  // inverterMatriz(m1);
  // for (int i = 0; i < 2; i++)
  // {
  //   for (int j = 0; j < 2; j++)
  //   {
  //     printf("%d ", m1[i][j]);
  //   }
  //   printf("\n");
  // }
  // crash();

  FILE *doc;
  char palavra[20];
  doc = fopen("teste.txt", "a");
  if (doc == NULL)
  {
    printf("Erro ao abrir arquivo!");
    return 1;
  }
  fgets(palavra, 20, stdin);
  fprintf(doc, "%s", palavra);
  fclose(doc);
  printf("Nome gravado com sucesso.");
  return 0;
}