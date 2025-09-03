#include <stdio.h>
#include <math.h>

int main() {
    int num1, num2;
    double media_geometrica;

    printf("Ingrese el primer número: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    media_geometrica = sqrt(num1 * num2);

    printf("La media geométrica de los dos números es: %.2f\n", media_geometrica);

    return 0;
}