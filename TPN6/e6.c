#include <stdio.h>

int main() {
    int n, a, b;
    
    printf("Ingrese el orden del vector: ");
    scanf("%d", &n);
    
    int V[n];
    
    printf("Ingrese A: ");
    scanf("%d", &a);
    printf("Ingrese B: ");
    scanf("%d", &b);
    
    V[0] = a;
    V[1] = b;
    
    for(int i = 2; i < n; i++) {
        if(i % 2 == 0) {
            V[i] = V[i-2] + V[i-1];
        } else {
            V[i] = V[i-2] - V[i-1];
        }
    }
    
    printf("Vector generado: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
    
    return 0;
}