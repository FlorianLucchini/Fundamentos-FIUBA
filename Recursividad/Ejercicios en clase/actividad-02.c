// Implementar una función que permita dividir dos números enteros por restas sucesivas.

#include <stdio.h>

int dividir(int a, int b)
{
    if(a < b)
        return 0;
    return 1 + dividir(a - b, b);
}

int main()
{
    int a = 16, b = 2; 
    dividir(a, b);
    printf("El resultado de %d dividido por %d es: %d\n", a, b, dividir(a, b));
    return 0;
}