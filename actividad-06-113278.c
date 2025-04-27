/*
a)
Escribir un programa modular (compuesto por funciones) en donde el usuario deba cargar una matriz de números reales, de n x m.
Las dimensiones se le solicitarán al usuario al inicio, validar que estén dentro del rango [1-10].

Luego de la carga de la matriz el programa debe completar un vector de dimensión n para que en cada posición i del mismo se almacene el elemento mínimo de cada fila i de la matriz.
Por ultimo se debe mostrar el promedio de los elementos de dicho vector.

Considerar un máximo físico de 10, por lo que n y m deben ser menores o igual a dicho número.
*/

# include <stdio.h>

int validar_dimension(int dim)
{
    return 1 <= dim && dim <= 10;
}

int pedir_dimension(int dim)
{
    do {

        printf("Ingrese un valor entero positivo entre 1-10: ");
        scanf("%d", dim);

        if(!validar_dimension)
            printf("Numero fuera de rango.");

    } while (!validar_dimension(dim));

    return dim;
}

void ingresar_dimensiones(int *n, int *m)
{
    printf("Debe ingresar las dimensiones (n x m) de la matriz a cargar.\n");

    printf("Primero debe ingresar n.\n");
    *n = pedir_dimension(n);

    printf("Ahora debe ingresar m.\n");
    *m = pedir_dimension(m);
}



int main()
{

    return 0;
}