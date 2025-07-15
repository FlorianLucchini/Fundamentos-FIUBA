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

#define MFTITULO 50
#define MFAUTOR 40
#define MFGENERO 20

typedef char T_titulo[MFTITULO];
typedef char T_autor[MFAUTOR];
typedef char T_genero[MFGENERO];

typedef struct {
    int isbn;
    T_titulo titulo;
    T_autor autor;
    T_genero genero;
    int cantidad;
} T_Libro;

int cargar_libros(FILE *archivo)
{
    T_Libro Libro;
    int i;

    archivo = fopen("Libros.dat", "a"); // Utilizo "a" en vez de "w" ya que el enunciado menciona "cargar nuevos libros" lo que implica una previa existencia de otros.

    if(archivo == NULL)
        printf("Error al abrir el archivo");
    else
    {
        printf("A continuacion ingrese el codigo del libro a almacenar (0 para terminar): ");
        scanf("%d", &Libro.isbn);

        i = 0;
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
            i++;

            printf("Continuemos con un nuevo libro.\n");
            printf("Ingrese el codigo (0 para finalizar): ");
            scanf("%d", &Libro.isbn);
        }
    }

    return 0;
}


int main()
{
    FILE *archivo;
    cargar_libros(archivo);
}