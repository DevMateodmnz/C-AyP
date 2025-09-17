#include <stdio.h>

int main() {
    int L, sum = 0, N = 0;
    printf("Ingrese L: ");
    scanf("%d", &L);
    while (sum + (N + 1) <= L) {
        N++;
        sum += N;
    }
    printf("El valor de N es: %d\n", N);
    return 0;
}
