#include <stdio.h>

int main() {
    int N, num, pos = 0, neg = 0, zero = 0;
    printf("Ingrese N: ");
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        printf("Ingrese numero %d: ", i + 1);
        scanf("%d", &num);
        if(num > 0) pos++;
        else if(num < 0) neg++;
        else zero++;
    }
    printf("Positivos: %d\nNegativos: %d\nCeros: %d\n", pos, neg, zero);
    return 0;
}
