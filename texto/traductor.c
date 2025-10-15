#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
    FILE *archivo_entrada;      // Puntero al archivo
    char linea[1024];           // Buffer donde se guardará cada línea

    // 1: Abrimos el archivo en modo lectura ("r")
    archivo_entrada = fopen("programa_es.c", "r");

    // 2: Verificamos si se abrió correctamente
    if (archivo_entrada == NULL) {
        printf("Error: no se pudo abrir el archivo de entrada.\n");
        return 1; // Terminamos el programa con error
    }

    // 3: Leemos línea por línea con fgets
    // fgets lee una línea completa hasta \n o EOF
    while (fgets(linea, sizeof(linea), archivo_entrada)) {
        // Mostramos la línea leída (solo para probar)
        printf("%s", linea);
    }

    // 4: Cerramos el archivo al terminar
    fclose(archivo_entrada);

    printf("\nLectura completada con éxito.\n");
    return 0;
}
