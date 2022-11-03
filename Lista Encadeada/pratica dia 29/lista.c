#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "lista.h"

NoEnc *no_enc_criar(int elemento) {
  NoEnc *novo_no = (NoEnc *) malloc(sizeof(NoEnc));

  novo_no->elemento = elemento;
  novo_no->proximo = NULL;

  return novo_no;
}
void no_enc_apagar(NoEnc *no) { free(no); }

ListaEncInt *lista_enc_criar() {
  ListaEncInt *nova_lista = (ListaEncInt*) malloc(sizeof(ListaEncInt) * 1);

  nova_lista->primeiro = NULL;

  return nova_lista;
}
bool lista_enc_pertence(ListaEncInt *lista, int elemento) {
  NoEnc *atual = lista->primeiro;

  while (atual != NULL) {
    if (atual->elemento == elemento) {
      return true;
    }

    atual = atual->proximo;
  }

  // * Versão mais enxuta >>>
  // * for (atual = lista->primeiro; atual != NULL; atual = atual->proximo)
  // * (...)

  return false;
}
bool lista_enc_inserir_em(ListaEncInt *lista, int elemento,
                          unsigned int indice) {
  if (indice == 0) {
    NoEnc *novo_no = no_enc_criar(elemento);

    novo_no->proximo = lista->primeiro;
    lista->primeiro = novo_no;
  } else {
    NoEnc *anterior = lista->primeiro;

    // TODO: Usar a nova função de indexação
    while (indice > 1 && anterior != NULL) {
      anterior = anterior->proximo;
      --indice;
    }

    if (anterior != NULL) {
      NoEnc *novo_no = no_enc_criar(elemento);

      novo_no->proximo = anterior->proximo;
      anterior->proximo = novo_no;
    } else {
      return false;
    }
  }

  return true;
}
void listaEncFiltragem(ListaEncInt *lista, bool (*filtro)(int)){
    //elimina os elementos da lista que seguem determinado filtro
    //caso exemplo: elementos menores do que 5
    NoEnc *atual = lista->primeiro;
    if(atual != NULL && filtro(atual->elemento)){
        NoEnc *aux = atual;
        atual = atual->proximo;
        lista->primeiro = atual;
        no_enc_apagar(aux);
    }

    while(atual != NULL){
      NoEnc *proximo = atual->proximo;
      if(proximo != NULL && filtro(proximo->elemento)){
        atual->proximo = proximo->proximo;
        no_enc_apagar(proximo);
    }
    atual = atual->proximo;
    }
}

void listaEncMapeamento(ListaEncInt *lista, int (*mapeamento)(int)){
    NoEnc *atual = lista->primeiro;
    while(atual != NULL){
        atual->elemento = mapeamento(atual->elemento);
        atual = atual->proximo;
    }
}

