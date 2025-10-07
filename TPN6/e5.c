#include <stdio.h>

int main() {
    int n;
    
    printf("Ingrese el orden del vector: ");
    scanf("%d", &n);
    
    int V[n];
    int valor = n;
    
    for(int i = n-1; i >= 0; i--) {
        V[i] = valor;
        valor++;
    }
    
    printf("Vector generado: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
    
    return 0;
}