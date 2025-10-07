#include <stdio.h>

int main() {
    int n, countCeros = 0;
    
    printf("Ingrese el orden del vector: ");
    scanf("%d", &n);
    
    int V[n];
    
    printf("Ingrese los elementos del vector:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &V[i]);
        if(V[i] == 0) {
            countCeros++;
        }
    }
    
    int W[countCeros];
    int index = 0;
    
    for(int i = 0; i < n; i++) {
        if(V[i] == 0) {
            W[index] = i+1; // Posiciones base 1
            index++;
        }
    }
    
    printf("Vector V: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
    
    printf("Vector W: ");
    for(int i = 0; i < countCeros; i++) {
        printf("%d ", W[i]);
    }
    printf("\n");
    
    return 0;
}