#include <stdio.h>
#include <stdbool.h>

int main()
{
  char mapa[100][100];
  int x, y;
  scanf("%d", &x);
  scanf("%d", &y);
  int valid = false;
  for (int i = 0; i < y; i++)
  {
    for (int j = 0; j < x; j++)
    {
      char icon;
      scanf(" %c", &icon);
      mapa[i][j] = icon;
    }
  }

  for (int i = 0; i < y; i++)
  {
    for (int j = 0; j < x; j++)
    {
      if (mapa[i][j] == '>')
      {
        mapa[i][j] = '.';
        if (mapa[i][j + 1] == '*')
        {
          printf("*\n");
          valid = true;
          break;
        }
        mapa[i][j + 1] = '>';
      }
      else if (mapa[i][j] == 'v')
      {
        mapa[i][j] = '.';
        if (mapa[i + 1][j] == '*')
        {
          printf("*\n");
          valid = true;
          break;
        }
        mapa[i + 1][j] = 'v';
      }
      else if (mapa[i][j] == '<')
      {
        mapa[i][j] = '.';
        if (mapa[i][j - 1] == '*')
        {
          printf("*\n");
          valid = true;
          break;
        }
        mapa[i][j - 1] = '<';
      }
      else if (mapa[i][j] == '^')
      {
        mapa[i][j] = '.';
        if (mapa[i - 1][j] == '*')
        {
          printf("*\n");
          valid = true;
          break;
        }
        mapa[i - 1][j] = '^';
      }
    }
  }

  if (!valid)
  {
    printf("!\n");
  }

  return 0;
}