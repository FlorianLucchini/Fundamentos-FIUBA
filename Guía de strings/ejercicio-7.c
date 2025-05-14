
// Escribir una función en C, que reciba una cadena que representa una palabra y devuelva si la misma es o no un palíndromo.
// Una palabra es un palíndromo, si se lee igual en ambos sentidos.
// Probar la función con los siguientes casos de prueba:
// - anilina (Es palíndromo)
// - ojo (Es palíndromo)
// - radar (Es palíndromo)
// - reconocer (Es palíndromo)
// - algoritmos (No es palíndromo)
// - programas (No es palíndromo)
//Evitar realizar ciclos innecesarios

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MF 51

typedef char Tstr[MF];

void gets_str(Tstr str)
{
    printf("Ingrese la palabra para validar si es un palindromo: \n");
    fgets(str, MF, stdin);
    fflush(stdin);
    str[strcspn(str, "\n")] = '\0';
}

bool es_palindromo(Tstr str)
{
    bool es_palindromo = true;
    int len = strlen(str), i = 0;

    while(i < (len / 2) && es_palindromo)
    {
        if(str[i] != str[len - i - 1])
            es_palindromo = false;

        i++;
    }

    return es_palindromo;
}

int main()
{
    Tstr str;
    bool es;
    gets_str(str);
    es = es_palindromo(str);
    if(es)
        printf("La palabra '%s' es palindromo.\n", str);
    else
        printf("La palabra '%s' no es palindromo.\n", str);

    return 0;
}