#ifndef QXD_ED_LISTA_ENCADEADA
#define QXD_ED_LISTA_ENCADEADA 1

#include <stdbool.h>

struct lista_encadeada;
typedef struct lista_encadeada ListaEncInt;

ListaEncInt *lista_enc_criar();
void lista_enc_apagar(ListaEncInt *lista);

bool lista_enc_pertence(ListaEncInt *lista, int elemento);

int lista_enc_obter_valor(ListaEncInt *lista, unsigned int indice);

void lista_enc_inserir_inicio(ListaEncInt *lista, int elemento);
void lista_enc_inserir_fim(ListaEncInt *lista, int elemento);
bool lista_enc_inserir_em(ListaEncInt *lista, int elemento,
                          unsigned int indice);

void lista_enc_remover_inicio(ListaEncInt *lista);
void lista_enc_remover_fim(ListaEncInt *lista);
bool lista_enc_remover_em(ListaEncInt *lista, unsigned int indice);
unsigned int lista_enc_remover_todos(ListaEncInt *lista, int elemento);

struct iterador_lista_encadeada;
typedef struct iterador_lista_encadeada ItListaEncInt;

ItListaEncInt *it_lista_enc_criar(ListaEncInt *lista);
void it_lista_enc_apagar(ItListaEncInt *it);
bool it_lista_enc_eh_valido(ItListaEncInt *it);
int it_lista_enc_obter_elemento(ItListaEncInt *it);
void it_lista_enc_avancar(ItListaEncInt *it);

ItListaEncInt *lista_enc_obter_primeiro(ListaEncInt *lista, int elemento);
ItListaEncInt *lista_enc_obter_posicao(ListaEncInt *lista, unsigned int indice);
bool lista_enc_inserir_apos_iterador(ListaEncInt *lista, int elemento,
                                     ItListaEncInt *posicao);
bool lista_enc_remover_apos_iterador(ListaEncInt *lista,
                                     ItListaEncInt *posicao);

// Considerando o intervalo semi-aberto (inicio, fim]
void lista_enc_remover_entre_it(ListaEncInt *lista, ItListaEncInt *inicio,
                                ItListaEncInt *fim)

#endif