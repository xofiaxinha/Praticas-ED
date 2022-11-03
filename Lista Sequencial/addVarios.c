#include "addVarios.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct lista_sequencial{
    int *dados;
    int tamanho;
    int capacidade;    
}ListaSeq;
typedef struct it_lista_sequencial{
    ListaSeq *lista;
    int posicao;
} ItListaSeq;

/// Alocar e retornar uma nova lista, inicialmente vazia
ListaSeq *lseq_criar(){
    ListaSeq *lista = malloc(sizeof(ListaSeq));
    lista->dados = NULL;
    lista->tamanho = 0;
    lista->capacidade = 0;
    return lista;
}
/// Desalocar `lista`
void lseq_devolver(ListaSeq *lista){
    free(lista->dados);
    free(lista);
}

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