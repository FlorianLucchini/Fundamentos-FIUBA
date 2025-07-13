// 7) Implementar una función que retorna un puntero a un vector de n struct del tipo t_alumno (ver anexo), el cual apunta a un bloque de memoria dinámica, respetando la siguiente declaración. En caso de no poder reservar la memoria, retornar NULL.
// t_alumno* crear_alumnos(int n);

#include <stdio.h>
#include <stdlib.h>

#define MF 30

typedef char string[MF];

typedef struct {
    int padron;
    string nombre;
    string apellido;
} T_alumno;

int solicitar_n(int *n)
{
    printf("Ingrese la cantidad de alumnos a guardar: \n");
    scanf("%d", n);
    return 0;
}

T_alumno* crear_alumnos(int n)
{
    return malloc(n * sizeof(T_alumno));
}

// Me robe las funciones del ejercicio 5 para probar.
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
    T_alumno *alumnos;
    solicitar_n(&n);
    alumnos = crear_alumnos(n);
    if(alumnos != NULL)
    {
        printf("Memoria reservada correctamente.\n");
        printf("H:%x", alumnos);
        ingresar_alumnos(alumnos, n);
        mostrar_alumnos(alumnos, n);
    }
    else
    {
        printf("Problemas al almacenar la memoria.\n");
    }

    free(alumnos);
    return 0;
}