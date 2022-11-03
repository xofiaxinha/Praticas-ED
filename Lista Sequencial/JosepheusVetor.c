#include <stdio.h>
int main(){
    int N, jog1, i=0;    
    scanf("%d %d", &N, &jog1);    
    int amg[N];
    for(int i=0; i<N; i++){
        amg[i] = i+1;        
    }jog1 = jog1 % N;    
    
    for(int i=0; i<N-1; i++){
        amg[jog1] = 0;        
        while (amg[jog1]==0){            
            jog1 = (jog1 + 1) % N;
        }jog1 = (jog1 + 1) % N;
        while (amg[jog1]==0)jog1 = (jog1 + 1) % N;
        }
        
    for (int i=0; i<N; i++){        
    if (amg[i]!=0) printf ("%d", amg[i]);}
}