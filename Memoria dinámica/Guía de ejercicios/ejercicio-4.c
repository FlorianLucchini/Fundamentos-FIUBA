// Escribir un programa el cual reserve memoria dinámica para almacenar un struct del tipo t_alumno (ver anexo). Luego solicitar al usuario que ingrese los datos del alumno y almacenarlos en la memoria previamente reservada.
// Mostrar luego todos los datos del alumno. Liberar la memoria reservada al finalizar el programa.

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

int main()
{   
    T_alumno *alumno = NULL;
    alumno = malloc(sizeof(T_alumno));

    if(alumno != NULL)
    {
        cargar_alumno(alumno);
        mostrar_datos_alumno(*alumno);
    }
    else
    {
        printf("Error al reservar la memoria.\n");
    }

    free(alumno);
    return 0;
}