#include <stdio.h>

int main() {
    int dec, original;
    printf("Ingrese numero decimal positivo: ");
    scanf("%d", &dec);
    if(dec <= 0) {
        printf("Debe ser positivo\n");
        return 1;
    }
    original = dec;
    char bin[33];
    int i = 0;
    while(dec > 0) {
        bin[i++] = (dec % 2) + '0';
        dec /= 2;
    }
    bin[i] = '\0';
    // reverse
    for(int j = 0; j < i / 2; j++) {
        char t = bin[j];
        bin[j] = bin[i - 1 - j];
        bin[i - 1 - j] = t;
    }
    printf("Decimal: %d\nBinario: %s\n", original, bin);
    return 0;
}
