#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAMANIO 3

/* definimos una estructura alumno */
typedef struct
{
     char nombre[30];
     int padron;
     char email[50];
     int notas[2] ;
     float promedio;
} alumno;

void cargar(alumno vec[TAMANIO], int *ml)
{
    int i;
    for(i=0;i<TAMANIO;i++)
    {
        printf("\nIngrese el Nombre:\n");
        scanf("%s",vec[i].nombre);

        printf("Ingrese el padron:\n");
        scanf("%d",&vec[i].padron);

        printf("Ingrese el email:\n");
        scanf("%s",vec[i].email);

        printf("Ingrese la nota del Parcial 1:\n");
        scanf("%d",&vec[i].notas[0]);

        printf("Ingrese la nota del Parcial 2:\n");
        scanf("%d",&vec[i].notas[1]);

	    vec[i].promedio = (float)(vec[i].notas[0] + vec[i].notas[1])/2;
    }
    *ml = i;
}

void mostrar(alumno vec[TAMANIO], int ml)
{
    int i;
    for(i = 0; i < ml; i++)
    {
        printf("\n\n Alumnos[%d]", i);
        printf("\n nombre: %s ", vec[i].nombre);
        printf("\n padron: %d ", vec[i].padron);	
        printf("\n email: %s ", vec[i].email);
        printf("\n Nota Parcial 1: %d Nota Parcial 2: %d", vec[i].notas[0], vec[i].notas[1]);
        printf("\n promedio Cd: %.2f ", vec[i].promedio);
    }
}

int mejor_promedio(alumno vec[TAMANIO], int ml) {
    int i, idx_mejor = 0;

    for(i = 1; i < ml; i++)
        if(vec[i].promedio > vec[idx_mejor].promedio)
            idx_mejor = i;

    return idx_mejor;
}

void promedio_general(alumno vec[TAMANIO], int ml)
{
    int i;
    float promedio_general = 0;
    for(i = 0; i < ml; i++)
    {
        promedio_general += vec[i].notas[0];
    }
    promedio_general = (float) promedio_general / 3;
    printf("\nEl promedio general del primer parcial es %.2f\n", promedio_general);
}

void sort_by_padron(alumno vec[TAMANIO], int ml)
{
    int j, i;
    alumno key;
    
    for(j = 1; j < ml; j++)
    {
        key = vec[j];
        i = j - 1;
        while(i >= 0 && key.padron < vec[i].padron)
        {
            vec[i + 1] = vec[i];
            i--;
        }
        vec[i + 1] = key;
    }
}

int search_by_padron(alumno vec[TAMANIO], int ml, int padron)
{
    int i, idx_founded = -1;
    bool founded = false;
    i = 0;
    while( ( i < ml ) && !founded)
    {
        if(vec[i].padron == padron)
        {
            founded = true;
            idx_founded = i;
        }
        i++;
    }

    return idx_founded;
}

int binary_search_by_padron(alumno vec[TAMANIO], int ml, int padron)
{
    int inf, sup, mid;
    bool finished;
    int pos = -1;

    inf = 0;
    sup = ml - 1;
    finished = false;

    while(!finished)
    {
        if( ( padron > vec[sup].padron ) || ( padron < vec[inf].padron ) )
        {
            finished = true;
            pos = -1;
        }
        else
        {
            mid = (inf + sup) / 2;

            if( padron == vec[mid].padron )
            {
                finished = true;
                pos = mid;
            }
            else
            {
                if( padron > vec[mid].padron )
                    inf = mid + 1;
                else
                    sup = mid - 1;
            }
        }
    }
    return pos;
}

void mostrar_registro(alumno Alumno)
{
	printf("\n nombre: %s ", Alumno.nombre);
	printf("\n padron: %d ", Alumno.padron);	
	printf("\n email: %s ", Alumno.email);
	printf("\n Nota Parcial 1: %d Nota Parcial 2: %d", Alumno.notas[0], Alumno.notas[1]);
	printf("\n promedio Cd: %.2f ", Alumno.promedio);
}

void sort_by_nombre(alumno vec[TAMANIO], int ml)
{
    int j, i;
    alumno key;
    
    for(j = 1; j < ml; j++)
    {
        key = vec[j];
        i = j - 1;
        while(i >= 0 && strcmp(key.nombre, vec[i].nombre) < 0)
        {
            vec[i + 1] = vec[i];
            i--;
        }
        vec[i + 1] = key;
    }
}

int main(void)
{
    alumno Alumnos[TAMANIO];
    int idx, padron, ml;

    // cargo los elementos con funcion cargar
    cargar(Alumnos, &ml);

 	/* Muestro datos del primer elemento de la tabla*/
    mostrar(Alumnos, ml);

    // Obtengo el indice del registro de alumno con mejor promedio.
    idx = mejor_promedio(Alumnos, ml);
    printf("\nEl alumno con mejor promedio es: %s (Promedio: %.2f)\n", Alumnos[idx].nombre, Alumnos[idx].promedio);

    // Calculo y muestro el promedio general del primer parcial entre todos los alumnos.
    promedio_general(Alumnos, ml);

    printf("\nAlumnos antes de ser ordenados por padron:\n");
    mostrar(Alumnos, ml);
    sort_by_padron(Alumnos, ml);
    printf("\nAlumnos luego de ser ordenados por padron.\n");
    mostrar(Alumnos, ml);

    printf("\nIngrese un padron para ver si esta en la tabla:\n");
    scanf("%d", &padron);
    
    if(ml > 0)
        idx = binary_search_by_padron(Alumnos, ml, padron);
    else
        printf("No hay alumnos cargados");
    
    if(idx != -1)
        mostrar_registro(Alumnos[idx]);
    else 
        printf("No encontrado el alumno del padron %d\n", padron);

    printf("\nAlumnos antes de ser ordenados por nombre alfabeticamente:\n");
    mostrar(Alumnos, ml);
    sort_by_nombre(Alumnos, ml);
    printf("\nAlumnos luego de ser ordenados por nombre alfabeticamente:\n");
    mostrar(Alumnos, ml);

	system("PAUSE");
	return 0;
}