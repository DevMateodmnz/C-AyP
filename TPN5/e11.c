#include <stdio.h>
#include <string.h>

int binaryToDecimal(const char *bin) {
    int len = strlen(bin);
    int dec = 0;
    for(int i = 0; i < len; i++) {
        if(bin[i] == '1') dec += (1 << (len - 1 - i));
    }
    return dec;
}

int main() {
    char bin1[17], bin2[17];
    printf("Ingrese primer numero binario de 4 digitos: ");
    scanf("%s", bin1);
    printf("Ingrese segundo numero binario de 4 digitos: ");
    scanf("%s", bin2);
    int dec1 = binaryToDecimal(bin1);
    int dec2 = binaryToDecimal(bin2);
    int sum = dec1 + dec2;
    printf("Numero 1: %s\nNumero 2: %s\nSuma decimal: %d\n", bin1, bin2, sum);
    return 0;
}
