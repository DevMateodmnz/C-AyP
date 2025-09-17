#include <stdio.h>

int main() {
    int n, numero;
    int suma_pares = 0, suma_impares = 0;
    int contador_pares = 0, contador_impares = 0;
    float promedio_pares, promedio_impares;

    printf("Ingrese la cantidad de numeros: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);

        if (numero != 0) {
            if (numero % 2 == 0) {
                suma_pares += numero;
                contador_pares++;
            } else {
                suma_impares += numero;
                contador_impares++;
            }
        }
    }
    if (contador_pares > 0) {
        promedio_pares = (float)suma_pares / contador_pares;
        printf("Promedio de numeros pares: %.2f\n", promedio_pares);
    } else {
        printf("No se ingresaron numeros pares.\n");
    }
    if (contador_impares > 0) {
        promedio_impares = (float)suma_impares / contador_impares;
        printf("Promedio de numeros impares: %.2f\n", promedio_impares);
    } else {
        printf("No se ingresaron numeros impares.\n");
    }
}