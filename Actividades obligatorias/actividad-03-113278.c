#include <stdio.h>
/*
a)
Escribir un programa que permita al usuario ingresar los montos de las compras
de un cliente y que al finalizar informe por pantalla el importe total a pagar,
teniendo en cuenta que si éste supera los $10.000 se le debe aplicar un 10% de descuento.
Se desconoce la cantidad de datos que se van a ingresar.
La carga de datos finaliza cuando el usuario ingresa el monto 0 (cero).
Se debe validar que no se ingresen montos negativos indicando al usuario monto invalido.
*/

int main() {
    float price, total;

    do {
        printf("Ingrese el monto de la venta (o 0 para terminar).\n");
        scanf("%f", &price);

        if (price < 0) {
            printf("Monto no valido.\n");
        } else {
            total += price;
        }
    } while (price != 0);

    if(total > 10000) {
        printf("El total a pagar ( $%.2f ) supera los $10000, se aplica descuento del 10%.\n", total);
        total = total - ((10 * total) / 100);
    }

    printf("Total a pagar: $%.2f\n", total);
    return 0;
}