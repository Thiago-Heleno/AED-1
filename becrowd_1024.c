#include <stdio.h>
#include <string.h>

int main()
{
  int n;
  scanf("%d", &n);
  getchar();
  for (int m = 0; m < n; m++)
  {
    char string[100];
    fgets(string, 100, stdin);
    // Remover a quebra de linha, se houver
    int size = strlen(string);
    if (string[size - 1] == '\n')
    {
      string[size - 1] = '\0';
      size--;
    }
    // Deslocar 3 pra direita letras minusculas
    int i = 0;
    while (string[i] != '\0')
    {
      if ((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z'))
      {
        string[i] += 3;
      }

      i++;
    }
    // Inverter a string
    for (int j = 0; j < size / 2; j++)
    {
      char temp = string[j];
      string[j] = string[size - j - 1];
      string[size - j - 1] = temp;
    }
    // Deslocar 1 pra esquerda letras depois da metade
    int metade = size / 2;
    for (int k = metade; k < size; k++)
    {
      string[k] -= 1;
    }
    printf("%s\n", string);
  }
  return 0;
}