//é mais vantajoso implementar fila com lista encadeada
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int TipoItem; // so trocar o int pro tipo do item
typedef struct no{
    TipoItem elemento;
    struct no *prox;
}Node;
typedef struct lista{
    Node *inicio;
    Node *fim;
}ListaEnc;
typedef struct it{
    Node *atual;
}Iterador;
//fuções básicas que não estarão no .h
//funções de criar
Node *criaNo(TipoItem x){
    Node *n = (Node*)malloc(sizeof(Node));
    n->elemento = x;
    n->prox = NULL;
    return n;
}
ListaEnc *criaLista(){
    ListaEnc *l = (ListaEnc*)malloc(sizeof(ListaEnc));
    l->inicio->prox = NULL;
    l->fim = NULL;
    return l;
}
Iterador *criaIterador(ListaEnc *l){
    Iterador *it = (Iterador*)malloc(sizeof(Iterador));
    it->atual = l->inicio;
    return it;
}
//funções de deletar
void deletaNo(Node *n){
    free(n);
}
void deletaLista(ListaEnc *l){
    Node *aux = l->inicio;
    while(aux != NULL){
        Node *aux2 = aux->prox;
        aux = aux2->prox;
        deletaNo(aux2);
    }
    free(l);
}
void deletaIterador(Iterador *it){
    free(it);
}
void pushFila(ListaEnc *l){
    //o push é feito inserindo no final e removendo no começo
}