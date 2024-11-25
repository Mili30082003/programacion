#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*----------------------ESTRUCTURA--------------------------*/
struct Cliente
{
    char RazonSocial[30];
    char telefono[15];
} typedef Cliente;

struct Empleado
{
    char NombreEmpleado[50];
    char ApellidoEmpleado[50];

} typedef Empleado;

struct Pedido
{
    Cliente cliente;
    int cantPedidos;
    Empleado empleado;

} typedef Pedido;

struct Especie
{
    char NombreUnico[50];
    char categoria[50];
    char NombreVulgar[50];
    int stock;
    float precio;
    Pedido *pedidos;
    int cantClientes;
} typedef Especie;

Especie *cargarDatos(int *cantEspecie)
{

    *cantEspecie = 4;

    Especie *especies = malloc(sizeof(Especie) * (*cantEspecie));

    Especie especie1 = {"especie1", "caduca", "Arce rojo", 25, 6000, malloc(sizeof(Pedido) * 3), 3};
    especie1.pedidos[0] = (Pedido){{"BRRS", "3814499121"}, 3, {"Milagros", "Antoni"}};
    especie1.pedidos[1] = (Pedido){{"MRRS", "3814523"}, 4, {"Victor", "Antoni"}};
    especie1.pedidos[2] = (Pedido){{"LRSS", "38145260"}, 5, {"Jungkook", "Jeon"}};

    Especie especie2 = {"especie2", "perenne", "Encina", 30, 7500, malloc(sizeof(Pedido) * 2), 2};
    especie2.pedidos[0] = (Pedido){{"RSSS", "3815240"}, 10, {"Taehyung", "Kim"}};
    especie2.pedidos[1] = (Pedido){{"PRSS", "3810247"}, 2, {"SeokJin", "Kim"}};

    Especie especie3 = {"especie3", "conifera", "Abeto", 35, 8200, malloc(sizeof(Pedido) * 1), 1};
    especie3.pedidos[0] = (Pedido){{"LRSS", "3814027"}, 6, {"Yoongi", "Min"}};

    Especie especie4 = {"especie4", "frutal", "Naranjo", 50, 9000, malloc(sizeof(Pedido) * 3), 3};
    especie4.pedidos[0] = (Pedido){{"MRSS", "3814569"}, 3, {"Jimin", "Park"}};
    especie4.pedidos[1] = (Pedido){{"LRTS", "38145690"}, 5, {"Namjoon", "Kim"}};
    especie4.pedidos[2] = (Pedido){{"PRSS", "38145623"}, 6, {"Rodrigo", "Toledo"}};

    especies[0] = especie1;
    especies[1] = especie2;
    especies[2] = especie3;
    especies[3] = especie4;

    return especies;
}

/* ------------FUNCIONES----------------- */

void MostrarArbolesDisponibles(Especie *especies, int cantEspecie);
void MostrarEspeciesSegunStock(Especie *especies, int cantEspecie);
void MostrarPedidos(Especie *especies, int cantEspecie);
void AgregarPedidos(Especie *especies, int cantEspecie);
void ActualizarStock(Especie *especies, int cantEspecie);
void ActualizarPrecio(Especie *especies, int cantEspecie);
void LiberarEspacio(Especie *especies, int cantEspecie);
/*------------------------------------------*/
void main()
{

    int cantEspecie = 0;
    Especie *especies = cargarDatos(&cantEspecie);
    MostrarArbolesDisponibles(especies, cantEspecie);
    MostrarEspeciesSegunStock(especies, cantEspecie);
    MostrarPedidos(especies, cantEspecie);
    AgregarPedidos(especies, cantEspecie);
    ActualizarStock(especies, cantEspecie);
    ActualizarPrecio(especies, cantEspecie);
    LiberarEspacio(especies, cantEspecie);
}

/*-----------------------------------------------------------------*/

/*  01. Mostrar todos los árboles/especies disponibles*/
void MostrarArbolesDisponibles(Especie *especies, int cantEspecie)
{

    printf("**** ESPECIES *****");
    printf("\n");

    for (int i = 0; i < cantEspecie; i++)
    {
        printf(" - Nombre Cientifico: %s\n", especies[i].NombreUnico);
        printf(" - Categoria: %s\n", especies[i].categoria);
        printf(" - Nombre Vulgar: %s\n", especies[i].NombreVulgar);
        printf(" - Precio: %.2f\n", especies[i].precio);

        printf("\n");
    }
}

/*  02. Mostrar árboles/especies según stock: módulo que muestre los árboles con stock inferior a
 un número dado como dato*/
