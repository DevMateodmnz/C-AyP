#include <stdio.h>
#include <ctype.h>

int main() {
    char palabra[100];
    int contador = 0;
    
    printf("Ingresa una palabra: ");
    scanf("%s", palabra);
    
    for(int i = 0; palabra[i] != '\0'; i++) {
        char letra = tolower(palabra[i]);
        if(letra == 'a' || letra == 'e' || letra == 'i' || 
           letra == 'o' || letra == 'u') {
            contador++;
        }
    }
    
    printf("La palabra '%s' tiene %d vocal(es)\n", palabra, contador);
    
    return 0;
}