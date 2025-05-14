// Escribir una función en C que reciba como primer parámetro, una cadena de tipo t_cadena, y devuelva como segundo parámetro, la misma cadena pero invertida, sin considerar los blancos.
// Sólo se deben invertir las posiciones con caracteres ciertos, y no aquellas posiciones potenciales a ser utilizadas pero que podrían contener caracteres inciertos.
// Recorrer la cadena a lo sumo una vez.
// Declare un tipo t_cadena acorde.
// Escribir el programa que incluya a la función y las invocaciones con los siguientes casos y las impresiones para comprobar que devuelven lo correcto.
// Casos:
// invertir_cadena("Hola, me llamo Ana.", cad_invertida) ==> cad_invertida: ".anAomallem,aloH"
// invertir_cadena("234561", cad_invertida) ==> cad_invertida: "165432"
// invertir_cadena(" ", cad_invertida) ==> cad_invertida: ""
// invertir_cadena("Somos o No somos", cad_invertida) ==> cad_invertida: "somosoNsomoS"

#include <stdio.h>
#include <string.h>

#define MF 51

typedef char Tstr[MF];

// Functions
void invertir_cadena(Tstr str, Tstr cad_invertida)
{
    int i = strlen(str) - 1;
    int j = 0;

    while(i >= 0)
    {
        if(str[i] != ' ')
        {
            cad_invertida[j] = str[i];
            j++;
        }
        i--;
    }

    cad_invertida[j] = '\0';
}

// MAIN
int main()
{
    Tstr str, cad_invertida;
    strcpy(str, "Hola, me llamo Ana.");
    invertir_cadena(str, cad_invertida);
    printf("La cadena '%s' invertida queda asi '%s'.\n", str, cad_invertida);
    
    strcpy(str, "234561");
    invertir_cadena(str, cad_invertida);
    printf("La cadena '%s' invertida queda asi '%s'.\n", str, cad_invertida);

    strcpy(str, " ");
    invertir_cadena(str, cad_invertida);
    printf("La cadena '%s' invertida queda asi '%s'.\n", str, cad_invertida);

    strcpy(str, "Somos o No somos");
    invertir_cadena(str, cad_invertida);
    printf("La cadena '%s' invertida queda asi '%s'.\n", str, cad_invertida);

    return 0;
}