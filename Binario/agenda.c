/*
Desarrollar un programa en C que funcione como una agenda de contactos, permitiendo gestionar contactos mediante las operaciones básicas:

#Agregar contactos (incluyendo DNI como identificador).
#Eliminar contactos individuales.
#Ordenar contactos.
#Eliminar todos los contactos.
#Buscar contactos (usando DNI u otros criterios).*/

#include <stdio.h>
#include <string.h>

#define MAX_CONTACTOS 100
// 🔹 Se usa una constante simbólica con #define para definir el tamaño máximo.
//   Esto permite cambiar fácilmente la capacidad sin modificar múltiples líneas de código.
//   Además evita usar memoria dinámica, lo que simplifica el manejo de datos.


// Estructura base para los contactos
struct Contacto {
    char nombre[50];
    char telefono[20];
    int dni;
};
// 🔹 Se agrupan los datos relacionados en una estructura, facilitando la manipulación.
// 🔹 El DNI se usa como identificador único, lo que permite búsquedas precisas y evita duplicados.
// 🔹 El uso de arrays fijos de char evita el uso de memoria dinámica (malloc), reduciendo errores comunes.


// Prototipos de funciones
// 🔹 Los prototipos informan al compilador qué funciones existen antes de main().
//   Esto es buena práctica y permite organizar el código mejor.
void agregarContacto(struct Contacto agenda[], int *cantidad);
void eliminarContacto(struct Contacto agenda[], int *cantidad);
void eliminarTodos(struct Contacto agenda[], int *cantidad);
void ordenarContactos(struct Contacto agenda[], int cantidad);
void buscarContacto(struct Contacto agenda[], int cantidad);
void mostrarContactos(struct Contacto agenda[], int cantidad);


