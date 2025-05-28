// Escribir un programa modular en C, que solicite el ingreso de 1 oración, de no más de 100 caracteres.
// Luego informar la cantidad de vocales minúsculas, no acentuadas, que hay en la oración.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MF 101
#define VOCALES_MIN "aeiou"
#define CHAR_NULL '\0'

typedef char Tstr[MF];

bool es_vocal(char c)
{
    char strchar[] = {c, CHAR_NULL};
    return strstr(VOCALES_MIN, strchar) != NULL;
}

int contar_vocales(Tstr str)
{
    int i = 0, cont = 0;

    while(str[i] != CHAR_NULL)
    {
        if(es_vocal(str[i]))
            cont++;

        i++;
    }

    return cont;
}

int main()
{
    Tstr str;
    int cont;
    cont = contar_vocales("Holacomo");
    printf("La cantidad de vocales es: %d", cont);
    return 0;
}