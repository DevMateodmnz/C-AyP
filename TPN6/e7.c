#include <stdio.h>

int main() {
    int n;
    
    printf("Ingrese el orden del vector: ");
    scanf("%d", &n);
    
    int V[n];
    
    printf("Ingrese los elementos del vector:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &V[i]);
    }
    
    printf("Vector original: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
    
    // Invertir el vector
    for(int i = 0; i < n/2; i++) {
        int temp = V[i];
        V[i] = V[n-1-i];
        V[n-1-i] = temp;
    }
    
    printf("Vector invertido: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
    
    return 0;
}