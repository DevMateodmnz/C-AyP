#include <stdio.h>
#include <string.h>
#include <ctype.h>

void capitalizar(char palabra[]) {
    if(palabra[0] != '\0') {
        palabra[0] = toupper(palabra[0]);
    }
    for(int i = 1; palabra[i] != '\0'; i++) {
        palabra[i] = tolower(palabra[i]);
    }
}

int main() {
    char nombre1[50], nombre2[50], apellido[50];
    
    printf("Ingresa dos nombres y un apellido: ");
    scanf("%s %s %s", nombre1, nombre2, apellido);
    
    capitalizar(nombre1);
    capitalizar(nombre2);
    capitalizar(apellido);
    
    printf("Resultado: %s-%s-%s\n", apellido, nombre1, nombre2);
    
    return 0;
}