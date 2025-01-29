#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

  int n;
  scanf("%d", &n);
  getchar();

  for (int i = 0; i < n; i++)
  {
    char *strings[50];
    char string[51];
    scanf("%50[^\n]", string);
    getchar();
    if (string[0] == ' ' && strlen(string) <= 1)
    {
      printf("\n");
      continue;
    }
    char *token = strtok(string, " ");
    int j = 0;
    while (token != NULL)
    {
      strings[j] = (char *)malloc(strlen(token) + 1);
      strcpy(strings[j], token);
      token = strtok(NULL, " ");
      j++;
    }

    for (int k = 0; k < j; k++)
    {
      printf("%c", strings[k][0]);
      free(strings[k]);
    }
    printf("\n");
  }
  return 0;
}