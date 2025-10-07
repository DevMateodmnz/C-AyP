#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char palabra[100];
    
    printf("Ingresa una palabra en mayusculas: ");
    scanf("%s", palabra);
    
    // Convertir a minúsculas
    for(int i = 0; palabra[i] != '\0'; i++) {
        palabra[i] = tolower(palabra[i]);
    }
    
    printf("Palabra en minusculas: %s\n", palabra);
    
    return 0;
}