// Escribir una función en C, que reciba una cadena que representa una palabra o una frase y devuelva si la misma es o no un palíndromo.
// Un palíndromo, es una palabra o frase que se lee igual en ambos sentidos.
// Probar la función con los siguientes casos de prueba:
// - anilina (Es palíndromo)
// - ojo (Es palíndromo)
// - radar (Es palíndromo)
// - reconocer (Es palíndromo)
// - amar a rama (Es palíndromo)
// - ana lava lana (Es palíndromo)
// - a ti no, bonita (Es palíndromo)
// - algoritmos y programas (No es palíndromo)
// - lenguaje C (No es palíndromo)
// Evitar realizar ciclos innecesarios. 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MF 51

typedef char Tstr[MF];

void gets_str(Tstr str)
{
    printf("Ingrese la palabra para validar si es un palindromo: \n");
    fgets(str, MF, stdin);
    fflush(stdin);
    str[strcspn(str, "\n")] = '\0';
}

void normalizar(Tstr str, Tstr str_normalizado)
{
    int i, j;

    i = 0;
    j = 0;
    while(str[i] != '\0')
    {
        if(str[i] != ' ' && str[i] != ',' )
        {
            str_normalizado[j] = str[i];
            j++;
        }
        i++;
    }

    str_normalizado[j] = '\0';
}

bool es_palindromo(Tstr str)
{
    Tstr str_normalizado;
    normalizar(str, str_normalizado);
    int len = strlen(str_normalizado), i = 0;
    bool es_palindromo = true;

    while(i < (len / 2) && es_palindromo)
    {
        if(str_normalizado[i] != str_normalizado[len - i - 1])
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
        printf("La palabra '%s' es palindromo", str);
    else
        printf("La palabra '%s' no es palindromo", str);
    
    return 0;
}