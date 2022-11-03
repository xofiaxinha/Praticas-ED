#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Cliente{
    char nome[4];
    int quantDoc, paciencia;
    struct Cliente *prox;
}*cliente;
cliente novoCliente(char nome[4], int quant, int paciencia){
    cliente novo = malloc(sizeof(cliente));
    novo->nome = nome;
    novo->quant = quant;
    novo->paciencia = paciencia;
    novo->prox = NULL;
    return novo;
}
typedef struct Fila{
    cliente *head;
    cliente *tail;
}*fila;
fila criar(){
    fila novo = malloc(sizeof(fila));
    novo->head = novoCliente(" ", 0, 0);
    novo->tail = NULL;
    return novo;
}
void deletarFila(fila atual){
    cliente aux = atual->head;
    while(aux != NULL){
        cliente temp = aux;
        aux = aux->prox;
        free(temp);
    }
    free(atual);
}
void deletarNaFila(fila *atual, cliente *vitima){
    cliente *aux = atual->head;
    while(aux->prox != vitima) aux = aux->prox;
    aux->prox = vitima->prox;
    printf("%s removido da fila", vitima->nome);
    free(vitima);
}
void adicionarNaFila(fila atual, char* nome, int n, int p){
    cliente novo = novoCliente(nome, n, p), aux = atual->head;
    while(aux->prox = NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    atual->tail = novo;
    printf("%s adicionado à fila", nome);
}
typedef struct Banco{
    bool *caixas;
    fila *espera;
    fila *desistencia;
    int quantidadeProcessada, tempo, quantidadePerdida;
}banco;
Banco *criarBanco(unsigned int nCaixas){
    banco *novo = malloc(sizeof(banco));
    novo->caixas = (bool*)realloc(novo->caixas, sizeof(bool) * nCaixas);
        for(int i=0; i<nCaixas; i++){
            novo->caixas[i] = true; //inicializa os caixas como disponíveis
        }
    novo->espera = NULL;
    novo->desistencia = NULL;
    novo->quantidadeProcessada =0; novo->tempo=0; novo->quantidadePerdida=0;
    return novo;
}
int main(void){
    fila teste = criar();
    adicionarNaFila(teste, "Gi", 2, 3);
    adicionarNaFila(teste, "Pi", 2, 5);
    adicionarNaFila(teste, "Si", 2, 10);
    //testando função de adicionar
    cliente *aux = teste->head->prox;
    aux = aux->prox; //vai pra Pi
    deletarNaFila(teste, aux);
    deletarFila(teste);
}