// a)
// Escribir un programa modular (compuesto por funciones) en donde el usuario deba cargar un alias bancario válido.
// En caso de ser invalido se le debe indicar al usuario y solicitar el siguiente.
// Como regla extra el alias no puede contener ninguna de las siguientes palabras: "banco", "cuenta", "saldo"

// Para un alias ser válido debe cumplir las siguientes reglas:
//  - Debe tener longitud entre 6 y 20 caracteres.
//  - Puede contener caracteres alfabeticos, numericos, "." (punto) y "-" (guión).
//  - El guión o punto no pueden estar ubicados ni en la primera ni ultima posición de la cadena.

// En la resolución evitar ciclos innecesario.
// La elección incorrecta del ciclo o el mal uso del mismo, es suficiente condición para considerar al ejercicio como inválido o no aceptado.

// Sugerencias:
//  - Pueden utilizar las funciones strstr, strlen, strcpy y strcmp de la biblioteca "string.h" según crean conveniente.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LONG_MAX 21
#define LONG_MIN 6

typedef char Talias[LONG_MAX];

void ingresar_alias(Talias alias)
{
    printf("Ingrese su alias bancario a continuación: \n");
    fgets(alias, LONG_MAX, stdin);
    alias[strcspn(alias, "\n")] = '\0';
}

bool es_valida_long(Talias alias)
{
    bool es_valido = false;
    int longitud = strlen(alias);
    if (LONG_MIN <= longitud && longitud < LONG_MAX)
        es_valido = true;
    else
        printf("%s -> inválido, no cumple rango de longitud.\n", alias);

    return es_valido;
}

bool es_alfabetico(char c)
{
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

bool es_digito(char c)
{
    return c <= '9' && c >= '0';
}

bool es_alfanumerico_valido(char c)
{
    return c == '.' || c == '-';
}

bool validar_caracteres(Talias alias)
{
    int i;
    bool es_valido = true;
    for(i = 0; i < strlen(alias); i++)
    {
        char caracter = alias[i];
        if(!(es_alfabetico(caracter) || es_digito(caracter) || es_alfanumerico_valido(caracter)))
            es_valido = false;
    }

    if(!es_valido)
        printf("%s -> inválido, contiene un caracter no permitido.\n", alias);

    return es_valido;
}

bool contiene_alfanumerico_en_extremo(Talias alias)
{
    int longitud = strlen(alias);
    char inicio_alias = alias[0];
    char final_alias = alias[longitud - 1];
    bool contiene = false;
    contiene = (es_alfanumerico_valido(inicio_alias) || es_alfanumerico_valido(final_alias));

    if(contiene)
        printf("%s -> inválido, el punto o guion no pueden estar en los extremos.\n", alias);
        
    return contiene;
}

bool contiene_palabras_no_permitidas(Talias alias)
{
    bool contiene = false;
    contiene = (strstr(alias, "banco") != NULL || strstr(alias, "cuenta") != NULL || strstr(alias, "saldo") != NULL);

    if(contiene)
        printf("%s -> inválido, contiene palabras no permitidas (banco, cuenta, saldo).\n", alias);

    return contiene;
}

bool alias_valido(Talias alias)
{
    return es_valida_long(alias) && validar_caracteres(alias) && !contiene_alfanumerico_en_extremo(alias) &&
    !contiene_palabras_no_permitidas(alias);
}

void pedir_alias_valido(Talias alias)
{   
    do
    {
        ingresar_alias(alias);
    } while(!alias_valido(alias));
    printf("%s -> válido.\n", alias);

}

int main()
{
    Talias alias;
    pedir_alias_valido(alias);
    return 0;
}