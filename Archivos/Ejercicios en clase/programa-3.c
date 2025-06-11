// Realizar un programa que muestre los alumnos de forma ordenada por Nombre ascendente.
// Suponer máximo 100 Alumnos.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NOM 100
#define MAX 1000

typedef char String[MAX_NOM];

typedef struct {
    int DNI;
    String Nombre;
    String Email;
    int Sede;
} T_Registro;

typedef T_Registro T_Tabla[MAX];

void cargar(FILE *Archivo, T_Tabla tabla, int *ml) {
    int i = 0;
    T_Registro Reg;

    Archivo = fopen("/ejercicio.dat", "r");
    fread(&Reg, sizeof(Reg), 1, Archivo);
    
    while (!feof(Archivo)) {
        tabla[i] = Reg;
        fread(&Reg, sizeof(Reg), 1, Archivo);
        i++;
    }

    fclose(Archivo);
    *ml = i;

    return;
}

void ordenar(T_Tabla tabla, int ml)
{
    int i, j;
    T_Registro aux;
    i = 1;
    bool hubo_intercambio = true;

    while ((i < ml) && hubo_intercambio)
    {
        hubo_intercambio = false;
        for (j = 0; j < ml - i; i++)
        {
            if (strcmp(tabla[j].Nombre, tabla[j+1].Nombre ) > 0)
            {
                aux = tabla[j];
                tabla[j] = tabla[j+1];
                tabla[j+1] = aux;
                hubo_intercambio = true;
            }
        i++;
        }
    }
}

int main() {
    FILE *Archivo;
    T_Tabla tabla;
    int ML;

    cargar(Archivo, tabla, &ML);
    ordenar(tabla, ML);
    Mostrar(tabla, ML);

    return 0;
}

