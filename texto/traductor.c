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
// 🔹 Uso de struct: permite agrupar datos relacionados (palabras en dos idiomas)
//   en un solo tipo, lo que hace el código más ordenado que usar dos arrays paralelos.
struct Traduccion {
    char* espanol;
    char* ingles;
};

// Función: reemplazar_palabra
// Reemplaza todas las apariciones de una palabra "buscar" por otra "reemplazo"
// dentro de la cadena "linea".
// 🔹 Esta función es clave: usa punteros y funciones de la librería string.h 
//   (como strstr, strncpy, sprintf, strcpy) para hacer reemplazos de forma segura.

void reemplazar_palabra(char* linea, const char* buscar, const char* reemplazo) {
    char buffer[1024];  // Buffer temporal donde guardaremos la línea modificada
    char* pos;          // Puntero para buscar la posición de la palabra a reemplazar

    // Mientras se encuentre la palabra buscada en la línea...
    while ((pos = strstr(linea, buscar)) != NULL) {
        buffer[0] = '\0';  // Limpia el buffer
        // 🔹 strstr devuelve un puntero a la primera aparición de "buscar" dentro de "linea".
        //    Si devuelve NULL, significa que no encontró coincidencias.

        // Copiamos la parte de la línea antes de la palabra a reemplazar
        strncpy(buffer, linea, pos - linea);
        buffer[pos - linea] = '\0'; // Cerramos el string correctamente
        // 🔹 Se usa strncpy para copiar solo el fragmento antes de la palabra.
        //    Es más seguro que strcpy cuando se trabaja con segmentos.

        // Agregamos al buffer la palabra reemplazada y el resto del texto
        sprintf(buffer + (pos - linea), "%s%s", reemplazo, pos + strlen(buscar));
        // 🔹 sprintf permite concatenar la palabra reemplazada con el resto del texto.
        //    Es útil para reconstruir la línea completa en una sola operación.

        // Copiamos el contenido modificado de vuelta a "linea"
        strcpy(linea, buffer);
        // 🔹 El buffer actúa como una zona temporal para evitar sobreescribir
        //    la misma cadena mientras se procesa.
    }
    // ⚠️ Limitación: este método reemplaza subcadenas dentro de palabras también,
    //    por ejemplo “para” dentro de “comparar”. Podría mejorarse con detección de separadores.
}

// Función: traducir_linea
// Recorre el diccionario de traducciones y aplica cada reemplazo
// sobre una línea de texto.
// 🔹 Separa la lógica de traducción de la lógica de lectura del archivo,
//   lo que mejora la modularidad y reutilización del código.

void traducir_linea(char* linea, struct Traduccion diccionario[], int n) {
    for (int i = 0; i < n; i++) {
        reemplazar_palabra(linea, diccionario[i].espanol, diccionario[i].ingles);
        // 🔹 Este bucle aplica todas las traducciones en orden.
        //    Si dos palabras se superponen o una contiene a otra, podría afectar el resultado.
    }
}

// Función principal
// Lee un archivo de código en español y genera una versión traducida al inglés.
// 🔹 Contiene la lógica principal: apertura, lectura, procesamiento y escritura de archivos.

int main() {
    FILE *entrada, *salida;   // Punteros a archivos
    char linea[1024];         // Buffer para leer cada línea del archivo
    // 🔹 Se usa un tamaño fijo (1024) para simplicidad, evitando malloc.
    //    Esto es suficiente para líneas cortas y evita fugas de memoria.

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
    // 🔹 Usar un arreglo de estructuras permite tener un "diccionario" claro y extensible.
    // 🔹 Cada par español → inglés está claramente definido.

    // Calculamos cuántas traducciones hay en el diccionario
    int num_traducciones = sizeof(diccionario) / sizeof(diccionario[0]);
    // 🔹 Forma automática de obtener el número de elementos.
    //    Si se agregan o quitan traducciones, el programa sigue funcionando sin cambios.

    // Abrimos el archivo fuente (en español) en modo lectura
    entrada = fopen("archivo-es.c", "r");
    // Abrimos el archivo de salida (traducido) en modo escritura
    salida = fopen("programa-en.c", "w");
    // 🔹 "r" = read (lectura), "w" = write (escritura).
    //    Al abrir en "w", si el archivo ya existe, se sobreescribe.

    // Verificamos que ambos archivos se hayan abierto correctamente
    if (!entrada || !salida) {
        printf("Error al abrir archivos.\n");
        // 🔹 Importante manejo de errores: evita usar punteros NULL en operaciones de E/S.
        return 1;
    }

    // Leemos el archivo línea por línea
    while (fgets(linea, sizeof(linea), entrada)) {
        // Traducimos la línea usando el diccionario
        traducir_linea(linea, diccionario, num_traducciones);

        // Escribimos la línea traducida en el archivo de salida
        fputs(linea, salida);
        // 🔹 fgets y fputs se usan porque son seguras y manejan líneas completas.
        //    fgets mantiene el salto de línea, lo que conserva la estructura original del archivo.
    }

    // Cerramos ambos archivos
    fclose(entrada);
    fclose(salida);
    // 🔹 Buen hábito: siempre cerrar los archivos para liberar recursos del sistema.

    printf("Traducción completada con éxito.\n");
    // 🔹 Mensaje final que confirma la ejecución correcta del programa.
    //    Podría extenderse mostrando la cantidad de líneas traducidas o palabras reemplazadas.
    return 0;
}
