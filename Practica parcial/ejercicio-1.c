// Una biblioteca necesita un sistema para gestionar su catálogo de libros. Para ello, se utilizará un archivo binario llamado Libros.dat. Cada registro en el archivo contendrá:
// - ISBN (entero de 13 dígitos, puedes usar long)
// - Título (50 caracteres)
// - Autor (40 caracteres)
// - Género (20 caracteres)
// - Cantidad de ejemplares (entero)

// Se pide desarrollar un programa modular en C que permita:
// a) Carga de Libros: Desarrollar un módulo que permita al usuario cargar nuevos libros en el archivo Libros.dat. La carga finaliza cuando el usuario ingresa un ISBN igual a 0.

// b) Filtrar por Autor: Crear una función que cargue en una tabla en memoria (asumir un máximo de 150 libros) todos los libros de un autor específico, solicitado al usuario.

// c) Ordenar y Mostrar: Implementar un módulo que ordene la tabla generada en el punto "b" alfabéticamente por título utilizando el método de ordenamiento por selección (selection_sort). Luego, mostrar por pantalla el contenido de la tabla ordenada.

// d) Generar Reporte de Stock Bajo: A partir de la tabla ya ordenada, generar un archivo de texto llamado Faltantes.txt que contenga el ISBN y el título de todos los libros cuyo número de ejemplares sea menor a 5. El formato debe ser: ISBN: [isbn_del_libro], Título: [titulo_del_libro].

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MF_TITULO 50
#define MF_AUTOR 40
#define MF_GENERO 20
#define MF_REGISTROS 150

typedef char T_titulo[MF_TITULO];
typedef char T_autor[MF_AUTOR];
typedef char T_genero[MF_GENERO];

typedef struct {
    int isbn;
    T_titulo titulo;
    T_autor autor;
    T_genero genero;
    int cantidad;
} T_Libro;

typedef T_Libro T_Tabla[MF_REGISTROS];

// a)
int cargar_libros(FILE *archivo)
{
    T_Libro Libro;

    archivo = fopen("Libros.dat", "ab"); // Utilizo "a" en vez de "w" ya que el enunciado menciona "cargar nuevos libros" lo que implica una previa existencia de otros.

    if(archivo == NULL)
        printf("Error al abrir el archivo.\n");
    else
    {
        printf("A continuacion ingrese el codigo del libro a almacenar (0 para terminar): ");
        scanf("%d", &Libro.isbn);

        while(Libro.isbn != 0)
        {
            printf("Ingrese el titulo: ");
            scanf(" %50[^\n]s", Libro.titulo);

            printf("Ingrese el autor: ");
            scanf(" %40[^\n]s", Libro.autor);

            printf("Ingrese el genero: ");
            scanf(" %20[^\n]s", Libro.genero);

            printf("Ingrese la cantidad de ejemplares actual: ");
            scanf("%d", &Libro.cantidad);

            fwrite(&Libro, sizeof(Libro), 1, archivo);

            printf("Continuemos con un nuevo libro.\n");
            printf("Ingrese el codigo (0 para finalizar): ");
            scanf("%d", &Libro.isbn);
        }
    }
    fclose(archivo);
    return 0;
}

// b)
int solicitar_autor(T_autor autor)
{
    printf("Ingrese el autor por filtrar: ");
    scanf(" %40[^\n]s", autor);
    return 0;
}

int generar_tabla(FILE *archivo, T_Tabla tabla, int *ml)
{
    T_Libro Libro;
    T_autor autor;
    int i;

    solicitar_autor(autor);

    archivo = fopen("Libros.dat", "rb");
    if(archivo == NULL)
        printf("Error al abrir el archivo.\n");
    else
    {
        fread(&Libro, sizeof(Libro), 1, archivo);

        i = 0;
        while(!feof(archivo) && i < MF_REGISTROS)
        {
            if(strcmp(Libro.autor, autor) == 0)
            {
                tabla[i] = Libro;
                i++;
            }
            fread(&Libro, sizeof(Libro), 1, archivo);
        }
    }
    
    *ml = i;
    fclose(archivo);
    return 0;
}

// c)
int mostrar_libro(T_Libro Libro)
{
    printf("ISBN: %d.\n", Libro.isbn);
    printf("Titulo: %s.\n", Libro.titulo);
    printf("Autor: %s.\n", Libro.autor);
    printf("Genero: %s,\n", Libro.genero);
    printf("Cantidad de ejemplares: %d.\n", Libro.cantidad);
    return 0;
}

int mostrar_tabla(T_Tabla tabla, int ml)
{
    int i;
    for(i = 0; i < ml; i++)
        mostrar_libro(tabla[i]);
    return 0;
}


int intercambiar(T_Tabla tabla, int i, int min)
{
    T_Libro aux;
    aux = tabla[i];
    tabla[i] = tabla[min];
    tabla[min] = aux;
    return 0;
}

int selection_sort_por_titulo(T_Tabla tabla, int ml)
{
    int i, j, min;

    for(i = 0; i < ml; i++)
    {
        min = i;
        for(j = i + 1; j < ml; j++)
            if(strcmp(tabla[min].titulo, tabla[j].titulo) > 0)
                min = j;

        intercambiar(tabla, i, min);
    }

    printf("La tabla ya ordenada se ve asi.\n");
    mostrar_tabla(tabla, ml);
    return 0;
}


// d)
bool stock_bajo(T_Libro Libro)
{
    return Libro.cantidad < 5;
}

int generar_reporte_stock(FILE *archivo, T_Tabla tabla, int ml)
{
    int i;
    archivo = fopen("Faltantes.txt", "wt");
    if(archivo == NULL)
        printf("Error al abrir el archivo.\n");
    else
    {
        for(i = 0; i < ml; i++)
            if(stock_bajo(tabla[i]))
                fprintf(archivo, "\nISBN: [%d], Título: [%s]", tabla[i].isbn, tabla[i].titulo);
    }

    fclose(archivo);
    return 0;
}

int main()
{
    FILE *archivo;
    T_Tabla tabla;
    int ml;

    cargar_libros(archivo);
    generar_tabla(archivo, tabla, &ml);
    selection_sort_por_titulo(tabla, ml);
    generar_reporte_stock(archivo, tabla, ml);
}