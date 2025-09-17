#include <stdio.h>
#include <string.h>

int main() {
    char bin[33];
    printf("Ingrese numero binario: ");
    scanf("%s", bin);
    int len = strlen(bin);
    int dec = 0;
    for(int i = 0; i < len; i++) {
        if(bin[i] == '1') dec += (1 << (len - 1 - i));
    }
    printf("Binario: %s\nDecimal: %d\n", bin, dec);
    return 0;
}
