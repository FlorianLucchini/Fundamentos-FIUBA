// Escribir un programa el cual reserve memoria dinámica para almacenar un número entero (int), le solicite al usuario el ingreso de un número y se asigna dicho valor en la memoria reservada, luego mostrar dicho valor por pantalla. Liberar la memoria reservada al finalizar el programa.

#include <stdio.h>
#include <stdlib.h>

int sol_dato(int *num)
{
    printf("Ingrese un numero: \n");
    scanf("%d", num);
    return 0;
}

int main()
{
    int *num = NULL;
    num = malloc(sizeof(num));
    if(num != NULL)
    {
        sol_dato(num);
        printf("El numero ingresado es %d", *num);
    }
    else
        printf("No se reservo correctamente la memoria");

    free(num);
    return 0;
}