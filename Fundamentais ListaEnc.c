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
//funções de inserir
void insere(ListaEnc *l, TipoItem x){
    Node *n = criaNo(x), *aux = l->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = n;
    l->fim = n;
}
//funções de busca
bool buscaElemento(ListaEnc *l, TipoItem x){
    Node *aux = l->inicio;
    while(aux != NULL){
        if(aux->elemento == x){
            return true;
        }
        aux = aux->prox;
    }
    return false;
}
Node *buscaNo(ListaEnc *l, TipoItem x){
    Node *aux = l->inicio;
    if(!buscaElemento(l, x)) return NULL;
    while(aux != NULL){
        if(aux->elemento == x){
            return aux;
        }
        aux = aux->prox;
    }
}
//funções de remover
void removeElemento(ListaEnc *l, TipoItem x){
    Node *aux = l->inicio;
    if(!buscaElemento(l, x)) return;
    while(aux->prox != NULL){
        if(aux->prox->elemento == x){
            Node *aux2 = aux->prox;
            aux->prox = aux2->prox;
            deletaNo(aux2);
            return;
        }
        aux = aux->prox;
    }
}
//funções de iterador
bool existeProx(Iterador *it){
    if(it->atual->prox != NULL) return true;
    return false;
}
void prox(Iterador *it){
    if(existeProx(it)){
        it->atual = it->atual->prox;
    }
}
//miscelânea
TipoItem elementoNo(Node *n){
    return n->elemento;
}
TipoItem elementoAtual(Iterador *it){
    return it->atual->elemento;
}
int main(){
    ListaEnc *l = criaLista();
    Iterador *it = criaIterador(l);
    insere(l, 1);
    insere(l, 2);
    insere(l, 3);
    insere(l, 4);
    insere(l, 5);
    insere(l, 6);
    insere(l, 7);
    insere(l, 8);
    insere(l, 9);
    insere(l, 10);
    while(existeProx(it)){
        printf("%d ", elementoAtual(it));
        prox(it);
    }
    deletaLista(l);
    deletaIterador(it);
    return 0;
}