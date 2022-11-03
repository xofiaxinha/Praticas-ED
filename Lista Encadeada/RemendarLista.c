#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct no{
    int dado;
    struct no *prox;
}noEnc;
typedef struct lista{
    noEnc *primeiro;
}ListaEnc;
ListaEnc *criar(){
    ListaEnc *nova = malloc(sizeof(ListaEnc));
    nova->primeiro = NULL;
    return nova;
}
void deletarLista(ListaEnc *lista){
    free(lista);
}
noEnc *criarNo(int elemento){
    noEnc *novo = malloc(sizeof(noEnc));
    novo->dado = elemento;
    novo->prox = NULL;
    return novo;
}
void deletarNo(ListaEnc *lista, noEnc *node){
    noEnc *atual = lista->primeiro, *anterior = NULL;
    while(atual != node){
        anterior = atual;
        atual = atual->prox;
    }
    if(anterior == NULL){
        lista->primeiro = atual->prox;
        free(atual);
        return;
    }
    anterior->prox = atual->prox;
    free(atual);
}
void inserir(ListaEnc *l, int elemento){
    noEnc *aux = l->primeiro;
    if(aux == NULL){
        l->primeiro = criarNo(elemento);
        return;
    }
    while(aux->prox != NULL) aux = aux->prox;
    noEnc *novo = criarNo(elemento);
    aux->prox = novo;
}
void imprimir(ListaEnc *l){
    noEnc *aux = l->primeiro;
    while(aux != NULL){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
}
void remendarListaIndice(ListaEnc *l1, unsigned int indice, ListaEnc *l2){
    noEnc *aux = l1->primeiro;
    for(int i = 0; i < indice; i++) aux = aux->prox;
    noEnc *aux2 = l2->primeiro, *guarda = aux->prox;
    while(aux2->prox != NULL){
        aux->prox = aux2;
        aux = aux->prox;
        aux2 = aux2->prox;
    }
    aux->prox = guarda;
    while(l2->primeiro != NULL){
        noEnc *aux3 = l2->primeiro;
        l2->primeiro = aux3->prox;
        free(aux3);
    }
    printf("A lista 2 foi emendada com a lista 1 no indice %d e a lista 2 esta vazia!\n", indice);
}

int main(){
    ListaEnc *lista1 = criar();
    for(int i=1; i<5; i++){
        inserir(lista1, i);
    }
    printf("Lista criada e preenchida!\n");
    printf("Lista 1: {");
    imprimir(lista1);
    printf("}\n");
    ListaEnc *lista2 = criar();
    for(int i=5; i<10; i++){
        inserir(lista2, i);
    }
    printf("Lista criada e preenchida!\n");
    printf("Lista 2: {");
    imprimir(lista2);
    printf("}\n");

    remendarListaIndice(lista1, 2, lista2);
    printf("Lista 1: {");
    imprimir(lista1);
    printf("}\n");
    printf("Lista 2: {");
    imprimir(lista2);
    printf("}\n");
    return 0;
}