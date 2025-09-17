#include <stdio.h>

int main () {
    int n;
    float numero, suma = 0, promedio;

    printf("Ingrese la cantidad de numeros: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("ingrese el numero %d: ", i + 1);
        scanf("%f", &numero);
        suma += numero;
    }

    promedio = suma / n;

    printf("El promedio es: %.2f\n", promedio);

    return 0;
}