#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Traduccion {
    char* espanol;
    char* ingles;
};

void reemplazar_palabra(char* linea, const char* buscar, const char* reemplazo) {
    char buffer[1024];
    char* pos;

    while ((pos = strstr(linea, buscar)) != NULL) {
        buffer[0] = '\0';
        strncpy(buffer, linea, pos - linea);
        buffer[pos - linea] = '\0';
        sprintf(buffer + (pos - linea), "%s%s", reemplazo, pos + strlen(buscar));
        strcpy(linea, buffer);
    }
}

void traducir_linea(char* linea, struct Traduccion diccionario[], int n) {
    for (int i = 0; i < n; i++) {
        reemplazar_palabra(linea, diccionario[i].espanol, diccionario[i].ingles);
    }
}

int main() {
    FILE *entrada, *salida;
    char linea[1024];

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

    int num_traducciones = sizeof(diccionario) / sizeof(diccionario[0]);

    entrada = fopen("archivo-es.c", "r");
    salida = fopen("programa-en.c", "w");

    if (!entrada || !salida) {
        printf("Error al abrir archivos.\n");
        return 1;
    }

    while (fgets(linea, sizeof(linea), entrada)) {
        traducir_linea(linea, diccionario, num_traducciones);
        fputs(linea, salida);
    }

    fclose(entrada);
    fclose(salida);

    printf("Traducción completada con éxito.\n");
    return 0;
}