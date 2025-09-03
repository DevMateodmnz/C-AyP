#include <stdio.h>

int main() {
    int dia_nac, mes_nac, anio_nac;
    int dia_act, mes_act, anio_act;
    int edad;

    printf("Ingrese su fecha de nacimiento (dd mm aaaa): ");
    scanf("%d %d %d", &dia_nac, &mes_nac, &anio_nac);

    printf("Ingrese la fecha actual (dd mm aaaa): ");
    scanf("%d %d %d", &dia_act, &mes_act, &anio_act);

    edad = anio_act - anio_nac;

    // Si aún no cumplió años este año, restar uno
    if (mes_act < mes_nac || (mes_act == mes_nac && dia_act < dia_nac)) {
        edad--;
    }

    printf("La edad es: %d años\n", edad);

    return 0;
}