#include <stdio.h>

int main() {
    int N1, N2, suma = 0;
    printf("Ingrese N1: ");
    scanf("%d", &N1);
    printf("Ingrese N2: ");
    scanf("%d", &N2);
    if (N1 >= N2) {
        printf("N1 debe ser menor que N2\n");
        return 1;
    }
    for (int i = N1 + 1; i < N2; i++) {
        suma += i;
        printf("%d", i);
        if (i < N2 - 1) printf(" + ");
        else printf(" = %d\n", suma);
    }
    printf("Suma de los enteros entre %d y %d: %d\n", N1, N2, suma);
    return 0;
}
