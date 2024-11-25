#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*---------------ESTRUCTURAS-----------------------*/
struct Venta
{
    char NombreCliente[50];
    char telefono[15];
    int cantProducto;
} typedef Venta;

struct Producto
{
    int codigoUnico;
    char Nombre[50];
    char Categoria[80];
    float PrecioUnidad;
    int stock;
    int cantidadVentas;
    Venta *ventas;
} typedef Producto;

/*----------------------FUNCIONES-----------------------*/

Producto *CargarDatos(int *cantProductos);
void MostrarProductos(Producto *productos, int cantProductos);
void MostrarProductoStock(Producto *productos, int cantProductos);
void RegistrarVenta(Producto *productos, int cantProductos);
void MostrarVenta(Producto *productos, int cantProductos);
void ActualizarStock(Producto *productos, int cantProductos);
void ActualizarPrecio(Producto *productos, int cantProductos);
void liberarMemoria(Producto * productos, int cantProductos);
/*-----------------------------------------------------*/
void main()
{
    int cantProductos = 0;
    Producto *productos = CargarDatos(&cantProductos);

    int opcion;
    do
    {
        printf("MENU\n");
        printf("\t 1 - Mostrar productos\n");
        printf("\t 2 - Mostrar Prodcutos segun Stock\n");
        printf("\t 3 - Registrar Venta\n");
        printf("\t 4 - Mostrar Ventas\n");
        printf("\t 5 - Actualizar Stock\n");
        printf("\t 6 - Actualizar Precio\n ");
        printf("\t 7 - SALIR\n");
        printf("Elegir una opcion : ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:

            MostrarProductos(productos, cantProductos);
            break;
        case 2:
            MostrarProductoStock(productos, cantProductos);
            break;
        case 3:
            RegistrarVenta(productos, cantProductos);
            break;
        case 4:

            MostrarVenta(productos, cantProductos);
            break;
        case 5:

            ActualizarStock(productos, cantProductos);
            break;
        case 6:

            ActualizarPrecio(productos, cantProductos);
            break;
        case 7:

            printf("Saliendo...\n");
            break;
        }

    } while (opcion != 7);
    
    liberarMemoria(productos, cantProductos);
}
/*---------------------------------------------------*/
Producto *CargarDatos(int *cantProductos)
{

    *cantProductos = 4;

    Producto *productos = malloc(sizeof(Producto) * (*cantProductos));

    Producto producto1 = {0023, "Martillo", "Herramientas", 6000, 10, 3, malloc(sizeof(Venta) * 3)};
    producto1.ventas[0] = (Venta){"Milagros", "3814499121", 1};
    producto1.ventas[1] = (Venta){"Jungkook", "381449923", 2};
    producto1.ventas[2] = (Venta){"Taehyung", "381445623", 1};

    Producto producto2 = {0012, "Pintura Rosa", "Pinturas", 5000, 12, 2, malloc(sizeof(Venta) * 2)};
    producto2.ventas[0] = (Venta){"Namjoon", "38156920", 2};
    producto2.ventas[1] = (Venta){"SeokJin", "38156920"}, 3;

    Producto producto3 = {005, "Cemento", "Material Construccion", 10000, 10, 3, malloc(sizeof(Venta) * 3)};
    producto3.ventas[0] = (Venta){"Yoongi", "38144952", 2};
    producto3.ventas[1] = (Venta){"Jimin", "38144560", 1};
    producto3.ventas[2] = (Venta){"Hoseok", "38145931", 3};

    Producto producto4 = {0023, "Ladrillos", "Material Construccion", 120300, 70, 1, malloc(sizeof(Venta) * 1)};
    producto4.ventas[0] = (Venta){"Rodrigo", "38145901", 100};

    productos[0] = producto1;
    productos[1] = producto2;
    productos[2] = producto3;
    productos[3] = producto4;

    return productos;
}

/* 1. Mostrar todos los productos disponibles*/
void MostrarProductos(Producto *productos, int cantProductos)
{

    printf("*** PRODUCTOS ***\n");

    for (int i = 0; i < cantProductos; i++)
    {
        printf("Producto: %s\n", productos[i].Nombre);
        printf("Codigo: %d\n", productos[i].codigoUnico);
        printf("Categoria: %s\n", productos[i].Categoria);
        printf("Precio por Unidad: %.2f\n", productos[i].PrecioUnidad);
        printf("Stock: %d\n", productos[i].stock);
        printf("\n");
    }
}

