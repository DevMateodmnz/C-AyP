#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char palabra[100];
    char nueva_palabra[5];
    
    printf("Ingresa una palabra (minimo 5 caracteres): ");
    scanf("%s", palabra);
    
    while(strlen(palabra) < 5) {
        printf("Error. Ingresa una palabra con al menos 5 caracteres: ");
        scanf("%s", palabra);
    }
    
    // Convertir a mayúsculas
    for(int i = 0; palabra[i] != '\0'; i++) {
        palabra[i] = toupper(palabra[i]);
    }
    
    // Construir nueva palabra
    nueva_palabra[0] = palabra[0];
    nueva_palabra[1] = palabra[1];
    nueva_palabra[2] = palabra[strlen(palabra)-2];
    nueva_palabra[3] = palabra[strlen(palabra)-1];
    nueva_palabra[4] = '\0';
    
    printf("Palabra original: %s\n", palabra);
    printf("Palabra extraida: %s\n", nueva_palabra);
    
    return 0;
}