#include <stdio.h>

int main() {
    float a, b, c;
    float mayor, cat1, cat2;

    printf("Ingrese el primer lado: ");
    scanf("%f", &a);

    printf("Ingrese el segundo lado: ");
    scanf("%f", &b);

    printf("Ingrese el tercer lado: ");
    scanf("%f", &c);

    // Determinar el mayor (hipotenusa) y los otros dos (catetos)
    if (a >= b && a >= c) {
        mayor = a;
        cat1 = b;
        cat2 = c;
    } else if (b >= a && b >= c) {
        mayor = b;
        cat1 = a;
        cat2 = c;
    } else {
        mayor = c;
        cat1 = a;
        cat2 = b;
    }

    if (a > 0 && b > 0 && c > 0) {
        if ( (mayor * mayor) == (cat1 * cat1 + cat2 * cat2) ) {
            printf("Son lados de un triángulo rectángulo.\n");
        } else {
            printf("No son lados de un triángulo rectángulo.\n");
        }
    } else {
        printf("Todos los valores deben ser positivos.\n");
    }

    return 0;
}