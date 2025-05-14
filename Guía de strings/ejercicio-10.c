
// Escribir un programa modular que solicite el ingreso de dos palabras y luego muestre las mismas según la longitud de cada una de ellas, mostrando primero la de menor longitud.
// A igualdad de longitud, mostrar primero la menor de las dos, en términos de orden alfabético.
// Las palabras tienen una longitud máxima de 15 caracteres

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MF 16

typedef char Tstr[MF];

void gets_str(Tstr str)
{
    fgets(str, MF, stdin);
    fflush(stdin);
    str[strcspn(str, "\n")] = '\0';
}

int first_upper_len(int len_str_1, int len_str_2)
{
    return len_str_1 > len_str_2;
}

int second_upper_len(int len_str_1, int len_str_2)
{
    return len_str_1 < len_str_2;
}

int first_upper_alphabetic(Tstr str_1, Tstr str_2)
{
    return strcmp(str_1, str_2) > 0;
}

int second_upper_alphabetic(Tstr str_1, Tstr str_2)
{
    return strcmp(str_1, str_2) < 0;
}

void str_compare(Tstr str_1, Tstr str_2)
{
    int bandera;
    int len_1 = strlen(str_1);
    int len_2 = strlen(str_2);

    if(first_upper_len(len_1, len_2))
        printf("En longitud, primero %s, luego %s", str_2, str_1);
    else if (second_upper_len(len_1, len_2))
        printf("En longitud, primero %s, luego %s", str_1, str_2);
    else
        if(first_upper_alphabetic(str_1, str_2))
            printf("Alfabeticamente, primero %s, luego %s", str_2, str_1);
        else if(second_upper_alphabetic(str_1, str_2))
            printf("Alfabeticamente, primero %s, luego %s", str_1, str_2);
        else
            printf("YA COMPARE TODO LOCO SON IGUALES");

    return;
}

int main()
{
    Tstr str_1, str_2;
    printf("Ingrese la primera palabra: ");
    gets_str(str_1);
    printf("Ingrese la segunda palabra: ");
    gets_str(str_2);
    str_compare(str_1, str_2);
}