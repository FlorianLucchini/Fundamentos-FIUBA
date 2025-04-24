/*
a)
Escribir una función que reciba un valor y calcule el factorial del mismo.
No debe imprimir el valor, debe solamente devolverlo.
Si no se puede calcular el factorial del valor recibido, la función deberá devolver 0, de lo contrario deberá devolver el valor calculado.


    a)
    printf("El factorial de %d es: %llu\n", 0, calcular_factorial(0));
    printf("El factorial de %d es: %llu\n", 3, calcular_factorial(3));
    printf("El factorial de %d es: %llu\n", 6, calcular_factorial(6));
    printf("El factorial de %d es: %llu\n", -10, calcular_factorial(-10));
*/

unsigned long long calcular_factorial(int num)
{
    int i;
    unsigned long long fact = 1;

    if (num >= 0)
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

/*
b)
Escribir una función que reciba dos valores enteros y devuelva la suma de los valores entre el menor y el mayor de dichos números, incluídos.
No debe imprimir el valor, debe solamente devolverlo.

Invocarla para los valores (-2, 2); (5, -10); (0, -4); (10, 15) y (-3, -25); mostrando en cada caso lo que devuelve.

    // b)
    printf("%d\n", sumar_rango_incluido(2, 2));
    printf("%d\n", sumar_rango_incluido(5, -10));
    printf("%d\n", sumar_rango_incluido(0, -4));
    printf("%d\n", sumar_rango_incluido(10, 15));
    printf("%d\n", sumar_rango_incluido(-3, -25));
*/

int sumar_rango_incluido(int num_1, int num_2)
{
    int min, max, suma = 0;
    if (num_1 > num_2)
    {
        min = num_2;
        max = num_1;
    }
    else
    {
        min = num_1;
        max = num_2;
    }

    while (min <= max)
    {
        suma += min;
        min++;
    }

    return suma;
}

/*
c)
Escribir un programa que solicite el ingreso de valores, que representarán una cantidad de segundos.
El programa deberá informar al usuario, el equivalente en días, horas, minutos y segundos.
Se debe validar que el valor ingresado sea entero y positivo, de lo contrario, deberá mostrarse el mensaje: “Valor ingresado inválido”.
El ingreso de valores finaliza cuando el usuario ingrese como valor 0.

// Tomamos segs.
// Valor entero y positivo.
// Devolver equivalente en dias, horas, minutos y segs.
*/

int obtener_datos(int *segundos)
{
    printf("Ingrese una cantidad de segundos, o 0 para salir: ");
    scanf("%d", segundos);
}

int calcular_dias(int *segundos)
{
    int dias = *segundos / 86400;
    *segundos %= 86400;
    return dias;
}

int calcular_horas(int *segundos)
{
    int horas = *segundos / 3600;
    *segundos %= 3600;
    return horas;
}

int calcular_minutos(int *segundos)
{
    int minutos = *segundos / 60;
    *segundos %= 60;
    return minutos;
}

void mostrar_conversion(int ds, int hs, int mins, int segs)
{
    printf("Resultado: Dias: %d, Horas: %d, Minutos: %d, Segundos: %d\n", ds, hs, mins, segs);
}

int es_negativo(int segundos)
{
    return segundos < 0;
}

int es_distinto_de_cero(int segundos)
{
    return segundos != 0;
}
/*
int main()
{
    int segundos, ds, hs, mins, segs;
    obtener_datos(&segundos);
    while (es_distinto_de_cero(segundos))
    {
        if (es_negativo(segundos))
        {
            printf("Valor ingresado inválido");
        }
        else
        {
            ds = calcular_dias(&segundos);
            hs = calcular_horas(&segundos);
            mins = calcular_minutos(&segundos);
            segs = segundos;
            mostrar_conversion(ds, hs, mins, segs);
        }
        obtener_datos(&segundos);
    }

    return 0;
}
*/

#include <stdio.h>

#define FILAS 4
#define COLUMNAS 4

void imprimir_matriz(int matriz[FILAS][COLUMNAS])
{
    int i;

    printf("Matriz:\n");
    for (i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void ingresar_valores_matriz(int matriz[FILAS][COLUMNAS])
{
    int i;
    printf("Ingrese los vaores de la matriz.\n");
    for (i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf("Ingrese el valor de la posicion (%d, %d): ", i, j);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }
}

int suma_diagonal_principal(int matriz[FILAS][COLUMNAS])
{
    int i, suma = 0;

    for (i = 0; i < FILAS; i++)
        suma += matriz[i][i];

    return suma;
}

int suma_diagonal_secundaria(int matriz[FILAS][COLUMNAS])
{
    int i, suma = 0;

    for (i = 0; i < FILAS; i++)
        suma += matriz[i][COLUMNAS - i - 1];

    return suma;
}

void sumar_filas(int matriz[FILAS][COLUMNAS], int vector[FILAS])
{
    int i;
    for (i = 0; i < FILAS; i++)
        for (int j = 0; j < COLUMNAS; j++)
            vector[i] += matriz[i][j];
}
/*
int main() {

    // Declaramos una matriz de enteros
    int matriz[FILAS][COLUMNAS];
    int suma_1, suma_2;
    int i, vector[FILAS] = {0, 0, 0}, size_vector = sizeof(vector) / sizeof(int);

    // Ingreso valores
    ingresar_valores_matriz(matriz);

    // Imprimimos la matriz
    imprimir_matriz(matriz);

    suma_1 = suma_diagonal_principal(matriz);
    printf("La suma de la diagonal principal es: %d.\n", suma_1);


    suma_2 = suma_diagonal_secundaria(matriz);
    printf("La suma de la diagonal principal es: %d.\n", suma_2);

    sumar_filas(matriz, vector);
    printf("La suma de cada fila es: \n");
    for(i = 0; i < size_vector; i++)
        printf("La suma de la fila %d es: %d.\n", i, vector[i]);

    return 0;
}
*/

// Mostrar el promedio de notas del curso.
// Mostrar todas las notas superiores al promedio calculado.

#include <stdio.h>

#define MAX 50
#define APROBO 4

typedef int Tvec[MAX];

void cargar_notas(Tvec vec, int *ML)
{
    int i = 0, nota;

    printf("Ingrese notas ( -1 para terminar ): ");
    scanf("%d", &nota);

    while ((nota > -1) && (i < MAX))
    {
        vec[i] = nota;
        i++;
        printf("Siga ingresando notas ( -1 para terminar ): ");
        scanf("%d", &nota);
    }

    *ML = i;
}

float calcular_promedio(Tvec vec, float ML)
{
    int i, suma = 0;

    for(i = 0; i < ML; i++)
    {
        suma += vec[i];
    }

    return suma / ML;
}

void mostrar_notas_sup(Tvec vec, int ML, float promedio)
{
    int i;
    for(i = 0; i < ML; i++)
    {
        if(vec[i] > promedio)
            printf("La nota %d, es superior al promedio %.2f.\n", vec[i], promedio);
    }
}

int main()
{
    Tvec vec;
    int ML = 0;
    float promedio;
    cargar_notas(vec, &ML);
    promedio = calcular_promedio(vec, ML);
    printf("El promedio de las notas es %.2f.\n", promedio);
    mostrar_notas_sup(vec, ML, promedio);


    return 0;
}