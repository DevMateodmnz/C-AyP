#include <stdio.h>

int main() {
    int N;
    printf("Ingrese N: ");
    scanf("%d", &N);
    double sum_pos = 0, sum_neg = 0;
    int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
    for (int i = 0; i < N; i++) {
        double x, y;
        printf("Ingrese coordenadas del punto %d (x y): ", i+1);
        scanf("%lf %lf", &x, &y);
        double area = 0.5 * x * y;
        if (area > 0) sum_pos += area;
        else sum_neg += area;
        if (x > 0 && y > 0) q1++;
        else if (x < 0 && y > 0) q2++;
        else if (x < 0 && y < 0) q3++;
        else if (x > 0 && y < 0) q4++;
    }
    printf("Suma de superficies positivas: %.2f\n", sum_pos);
    printf("Suma de superficies negativas: %.2f\n", sum_neg);
    printf("Triangulos en Q1: %d\n", q1);
    printf("Triangulos en Q2: %d\n", q2);
    printf("Triangulos en Q3: %d\n", q3);
    printf("Triangulos en Q4: %d\n", q4);
    return 0;
}
