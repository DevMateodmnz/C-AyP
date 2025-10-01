#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertirMayusculasInvertida(char *palabra) {
    int longitud = strlen(palabra);
    // Convertir a mayúsculas
    for (int i = 0; i < longitud; i++) {
        palabra[i] = toupper(palabra[i]);
    }
    // Invertir la cadena
    for (int i = 0; i < longitud / 2; i++) {
        char temp = palabra[i];
        palabra[i] = palabra[longitud - 1 - i];
        palabra[longitud - 1 - i] = temp;
    }
    printf("Presenta: %s\n", palabra);
}

int main() {
    char palabra[100];
    printf("Ingresa: ");
    scanf("%s", palabra);
    convertirMayusculasInvertida(palabra);
    return 0;
}
