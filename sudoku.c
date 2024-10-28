#include <stdio.h>

int main()
{

  int n, t;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    int game[9][9];
    int valid = 1;

    // Fill the Matrix
    for (int j = 0; j < 9; j++)
    {
      for (int k = 0; k < 9; k++)
      {
        scanf("%d", &t);
        game[j][k] = t;
      }
    }

    // Check Lines and Rows
    for (int j = 0; j < 9; j++)
    {
      int numRows[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
      int numCols[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

      for (int k = 0; k < 9; k++)
      {
        for (int h = 0; h < 9; h++)
        {
          if (game[j][k] == numRows[h])
            numRows[h] = 0;
          if (game[k][j] == numCols[h])
            numCols[h] = 0;
        }
      }
      int sum = 0;
      int sum2 = 0;
      for (int z = 0; z < 9; z++)
      {
        sum += numRows[z];
        sum2 += numCols[z];
      }
      if (sum != 0)
      {
        valid = 0;
        break;
      }
      if (sum2 != 0)
      {
        valid = 0;
        break;
      }
    }

    // Check submatrix
    if (valid)
    {
      int offsetRow = 0;
      int offsetCol = 0;
      for (int r = 0; r < 3; r++)
      {
        for (int rr = 0; rr < 3; rr++)
        {
          int subNumbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
          for (int c = 0; c < 3; c++)
          {
            for (int cc = 0; cc < 3; cc++)
            {
              for (int zz = 0; zz < 9; zz++)
              {
                if (game[c + offsetRow][cc + offsetCol] == subNumbers[zz])
                  subNumbers[zz] = 0;
              }
            }
          }

          int sum = 0;
          for (int zz = 0; zz < 9; zz++)
          {
            sum += subNumbers[zz];
          }
          if (sum != 0)
          {
            valid = 0;
            break;
          }
          offsetCol += 3;
        }
        if (!valid)
          break;
        offsetCol = 0;
        offsetRow += 3;
      }
    }

    printf("Instancia %d\n%s\n\n", i + 1, valid ? "SIM" : "NAO");
  }

  return 0;
}