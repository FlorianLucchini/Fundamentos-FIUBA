// 11. Escribir un programa modular en C, que solicite el ingreso de no más de 20 palabras. C Cada palabra no tendrá más de 20 caracteres. Informar:
// 1. Mostrar las palabras ingresadas.
// 2. Cuál es la palabra más larga.
// 3. Solictar el ingreso de una palabra, e indicar si la misma se encuentra entre las ingresadas. 

#include <stdio.h>

#define MF_PALABRA 21
#define MF_PALABRAS 2

typedef char Tpalabra[MF_PALABRA];
typedef Tpalabra Tpalabras[MF_PALABRAS];

void solicitar_palabras(Tpalabras palabras)
{
    int i;
    Tpalabra palabra;

    for(i = 0; i < MF_PALABRAS; i++)
    {
        printf("Ingrese su palabra: ");
        fgets(palabras[i], MF_PALABRA, stdin);
        fflush(stdin);
    }
}

void mostrar_palabras(Tpalabras palabras)
{
    int i;
    for(i = 0; i < MF_PALABRAS; i++)
    {
        printf("%s", palabras[i]);
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

int main()
{
    int index;
    Tpalabras palabras;
    solicitar_palabras(palabras);
    mostrar_palabras(palabras);
    index = palabra_mas_larga(palabras);
    printf("La palabra mas larga del array es, %s", palabras[index]);
    return 0;
}