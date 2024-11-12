/*
  Autor: Thiago Heleno
  Solucao: Lista encadeado com sistema de pilha para resolver jogo de Carta
  https://judge.beecrowd.com/en/problems/view/1110
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista
{
  int number;
  struct lista *NO;
} celula;

celula *ultima_celula(celula *Cabeca)
{
  celula *atual = Cabeca;
  while (atual->NO != NULL)
  {
    atual = atual->NO;
  }
  return atual;
}

bool Pop(celula *Cabeca)
{
  celula *primeiro_elemento = Cabeca->NO;
  if (primeiro_elemento == NULL)
    return true;
  celula *trash = Cabeca->NO;
  if (Cabeca->NO->NO == NULL)
    Cabeca->NO = NULL;
  else
    Cabeca->NO = Cabeca->NO->NO;
  free(trash);
  return false;
}

void Push(celula *Cabeca, int number)
{
  celula *nova = malloc(sizeof(celula));
  nova->number = number;
  celula *nocabeca = Cabeca->NO;
  Cabeca->NO = nova;
  nova->NO = nocabeca;
}

void clear_list(celula *Cabeca)
{
  bool is_clear = false;
  do
  {
    is_clear = Pop(Cabeca);
  } while (is_clear == false);
}

void fill_list(celula *Cabeca, int n)
{
  for (int i = 0; i < n; i++)
  {
    celula *new = malloc(sizeof(celula));
    new->number = n - i;
    if (Cabeca->NO == NULL)
    {
      Cabeca->NO = new;
      new->NO = NULL;
    }
    else
    {
      new->NO = Cabeca->NO;
      Cabeca->NO = new;
    }
  }
}

void print_list(celula *Cabeca)
{
  celula *current = Cabeca;
  while (current != NULL)
  {
    printf("%d\n", current->number);
    current = current->NO;
  }
}

int main()
{
  celula Cabeca;
  Cabeca.NO = NULL;
  Cabeca.number = 999;
  char formula[10000];

  int n;
  scanf("%d", &n);
  while (n != 0)
  {
    clear_list(&Cabeca);
    fill_list(&Cabeca, n);
    printf("Discarded cards:");
    while (Cabeca.NO->NO != NULL)
    {
      if (Cabeca.NO->NO->NO == NULL)
        printf(" %d\n", Cabeca.NO->number);
      else
        printf(" %d,", Cabeca.NO->number);
      Pop(&Cabeca);
      celula *ultima = ultima_celula(&Cabeca);
      ultima->NO = Cabeca.NO;
      Cabeca.NO = Cabeca.NO->NO;
      ultima->NO->NO = NULL;
    }

    printf("Remaining card: %d\n", Cabeca.NO->number);
    scanf("%d", &n);
  }

  return 0;
}