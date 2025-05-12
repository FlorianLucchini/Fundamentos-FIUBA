// Escribir una función que reciba como parámetro una cadena de caracteres y devuelva la cantidad de caracteres no alfabéticos que hay en la cadena.
// No tener en cuenta la ñ, ni las vocales acentuadas. 

#include <stdio.h>
#include <stdbool.h>

#define MF 31

typedef char Tstr[MF];

bool is_alphabetic(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ;
}

int count_non_alphabetic_chars(Tstr str)
{
    int i, counter = 0;

    i = 0;
    while(str[i] != '\0')
    {
        if(!is_alphabetic(str[i]))
            counter++;

        i++;
    }

    printf("La cantidad de caracteres no alfabéticos en %s es de: %d.\n", str, counter);

    return counter;
}

int main()
{
    count_non_alphabetic_chars("----");
    count_non_alphabetic_chars("-a-B");
    count_non_alphabetic_chars("-23x");
    count_non_alphabetic_chars("-aIl");
    return 0;
}