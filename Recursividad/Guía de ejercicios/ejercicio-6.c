// Desarrollar un programa que solicite al usuario el ingreso de un número entero y lo muestre invertido. No se puede utilizar vectores.

#include <stdio.h>

int solicitar_num(int *num)
{
    printf("Ingrese un numero entero: ");
    scanf("%d", num);
    return 0;
}

int invertir(int num) {}

int main()
{
    int num, inv;
    solicitar_num(&num);
    inv = invertir(num);
    printf("El numero invertido es: ", inv);
    return 0;
}