#include <stdio.h>
#include <math.h>

int main() {
    int N;
    printf("Ingrese N: ");
    scanf("%d", &N);
    int total_score = 0;
    for (int i = 0; i < N; i++) {
        double x, y;
        printf("Ingrese coordenadas del punto %d (x y): ", i+1);
        scanf("%lf %lf", &x, &y);
        double r = sqrt(x*x + y*y);
        int score = 0;
        if (r <= 1) score = 4;
        else if (r <= 2) score = 3;
        else if (r <= 3) score = 2;
        else if (r <= 4) score = 1;
        total_score += score;
    }
    double promedio = (double)total_score / N;
    printf("Puntaje total: %d\n", total_score);
    printf("Promedio: %.2f\n", promedio);
    return 0;
}
