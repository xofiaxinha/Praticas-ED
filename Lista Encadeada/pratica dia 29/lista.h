#include <stdio.h>
#include <stdbool.h>
typedef struct no_encadeado {
  int elemento;
  struct no_encadeado *proximo;
} NoEnc;
typedef struct lista_encadeada {
  NoEnc *primeiro;
}ListaEncInt;

NoEnc *no_enc_criar(int elemento);
void no_enc_apagar(NoEnc *no);
ListaEncInt *lista_enc_criar();
bool lista_enc_pertence(ListaEncInt *lista, int elemento);
bool lista_enc_inserir_em(ListaEncInt *lista, int elemento, unsigned int indice);

void listaEncFiltragem(ListaEncInt *lista, bool (*filtro)(int));
void listaEncMapeamento(ListaEncInt *lista, int (*mapeamento)(int));