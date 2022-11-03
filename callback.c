#include <stdio.h>
#include <stdbool.h>

bool paridade(int n, bool (div)(int, int)){
    if(div(n, 2)) return true;
    else return false;
}
bool div(int num, int divisor){
    if(num % divisor == 0) return true;
    else return false;
}

int main(){
    int n1 = 2, n2 = 5, n3 = -16;
    printf("\tTeste de callback\n");
    printf("Numeros testados: %d, %d, %d\n", n1, n2, n3);
    printf("Teste n1: %d ", n1);
        if(paridade(n1, div)) printf(" eh par.\n");
        else printf(" nao eh par.\n");
    printf("Teste n2: %d ", n2);
        if(paridade(n2, div)) printf(" eh par.\n");
        else printf(" nao eh par.\n");
    printf("Teste n3: %d ", n3);
        if(paridade(n3, div)) printf(" eh par.\n");
        else printf(" nao eh par.\n");
}