#include <stdio.h>

int main() {
    float metros, decimetros, centimetros;

    printf("Ingrese la medida en metros: ");
    scanf("%f", &metros);

    decimetros = metros * 10;
    centimetros = metros * 100;

    printf("Medida en metros: %.2f m\n", metros);
    printf("Equivalente en decímetros: %.2f dm\n", decimetros);
    printf("Equivalente en centímetros: %.2f cm\n", centimetros);

    return 0;
}