// 5) Escribir un programa el cual reserve memoria dinámica para almacenar una cantidad n de struct del tipo t_alumno (ver anexo). El usuario debe ingresar la cantidad n. Luego solicitar al usuario que ingrese los datos de los n alumnos y almacenarlos en la memoria previamente reservada. Mostrar luego todos los datos de todos los alumnos. Liberar la memoria reservada al finalizar el programa.

#include <stdio.h>
#include <stdlib.h>

#define MF 30

typedef char string[50];

typedef struct {
    int padron;
    string nombre;
    string apellido;
} T_alumno;

int solicitar_n(int *n)
{
    printf("Ingrese la cantidad de alumnos a guardar: ");
    scanf("%d", n);
}

int ingresar_alumnno(T_alumno *alumno)
{
    printf("Padron: ");
    scanf("%d", &(alumno->padron));
    printf("Nombre: ");
    scanf(" %30[^\n]s", alumno->nombre);
    printf("Apellido: ");
    scanf(" %30[^\n]s", alumno->apellido);
    return 0;
}

int ingresar_alumnos(T_alumno alumnos[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("A continuacion ingrese los datos del alumno N*%d: \n", i);
        ingresar_alumnno(alumnos + i);
        // ingresar_alumnos(&alumnos[i]);
    }
    return 0;
}

int mostrar_alumno(T_alumno alumno)
{
    printf("Padro: %d \n", alumno.padron);
    printf("Nombre: %s \n", alumno.nombre);
    printf("Apellido: %s \n", alumno.apellido);
    return 0;
}

int mostrar_alumnos(T_alumno alumnos[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("A continuacion se mostraran los datos del alumno N*%d \n", i);
        mostrar_alumno(alumnos[i]);
    }
    return 0;
}

int main()
{
    int n;
    T_alumno *alumnos = NULL;
    solicitar_n(&n);
    alumnos = malloc(n * sizeof(T_alumno));
    if(alumnos != NULL)
    {
        ingresar_alumnos(alumnos, n);
        mostrar_alumnos(alumnos, n);
    }
    else
        printf("No se pudo almacenar la memoria. \n");

    free(alumnos);
    return 0;
}