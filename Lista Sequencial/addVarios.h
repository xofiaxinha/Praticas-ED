#ifndef QXD_LISTA_SEQ_H
#define QXD_LISTA_SEQ_H

// !!!!!!!    Não altere este arquivo    !!!!!!!

#include <stdbool.h>

struct lista_sequencial;
typedef struct lista_sequencial ListaSeq;

struct it_lista_sequencial;
typedef struct it_lista_sequencial ItListaSeq;

/// Alocar e retornar uma nova lista, inicialmente vazia
ListaSeq *lseq_criar();
/// Desalocar `lista`
void lseq_devolver(ListaSeq *lista);

/// Inserir `elemento` no final de `lista`
void lseq_inserir_fim(ListaSeq *lista, int elemento);

/// Adicionar todos os `num` elementos de `novos` no índice `i` de `lista`
void lseq_inserir_varios(ListaSeq *lista, unsigned int i, unsigned int num,
                         int novos[]);

/// Alocar e retornar um iterador, marcando inicialmente o primeiro elemento de
/// `lista`
ItListaSeq *lseq_criar_iterador(ListaSeq *lista);
/// Desalocar `iterador`, sem alterar nada em `lista`
void lseq_devolver_iterador(ListaSeq *lista, ItListaSeq *iterador);

/// Informar se `iterador` marca um elemento válido
bool it_lseq_valido(ItListaSeq *iterador);
/// Fazer `iterador` marcar o próximo elemento, ou se tornar inválido caso não
/// haja mais elementos
void it_lseq_avancar(ItListaSeq *iterador);
/// Informar o valor do elemento marcado por `iterador`
int it_lseq_elemento(ItListaSeq *iterador);

#endif