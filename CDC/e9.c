#include <stdio.h>
#include <string.h>
#include <ctype.h>

int esVocal(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    char palabra[100];
    char resultado[100];
    
    printf("Ingresa una palabra en minusculas: ");
    scanf("%s", palabra);
    
    strcpy(resultado, palabra);
    
    // Convertir consonantes a mayúsculas
    for(int i = 0; resultado[i] != '\0'; i++) {
        if(!esVocal(resultado[i])) {
            resultado[i] = toupper(resultado[i]);
        }
    }
    
    printf("Palabra original: %s\n", palabra);
    printf("Palabra modificada: %s\n", resultado);
    
    return 0;
}