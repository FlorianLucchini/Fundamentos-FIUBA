#include <stdio.h>

#define MF_DESC 31

typedef struct {
    int codigo;
    char descripcion[MF_DESC];
    float cantidad;
} TregProducto;

void cargar_datos(FILE *arProductos) {
    TregProducto rProducto;

    printf("Codigo de Articulo (Ingrese 0 para finalizar): ");
    scanf("%d", &rProducto.codigo);
    fflush(stdin);

    while (rProducto.codigo != 0) {
        printf("Descripcion: ");
        scanf("%30[^\n]", rProducto.descripcion);
        fflush(stdin);

        printf("Cantidad en Stock: ");
        scanf("%f", &rProducto.cantidad);   
        fflush(stdin);

        fwrite(&rProducto, sizeof(rProducto), 1, arProductos);

        printf("\nCodigo de Articulo (Ingrese 0 para finalizar): ");
        scanf("%d", &rProducto.codigo);
        fflush(stdin);
    }
}

void mostrar_dato(FILE *arProductos)
{
    TregProducto rProducto;

    fread(&rProducto, sizeof(rProducto), 1, arProductos);

    printf("\nCodigo \tDescripcion \t\t\tCantidad");

    while( !feof( arProductos) )
    {
        printf("\n%d \t%-30s %8.2f", rProducto.codigo, rProducto.descripcion, rProducto.cantidad);
        fread(&rProducto, sizeof(rProducto), 1, arProductos);
    }
}

int main() {
    FILE *arProductos;
    arProductos = fopen("productos.dat", "wb");
    
    if (arProductos == NULL) {
        printf("\nNo se pudo crear el archivo!\n");
    } else {
        cargar_datos(arProductos);
        mostrar_dato(arProductos);  
        fclose(arProductos);
    }
    return 0;
}