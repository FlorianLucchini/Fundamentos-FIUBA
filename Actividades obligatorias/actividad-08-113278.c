// Un supermercado posee un archivo denominado Stock.dat, cuyos registros contienen el código de producto (entero), rubro (25 caracteres), el nombre (30 caracteres) y el stock actual (entero).

// Dicho archivo no está ordenado y "no entra" en memoria en su totalidad.

// Se pide desarrollar un programa modular en lenguaje C que procese este archivo y permita:

// a) Desarrollar un modulo de carga de la información, la misma debe guardarse en el archivo Stock.dat. La carga finaliza cuando el usuario ingresa un código de producto igual a cero.

// b) Solicitar al usuario el ingreso de un rubro para luego generar una tabla llamada dat_rubro que contenga los productos pertenecientes al rubro ingresado (con la misma estructura del archivo). Asumir que esta tabla tendrá como máximo 200 registros, y que cabe en memoria.

// c) Mostrar por pantalla un listado de los productos cargados en la tabla del punto "b" cuyo stock sea superior al stock promedio de la tabla.

// d) A partir de la tabla del punto b, generar un archivo de texto con los códigos de productos que tengan un stock menor a 25 unidades.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MF_RUBRO 26
#define MF_NOMBRE 31
#define MF_REGISTROS 200

typedef char Trubro[MF_RUBRO];
typedef char Tnombre[MF_NOMBRE];

typedef struct
{
    int codigo;
    Trubro rubro;
    Tnombre nombre;
    int stock;
} Tproducto;

typedef Tproducto Ttabla[MF_REGISTROS];

void mostrar_datos_producto(Tproducto Producto)
{
    printf("\nCodigo: %d", Producto.codigo);
    printf("\nRubro: %s", Producto.rubro);
    printf("\nNombre: %s", Producto.nombre);
    printf("\nStock: %d\n", Producto.stock);
}

void mostrar_datos(FILE *archivo)
{
    Tproducto Producto;

    fread(&Producto, sizeof(Producto), 1, archivo);

    printf("\nCodigo \tNombre \t\t\tRubro \t\t\tStock");

    while (!feof(archivo))
    {
        mostrar_datos_producto(Producto);
        fread(&Producto, sizeof(Producto), 1, archivo);
    }

    fclose(archivo);
    return;
}

// a)
void cargar_productos(FILE *archivo)
{
    Tproducto Producto;
    int i;

    archivo = fopen("Stock.dat", "wb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
    }
    else
    {
        printf("Ingrese el codigo del producto (0 para finalizar): ");
        scanf("%d", &Producto.codigo);

        i = 0;
        while (Producto.codigo != 0)
        {
            printf("Ingrese el rubro del producto: ");
            scanf(" %26[^\n]s", Producto.rubro);

            printf("Ingrese el nombre del producto: ");
            scanf(" %31[^\n]s", Producto.rubro);

            printf("Ingrese el stock del producto: ");
            scanf("%d", &Producto.stock);

            fwrite(&Producto, sizeof(Producto), 1, archivo);
            i++;

            printf("Ingrese el codigo del producto (0 para finalizar): ");
            scanf("%d", &Producto.codigo);
        }
    }
    fclose(archivo);
    return;
}

// b)
void solicitar_rubro(Trubro rubro)
{
    printf("Ingrese el rubro a buscar: ");
    fgets(rubro, MF_RUBRO, stdin);
    rubro[strcspn(rubro, "\n")] = '\0';

    return;
}

void generar_tabla_rubro(FILE *archivo, Ttabla dat_rubro, int *ml)
{
    Tproducto Producto;
    Trubro rubro;
    int i;

    solicitar_rubro(rubro);

    archivo = fopen("Stock.dat", "rb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
    }
    else
    {
        fread(&Producto, sizeof(Producto), 1, archivo);

        i = 0;
        while (!feof(archivo) && i < MF_REGISTROS)
        {
            if (strcmp(Producto.rubro, rubro) == 0)
            {
                dat_rubro[i] = Producto;
                i++;
            }

            fread(&Producto, sizeof(Producto), 1, archivo);
        }
    }
    
    fclose(archivo);
    *ml = i;
    return;
}

// c)
float calcular_promedio_stock(Ttabla dat_rubro, int ml)
{
    int i;
    int sum = 0;

    for (i = 0; i < ml; i++)
        sum += dat_rubro[i].stock;

    return (float)sum / ml;
}

void productos_con_stock_superior_a_promedio(Ttabla dat_rubro, int ml)
{
    float promedio = calcular_promedio_stock(dat_rubro, ml);
    int i;

    printf("\nListado de productos con stock superior al promedio (%.2f):\n", promedio);
    for (i = 0; i < ml; i++)
        if (dat_rubro[i].stock > promedio)
        {
            mostrar_datos_producto(dat_rubro[i]);
            printf("------------------------------\n");
        }

    return;
}

// d)
bool stock_menor_25(Tproducto Producto)
{
    return Producto.stock < 25;
}

void generar_archivo_stock_menor_25(FILE *archivo, Ttabla dat_rubro, int ml)
{
    int i;
    archivo = fopen("Stock_menor_25.txt", "wt");

    if (archivo == NULL)
        printf("Error al crear el archivo.\n");
    else
    {
        for (i = 0; i < ml; i++)
        {
            if (stock_menor_25(dat_rubro[i]))
                fprintf(archivo, "%d\n", dat_rubro[i].codigo);
        }
    }

    fclose(archivo);
    return;
}

int main()
{
    FILE *archivo;
    Ttabla dat_rubro;
    int ml;

    cargar_productos(archivo);

    generar_tabla_rubro(archivo, dat_rubro, &ml);
    printf("\nBuscando productos con stock superior al promedio.\n");
    productos_con_stock_superior_a_promedio(dat_rubro, ml);
    printf("\nGenerando archivo de productos con stock menor a 25.\n");
    generar_archivo_stock_menor_25(archivo, dat_rubro, ml);

    return 0;
}