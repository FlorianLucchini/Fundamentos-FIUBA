//  Reservar memoria para almacenar una palabra ingresada por el usuario, es leída en una cadena auxiliar, luego copiada a memoria dinámica, recordando que se requiere adicionar un carácter de fin de cadena '\n'.
// Ejemplo:
// "hola mundo" + '\0' -> requiere espacio para 11 caracteres.
// char* cadena_aux = "hola mundo";
// char* cadena = malloc(strlen(cadena_aux) * sizeof(char) + 1);

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str_aux, *cadena;
    printf("Ingrese la palabra: ");
    // scanf(" %30[^\n]s", str_aux);
    fgets(str_aux, 30, stdin);
    str_aux[strcspn(str_aux, "\n")] = '\0';
    cadena = malloc((strlen(str_aux) * sizeof(char)) + 1);
    strcpy(cadena, str_aux);
    printf("Length: %d\n", strlen(cadena));
    printf("%s", cadena);
    printf("a");
    free(cadena);
    return 0;
}