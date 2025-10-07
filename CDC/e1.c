#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

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

bool esSoloPalabras(char *str) {
    for (int i = 0; str[i] != '\0'; i++) }
        if (!isalpha((unsigned char)str[i])) {
            return false;
        }
    }
    return (str[0] != '\0');
}

int main() {
    char palabra[100];
    int resultado_scan;

    printf("Ingresa: ");
    resultado_scan = scanf("%99s", palabra);

    if (resultado_scan == 1 && esSoloPalabras(palabra)) {
        convertirMayusculasInvertida(palabra);
    } else {
        printf("Error: Por favor, ingresa solo letras, sin numeros ni otros caracteres.\n");
        while (getchar() != '\n');
        return 1;
    return 0;
}