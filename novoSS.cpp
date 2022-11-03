/*
Escreva uma versão do SelectionSort que, a cada passada pela área de interesse no vetor, 
posiciona corretamente dois elementos (em vez de um): um no início e um no final do vetor.
*/
#include <iostream>
using namespace std;

int main(){
    int tamanho;
    cin >> tamanho;
    int vetor[tamanho];
    for(int i=0; i<tamanho; i++){
        cin >> vetor[i];
    }
    
    for(int i=0, k=tamanho-1; i<tamanho; i++, k--){
        int menorIndice = i; int maiorIndice = 0;
        for(int j=i+1; j<tamanho; j++){
            if(vetor[j] < vetor[menorIndice]) menorIndice = j;
        }//for pra achar o indice de menor valor
        for(int j=i+1; j<tamanho; j++){
            if(vetor[j] > vetor[maiorIndice]) maiorIndice = j;
        }//for pra achar o indice de maior valor
        
        int a1 = vetor[i], a2 = vetor[k];
        vetor[i] = vetor[menorIndice]; vetor[k] = vetor[maiorIndice];
        vetor[menorIndice] = a1; vetor[maiorIndice] = a2;
    }
    
    for(int i=0; i<tamanho; i++){
        cout << vetor[i] << " ";
    }
}
//g++ novoSS.cpp -o novoSS && novoSS