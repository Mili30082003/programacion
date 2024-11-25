#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*------------------------ESTRUCTURAS--------------------------------*/
struct Proveedor
{
    char Nombre[50];
    char Telefono[15];

} typedef Proveedor;

struct Producto
{
    char NombreProducto[50];
    int codigoProducto;
    int stock;
    float PrecioUnitario;
    int cantProveedor;
    Proveedor *proveedores;

} typedef Producto;

/*------------------FUNCIONES-----------------------------------*/

Producto *cargarDatos(int *cantProducto);
void MostrarProductos(Producto *productos, int cantProductos);
void MostrarProductoMenorCantidad(Producto *productos, int cantProductos);
void CalcularTotal(Producto *productos, int cantProductos);
void LiberarEspacio(Producto *productos, int cantProductos);

/*-------------------------------------------------------------*/

void main()
{

    int cantProductos = 0;
    Producto *productos = cargarDatos(&cantProductos);

    MostrarProductos(productos, cantProductos);
    MostrarProductoMenorCantidad(productos, cantProductos);
    CalcularTotal(productos, cantProductos);
    
}

Producto *cargarDatos(int *cantProducto)
{

    *cantProducto = 3;

    Producto *productos = malloc(sizeof(Producto) * (*cantProducto));

    Producto producto1 = {"Labial", 10236, 30, 2500, 2, malloc(sizeof(Proveedor) * 2)};
    producto1.proveedores[0] = (Proveedor){"Makeup Ana", "3814499121"};
    producto1.proveedores[1] = (Proveedor){"Makeup Mayorista", "3814569"};

    Producto producto2 = {"Rubor", 45023, 40, 4000, 1, malloc(sizeof(Proveedor) * 1)};
    producto2.proveedores[0] = (Proveedor){"Makeup Chino", "381458631"};

    Producto producto3 = {"Mascara", 40002, 45, 3500, 3, malloc(sizeof(Proveedor) * 3)};
    producto3.proveedores[0] = (Proveedor){"Makeup Mili", "38145022"};
    producto3.proveedores[1] = (Proveedor){"Makeup Jungkook", "3810963"};
    producto3.proveedores[2] = (Proveedor){"Kim Makeup", "35142001"};

    productos[0] = producto1;
    productos[1] = producto2;
    productos[2] = producto3;

    return productos;
}

void MostrarProductos(Producto *productos, int cantProductos)
{

    char NombreProducto[50];
    printf("Ingresar el Nombre del Producto: ");
    fflush(stdin);
    gets(NombreProducto);

    int ProductoEncontrado = 0;

    for (int i = 0; i < cantProductos; i++)
    {
        if (strcmp(productos[i].NombreProducto, NombreProducto) == 0)
        {
            ProductoEncontrado = 1;
            printf("Producto: %s\n", productos[i].NombreProducto);
            printf("Proveedor: %s\n", productos[i].proveedores->Nombre);
        }
    }

    if (!ProductoEncontrado)
    {
        printf("El producto '%s' no se encuentra en la lista\n", NombreProducto);
    }
}

/* Módulo 1: Listar los productos con una cantidad menor a un umbral
especificado por el usuario, mostrando también el nombre del proveedor.  */
void MostrarProductoMenorCantidad(Producto *productos, int cantProductos)
{

    int Stock;
    printf("Ingresar el Stock: ");
    scanf("%d", &Stock);

    int StockEncontrado = 0;

    for (int i = 0; i < cantProductos; i++)
    {
        if (productos[i].stock < Stock)
        {
            StockEncontrado = 1;
            printf("Producto: %s\n", productos[i].NombreProducto);
            printf("Proveedor: %s\n", productos[i].proveedores->Nombre);
        }
    }

    if (StockEncontrado != 1)
    {
        printf("No se encuentra el stock.\n");
    }
}

/*Módulo 2: Calcular el valor total del inventario (cantidad por precio
unitario para cada producto).*/
void CalcularTotal(Producto *productos, int cantProductos)
{

    char NombreProducto[50];
    int cantProducto;

    printf("Ingresar el nombre del producto: ");
    fflush(stdin);
    gets(NombreProducto);

    printf("Ingresar la cantidad de %s a llevar: ");
    fflush(stdin);
    scanf("%d", &cantProducto);

    int Producto = 0;

    for (int i = 0; i < cantProductos; i++)
    {

        if (strcmp(productos[i].NombreProducto, NombreProducto) == 0)
        {

            Producto = 1;
            float Total = productos[i].PrecioUnitario * cantProducto;

            printf("El total a llevar de %s es: %.2f\n", NombreProducto, Total);
        }
    }

    if (Producto != 1)
    {
        printf("No se encontro el producto\n");
    }
}

void LiberarEspacio(Producto *productos, int cantProductos) {

    for (int i = 0; i < cantProductos; i++)
    {
        free(productos[i].proveedores);
    }
    
    free(productos);
}