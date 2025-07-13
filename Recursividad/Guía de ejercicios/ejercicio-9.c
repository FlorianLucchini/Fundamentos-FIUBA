// Desarrollar un programa que solicite al usuario el ingreso de un número entero y muestre el resultado de sumar sus dígitos.

#include <stdio.h>

int solicitar_num(int *num)
{
    printf("Ingrese un numero: ");
    scanf("%d", num);
}

int sumar_digitos(int num)
{
    int suma = num % 10;
    if(num == 0)
        return 0;
    else
        return suma + sumar_digitos(num / 10);   
}

int main()
{
    int num, suma;
    solicitar_num(&num);
    suma = sumar_digitos(num);
    printf("La suma de todo los digitos de %d es %d", num, suma);
}