#include <stdio.h>

int main() {
    int N;
    printf("Ingrese N: ");
    scanf("%d", &N);
    int max_edad = -1, order_edad = -1;
    double min_altura = 1e9, sum_altura = 0;
    int order_altura = -1, sum_edad = 0;
    for (int i = 0; i < N; i++) {
        int edad;
        double altura;
        printf("Ingrese edad y altura de la persona %d: ", i+1);
        scanf("%d %lf", &edad, &altura);
        sum_edad += edad;
        sum_altura += altura;
        if (edad > max_edad) {
            max_edad = edad;
            order_edad = i + 1;
        }
        if (altura < min_altura) {
            min_altura = altura;
            order_altura = i + 1;
        }
    }
    double prom_edad = (double)sum_edad / N;
    double prom_altura = sum_altura / N;
    printf("Mayor edad: %d, orden: %d\n", max_edad, order_edad);
    printf("Menor altura: %.2f, orden: %d\n", min_altura, order_altura);
    printf("Promedio edades: %.2f\n", prom_edad);
    printf("Promedio alturas: %.2f\n", prom_altura);
    return 0;
}
