#include <stdio.h>
#include <string.h>
#include <ctype.h>

int esMayusculas(char cadena[]) {
    for(int i = 0; cadena[i] != '\0'; i++) {
        if(!isupper(cadena[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char palabra[100];
    char resultado[100] = "";
    int i = 0, j = 0;
    
    printf("Ingresa una palabra en mayusculas: ");
    scanf("%s", palabra);
    
    while(!esMayusculas(palabra)) {
        printf("Error. Ingresa la palabra en mayusculas: ");
        scanf("%s", palabra);
    }
    
    // Eliminar "CA"
    while(palabra[i] != '\0') {
        if(palabra[i] == 'C' && palabra[i+1] == 'A') {
            i += 2; // Saltar los dos caracteres
        } else {
            resultado[j] = palabra[i];
            j++;
            i++;
        }
    }
    resultado[j] = '\0';
    
    printf("Palabra original: %s\n", palabra);
    printf("Palabra modificada: %s\n", resultado);
    
    return 0;
}