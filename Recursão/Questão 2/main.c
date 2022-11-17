#include <stdio.h>
void inverte(int *v, int n){
  if(n > 0) {
    printf("%d ", v[n-1]);
    inverte(v, n-1);
  }
}
// retornar o valor maximo:: To-do
int maximo(int *v, int inicio, int fim){
  if(inicio <= fim){
  fim -= 1;
  int n=0;
  if(v[inicio] > v[fim]) n = v[inicio];
  else{
    n = v[fim];
    if(maximo(v, inicio+1, fim) > n) return maximo(v, inicio+1, fim);
  }
  return n;
  }
  return 0;
}
int palindromo(int *v, int inicio, int fim){
  fim = fim-1;
  if(v[inicio] != v[fim]) return 0;
  else{
    if(inicio <= fim){
    if(palindromo(v, inicio+1, fim)) return 1;
      else return 0;}
  }
  return 1;
}
void reverter(int *v, int inicio, int fim){
  //fim = fim-1;
  if(inicio <= fim){
    reverter(v, inicio+1, fim-1);
    int aux = v[inicio];
    v[inicio] = v[fim-1];
    v[fim-1] = aux;
  }
}

int main(){
  int n;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);
  int v[n];
  printf("Digite o vetor: ");
  for(int i=0; i<n; i++){
    scanf("%d", &v[i]);
  }
  printf("O vetor invertido:\n[");
  inverte(v, n);
  printf("]");
  int m;
  printf("\nDigite o tamanho do vetor palindromo: ");
  scanf("%d", &m);
  int p[m];
  printf("Digite o vetor: ");
  for(int i=0; i<m; i++){
    scanf("%d", &p[i]);
  }
  if(palindromo(p, 0, m)) printf("O vetor eh palindromo\n");
  else {printf("O vetor nao eh palindromo\n");
    printf("Revertendo o vetor:");
    reverter(p, 0, m);
    for(int i=0; i<m; i++){
    printf("%d ", p[i]);
  }}
  printf("O valor maximo eh: %d", maximo(v, 0, m));
}