#include <stdio.h>

int main()
{

  int num[3];
  scanf("%d %d %d", &num[0], &num[1], &num[2]);
  int max = num[0];
  for (int i = 0; i < 3; i++)
  {
    if (num[i] > max)
    {
      max = num[i];
    }
  }
  printf("%d eh o maior\n", max);
  return 0;
}