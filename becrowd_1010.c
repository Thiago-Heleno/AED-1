#include <stdio.h>

int main()
{

  int a, b, c, d;
  float x, y;
  scanf("%d %d %f", &a, &b, &x);
  scanf("%d %d %f", &c, &d, &y);
  printf("VALOR A PAGAR: R$ %.2f\n", b * x + d * y);

  return 0;
}