#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*------------------ESTRUCTURAS-----------------------*/
struct FechaCaducidad
{
    int dia;
    int mes;
    int anio;
} typedef FechaCaducidad;

struct Cliente
{
    char Nombre[50];
    int cuil;
    char mail[30];
    int cantSucursales;

} typedef Cliente;

struct Producto
{
    char NombreProducto[50];
    char categoria[50];
    float PrecioProducto;
    FechaCaducidad fecha;
    int stock;
    int cantClientes;
    Cliente *clientes;

} typedef Producto;

/*--------------FUNCIONES------------------------ */

Producto *cargarDatos();
void ClientesBrabante(Producto *productos, int cantProductos);
void AumentarPrecio(Producto *productos, int cantProductos);
void LiberarEspacio(Producto *productos, int cantProductos);

/*------------------------------------------------------------------*/
void main()
{

    Producto *productos = cargarDatos();
    int opcion;

    do
    {
        printf("Menu\n");
        printf("\t 1 - Mostrar Cliente Brabante\n");
        printf("\t 2 - Aumentar precio segun stock\n");
        printf("\t 3 - Salir del programa\n");
        printf("Elegir opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            ClientesBrabante(productos, 5);
            break;
        case 2:
            AumentarPrecio(productos, 5);
            break;
        case 3:
            printf("Saliendo...\n");
            break;
        }
    } while (opcion != 3);
}
/*------------------------------------------------------------------------------------*/

Producto *cargarDatos()
{

    int cantProductos = 5;

    Producto Coca = {"CocaCola", "gaseosa", 2500, {25, 11, 2024}, 200, 5, malloc(sizeof(Cliente) * 5)};
    Coca.clientes[0] = (Cliente){"Milagros", 2024556, "miliantoni@gmail.com", 2};
    Coca.clientes[1] = (Cliente){"Sebastian", 2788546, "sebastian@gmail.com", 1};
    Coca.clientes[2] = (Cliente){"Sebastian", 2788546, "sebastian@gmail.com", 1};
    Coca.clientes[3] = (Cliente){"Gaston", 2788546, "sebastian@gmail.com", 2};
    Coca.clientes[4] = (Cliente){"Gaston", 2788546, "sebastian@gmail.com", 2};

    Producto brabante = {"Brabante", "cerveza", 6500, {28, 11, 2024}, 300, 5, malloc(sizeof(Cliente) * 5)};
    brabante.clientes[0] = (Cliente){"Julieta", 2024556, "miliantoni@gmail.com", 3};
    brabante.clientes[1] = (Cliente){"Gaston", 2788546, "sebastian@gmail.com", 2};
    brabante.clientes[2] = (Cliente){"Sebastian", 2788546, "sebastian@gmail.com", 1};
    brabante.clientes[3] = (Cliente){"Gaston", 2788546, "sebastian@gmail.com", 2};
    brabante.clientes[4] = (Cliente){"Victor", 2788546, "sebastian@gmail.com", 2};

    Producto Sprite = {"Sprite", "gaseosa", 1500, {30, 11, 2024}, 205, 5, malloc(sizeof(Cliente) * 5)};
    Sprite.clientes[0] = (Cliente){"Jose", 275552, "Julieta@gmail.com"};
    Sprite.clientes[1] = (Cliente){"Gaston", 2788546, "sebastian@gmail.com", 2};
    Sprite.clientes[2] = (Cliente){"Gaston", 2788546, "sebastian@gmail.com", 2};
    Sprite.clientes[3] = (Cliente){"Gaston", 2788546, "sebastian@gmail.com", 2};
    Sprite.clientes[4] = (Cliente){"Gaston", 2788546, "sebastian@gmail.com", 2};

    Producto Smirnoff = {"Smirnoff", "Bebidas Blancas", 5000, {1, 12, 2024}, 400, 5, malloc(sizeof(Cliente) * 5)};
    Smirnoff.clientes[0] = (Cliente){"Gabriel", 2745522, "gabriel@gmail.com", 1};
    Smirnoff.clientes[1] = (Cliente){"Rodrigo", 2745522, "rodrigo@gmail.com", 3};
    Smirnoff.clientes[2] = (Cliente){"Rodrigo", 2745522, "rodrigo@gmail.com", 4};
    Smirnoff.clientes[3] = (Cliente){"Rodrigo", 2745522, "rodrigo@gmail.com", 1};
    Smirnoff.clientes[4] = (Cliente){"Rodrigo", 2745522, "rodrigo@gmail.com", 2};

    Producto Toro = {" vino Toro", "vino", 3000, {8, 12, 2024}, 302, 5, malloc(sizeof(Cliente) * 5)};
    Toro.clientes[0] = (Cliente){"Gabriel", 2745522, "gabriel@gmail.com", 2};
    Toro.clientes[1] = (Cliente){"Rodrigo", 2745522, "rodrigo@gmail.com", 3};
    Toro.clientes[2] = (Cliente){"Rodrigo", 2745522, "rodrigo@gmail.com", 4};
    Toro.clientes[3] = (Cliente){"Rodrigo", 2745522, "rodrigo@gmail.com", 5};
    Toro.clientes[4] = (Cliente){"Rodrigo", 2745522, "rodrigo@gmail.com", 2};

    Producto *productos = malloc(sizeof(Producto) * 5);

    productos[0] = Coca;
    productos[1] = brabante;
    productos[2] = Sprite;
    productos[3] = Smirnoff;
    productos[4] = Toro;

    return productos;
}

/*
Módulo para listar a los clientes que compran cerveza Brabante
y que tengan más de 2 sucursales. */
void ClientesBrabante(Producto *productos, int cantProductos)
{

    printf("\n ******** Clientes Brabante ************\n");

    for (int i = 0; i < cantProductos; i++)
    {
        for (int j = 0; j < productos[i].cantClientes; j++)
        {
            if (strcmp(productos[i].NombreProducto, "Brabante") == 0 && productos[i].clientes[j].cantSucursales > 2)
            {
                printf("Cliente: %s\n", productos[i].clientes[j].Nombre);
                printf("Cuil: %d\n", productos[i].clientes[j].cuil);
                printf("Mail: %s\n", productos[i].clientes[j].mail);
                printf("Cantidad de sucursales: %d\n", productos[i].clientes[j].cantSucursales);
            }
        }
    }
}

void AumentarPrecio(Producto *productos, int cantProductos)
{
    printf("\n ********* Aumentar Precio Segun Stock ***********\n");
    for (int i = 0; i < cantProductos; i++)
    {
        if (productos[i].stock < 300)
        {
            productos[i].PrecioProducto *= 1.10;
        }

        printf("\t Nombre del producto: %s\n", productos[i].NombreProducto);
        printf("\t Precio: $%2.f\n", productos[i].PrecioProducto);
        printf("\t Stock: %d\n", productos[i].stock);
    }
}

void LiberarEspacio(Producto * productos, int cantProductos)
{

    for (int i = 0; i < cantProductos; i++)
    {

        free(productos[i].clientes);

        free(productos);
    }
}