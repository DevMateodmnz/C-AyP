#include <stdio.h>

int main() {
    int num;
    printf("Ingrese numero de 4 digitos: ");
    scanf("%d", &num);
    if(num < 1000 || num > 9999) {
        printf("Debe ser de 4 digitos\n");
        return 1;
    }
    printf("Divisores de %d: ", num);
    for(int i = 1; i <= num; i++) {
        if(num % i == 0) printf("%d ", i);
    }
    printf("\n");
    return 0;
}
