#include <stdio.h>

int main() {
    int n, c;
    
    printf("Ingrese el orden del vector: ");
    scanf("%d", &n);
    
    int X[n];
    long long numero = 1;
    
    printf("Ingrese los elementos del vector:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }
    
    printf("Ingrese el valor entero C: ");
    scanf("%d", &c);
    
    for(int i = 0; i < n; i++) {
        numero *= (X[i] - c);
    }
    
    printf("El valor de NUMERO es: %lld\n", numero);
    
    return 0;
}