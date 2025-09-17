#include <stdio.h>

int main() {
    int N;
    printf("Ingrese N: ");
    scanf("%d", &N);
    if(N & 1) printf("Impar\n");
    else printf("Par\n");
    return 0;
}
