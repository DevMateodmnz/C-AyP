#include <stdio.h>
#define PI 3.141592653589793

int main() {
    float radio, diametro, perimetro, area;

    printf("Ingrese el radio del círculo: ");
    scanf("%f", &radio);

    diametro = 2 * radio;
    perimetro = 2 * PI * radio;
    area = PI * radio * radio;

    printf("Diámetro del círculo: %.2f\n", diametro);
    printf("Perímetro del círculo: %.2f\n", perimetro);
    printf("Área del círculo: %.2f\n", area);

    return 0;
}