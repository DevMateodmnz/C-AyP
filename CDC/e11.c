#include <stdio.h>
#include <string.h>
#include <ctype.h>

int esVocal(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    char palabra[100];
    char resultado[200] = ""; // El doble de tamaño por si todas son consonantes
    int j = 0;
    
    printf("Ingresa una palabra: ");
    scanf("%s", palabra);
    
    // Reemplazar consonantes por "++"
    for(int i = 0; palabra[i] != '\0'; i++) {
        if(!esVocal(palabra[i]) && isalpha(palabra[i])) {
            resultado[j++] = '+';
            resultado[j++] = '+';
        } else {
            resultado[j++] = palabra[i];
        }
    }
    resultado[j] = '\0';
    
    printf("Palabra original: %s\n", palabra);
    printf("Palabra modificada: %s\n", resultado);
    
    return 0;
}