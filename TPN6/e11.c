#include <stdio.h>

int main() {
    int n;
    
    printf("Ingrese el orden del vector (par): ");
    scanf("%d", &n);
    
    if(n % 2 != 0) {
        printf("El orden debe ser par.\n");
        return 1;
    }
    
    int V[n];
    int subVec1[n/2], subVec2[n/2];
    
    printf("Ingrese los elementos del vector:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &V[i]);
    }
    
    int idx1 = 0, idx2 = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            subVec1[idx1] = V[i];
            idx1++;
        } else {
            subVec2[idx2] = V[i];
            idx2++;
        }
    }
    
    printf("Sub-vector 1 (posiciones pares): ");
    for(int i = 0; i < n/2; i++) {
        printf("%d ", subVec1[i]);
    }
    printf("\n");
    
    printf("Sub-vector 2 (posiciones impares): ");
    for(int i = 0; i < n/2; i++) {
        printf("%d ", subVec2[i]);
    }
    printf("\n");
    
    return 0;
}