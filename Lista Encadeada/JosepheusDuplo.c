#include <stdio.h>
#include <stdlib.h>

typedef struct knot{
  int n;
  struct knot *anterior, *proximo;
}node;
node *novoNo(int n){
  node *novo = malloc(sizeof(node));
  novo->n = n;
  novo->anterior = NULL;
  novo->proximo = NULL;
  return novo;
}
typedef struct l{
  node *primeiro;
  node *ultimo;
}lista;
lista *novaLista(){
    lista *l = malloc(sizeof(lista));
    l->primeiro = novoNo(0);
    l->ultimo = primeiro;
    return l;
}
void removeLista(lista *l){
    node aux = l->primeiro;
    while(aux != NULL){
        node temp = aux;
        aux = aux->prox;
        free(temp);
    }
    free(l);
}
void inserir(lista *l, int  n){
    node *k = novoNo(n);
    node *aux = l->primeiro;
    while(aux->prox != NULL) aux = aux->prox;
    k->anterior = aux;
    aux->prox = k;
}