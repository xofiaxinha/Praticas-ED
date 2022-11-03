#include<stdio.h>
#include<stdlib.h>
typedef struct  no{
    int valor;
    struct no *prox;
}knot;
struct lista{
    knot *inicio;
};
void inicializa(struct lista *l){
    l->inicio = NULL;
}
knot *novoNo(int n){
    knot *ovo =  malloc(sizeof(knot));
    ovo->valor = n;
    ovo->prox =  NULL;

    return ovo;
}
void inserir(struct lista *l, int  n, knot *aux){
    knot *k = novoNo(n);
    aux = l->inicio;
    if(aux == NULL) l->inicio = k; //caso de inserir no inicio
    else{
        while(aux->prox != NULL) aux = aux->prox;

        aux->prox = k;
    }
}
void remove(knot *no){free(no);}
void mataProx(struct lista *l, knot *aux){
    
}
int main(){
    struct lista *l;
    inicializa(l);
    int n, espada;
    scanf("%d %d", &n, &espada);
    knot *aux;
    for(int i = 0; i < n; i++){
        inserir(l, (i+1), aux);
    }
    espada = espada % n;
    printf("%d", aux->valor);
    return 0;
}