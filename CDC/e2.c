#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generarNuevaPalabra(char *palabra) {
    printf("Presenta: %s ", palabra);
    int longitud = strlen(palabra);
    for (int i = 0; i < longitud; i++) {
        printf("%c ", toupper(palabra[i]));
    }
    printf("\n");
}

int main() {
    char palabra[100];
    printf("Ingresa: ");
    scanf("%s", palabra);
    generarNuevaPalabra(palabra);
    return 0;
}