/*  2. Mostrar productos con stock inferior a un valor ingresado */
void MostrarProductoStock(Producto *productos, int cantProductos)
{

    int stock;
    printf("Ingresar Stock a buscar: ");
    fflush(stdin);
    scanf("%d", &stock);

    int StockEncontrado = 0;

    for (int i = 0; i < cantProductos; i++)
    {
        if (productos[i].stock < stock)
        {
            StockEncontrado = 1;
            printf("Producto: %s\n", productos[i].Nombre);
            printf("Codigo: %d\n", productos[i].codigoUnico);
            printf("Categoria: %s\n", productos[i].Categoria);
            printf("Stock: %d\n", productos[i].stock);
            printf("------------------------\n");
        }
    }

    if (!StockEncontrado)
    {
        printf("No se encontro el stock menor a  : %d\n", stock);
    }
}

/* 3. Registrar una venta (controlando el stock disponible).*/
void RegistrarVenta(Producto *productos, int cantProductos)
{

    char NombreProducto[50];
    printf("Ingresar producto: ");
    fflush(stdin);
    gets(NombreProducto);

    int ProductoEncontrado = 0;
    for (int i = 0; i < cantProductos; i++)
    {
        if (strcmp(productos[i].Nombre, NombreProducto) == 0)
        {
            ProductoEncontrado = 1;

            for (int j = 0; j < productos[i].cantidadVentas; j++)
            {
                if (productos[i].stock > 0)
                {

                    Venta nuevaVenta;

                    printf("Ingresar Nombre: ");
                    fflush(stdin);
                    gets(nuevaVenta.NombreCliente);
                    printf("Ingresar Telefono: ");
                    fflush(stdin);
                    gets(nuevaVenta.telefono);
                    printf("Ingresar cantidad: ");
                    fflush(stdin);
                    scanf("%d", &nuevaVenta.cantProducto);

                    productos[i].ventas = realloc(productos[i].ventas, sizeof(Venta) * productos[i].cantidadVentas + 1);

                    productos[i].cantidadVentas++;
                    productos[i].stock -= cantProductos;

                    printf("Venta Registrada: \n");
                    printf("\n ------------------\n");

                    printf("Nombre Cliente: %s\n", nuevaVenta.NombreCliente);
                    printf("Telefono: %s\n", nuevaVenta.telefono);

                    float Total = productos[i].PrecioUnidad * cantProductos;
                    printf("Total a Pagar: %.2f\n", Total);

                    printf("\n ----------------------------\n");

                    return;
                }
                else
                {
                    printf("No se pudo registrar la venta por falta de stock \n");
                }
            }
        }
    }

    if (!ProductoEncontrado)
    {
        printf("No se encontro el producto\n");
    }
}

void MostrarVenta(Producto *productos, int cantProductos)
{

    printf("*** VENTAS ***\n");
    for (int i = 0; i < cantProductos; i++)
    {
        for (int j = 0; j < productos[i].cantidadVentas; j++)
        {

            float total = productos[i].PrecioUnidad * productos[i].ventas[j].cantProducto;
            printf("Cliente: %s\n", productos[i].ventas[j].NombreCliente);
            printf("Telefono: %s\n", productos[i].ventas[j].telefono);
            printf("Cantidad : %d\n", productos[i].ventas[j].cantProducto);
            printf("Total a pagar: %.2f\n", total);
            printf("\n");
        }
    }
}
/* 5. Actualizar el stock de un producto*/
void ActualizarStock(Producto *productos, int cantProductos)
{

    int stock;
    char NombreProducto[50];
    printf("Ingresar Producto: ");
    fflush(stdin);
    gets(NombreProducto);

    printf("Ingresar Stock: ");
    fflush(stdin);
    scanf("%d", &stock);

    int ProductoEncontrado = 0;

    for (int i = 0; i < cantProductos; i++)
    {
        if (strcmp(productos[i].Nombre, NombreProducto) == 0)
        {
            ProductoEncontrado = 1;
            productos[i].stock += stock;
            printf("Nuevo stock de '%s' es: %d\n", NombreProducto, productos[i].stock);
        }
    }

    if (!ProductoEncontrado)
    {
        printf("No se pudo encontrar el producto\n");
    }
}
/* 6. Actualizar el precio de un producto.*/
void ActualizarPrecio(Producto *productos, int cantProductos)
{

    char NombreProducto[50];
    printf("Ingresar el Producto: ");
    fflush(stdin);
    gets(NombreProducto);

    float precio;
    printf("Ingresar el nuevo precio: ");
    fflush(stdin);
    scanf("%f", &precio);

    int Encontrado = 0;

    for (int i = 0; i < cantProductos; i++)
    {
        if (strcmp(productos[i].Nombre, NombreProducto) == 0)
        {
            Encontrado = 1;

            productos[i].PrecioUnidad = precio;

            printf("El nuebo precio del producto %s es: %.2f\n", NombreProducto, productos[i].PrecioUnidad);
        }
    }

    if (!Encontrado)
    {
        printf("No se pudo encontrar el producto\n");
    }
}

void liberarMemoria(Producto * productos, int cantProductos) {
    for (int i = 0; i < cantProductos; i++)
    {
        free(productos[i].ventas);
    }
    free(productos);
    
}