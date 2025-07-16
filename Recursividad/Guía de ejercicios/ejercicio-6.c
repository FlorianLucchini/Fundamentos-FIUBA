// Desarrollar un programa que solicite al usuario el ingreso de un número entero y lo muestre invertido. No se puede utilizar vectores.

#include <stdio.h>

int solicitar_num(int *num)
{
    printf("Ingrese un numero entero: ");
    scanf("%d", num);
    return 0;
}

int invertir(int num, int *inv)
{
    if(num == 0)
        return *inv;
    else
        return invertir(num / 10, (num % 10) + (*inv * 10));
}

int main()
{
    int num, inv = 0;
    solicitar_num(&num);
    invertir(num, &inv);
    printf("El numero invertido es: %d", inv);
    return 0;
}