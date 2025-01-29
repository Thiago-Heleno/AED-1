#include <stdio.h>

int main()
{
  int t, h = 0, m = 0, s = 0;
  scanf("%d", &t);
  for (int i = 0; i < t; i++)
  {
    s++;
    if (s >= 60)
    {
      m++;
      s = 0;
    }
    if (m >= 60)
    {
      h++;
      m = 0;
    }
  }
  printf("%d:%d:%d\n", h, m, s);
  return 0;
}