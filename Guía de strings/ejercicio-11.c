// 11. Escribir un programa modular en C, que solicite el ingreso de no más de 20 palabras. C Cada palabra no tendrá más de 20 caracteres. Informar:
// 1. Mostrar las palabras ingresadas.
// 2. Cuál es la palabra más larga.
// 3. Solictar el ingreso de una palabra, e indicar si la misma se encuentra entre las ingresadas. 

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MF_PALABRA 21
#define MF_PALABRAS 2

typedef char Tpalabra[MF_PALABRA];
typedef Tpalabra Tpalabras[MF_PALABRAS];

void ingresar_palabra(Tpalabra palabra)
{
    printf("Ingrese su palabra: ");
    fgets(palabra, MF_PALABRA, stdin);
    fflush(stdin);
    palabra[strcspn(palabra, "\n")] = '\0';
}

void solicitar_palabras(Tpalabras palabras)
{
    int i;

    printf("Ingrese sus palabras a continuacion: \n");
    for(i = 0; i < MF_PALABRAS; i++)
    {
        ingresar_palabra(palabras[i]);
    }
}

void mostrar_palabras(Tpalabras palabras)
{
    int i;
    for(i = 0; i < MF_PALABRAS; i++)
    {
        printf("%s\n", palabras[i]);
    }
}

int palabra_mas_larga(Tpalabras palabras)
{
    int i, max_idx = 0;
    for(i = 1; i < MF_PALABRAS; i++)
    {
        if(strlen(palabras[max_idx]) < strlen(palabras[i]))
        {
            max_idx = i;
        }
    }
    return max_idx;
}

bool in_array(Tpalabras palabras, Tpalabra pivot)
{
    int i;
    bool in = false;
    for(i = 0; i < MF_PALABRAS; i++)
        if(strcmp(palabras[i], pivot) == 0)
            in = true;
    
    return in;
}

void show_in_array(bool in)
{
    if(in)
        printf("Esta entre las palabras");
    else
        printf("No esta en el array");
}

int main()
{
    int index;
    Tpalabras palabras;
    Tpalabra pivot;
    bool in;
    solicitar_palabras(palabras);
    mostrar_palabras(palabras);
    index = palabra_mas_larga(palabras);
    printf("La palabra mas larga del array es, %s", palabras[index]);
    ingresar_palabra(pivot);
    in = in_array(palabras, pivot);
    show_in_array(in);
    return 0;
}