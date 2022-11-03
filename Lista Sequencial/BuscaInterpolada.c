#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct lista_sequencial{
    int *dados;
    int tamanho;
    int capacidade;
}LSeq;
LSeq *criar(){
    LSeq *nova = malloc(sizeof(LSeq));
    nova->dados = NULL;
    nova->tamanho = 0;
    nova->capacidade = 0;

    return nova;
}
void setCapacidade(LSeq *lista, unsigned int capacidade){
    lista->capacidade = capacidade;
    lista->dados = (int *)realloc(lista->dados, (capacidade * sizeof(int)));
}
void inserirFim(LSeq *lista, int dado){
    if(lista->tamanho == lista->capacidade) return;
    lista->dados[lista->tamanho] = dado;
    lista->tamanho = lista->tamanho+1;
}
bool checarOrdenacao(LSeq *lista){
    for(int i = 0; i < lista->tamanho - 1; i++){
        if(lista->dados[i] > lista->dados[i+1]){
            return false;
        }
    }
    return true;
}
int buscaInterpolada(LSeq *lista, int elemento){
    int inicio = 0;
    int fim = lista->tamanho - 1;
    int posicao;
    
}

int main(){
    LSeq *teste = criar();
    setCapacidade(teste, 6);

    for(int i=0; teste->tamanho < teste->capacidade; i++){
        inserirFim(teste, i+1);
    }
    printf("Lista criada e preenchida!\n");
    if(checarOrdenacao(teste)) printf("A lista esta ordenada\n");
    else {
        printf("A lista nao esta ordenada.\nOrdenando...");
        system("pause");
    }
    printf("O valor 5 esta na posicao %d\n", buscaInterpolada(teste, 5));
    printf("O valor 10 esta na posicao %d\n", buscaInterpolada(teste, 10));
}