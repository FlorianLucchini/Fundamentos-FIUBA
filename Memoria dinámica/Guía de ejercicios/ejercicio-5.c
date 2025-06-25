// 5) Escribir un programa el cual reserve memoria dinámica para almacenar una cantidad n de struct del tipo t_alumno (ver anexo). El usuario debe ingresar la cantidad n. Luego solicitar al usuario que ingrese los datos de los n alumnos y almacenarlos en la memoria previamente reservada. Mostrar luego todos los datos de todos los alumnos. Liberar la memoria reservada al finalizar el programa.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int padron;
    char nombre[30];
    char apellido[30];
} T_alumno;

int cargar_alumno(T_alumno *alumno)
{
    printf("Ingrese los datos del alumno.\n");
    printf("Ingerese el padron: ");
    scanf("%d", &alumno->padron);
    printf("Ingrese el nombre: ");
    scanf(" %30[^\n]s", alumno->nombre);
    printf("Ingrese el apellido: ");
    scanf(" %30[^\n]s", alumno->apellido);
    return 0;
}

int mostrar_datos_alumno(T_alumno alumno)
{
    printf("Los datos del alumno: ");
    printf("\nPadron: %d", alumno.padron);
    printf("\nNombre: %s", alumno.nombre);
    printf("\nApellido: %s\n", alumno.apellido);
    return 0;
}

int mostrar_alumnos(T_alumno alumnos[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("\nAlumno Nro %d:\n", i + 1);
        mostrar_datos_alumno(alumnos[i]);
    }
    return 0;
}

int main()
{   
    T_alumno *alumnos = NULL;
    int n, i;

    printf("Ingrese la cantidad n de alumnos: ");
    scanf("$d", &n);

    alumnos = malloc(sizeof(T_alumno) * n);

    if(alumnos != NULL)
    {
        for(i = 0; i < n; i++)
        {
            printf("\nAlumno Nro *%d:\n", i + 1);
            cargar_alumno(alumnos + i);
        }
        mostrar_alumnos(alumnos, n);
    }
    else
    {
        printf("Error al reservar la memoria.\n");
    }

    free(alumnos);
    return 0;
}