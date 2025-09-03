#include <stdio.h>

int main() {
    float lado1, lado2, perimetro, superficie;

    printf("Ingrese el primer lado del rectángulo: ");
    scanf("%f", &lado1);

    printf("Ingrese el segundo lado del rectángulo: ");
    scanf("%f", &lado2);

    perimetro = 2 * (lado1 + lado2);
    superficie = lado1 * lado2;

    printf("Perímetro del rectángulo: %.2f\n", perimetro);
    printf("Superficie del rectángulo: %.2f\n", superficie);

    return 0;
}