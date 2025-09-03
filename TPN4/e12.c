#include <stdio.h>

int main() {
    int a, b, c;

    printf("Ingrese el primer número: ");
    scanf("%d", &a);

    printf("Ingrese el segundo número: ");
    scanf("%d", &b);

    printf("Ingrese el tercer número: ");
    scanf("%d", &c);

    if (a < b && b < c) {
        printf("Los números están ordenados en forma ascendente.\n");
    } else if (a > b && b > c) {
        printf("Los números están ordenados en forma descendente.\n");
    } else {
        printf("Los números no están ordenados en forma ascendente ni descendente.\n");
    }

    if ((b == a + 1 && c == b + 1) || (b == a - 1 && c == b - 1)) {
        printf("Los números son consecutivos.\n");
    } else {
        printf("Los números no son consecutivos.\n");
    }

    return 0;
}