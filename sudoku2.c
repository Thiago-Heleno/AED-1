/*
\033[1;31m - Vermelho
\033[1;32m - Verde
\033[1;33m - Amarelo
\033[1;34m - Azul
\033[0m - Reseta a cor

printf("\033[1;31mTexto em vermelho!\033[0m\n"); // \033[1;31m ativa o vermelho

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

void limpar_console()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void imprimirSudoku(int game[9][9])
{
  limpar_console();
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      if (j == SIZE - 1)
        if (game[i][j] == 0)
        {
          printf("  ");
        }
        else
        {
          printf(" %d", game[i][j]);
        }
      else
      {
        if (game[i][j] == 0)
        {
          printf("   |");
        }
        else
        {
          printf(" %d |", game[i][j]);
        }
      }
    }
    if (i < SIZE - 1)
      printf("\n--------------------------\n");
  }
}

void inputJogador(int game[SIZE][SIZE])
{
  int x, y, t;
  printf("\nInput do Jogador (linha) (coluna) (valor): ");
  scanf("%d %d %d", &x, &y, &t);
  game[x - 1][y - 1] = t;
}

bool checarSudoku(int game[SIZE][SIZE])
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      if (game[i][j] == 0)
        return false;
    }
  }
  return false;
  // Realmente checar quando estiver preenchido por completo
}

int main()
{
  int game[9][9] = {0};
  int gameOver = false;
  while (!gameOver)
  {
    imprimirSudoku(game);
    inputJogador(game);
    if (checarSudoku(game))
    {
      printf("\n\nBoa!!");
    }
  }

  return 0;
}