#include<stdio.h>

void imprimirDecrescente(int n){
  if(n >= 0) {printf("%d ", n);
    imprimirDecrescente(n-1);}
  return;
}
void imprimirCrescente(int n){
  if(n > 0) imprimirCrescente(n-1);
  printf("%d ", n);
}
void imprimirCresDec(int n){
  if(n >= 0) {printf("%d ", n);
    imprimirDecrescente(n-1);}
  printf("%d ", n);
}
void imprimirPares(int n){
  if(n>=0 && (n%2 == 0)) {printf("%d ", n);
    imprimirPares(n-1);}
  else if(n>=0 && (n%2 == 1)){
    imprimirPares(n-1);
      printf("%d ", n);}
}
int soma(int n){
  if(n>0){
    return soma(n-1) + n;}
  else return 0;
}
int main(){
  printf("Digite um numero: ");
  int n;
  scanf("%d", &n);
  printf("Ordem decrescente de n a 0\n");
  imprimirDecrescente(n);
  printf("\nOrdem crescente de n a 0\n");
  imprimirCrescente(n);
  printf("\nOrdem decrescente de n a 0 e ordem crescente de n a 0\n");
  imprimirCresDec(n);
  printf("\nPares e impares\n");
  imprimirPares(n);

  printf("\nA soma eh = %d\n", soma(n));
}