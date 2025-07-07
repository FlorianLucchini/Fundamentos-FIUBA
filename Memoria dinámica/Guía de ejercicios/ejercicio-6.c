// 6) Implementar una función que retorna un puntero a un struct del tipo t_alumno (ver anexo), el cual apunta a un bloque de memoria dinámica, respetando la siguiente declaración. En caso de no poder reservar la memoria, retornar NULL. 
/*
t_alumno* crear_alumno();
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int padron;
    char nombre[30];
    char apellido[30];
} T_alumno;

T_alumno* crear_alumno()
{
    return malloc(sizeof(T_alumno));
}

int main()
{
    T_alumno *alumno = crear_alumno();
    if(alumno != NULL)
    {
        printf("Memoria reservada correctamente.\n");
        printf("Direccion H:%x.\n", alumno);
    }
    else
    {
        printf("No se pudo reservar memoria.\n");
    }

    free(alumno); 
    return 0;
}