/*
a)
Escribir un programa modular (compuesto por funciones), en donde se le solicita al usuario un número natural positivo entre 1 y 20. 

En el caso que el número ingresado este fuera de rango indicarle al usuario y solicitarlo nuevamente, hasta que esté dentro del rango pedido.

Luego si el numero ingresado es primo se pide mostrar como resultado  el factorial del mismo, en el caso que no sea primo se pide mostrar como resultado la suma n-ésima parcial del número usando la siguiente formula  (n*(n+1))/2.

La obtención del dato por parte del usuario debe realizarse a través de una función que opere con pasaje de parámetros por referencia.

// Pedir al usuario un número natural positivo entre 1 y 20.
// Validar el dato.
// ¿Es válido? No. --> Solicitarlo nuevamente hasta que sea válido.
// ¿Es válido? Si:
// Si es primo mostrar como resultado el factorial de dicho número.
// Si no es primo mostrar como resultado la suma n-ésima parcial del número.
// | Fórmula: ( n * ( n + 1 ) ) / 2 |
// Obligatorio: La obtención del dato debe realizarse por medio de una función con parámetros por referencia.
*/

#include <stdio.h>

void obtener_dato(int *num)
{
    printf("Ingrese un numero natural positivo entre 1 y 20: ");
    scanf("%d", num);
    return;
}

int validar_dato(int num)
{
    return 1 <= num && num <= 20;
}

unsigned int contar_divisores(int num)
{
    int i, cant_divisores = 0;

    for (i = 1; i <= num; i++)
    {
        if (num % i == 0)
            cant_divisores += 1;
    }

    return cant_divisores;
}

int es_primo(int num)
{
    int cant_divisores, es_primo = 0;

    cant_divisores = contar_divisores(num);

    if (cant_divisores == 2)
        es_primo = 1;

    return es_primo;
}

unsigned long long calcular_factorial(int num)
{
    int i;
    unsigned long long fact = 1;

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

unsigned int calcular_suma_nesima(int num)
{
    return (num * (num + 1)) / 2;
}

void analizar_resultado(int num, unsigned long long *resultado)
{
    if(es_primo(num)) 
    {
        *resultado = calcular_factorial(num);
    }
    else
    {
        *resultado = calcular_suma_nesima(num);
    }
    return;
}

void mostrar_resultado(unsigned long long resultado)
{
    printf("El resultado es: %llu.\n", resultado);
}

int main()
{
    int num;
    unsigned long long resultado;
    do
    {
        obtener_dato(&num);
    } while (!validar_dato(num));
    
    analizar_resultado(num, &resultado);
    mostrar_resultado(resultado);

    return 0;
}   