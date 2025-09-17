#include <stdio.h>

int main() {
    int N1, N2, x;
    printf("Ingrese N1 N2 x: ");
    scanf("%d %d %d", &N1, &N2, &x);
    if(N1 >= N2) {
        printf("N1 debe ser menor que N2\n");
        return 1;
    }
    printf("Multiplos de %d entre %d y %d: ", x, N1, N2);
    for(int i = N1; i <= N2; i++) {
        if(i % x == 0) printf("%d ", i);
    }
    printf("\n");
    return 0;
}
