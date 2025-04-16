/*
Escribir una función que reciba un valor y calcule el factorial del mismo.
No debe imprimir el valor, debe solamente devolverlo.
Si no se puede calcular el factorial del valor recibido, la función deberá devolver 0, de lo contrario deberá devolver el valor calculado.
*/

#include <stdio.h>

int calcular_factorial(int num)
{
    int i;
    long long fact = 1;

    if ( num >= 0 )
    {
        for (i = 1; i <= num; i++)
        {
            fact *= i;
        }
    }
    else
    {
        fact = 0;
    }


    return fact;
}

int main()
{
    printf("El factorial de 0 es: %d\n", calcular_factorial(0));
    printf("El factorial de 3 es: %d\n", calcular_factorial(3));
    printf("El factorial de 6 es: %d\n", calcular_factorial(6));
    printf("El factorial de -10 es: %d\n", calcular_factorial(-10));
}