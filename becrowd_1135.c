#include <stdio.h>
#include <stdlib.h>

int main()
{
  int N, B;
  while (scanf("%d %d", &N, &B) && (N != 0 || B != 0))
  {
    int balls[90];
    int possible[91];

    for (int i = 0; i <= N; i++)
    {
      possible[i] = 0;
    }

    for (int i = 0; i < B; i++)
    {
      scanf("%d", &balls[i]);
    }

    for (int i = 0; i < B; i++)
    {
      for (int j = 0; j < B; j++)
      {
        int diff = abs(balls[i] - balls[j]);
        possible[diff] = 1;
      }
    }

    int all_possible = 1;
    for (int i = 0; i <= N; i++)
    {
      if (!possible[i])
      {
        all_possible = 0;
        break;
      }
    }

    if (all_possible)
    {
      printf("Y\n");
    }
    else
    {
      printf("N\n");
    }
  }
  return 0;
}
