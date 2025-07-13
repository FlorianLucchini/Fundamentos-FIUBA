// 6) Implementar una función que retorna un puntero a un struct del tipo t_alumno (ver anexo), el cual apunta a un bloque de memoria dinámica, respetando la siguiente declaración.
// En caso de no poder reservar la memoria, retornar NULL. 
// t_alumno* crear_alumno() { ... }

#include <stdio.h>
#include <stdlib.h>

#define MF 30

typedef char string[MF];

typedef struct
{
    int padron;
    string nombre;
    string apellido;
} T_alumno;

T_alumno* crear_alumno()
{
    return malloc(sizeof(T_alumno));
}

// Me robe las funciones del ejercicio 4 para probar.
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
    T_alumno *alumno = crear_alumno();
    if(alumno != NULL)
    {
        printf("Memoria reservada correctamente.\n");
        printf("Direccion H:%x.\n", alumno);
        ingresar_alumno(alumno);
        mostrar_alumno(*alumno);
    }   
    else
        printf("La memoria no se cargo correctamente.\n");

    free(alumno);
    return 0;
}