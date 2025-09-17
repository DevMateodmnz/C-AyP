#include <stdio.h>

int main() {
    int N, num, max, min;
    printf("Ingrese N: ");
    scanf("%d", &N);
    if (N <= 0) {
        printf("N debe ser mayor que 0\n");
        return 1;
    }
    printf("Ingrese numero 1: ");
    scanf("%d", &num);
    max = min = num;
    for(int i = 1; i < N; i++) {
        printf("Ingrese numero %d: ", i + 1);
        scanf("%d", &num);
        if(num > max) max = num;
        if(num < min) min = num;
    }
    printf("Mayor: %d\nMenor: %d\n", max, min);
    return 0;
}
