/*
a)
Escribir un programa en lenguaje C que solicite un listado de alumnos que consiste en número de padrón (legajo) y 3 notas por alumno.
Todos los datos se le deben solicitar al usuario uno a uno.
Informar el mayor y el menor promedio registrado junto con el número de padrón del alumno.
La carga de datos finaliza cuando se ingresa padrón igual a cero.
Asumir que los numeros que ingresa el usuario son todos enteros positivos por lo que no requieren validación.
En los datos de prueba de su ejecución debe estar incluido su propio padrón.
*/

// Pasos:
// Tomar legajos y tres notas por legejo.
// De cada legajo imprimir el promedio de las tres notas.
// Comparar el promedio contra el promedio mayor y menor ya almacenados, si es mayor o menor, reemplazarlos.
// Finalizar cuando se ingresa cero en el legajo.

#include <stdio.h>

int main()
{
    // Variables (Separadas para mayor legibilidad).
    int legajo_actual, legajo_max, legajo_min;
    int nota_1, nota_2, nota_3;
    float promedio_actual, promedio_max = -1, promedio_min = -1;

    printf("Ingrese su legajo:\n");
    scanf("%d", &legajo_actual);

    if ( legajo_actual == 0 )
    {
        printf("No hay datos ingresados.\n");
        return 0;
    }

    while ( legajo_actual != 0 )
    {
        printf("Ingrese la primera nota: \n");
        scanf("%d", &nota_1);
        printf("Ingrese la segunda nota: \n");
        scanf("%d", &nota_2);
        printf("Ingrese la tercera nota: \n");
        scanf("%d", &nota_3);

        promedio_actual = (nota_1 + nota_2 + nota_3) / 3.0;

        printf("Legajo: %d", legajo_actual);
        printf(", notas: [%d", nota_1);
        printf(", %d", nota_2);
        printf(", %d]", nota_3);
        printf(", promedio: %.2f\n", promedio_actual);

        if ( promedio_max == -1 || promedio_min == -1 )
        {
            promedio_max = promedio_actual;
            promedio_min = promedio_actual;
            legajo_max = legajo_actual;
            legajo_min = legajo_actual;
        }
        else
        {
            if (promedio_actual > promedio_max)
            {   
                promedio_max = promedio_actual;
                legajo_max = legajo_actual;
            } 
            if (promedio_actual < promedio_min)
            {
                promedio_min = promedio_actual;
                legajo_min = legajo_actual;
            }
        }

        printf("Ingrese su legajo:\n");
        scanf("%d", &legajo_actual);
    }

    printf("\n\n");
    printf("Mayor promedio: %.2f", promedio_max);
    printf(", legajo: %d\n", legajo_max);
    printf("Menor promedio: %.2f", promedio_min);
    printf(", legajo: %d\n", legajo_min);

    return 0;
}