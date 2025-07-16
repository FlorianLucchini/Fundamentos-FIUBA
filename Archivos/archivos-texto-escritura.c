#include <stdio.h>

#define MAX 100

void escritura_fputc(FILE *archivo)
{
    char caracter;

    printf("\nTexto a agregar al archivo: ");

    caracter = getchar();
    while (caracter != '\n') // agrega carácter a carácter hasta que se presiona Enter
    {
        fputc(caracter, archivo);
        caracter = getchar();
    }

    fclose(archivo);
}

void escritura_fputs(FILE *archivo)
{
    char cadena[MAX];
    printf("Texto a agregar al archivo: ");
    fgets(cadena, MAX, stdin);

    if (fputs(cadena, archivo) == 0)
        printf("\nEl archivo fue actualizado");
    else
        printf("\nNo fue posible agregar el texto al archivo");

    fclose(archivo);
}

void escritura_fprintf(FILE *archivo)
{
    char cadena[MAX];
    int cant_caracteres = 0;

    printf("Texto a agregar al archivo: ");
    fgets(cadena, MAX, stdin);

    cant_caracteres = fprintf(archivo, "\n%s", cadena);
    
    printf("\nSe escribieron %i caracteres\n", cant_caracteres);

    fclose(archivo);
}

void main()
{
    FILE *archivo;
    archivo = fopen("texto2.txt", "a");

    if (archivo == NULL)
        printf("\nError de apertura del archivo. \n\n");
    else
    {
        printf("\nEscritura con fgetc:\n");
        escritura_fputc(archivo);
        printf("\nEscritura con fgets:\n");
        escritura_fputs(archivo);
        printf("\nEscritura con fprintf:\n");
        escritura_fprintf(archivo);
    }

    return;
}
