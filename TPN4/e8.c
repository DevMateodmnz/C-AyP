#include <stdio.h>

int main() {
    float precio, iva, ingresos_brutos, impuesto_municipal;

    printf("Ingrese el precio del producto: ");
    scanf("%f", &precio);

    iva = precio * 0.21;
    ingresos_brutos = precio * 0.025;
    impuesto_municipal = precio * 0.015;

    printf("IVA (21%%): %.2f\n", iva);
    printf("Ingresos Brutos (2.5%%): %.2f\n", ingresos_brutos);
    printf("Impuesto Municipal (1.5%%): %.2f\n", impuesto_municipal);

    return 0;
}