#include <stdio.h>

int main() {
    int n, x, count = 0;
    
    printf("Ingrese el orden del vector: ");
    scanf("%d", &n);
    
    int vector[n];
    
    printf("Ingrese los elementos del vector:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &vector[i]);
    }
    
    printf("Ingrese el valor x a buscar: ");
    scanf("%d", &x);
    
    for(int i = 0; i < n; i++) {
        if(vector[i] == x) {
            count++;
        }
    }
    
    printf("Cantidad de elementos iguales a %d: %d\n", x, count);
    
    return 0;
}