void MostrarEspeciesSegunStock(Especie *especies, int cantEspecie)
{

    int stock;
    printf("Ingresar stock a buscar: ");
    fflush(stdin);
    scanf("%d", &stock);
    printf("\n");

    int encontrados = 0;
    printf("\nEspecies con stock inferior a %d:\n", stock);
    printf("----------------------------------------------------\n");

    for (int i = 0; i < cantEspecie; i++)
    {

        if (especies[i].stock < stock)
        {
            encontrados++;
            printf("Nombre Vulgar: %s\n", especies[i].NombreVulgar);
            printf("Categoria: %s\n", especies[i].categoria);
            printf("Stock: %d\n", especies[i].stock);
            printf("----------------------------------------------\n");
        }
    }

    if (encontrados == 0)
    {
        printf("No se encontraron especies con stock inferios a %d\n", stock);
    }
}

/*  03. Mostrar todos los pedidos: indicando el monto a cobrar a cada cliente*/
void MostrarPedidos(Especie *especies, int cantEspecie)
{
    printf("\n *** PEDIDOS ***\n");
    for (int i = 0; i < cantEspecie; i++)
    {
        printf("Especie: %s\n", especies[i].NombreVulgar);
        for (int j = 0; j < especies[i].cantClientes; j++)
        {

            float totalCobro = especies[i].precio * especies[i].pedidos[j].cantPedidos;

            printf("Razon Social: %s\n", especies[i].pedidos[j].cliente.RazonSocial);
            printf("Telefono: %s\n", especies[i].pedidos[j].cliente.telefono);
            printf("Empleado: %s %s\n", especies[i].pedidos[j].empleado.NombreEmpleado, especies[i].pedidos[j].empleado.ApellidoEmpleado);
            printf("Total A Pagar: %.2f\n", totalCobro);
            printf("\n");
        }
    }
}

/* Agregar pedidos a una especie: si la especie aún no cuenta con pedidos. Controlar si hay
 stock disponible, caso contrario informar con un mensaje*/
void AgregarPedidos(Especie *especies, int cantEspecie)
{

    char NombreEspecie[50];
    int cantPedido;

    printf("Ingrese el Nombre Vulgar de la especie: ");
    fflush(stdin);
    gets(NombreEspecie);

    printf("Ingrese la cantidad de pedidos: ");
    fflush(stdin);
    scanf("%d", &cantPedido);

    for (int i = 0; i < cantEspecie; i++)
    {
        if (strcmp(especies[i].NombreVulgar, NombreEspecie) == 0)
        {
            if (especies[i].stock >= cantPedido)
            {
                especies[i].pedidos += cantPedido;
                especies[i].stock -= cantPedido;
                printf("Pedido agregado exitosamente\n");
                printf("Nueva Cantidad de pedidos: %d\n", especies[i].pedidos->cantPedidos);
            }
        }
    }
}

/*  05. Actualizar stock de una especie: en caso de mermar controlar que el valor ingresado no sea
 inferior a los pedidos vigentes en caso de existir*/
void ActualizarStock(Especie *especies, int cantEspecie)
{

    char NombreEspecie[50];
    int cantPedidos;

    printf("Ingresar el Nombre Vulgar de la Especie: ");
    fflush(stdin);
    gets(NombreEspecie);

    printf("Ingrese la cantidad de Pedidos a agregar: ");
    fflush(stdin);
    scanf("%d", &cantPedidos);

    for (int i = 0; i < cantEspecie; i++)
    {
        if (strcmp(especies[i].NombreVulgar, NombreEspecie) == 0)
        {
            especies[i].stock -= cantPedidos;
            if (especies[i].stock < cantPedidos)
            {
                printf("No se pudo reducir el stock");
            }
            else
            {

                printf("Stock Actualizado. Nuevo Stock: %d\n", especies[i].stock);
            }
        }
    }
}

// 06. Actualizar el precio de una especie
void ActualizarPrecio(Especie *especies, int cantEspecie)
{

    char NombreEspecie[50];
    float Precio;

    printf("Ingrese el Nombre Vulgar de la especie: ");
    fflush(stdin);
    gets(NombreEspecie);

    printf("Ingrese el Nuevo Precio: ");
    fflush(stdin);
    scanf("%f", &Precio);

    for (int i = 0; i < cantEspecie; i++)
    {
        if (strcmp(especies[i].NombreVulgar, NombreEspecie) == 0)
        {

            especies[i].precio = Precio;
        }

        // Muestro el final de las especies
        printf("Especie: %s | Precio: %.2f\n", especies[i].NombreVulgar, especies[i].precio);
    }
}

void LiberarEspacio(Especie *especies, int cantEspecie) {

    for (int i = 0; i < cantEspecie; i++)
    {
        free(especies[i].pedidos);
    }
    free(especies);
}