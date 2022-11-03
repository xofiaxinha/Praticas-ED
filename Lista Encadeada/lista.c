#include "lista-encadeada.h"

#include <limits.h>
#include <stdlib.h>

typedef struct no_encadeado {
  int elemento;
  struct no_encadeado *proximo;
} NoEnc;

struct lista_encadeada {
  NoEnc *primeiro;
};

struct iterador_lista_encadeada {
  NoEnc *no_atual;
};

// Funções privadas >>>

NoEnc *no_enc_criar(int elemento) {
  NoEnc *novo_no = malloc(sizeof(struct no_encadeado));

  novo_no->elemento = elemento;
  novo_no->proximo = NULL;

  return novo_no;
}

void no_enc_apagar(NoEnc *no) { free(no); }

// Funções públicas >>>

ListaEncInt *lista_enc_criar() {
  ListaEncInt *nova_lista = malloc(sizeof(struct lista_encadeada));

  nova_lista->primeiro = NULL;

  return nova_lista;
}

void lista_enc_apagar(ListaEncInt *lista) {
  // TODO: Apagar também todos os nós da Lista

  free(lista);
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

static NoEnc *lista_enc_obter_no_indice(ListaEncInt *lista,
                                        unsigned int indice) {
  NoEnc *no = lista->primeiro;

  while (indice > 1 && no != NULL) {
    no = no->proximo;
    --indice;
  }

  return no;
}

int lista_enc_obter_valor(ListaEncInt *lista, unsigned int indice) {
  NoEnc *no = lista_enc_obter_no_indice(lista, indice);

  // TODO: Proibir a inserção do valor INT_MAX
  if (no != NULL) {
    return no->elemento;
  } else {
    return INT_MAX; // Representa que o índice não existe
  }
}

void lista_enc_inserir_inicio(ListaEncInt *lista, int elemento) {
  NoEnc *novo_no = no_enc_criar(elemento);

  novo_no->proximo = lista->primeiro;
  lista->primeiro = novo_no;
}

void lista_enc_inserir_fim(ListaEncInt *lista, int elemento) {
  NoEnc *ultimo = lista->primeiro;
  NoEnc *novo_no = no_enc_criar(elemento);

  if (lista->primeiro == NULL) { // Lista vazia
    lista->primeiro = novo_no;
  } else {
    while (ultimo->proximo != NULL) {
      ultimo = ultimo->proximo;
    }

    ultimo->proximo = novo_no;
  }
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

bool lista_enc_inserir_apos_iterador(ListaEncInt *lista, int elemento,
                                     ItListaEncInt *posicao) {
  if (it_lista_enc_eh_valido(posicao)) {
    NoEnc *no = posicao->no_atual;

    // TODO: Extrair operação de "inserir na frente de um nó" para uma função
    //       auxiliar e usá-la tanto aqui quanto nos outros `inserir`.
  }
}

void lista_enc_remover_inicio(ListaEncInt *lista) {
  if (lista->primeiro != NULL) {
    NoEnc *removido = lista->primeiro;

    lista->primeiro = lista->primeiro->proximo;
    no_enc_apagar(removido);

    // * Versão alternativa >>>
    // * NoEnc *novo_primeiro = lista->proximo->proximo;
    // * no_enc_apagar(lista->proximo);
    // * lista->primeiro = novo_primeiro;
  }
}

void lista_enc_remover_fim(ListaEncInt *lista) {
  if (lista->primeiro == NULL) {
    return; // Pois a lista está vazia
  } else {
    NoEnc *atual, *anterior;

    if (lista->primeiro->proximo == NULL) {
      // Tornando a lista vazia
      no_enc_apagar(lista->primeiro);
      lista->primeiro = NULL;
    } else {
      anterior = lista->primeiro;
      atual = anterior->proximo;

      while (atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
      }

      no_enc_apagar(atual); // Pois `atual` marca o último neste ponto
      anterior->proximo = NULL;
    }
  }
}

bool lista_enc_remover_em(ListaEncInt *lista, unsigned int indice) {
  if (indice == 0) {
    if (lista->primeiro != NULL) {
      no_enc_apagar(lista->primeiro);
      lista->primeiro = lista->primeiro->proximo;
    } else {
      return false;
    }
  } else {
    NoEnc *anterior = lista->primeiro;

    // TODO: Usar a nova função de indexação
    while (indice > 1 && anterior != NULL) {
      anterior = anterior->proximo;
      --indice;
    }

    if (anterior != NULL && anterior->proximo != NULL) {
      NoEnc *aux = anterior->proximo->proximo;
      no_enc_apagar(anterior->proximo);
      anterior->proximo = aux;
    } else {
      return false;
    }
  }

  return true;
}

bool lista_enc_remover_apos_iterador(ListaEncInt *lista,
                                     ItListaEncInt *posicao) {
  if (it_lista_enc_eh_valido(posicao)) {
    NoEnc *no = posicao->no_atual;

    // TODO: Extrair operação de "remover da frente de um nó" para uma função
    // auxiliar e usá-la tanto aqui quanto nos outros `remover`.
  }
}

// Considerando o intervalo semi-aberto (inicio, fim]
void lista_enc_remover_entre_it(ListaEncInt *lista, ItListaEncInt *inicio,
                                ItListaEncInt *fim) {
  if (inicio->no_atual != NULL) {
    NoEnc *i_no = inicio->no_atual;
    NoEnc *f_no = fim->no_atual;
    NoEnc *atual = i_no->proximo;

    while (atual != f_no) {
      NoEnc *temp = atual->proximo;
      no_enc_apagar(atual);
      atual = temp;
    }

    if (f_no != NULL) {
      i_no->proximo = f_no->proximo;
      no_enc_apagar(f_no);
    } else {
      i_no->proximo = NULL;
    }
  }
}

unsigned int lista_enc_remover_todos(ListaEncInt *lista, int elemento) {
  unsigned int nos_removidos = 0;

  while (lista->primeiro != NULL && lista->primeiro->elemento == elemento) {
    NoEnc *temp = lista->primeiro->proximo;
    no_enc_apagar(lista->primeiro);
    lista->primeiro = temp;
    ++nos_removidos;
  }

  if (lista->primeiro != NULL) {
    NoEnc *atual = lista->primeiro;

    while (atual->proximo != NULL) {
      if (atual->proximo->elemento == elemento) {
        NoEnc *temp = atual->proximo->proximo;
        no_enc_apagar(atual->proximo);
        atual->proximo = temp;
        ++nos_removidos;
      }
    }
  }

  return nos_removidos;
}

// Iteradores -->

ItListaEncInt *it_lista_enc_criar(ListaEncInt *lista) {
  ItListaEncInt *iterador = malloc(sizeof(struct iterador_lista_encadeada));

  iterador->no_atual = lista->primeiro;

  return iterador;
}

void it_lista_enc_apagar(ItListaEncInt *it) { free(it); }

bool it_lista_enc_eh_valido(ItListaEncInt *it) { return it->no_atual != NULL; }

int it_lista_enc_obter_elemento(ItListaEncInt *it) {
  return it->no_atual->elemento;
}

void it_lista_enc_avancar(ItListaEncInt *it) {
  it->no_atual = it->no_atual->proximo;
}