#include <stdio.h>

int main() {
    int num1, num2, num3, suma;

    printf("Ingrese el primer número: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    printf("Ingrese el tercer número: ");
    scanf("%d", &num3);

    suma = num1 + num2 + num3;

    printf("La suma de los tres números es: %d\n", suma);

    return 0;
}