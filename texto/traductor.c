/*
# El programa lee línea por línea un archivo llamado archivo-es.c.

# En cada línea, busca palabras definidas en el diccionario de traducciones.

# eemplaza las palabras encontradas (por ejemplo, "entero" → "int", "imprimir" → "printf").

# Escribe la línea traducida en un nuevo archivo llamado programa-en.c.

# Al finalizar, muestra el mensaje “Traducción completada con éxito.” */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definimos una estructura que guarda pares de palabras:
// una en español y su equivalente en inglés.
struct Traduccion {
    char* espanol;
    char* ingles;
};

// Función: reemplazar_palabra
// Reemplaza todas las apariciones de una palabra "buscar" por otra "reemplazo"
// dentro de la cadena "linea".

void reemplazar_palabra(char* linea, const char* buscar, const char* reemplazo) {
    char buffer[1024];  // Buffer temporal donde guardaremos la línea modificada
    char* pos;          // Puntero para buscar la posición de la palabra a reemplazar

    // Mientras se encuentre la palabra buscada en la línea...
    while ((pos = strstr(linea, buscar)) != NULL) {
        buffer[0] = '\0';  // Limpia el buffer

        // Copiamos la parte de la línea antes de la palabra a reemplazar
        strncpy(buffer, linea, pos - linea);
        buffer[pos - linea] = '\0'; // Cerramos el string correctamente

        // Agregamos al buffer la palabra reemplazada y el resto del texto
        sprintf(buffer + (pos - linea), "%s%s", reemplazo, pos + strlen(buscar));

        // Copiamos el contenido modificado de vuelta a "linea"
        strcpy(linea, buffer);
    }
}

// Función: traducir_linea
// Recorre el diccionario de traducciones y aplica cada reemplazo
// sobre una línea de texto.

void traducir_linea(char* linea, struct Traduccion diccionario[], int n) {
    for (int i = 0; i < n; i++) {
        reemplazar_palabra(linea, diccionario[i].espanol, diccionario[i].ingles);
    }
}

// Función principal
// Lee un archivo de código en español y genera una versión traducida al inglés.

int main() {
    FILE *entrada, *salida;   // Punteros a archivos
    char linea[1024];         // Buffer para leer cada línea del archivo

    // Diccionario de traducciones: español → inglés
    struct Traduccion diccionario[] = {
        {"entero", "int"},
        {"flotante", "float"},
        {"doble", "double"},
        {"caracter", "char"},
        {"vacío", "void"},
        {"mientras", "while"},
        {"para", "for"},
        {"hacer", "do"},
        {"si", "if"},
        {"sino", "else"},
        {"interrumpir", "break"},
        {"continuar", "continue"},
        {"retornar", "return"},
        {"principal", "main"},
        {"incluir", "#include"},
        {"definir", "#define"},
        {"constante", "const"},
        {"imprimir", "printf"},
        {"leer", "scanf"},
        {"estructura", "struct"},
        {"enumeracion", "enum"},
        {"unión", "union"},
        {"tipo", "typedef"},
        {"estático", "static"},
        {"externo", "extern"},
        {"registrar", "register"},
        {"volátil", "volatile"},
        {"ir_a", "goto"},
    };

    // Calculamos cuántas traducciones hay en el diccionario
    int num_traducciones = sizeof(diccionario) / sizeof(diccionario[0]);

    // Abrimos el archivo fuente (en español) en modo lectura
    entrada = fopen("archivo-es.c", "r");

    // Abrimos el archivo de salida (traducido) en modo escritura
    salida = fopen("programa-en.c", "w");

    // Verificamos que ambos archivos se hayan abierto correctamente
    if (!entrada || !salida) {
        printf("Error al abrir archivos.\n");
        return 1;
    }

    // Leemos el archivo línea por línea
    while (fgets(linea, sizeof(linea), entrada)) {
        // Traducimos la línea usando el diccionario
        traducir_linea(linea, diccionario, num_traducciones);

        // Escribimos la línea traducida en el archivo de salida
        fputs(linea, salida);
    }

    // Cerramos ambos archivos
    fclose(entrada);
    fclose(salida);

    printf("Traducción completada con éxito.\n");
    return 0;
}
