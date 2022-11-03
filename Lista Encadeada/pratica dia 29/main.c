#include <stdio.h>
#include "lista.h"
bool filtro(int elemento){
    //filtro: elemento menor que 5
    if(elemento < 5) return true;
    else return false;
}
int mapeamento(int valor){
    if(valor % 2 != 0) return valor * 2;
    else return valor / 2;
}
int main(){
    ListaEncInt *novo = lista_enc_criar();
    int n=0;
    if(lista_enc_inserir_em(novo, 2, n)){
        printf("Elemento 2 adicionado!\n");
        n++;
    }else printf("ERRO");
    if(lista_enc_inserir_em(novo, 5, n)){
        printf("Elemento 5 adicionado!\n");
        n++;
    }else printf("ERRO");
    if(lista_enc_inserir_em(novo, 9, n)){
        printf("Elemento 9 adicionado!\n");
        n++;
    }else printf("ERRO");
    if(lista_enc_inserir_em(novo, 3, n)){
        printf("Elemento 3 adicionado!\n");
        n++;
    }else printf("ERRO");

    listaEncFiltragem(novo, filtro);
    printf("\nLista Filtrada!");
    listaEncMapeamento(novo, mapeamento);
    printf("\nLista Mapeada!");

    NoEnc *atual = novo->primeiro;
    while(atual != NULL){
        printf("%d ", atual->elemento);
        atual = atual->proximo;}
}