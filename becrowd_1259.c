#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
  int A = *(int *)a, B = *(int *)b;

  if (A % 2 == 0)
    if (B % 2 == 0)
      return A - B;
    else
      return -1;
  else if (B % 2 == 0)
    return 1;
  else
    return B - A;
}

int main()
{
  int n;
  scanf("%d", &n);
  int *nums = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &nums[i]);
  }
  qsort(nums, n, sizeof(int), comp);
  for (int i = 0; i < n; i++)
  {
    printf("%d\n", nums[i]);
  }
  return 0;
}