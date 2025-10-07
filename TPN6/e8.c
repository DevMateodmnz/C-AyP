#include <stdio.h>

int main() {
    int n, x, z;
    int cargados = 0;
    
    printf("Ingrese el orden del vector: ");
    scanf("%d", &n);
    
    int V[n];
    
    // Inicializar vector con ceros
    for(int i = 0; i < n; i++) {
        V[i] = 0;
    }
    
    while(cargados < n) {
        printf("Ingrese posicion x: ");
        scanf("%d", &x);
        
        if(x >= 0 && x < n && V[x] == 0) {
            printf("Ingrese valor z: ");
            scanf("%d", &z);
            V[x] = z;
            cargados++;
        } else {
            printf("Posicion invalida o ocupada. Intente otra.\n");
        }
    }
    
    printf("Vector cargado: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
    
    return 0;
}