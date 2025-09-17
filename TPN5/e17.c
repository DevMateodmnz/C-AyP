#include <stdio.h>

int main() {
    int N;
    long long fact = 1;
    printf("Ingrese un numero natural: ");
    scanf("%d", &N);
    if (N < 0) {
        printf("Debe ser positivo\n");
        return 1;
    }
    printf("%d! = ", N);
    for (int i = N; i >= 1; i--) {
        fact *= i;
        printf("%d", i);
        if (i > 1) printf(" * ");
        else printf(" = %lld\n", fact);
    }
    return 0;
}
