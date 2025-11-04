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

struct Contacto {
    char nombre[50];
    char telefono[20];
    int dni;
};

// Declaración de funciones
void agregarContacto(struct Contacto agenda[], int *cantidad);
void eliminarContacto(struct Contacto agenda[], int *cantidad);
void eliminarTodos(struct Contacto agenda[], int *cantidad);
void ordenarContactos(struct Contacto agenda[], int cantidad);
void buscarContacto(struct Contacto agenda[], int cantidad);
void mostrarContactos(struct Contacto agenda[], int cantidad);

int main() {
    struct Contacto agenda[MAX_CONTACTOS];
    int cantidad = 0;
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

        switch(opcion) {
            case 1: agregarContacto(agenda, &cantidad); break;
            case 2: buscarContacto(agenda, cantidad); break;
            case 3: ordenarContactos(agenda, cantidad); break;
            case 4: eliminarContacto(agenda, &cantidad); break;
            case 5: eliminarTodos(agenda, &cantidad); break;
            case 6: mostrarContactos(agenda, cantidad); break;
            case 0: printf("Saliendo del programa...\n"); break;
            default: printf("Opción inválida.\n");
        }

    } while(opcion != 0);

    return 0;
}
