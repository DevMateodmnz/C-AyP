#include <stdio.h>

int main() {
    int num1, num2;
    float promedio;

    printf("Ingrese el primer número: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    promedio = (num1 + num2) / 2.0;

    printf("El promedio de los dos números es: %.2f\n", promedio);

    return 0;
}