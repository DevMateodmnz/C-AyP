#include <stdio.h>
#include <string.h>

int main() {
    char num[20];
    printf("Ingrese numero de 4 o mas digitos: ");
    scanf("%s", num);
    int len = strlen(num);
    if(len < 4) {
        printf("Debe tener al menos 4 digitos\n");
        return 1;
    }
    printf("Numero: %s\nInvertido: ", num);
    for(int i = len - 1; i >= 0; i--) printf("%c", num[i]);
    printf("\n");
    return 0;
}
