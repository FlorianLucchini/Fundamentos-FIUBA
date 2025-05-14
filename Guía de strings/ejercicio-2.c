// Escribir una función que reciba como parámetro una cadena de caracteres y devuelva la cantidad de caracteres no alfabéticos que hay en la cadena.
// No tener en cuenta la ñ, ni las vocales acentuadas. 

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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


    return counter;
}

int main()
{
    Tstr str;
    int cnt;
    
    strcpy(str, "----");
    cnt = count_non_alphabetic_chars(str);
    printf("La cantidad de caracteres no alfabéticos en %s es de: %d.\n", str, cnt);

    strcpy(str, "-a-B");
    cnt = count_non_alphabetic_chars(str);
    printf("La cantidad de caracteres no alfabéticos en %s es de: %d.\n", str, cnt);

    strcpy(str, "-23x");
    cnt = count_non_alphabetic_chars(str);
    printf("La cantidad de caracteres no alfabéticos en %s es de: %d.\n", str, cnt);

    strcpy(str, "-aIl");
    cnt = count_non_alphabetic_chars(str);
    printf("La cantidad de caracteres no alfabéticos en %s es de: %d.\n", str, cnt);

    return 0;
}