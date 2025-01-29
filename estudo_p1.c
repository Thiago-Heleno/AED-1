// #include <stdio.h>
// #include <stdlib.h>

// typedef struct TipoItem
// {
//   int chave;
//   struct TipoItem *prox;
// } TipoItem;

// typedef struct
// {
//   TipoItem *Topo;
// } TipoPilhaD;

// void push(TipoPilhaD *pPilha, int x)
// {
//   TipoItem *new = malloc(sizeof(TipoItem));
//   new->chave = x;
//   new->prox = pPilha->Topo;
//   pPilha->Topo = new;
// }

// void pop(TipoPilhaD *pPilha)
// {
//   TipoItem *temp = pPilha->Topo;
//   pPilha->Topo = pPilha->Topo->prox;
//   free(temp);
// }

// void print_pilha(TipoPilhaD *pPilha)
// {
//   TipoItem *atual = pPilha->Topo;
//   while (atual != NULL)
//   {
//     printf("%d ", atual->chave);
//     atual = atual->prox;
//   }
// }

// int main()
// {
//   TipoPilhaD pPilha;
//   pPilha.Topo = NULL;
//   push(&pPilha, 2);
//   push(&pPilha, 7);
//   push(&pPilha, 5);
//   push(&pPilha, 3);
//   pop(&pPilha);
//   print_pilha(&pPilha);
//   return 0;
// }

// Fila
//  #include <stdio.h>
//  #include <stdlib.h>

// typedef struct TipoItem
// {
//   int chave;
//   struct TipoItem *prox;
// } TipoItem;

// typedef struct
// {
//   TipoItem *Final;
// } TipoListaD;

// void push(TipoListaD *pListaD, int x)
// {
//   TipoItem *new = malloc(sizeof(TipoItem));
//   new->chave = x;
//   new->prox = pListaD->Final;
//   pListaD->Final = new;
// }

// void pop(TipoListaD *pListaD)
// {
//   TipoItem *atual = pListaD->Final;
//   TipoItem *anterior = NULL;
//   while (atual->prox != NULL)
//   {
//     anterior = atual;
//     atual = atual->prox;
//   }
//   anterior->prox = NULL;
//   free(atual);
// }

// void print_lista(TipoListaD *pLista)
// {
//   TipoItem *atual = pLista->Final;
//   while (atual != NULL)
//   {
//     printf("%d ", atual->chave);
//     atual = atual->prox;
//   }
// }

// int main()
// {
//   TipoListaD Lista;
//   Lista.Final = NULL;
//   push(&Lista, 2);
//   push(&Lista, 3);
//   push(&Lista, 5);
//   push(&Lista, 6);
//   pop(&Lista);
//   pop(&Lista);
//   print_lista(&Lista);
//   return 0;
// }

// Juncao de Filas circulares
#include <stdio.h>
#include <stdlib.h>

typedef struct TipoItem
{
  int chave;
  struct TipoItem *prox;
} TipoItem;

typedef struct
{
  TipoItem *Final;
} TipoLista;

int tamanho_lista(TipoLista *lista){
  int i = 0;
  TipoItem *atual = lista->Final;
  while(atual != NULL){
    atual = atual->prox;
    i++;
  }
  return i;
}

int indice_lista(TipoLista *lista, int n){
  TipoItem *final = lista->Final;
  for(int i = 0; i < n; i++){
    if(final != NULL){
      fina
    }else{
      return NULL;
    }
  }
}

void mesclar_lista(TipoLista *Lista1, TipoLista *Lista2, TipoItem *Lista3){
  int i = 0, j = 0, k = 0;
  while(i < tamanho_lista(Lista1) && j < tamanho_lista(Lista2)){
    if()
  }
}

int main()
{
  TipoLista Lista1;
  Lista1.Final = NULL;

  TipoLista Lista2;
  Lista2.Final = NULL;

  TipoLista Lista3;
  Lista3.Final = NULL;

  mesclar_listas(&Lista1, &Lista2, &Lista3);
  return 0;
}