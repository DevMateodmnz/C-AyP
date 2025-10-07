#include <stdio.h>

int main() {
    int n;
    
    printf("Ingrese el orden del vector: ");
    scanf("%d", &n);
    
    int vector[n];
    
    printf("Ingrese los elementos del vector:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &vector[i]);
    }
    
    int mayor = vector[0];
    int posicion = 0;
    
    for(int i = 1; i < n; i++) {
        if(vector[i] > mayor) {
            mayor = vector[i];
            posicion = i;
        }
    }
    
    printf("El elemento mayor es %d y está en la posición %d\n", mayor, posicion);
    
    return 0;
}