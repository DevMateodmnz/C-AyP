#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1, x2, y2;
    float base, altura, perimetro, superficie;

    printf("Ingrese las coordenadas del vértice inferior izquierdo (x1 y1): ");
    scanf("%f %f", &x1, &y1);

    printf("Ingrese las coordenadas del vértice superior derecho (x2 y2): ");
    scanf("%f %f", &x2, &y2);

    base = fabs(x2 - x1);
    altura = fabs(y2 - y1);

    perimetro = 2 * (base + altura);
    superficie = base * altura;

    printf("Perímetro del rectángulo: %.2f\n", perimetro);
    printf("Superficie del rectángulo: %.2f\n", superficie);

    return 0;
}