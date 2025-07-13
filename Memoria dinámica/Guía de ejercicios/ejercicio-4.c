// Escribir un programa el cual reserve memoria dinámica para almacenar un struct del tipo t_alumno (ver anexo). Luego solicitar al usuario que ingrese los datos del alumno y almacenarlos en la memoria previamente reservada.
// Mostrar luego todos los datos del alumno.
// Liberar la memoria reservada al finalizar el programa.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int padron;
    char nombre[30];
    char apellido[30];
} T_alumno;

int ingresar_alumno(T_alumno *alumno)
{
    printf("A continuacion ingrese los datos del alumno: \n");
    printf("Padron: ");
    scanf("%d", &(alumno->padron));
    printf("Nombre: ");
    scanf(" %30[^\n]s", alumno->nombre);
    printf("Apellido: ");
    scanf(" %30[^\n]s", alumno->apellido);
    return 0;
}

int mostrar_alumno(T_alumno alumno)
{
    printf("A continuacion muestro los datos del alumno ingresado: \n");
    printf("Padron: %d\n", alumno.padron);
    printf("Nombre: %s\n", alumno.nombre);
    printf("Apellido: %s\n", alumno.apellido);
    return 0;
}

int main()
{
    T_alumno *alumno = NULL;
    alumno = malloc(sizeof(T_alumno));
    if(alumno != NULL)
    {
        ingresar_alumno(alumno);
        mostrar_alumno(*alumno);
    }
    else
        printf("Error al reservar memoria.");
    
    free(alumno);
    return 0;
}