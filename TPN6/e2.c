#include <stdio.h>

int main() {
    int m, N = 0, P = 0;
    
    printf("Ingrese el orden del vector: ");
    scanf("%d", &m);
    
    int vector[m];
    
    printf("Ingrese los elementos del vector:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &vector[i]);
        
        if(vector[i] < 0) {
            N += vector[i];
        } else {
            P += vector[i];
        }
    }
    
    printf("Acumulado de negativos (N): %d\n", N);
    printf("Acumulado de positivos (P): %d\n", P);
    
    return 0;
}