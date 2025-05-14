// Escribir una función que recibirá por parámetro, una palabra, que representa un sustantivo en singular.

// La función deberá devolver, el plural de dicho sustantivo, aplicando las siguientes reglas:
// a. Agregar una “s” al final, si la palabra termina en vocal sin acento.

// b. Agregar una “s” al final, si la palabra termina con una é (acentuada).

// c. Si la palabra termina en “z”, la reemplazamos por “ces”.

// d. Agregamos “es” al final, si la palabra termina en una consonante (a excepción de la “s”, la “z”, y la “x”), ó si la palabra termina con las vocales acentuadas: á, í, ó, ú.

// e. Si el sustantivo termina en “s” ó “x”, entonces el plural es igual al singular, por lo tanto la función deberá devolver lo mismo que recibió.

// Para cada uno de los siguientes ejercicios, deberás escribir un programa compuesto por una o más funciones. Recordá que lo adecuado es que una función realice sólo una tarea, por eso, antes de ponerte a programar cada una de las soluciones de los ejercicios, diseña la solución indicando cuáles serán las funciones que escribirás y compondrán tu programa. 

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MF 51

typedef char Tsust[MF];

void gets_str(Tsust sust)
{
    printf("Ingrese el sust. para convertirlo en plural: \n");
    fgets(sust, MF, stdin);
    fflush(stdin);
    sust[strcspn(sust, "\n")] = '\0';
}


bool termina_en_vocal(char c)
{
    return 'a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c;
}

bool termina_en_s_x(char c)
{
    return c == 's' || c == 'x';
}

bool termina_en_z(char c)
{
    return c == 'z';
}

bool termina_en_e_acentuada(char c)
{
    return c == 'é';
}

void convertir_a_plural(Tsust sust, Tsust plural)
{
    int ml = strlen(sust);
    strcpy(plural, sust);

    if(termina_en_vocal(sust[ml - 1]) || termina_en_e_acentuada(sust[ml - 1]))
    {
        strcat(plural, "s");
    }
    else if(termina_en_z(sust[ml - 1]))
    {
        plural[ml - 1] = '\0';
        strcat(plural, "ces");
    }
    else
    {
        if(!termina_en_s_x(sust[ml - 1]))
            strcat(plural, "es");
    }
}

int main()
{
    Tsust sust, plural;
    gets_str(sust);
    convertir_a_plural(sust, plural);
    printf("El sustantivo %s el plural es %s", sust, plural);
    return 0;
}