// Función principal
int main() {
    struct Contacto agenda[MAX_CONTACTOS]; // 🔹 Se declara el array de estructuras.
    int cantidad = 0;                      // 🔹 Contador de contactos actuales.
    int opcion;

    do {
        printf("\n=== AGENDA DE CONTACTOS ===\n");
        printf("1. Agregar contacto\n");
        printf("2. Buscar contacto\n");
        printf("3. Ordenar contactos\n");
        printf("4. Eliminar contacto\n");
        printf("5. Eliminar todos los contactos\n");
        printf("6. Mostrar todos los contactos\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // limpia el buffer del salto de línea
        // 🔹 Se usa getchar() para eliminar el salto de línea que deja scanf, 
        //   evitando que interfiera con futuras lecturas con fgets.

        switch(opcion) {
            case 1: agregarContacto(agenda, &cantidad); break;
            case 2: buscarContacto(agenda, cantidad); break;
            case 3: ordenarContactos(agenda, cantidad); break;
            case 4: eliminarContacto(agenda, &cantidad); break;
            case 5: eliminarTodos(agenda, &cantidad); break;
            case 6: mostrarContactos(agenda, cantidad); break;
            case 0: printf("Saliendo del programa...\n"); break;
            default: printf("Opción inválida. Intente de nuevo.\n");
        }
        // 🔹 Se usa un switch para controlar el flujo principal. 
        //   Es más claro y escalable que usar múltiples if/else.

    } while(opcion != 0);

    return 0;
}


// FUNCIONES PRINCIPALES

void agregarContacto(struct Contacto agenda[], int *cantidad) {
    if (*cantidad >= MAX_CONTACTOS) {
        printf("La agenda está llena. No se pueden agregar más contactos.\n");
        return;
    }

    struct Contacto nuevo;

    printf("Ingrese nombre: ");
    fgets(nuevo.nombre, sizeof(nuevo.nombre), stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = 0; // eliminar salto de línea
    // 🔹 strcspn busca el primer '\n' y lo reemplaza por '\0'. Esto evita errores de formato al mostrar.

    printf("Ingrese teléfono: ");
    fgets(nuevo.telefono, sizeof(nuevo.telefono), stdin);
    nuevo.telefono[strcspn(nuevo.telefono, "\n")] = 0;

    printf("Ingrese DNI: ");
    scanf("%d", &nuevo.dni);
    getchar();

    // Verificar si ya existe el contacto por DNI
    for (int i = 0; i < *cantidad; i++) {
        if (agenda[i].dni == nuevo.dni) {
            printf("Ya existe un contacto con ese DNI.\n");
            return;
        }
    }
    // 🔹 Se valida la unicidad del contacto por DNI, lo que evita duplicados.
    // 🔹 Esta comprobación se hace linealmente (O(n)), lo que está bien para pocos contactos.

    agenda[*cantidad] = nuevo;
    (*cantidad)++;

    printf("Contacto agregado con éxito.\n");
}


void mostrarContactos(struct Contacto agenda[], int cantidad) {
    if (cantidad == 0) {
        printf("No hay contactos en la agenda.\n");
        return;
    }

    printf("\n--- LISTA DE CONTACTOS ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d. %s | Tel: %s | DNI: %d\n", i + 1, agenda[i].nombre, agenda[i].telefono, agenda[i].dni);
    }
    // 🔹 Muestra todos los contactos con formato claro.
    // 🔹 Se usa un índice desde 1 para que sea más amigable al usuario.
}


void buscarContacto(struct Contacto agenda[], int cantidad) {
    if (cantidad == 0) {
        printf("No hay contactos para buscar.\n");
        return;
    }

    int opcion;
    printf("Buscar por:\n1. Nombre\n2. DNI\nOpción: ");
    scanf("%d", &opcion);
    getchar();

    if (opcion == 1) {
        char nombre[50];
        printf("Ingrese el nombre a buscar: ");
        fgets(nombre, sizeof(nombre), stdin);
        nombre[strcspn(nombre, "\n")] = 0;

        int encontrado = 0;
        for (int i = 0; i < cantidad; i++) {
            if (strcmp(agenda[i].nombre, nombre) == 0) {
                printf("Encontrado: %s | Tel: %s | DNI: %d\n", agenda[i].nombre, agenda[i].telefono, agenda[i].dni);
                encontrado = 1;
            }
        }
        if (!encontrado) printf("No se encontró ningún contacto con ese nombre.\n");

    } else if (opcion == 2) {
        int dni;
        printf("Ingrese el DNI a buscar: ");
        scanf("%d", &dni);

        int encontrado = 0;
        for (int i = 0; i < cantidad; i++) {
            if (agenda[i].dni == dni) {
                printf("Encontrado: %s | Tel: %s | DNI: %d\n", agenda[i].nombre, agenda[i].telefono, agenda[i].dni);
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) printf("No se encontró ningún contacto con ese DNI.\n");

    } else {
        printf("Opción inválida.\n");
    }
    // 🔹 La búsqueda por nombre es exacta (sensible a mayúsculas/minúsculas).
    // 🔹 Se podría mejorar usando strcasecmp() o strstr() para búsquedas parciales.
}


void ordenarContactos(struct Contacto agenda[], int cantidad) {
    if (cantidad == 0) {
        printf("No hay contactos para ordenar.\n");
        return;
    }

    int opcion;
    printf("Ordenar por:\n1. Nombre\n2. DNI\nOpción: ");
    scanf("%d", &opcion);
    getchar();

    struct Contacto temp;

    if (opcion == 1) {
        for (int i = 0; i < cantidad - 1; i++) {
            for (int j = i + 1; j < cantidad; j++) {
                if (strcmp(agenda[i].nombre, agenda[j].nombre) > 0) {
                    temp = agenda[i];
                    agenda[i] = agenda[j];
                    agenda[j] = temp;
                }
            }
        }
        printf("Contactos ordenados por nombre.\n");
    } else if (opcion == 2) {
        for (int i = 0; i < cantidad - 1; i++) {
            for (int j = i + 1; j < cantidad; j++) {
                if (agenda[i].dni > agenda[j].dni) {
                    temp = agenda[i];
                    agenda[i] = agenda[j];
                    agenda[j] = temp;
                }
            }
        }
        printf("Contactos ordenados por DNI.\n");
    } else {
        printf("Opción inválida.\n");
    }
    // 🔹 Implementa una versión simple de ordenamiento burbuja (O(n²)).
    // 🔹 Es suficiente para listas pequeñas, pero ineficiente para muchas entradas.
    // 🔹 Se podría mejorar con qsort() y una función de comparación.
}


void eliminarContacto(struct Contacto agenda[], int *cantidad) {
    if (*cantidad == 0) {
        printf("No hay contactos para eliminar.\n");
        return;
    }

    int dni;
    printf("Ingrese el DNI del contacto a eliminar: ");
    scanf("%d", &dni);

    int encontrado = -1;
    for (int i = 0; i < *cantidad; i++) {
        if (agenda[i].dni == dni) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("No se encontró ningún contacto con ese DNI.\n");
        return;
    }

    // Mover todos los elementos hacia atrás
    for (int i = encontrado; i < *cantidad - 1; i++) {
        agenda[i] = agenda[i + 1];
    }

    (*cantidad)--;
    printf("Contacto eliminado con éxito.\n");
    // 🔹 Esta eliminación mantiene la lista compacta.
    // 🔹 Costo O(n), pero simple y efectivo para listas pequeñas.
}


void eliminarTodos(struct Contacto agenda[], int *cantidad) {
    if (*cantidad == 0) {
        printf("La agenda ya está vacía.\n");
        return;
    }

    *cantidad = 0;
    printf("Todos los contactos fueron eliminados.\n");
    // 🔹 Simplemente se pone cantidad = 0.
    //   No hace falta limpiar memoria porque los datos están en un array local (no dinámico).
}
