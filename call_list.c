/*
  Thiago Heleno
  Sorting Algorithm
  https://judge.beecrowd.com/en/problems/view/2381
*/

#include <stdio.h>
#include <string.h>

typedef struct classList
{
  char name[21];
} Class;

int main()
{
  int n, k;
  Class class[100];
  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; i++)
  {
    scanf("%s", class[i].name);
  }

  // Sort - Bubble
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - 1; j++)
    {
      if (strcmp(class[j].name, class[j + 1].name) > 0)
      {
        char temp[21];
        strcpy(temp, class[j + 1].name);
        strcpy(class[j + 1].name, class[j].name);
        strcpy(class[j].name, temp);
      }
    }
  }

  printf("%s\n", class[k - 1].name);

  return 0;
}