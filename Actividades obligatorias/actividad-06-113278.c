/*
a)
Escribir un programa modular (compuesto por funciones) en donde el usuario deba cargar una matriz de números reales, de n x m.
Las dimensiones se le solicitarán al usuario al inicio, validar que estén dentro del rango [1-10].

Luego de la carga de la matriz el programa debe completar un vector de dimensión n para que en cada posición i del mismo se almacene el elemento mínimo de cada fila i de la matriz.
Por ultimo se debe mostrar el promedio de los elementos de dicho vector.

Considerar un máximo físico de 10, por lo que n y m deben ser menores o igual a dicho número.
*/

#include <stdio.h>

#define MAX 10

typedef float Tmatriz[MAX][MAX];
typedef float Tvec[MAX];

int validar_dimension(int dim)
{
    return 1 <= dim && dim <= 10;
}

int pedir_dimension()
{
    int dim;
    do {

        printf("Ingrese un valor entero positivo entre 1-10: ");
        scanf("%d", &dim);

        if(!validar_dimension(dim))
            printf("Numero fuera de rango.");

    } while (!validar_dimension(dim));

    return dim;
}

void ingresar_dimensiones(int *n, int *m)
{
    printf("Debe ingresar las dimensiones (n x m) de la matriz a cargar.\n");

    printf("Primero debe ingresar n. \n");
    *n = pedir_dimension();

    printf("Ahora debe ingresar m. \n");
    *m = pedir_dimension();
}

void imprimir_matriz(Tmatriz matriz, int filas, int cols)
{
    int i, j;

    printf("Matriz: \n");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void ingresar_valores_matriz(Tmatriz matriz, int filas, int cols)
{
    int i, j;

    printf("Ingrese los vaores de la matriz.\n");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Ingrese el valor de matriz[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }
        printf("\n");
    }
}

float evaluar_minimo_fila(Tvec vec, int ML)
{
    int i;
    float min = vec[0];

    for(i = 1; i < ML; i++)
    {
        if(min >= vec[i])
            min = vec[i];
    }

    return min;
}

void completar_vector(Tmatriz matriz, int filas, int cols, Tvec vec)
{
    int i;
    float min;
    for(i = 0; i < filas; i++)
    {
        min = evaluar_minimo_fila(matriz[i], cols);
        vec[i] = min;
    }
}

void mostrar_vector(Tvec vec, int ML)
{
    int i;
    printf("El vector de minimos por fila es: ");
    printf("[ ");
    for(i = 0; i < ML; i++)
        printf("%.2f ", vec[i]);
    printf("]");
    printf("\n");
}

float calcular_promedio(Tvec vec, int ML)
{
    int i;
    float suma = 0;

    for(i = 0; i < ML; i++)
    {
        suma += vec[i];
    }

    return suma / ML;
}

int main()
{
    int filas, cols;
    float promedio;
    Tmatriz matriz;
    Tvec vec;
    ingresar_dimensiones(&filas, &cols);
    ingresar_valores_matriz(matriz, filas, cols);
    imprimir_matriz(matriz, filas, cols);

    completar_vector(matriz, filas, cols, vec);
    mostrar_vector(vec, filas);
    promedio = calcular_promedio(vec, filas);
    printf("El promedio de los elementos menores de cada fila es: %.2f \n", promedio);
    return 0;
}