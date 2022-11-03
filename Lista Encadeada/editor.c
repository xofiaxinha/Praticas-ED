#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    char caractere;
    struct no *prox;
}node;
typedef struct s{
    node *primeiro;
}palavra;
palavra *novaP(){
    palavra *novo = malloc(sizeof(palavra));
    novo->primeiro = NULL;
    return novo;
}
node* novoNo(char c){
    node *novo = malloc(sizeof(node));
    novo->prox = NULL;
    novo->caractere = c;
    return novo;
}
void inserir(palavra *lista, char c){
    node *novo = novoNo(c), *aux = lista->primeiro;;
    if(lista->primeiro == NULL){
        lista->primeiro = novo;
        return;
    }
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    
    aux->prox = novo;
}
void apagaPalavra(palavra *lista){
    node *aux = palavra->primeiro;
    while(aux != NULL){
        node *n = aux;
        aux = aux->prox;
        free(n);
    }
    free(lista);
}
void enter(node *aux, node *d){
    aux = novoNo('\n');
    aux->prox = d;
}
void back(palavra *lista, node *espaco){
    node *d = lista->primeiro, *aux = d;
    while(d->prox != espaco) 
        {aux = d;
        d = d->prox;}
    aux->prox = espaco;
    free(d);
    printf("chego chego");
}
void editor(palavra *lista){
    node *aux = lista->primeiro;
    while(aux != NULL){
       if(aux->caractere == 'R'){
           enter(aux, aux->prox);
       }
       else if(aux->caractere == ' '){
           back(lista, aux);
       }
       aux = aux->prox;
    }
}
int main(){
    char s[100];
    palavra *lista = novaP();
    scanf(" %s", s);
    char i;
    for(int n=0; s[n]; n++){
        i = s[n];
        inserir(lista, i);
    }
    inserir(lista, '|');
    
    editor(lista);
    apagaPalavra(lista);
}