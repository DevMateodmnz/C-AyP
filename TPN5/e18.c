#include <stdio.h>
#include <math.h>

int main() {
    double M;
    int N;
    printf("Ingrese M: ");
    scanf("%lf", &M);
    printf("Ingrese N: ");
    scanf("%d", &N);
    int lados = 0, diag = 0, sup = 0, inf = 0;
    for (int i = 0; i < N; i++) {
        double x, y;
        printf("Ingrese coordenadas del punto %d (x y): ", i+1);
        scanf("%lf %lf", &x, &y);
        if (fabs(x - 0) < 1e-9 || fabs(x - M) < 1e-9 || fabs(y - 0) < 1e-9 || fabs(y - M) < 1e-9) {
            lados++;
        }
        if (fabs(x - y) < 1e-9) {
            diag++;
        }
        if (y > x && x >= 0 && x <= M && y >= 0 && y <= M) {
            sup++;
        }
        if (y < x && x >= 0 && x <= M && y >= 0 && y <= M) {
            inf++;
        }
    }
    printf("Puntos en los lados: %d\n", lados);
    printf("Puntos en la diagonal: %d\n", diag);
    printf("Puntos en el triangulo superior: %d\n", sup);
    printf("Puntos en el triangulo inferior: %d\n", inf);
    return 0;
}
