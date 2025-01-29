#include <stdio.h>

int mdc(int a, int b)
{
  while (b != 0)
  {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main()
{
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", mdc(a, b));
  }
}