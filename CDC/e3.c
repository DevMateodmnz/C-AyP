#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char palabra[100];
    char nueva_palabra[100];
    int i;
    
    printf("Ingresa una palabra: ");
    scanf("%s", palabra);
    
    for(i = 0; palabra[i] != '\0'; i++) {
        char letra = toupper(palabra[i]);
        if(letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U') {
            nueva_palabra[i] = '*';
        } else {
            nueva_palabra[i] = palabra[i];
        }
    }
    nueva_palabra[i] = '\0';
    
    printf("Palabra original: %s\n", palabra);
    printf("Palabra modificada: %s\n", nueva_palabra);
    
    return 0;
}