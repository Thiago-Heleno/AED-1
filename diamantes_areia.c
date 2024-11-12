/*
  Autor: Thiago Heleno
  Solucao: Lista encadeado com sistema de pilha
  https://judge.beecrowd.com/en/problems/view/1069
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista
{
  char texto[2];
  struct lista *NO;
} celula;

celula *ultima_celula(celula *Cabeca)
{
  celula *atual = Cabeca;
  while (atual != NULL)
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

void Push(celula *Cabeca, char texto)
{
  celula *nova = malloc(sizeof(celula));
  nova->texto[0] = texto;
  nova->texto[1] = '\0';
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

int main()
{
  int n;
  scanf("%d", &n);
  getchar();
  celula Cabeca;
  strcpy(Cabeca.texto, "H");
  Cabeca.NO = NULL;

  char formula[10000];

  for (int i = 0; i < n; i++)
  {
    clear_list(&Cabeca);
    int i = 0;
    int count = 0;
    fgets(formula, sizeof(formula), stdin);
    while (formula[i] != '\0')
    {
      if (formula[i] == '<' || formula[i] == '>')
      {
        Push(&Cabeca, formula[i]);

        celula *first = Cabeca.NO;
        celula *second = Cabeca.NO->NO;
        if (first != NULL && second != NULL)
        {
          if (first->texto[0] == '>' && second->texto[0] == '<')
          {
            Pop(&Cabeca);
            Pop(&Cabeca);
            count++;
          }
        }
      }
      i++;
    }
    printf("%d\n", count);
  }

  return 0;
}