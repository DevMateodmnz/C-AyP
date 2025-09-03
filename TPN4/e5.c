#include <stdio.h>

int main() {
    float fahrenheit, centigrados;

    printf("Ingrese la temperatura en grados Fahrenheit: ");
    scanf("%f", &fahrenheit);

    centigrados = (5.0 / 9.0) * (fahrenheit - 32);

    printf("Temperatura en Fahrenheit: %.2f °F\n", fahrenheit);
    printf("Temperatura en Centígrados: %.2f °C\n", centigrados);

    return 0;
}