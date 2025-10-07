#include <stdio.h>

int main() {
    int numero, temp, orden = 0;
    
    printf("Ingrese un numero de 4 o mas digitos: ");
    scanf("%d", &numero);
    
    temp = numero;
    while(temp > 0) {
        orden++;
        temp /= 10;
    }
    
    int V[orden];
    temp = numero;
    
    for(int i = orden-1; i >= 0; i--) {
        V[i] = temp % 10;
        temp /= 10;
    }
    
    printf("Vector generado: ");
    for(int i = 0; i < orden; i++) {
        printf("%d ", V[i]);
    }
    printf("\nOrden: %d\n", orden);
    
    return 0;
}