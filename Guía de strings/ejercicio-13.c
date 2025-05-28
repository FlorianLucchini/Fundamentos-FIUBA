// Escribir un programa modular en C, que solicite el ingreso de 3 oraciones, de no más de 50 caracteres cada una.
// Luego informar:
// 1. Cuál es la oración más larga.
// 2. Si hay al menos 2 oraciones iguales.
// 3. Solicitar el ingreso de una palabra o parte de una oración, e indicar si la misma se encuentra en las oraciones, y en cuales.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MF_ORACION 51
#define MF_ORACIONES 3

typedef char Torn[MF_ORACION];
typedef Torn Torns[MF_ORACIONES];

void ingresar_oracion(Torn orn)
{
    printf("Ingrese la oracion a continuacion: ");
    fgets(orn, MF_ORACION, stdin);
    fflush(stdin);
    orn[strcspn(orn, "\n")] = '\0';
}

void ingresar_oraciones(Torns orns)
{
    int i;
    for(i = 0; i < MF_ORACIONES; i++)
        ingresar_oracion(orns[i]);
}

int idx_oracion_mayor(Torns orns)
{
    int i, max_idx = 0;
    for(i = 1; i < MF_ORACIONES; i++)
        if(orns[max_idx] < orns[i])
            max_idx = i;

    return max_idx;
}

   