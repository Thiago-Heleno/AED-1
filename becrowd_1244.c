#include <stdio.h>
#include <string.h>

void ordenarStrings(char strings[51][51], int n)
{
  int indices[51];
  for (int i = 0; i < n; i++)
    indices[i] = i;

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (strlen(strings[indices[j]]) < strlen(strings[indices[j + 1]]))
      {
        int temp = indices[j];
        indices[j] = indices[j + 1];
        indices[j + 1] = temp;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    printf("%s", strings[indices[i]]);
    if (i < n - 1)
      printf(" ");
  }
  printf("\n");
}

int main()
{
  int N;
  scanf("%d", &N);
  getchar();

  while (N--)
  {
    char strings[51][51];
    char linha[2560];
    fgets(linha, sizeof(linha), stdin);

    int n = 0;
    char *token = strtok(linha, " \n");
    while (token != NULL)
    {
      strcpy(strings[n++], token);
      token = strtok(NULL, " \n");
    }

    ordenarStrings(strings, n);
  }

  return 0;
}