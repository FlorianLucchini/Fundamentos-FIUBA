// Desarrollar un programa que solicite al usuario el ingreso de 2 números A y B y calcule la potencia de A elevado a la B de forma recursiva.

#include <stdio.h>

int potencia(int a, int b)
{
    if(b == 0)
        return 1;
    else
        return a * potencia(a, b - 1);
}


int main()
{
    int a = 5;
    int b = 3;
    printf("El numero %d elevado a %d da %d", a, b, potencia(a,b));
    return 0;
}