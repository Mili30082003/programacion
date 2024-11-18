#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Juego
{
    char *Nombre;
    char *Genero;
    char *Plataforma;
    float Precio;
} typedef Juego;

struct FechaCompra
{
    int dia;
    int mes;
    int anio;
} typedef FechaCompra;

struct Compra
{
    FechaCompra fechas;
    int CantJuegosComprados;
    Juego *juegos;
    int PuntosObtenidosCompra;

} typedef Compra;

struct Cliente
{
    int DNI;
    char *Nombre;
    int edad;
    int cantCompras;
    Compra *compras;

} typedef Cliente;

void CargarCliente(Cliente *clientes, int cantClientes)
{

    for (int i = 0; i < cantClientes; i++)
    {
        clientes[i].Nombre = malloc(sizeof(char) * 50);

        printf("\nIngresar el DNI del cliente: ");
        fflush(stdin);
        scanf("%d", &clientes[i].DNI);
        printf("'\nNombre: ");
        fflush(stdin);
        gets(clientes[i].Nombre);
        printf("\nEdad: ");
        fflush(stdin);
        scanf("%d", &clientes[i].edad);

        printf("\nCantidad de Compras: \n ");
        scanf("%d", &clientes[i].cantCompras);

        clientes[i].compras = malloc(sizeof(Compra) * clientes[i].cantCompras);

        for (int j = 0; j < clientes[i].cantCompras; j++)
        {

            printf("\nFecha de Compra: ");
            scanf("%d %d %d", &clientes[i].compras[j].fechas.dia,
                  &clientes[i].compras[j].fechas.mes,
                  &clientes[i].compras[j].fechas.anio);

            printf("Numero de Juegos comprados:  ");
            scanf("%d", &clientes[i].compras[j].CantJuegosComprados);

            // Asignacion Dinamica para los Juegos
            clientes[i].compras[j].juegos = malloc(sizeof(Juego) * clientes[i].compras[j].CantJuegosComprados);

            float totalCompra = 0; // Para Calcular los puntos

            for (int k = 0; k < clientes[i].compras[j].CantJuegosComprados; k++)
            {
                clientes[i].compras[j].juegos[k].Nombre = malloc(sizeof(char) * 50);
                clientes[i].compras[j].juegos[k].Genero = malloc(sizeof(char) * 30);
                clientes[i].compras[j].juegos[k].Plataforma = malloc(sizeof(char) * 20);

                printf("\n Nombre del Juego %d: ", k + 1);
                getchar();
                fgets(clientes[i].compras[j].juegos[k].Nombre, 50, stdin);

                printf("\n Genero del Juego: ");
                getchar();
                fgets(clientes[i].compras[j].juegos[k].Genero, 30, stdin);

                printf("\n Plataforma del Juego: ");
                getchar();
                fgets(clientes[i].compras[j].juegos[k].Plataforma, 20, stdin);

                printf("\n Precio del Juego: ");
                fflush(stdin);
                scanf("%f", &clientes[i].compras[j].juegos[k].Precio);

                totalCompra += clientes[i].compras[j].juegos[k].Precio;
            }

            // Calcular los puntos de la compra
            clientes[i].compras[j].PuntosObtenidosCompra = totalCompra / 10000;
        }
    }
}

void CompraClienteJoven(Cliente *clientes, int cantclientes)
{
    int edadMinima = 9999; // Inicializo con un valor alto para encontrar el minimo
    // se inicializa con un valor alto porque quiero encontrar la edad mas baja.
    // Este valor es arbitriario, pero debe ser suficientemente grande para que cualquier edad del cliente sea mas baja que este valor

    int indiceClienteJoven = -1;
    // Se inicializa con -1 , un valor que indica que aun no hemos encontrado al cliente mas joven. si encontramos un cliente joven, este indice se actualizara con la posicion del cliente en el arreglo
    for (int i = 0; i < cantclientes; i++)
    {
        if (clientes[i].cantCompras > 0) // solo considero a los clientes que hicieron compras
        {
            if (clientes[i].edad < edadMinima)
            {
                edadMinima = clientes[i].edad;
                indiceClienteJoven = i;
            }
        }
    }

    if (indiceClienteJoven != -1)
    {
        printf("\n El cliente mas joven es: \n");
        printf("DNI: %d\n", clientes[indiceClienteJoven].DNI);
        printf("Nombre: %s\n", clientes[indiceClienteJoven].Nombre);
        printf("Edad: %d\n", clientes[indiceClienteJoven].edad);
    }
    else
    {
        printf("\n No hay clientes que hayan realizado compras. \n");
    }
}


void ClienteConMasCompras (Cliente * clientes, int cantclientes) {
    int MaxCompra = 0;
    int indiceCliente = -1;

    for (int i = 0; i < cantclientes; i++)
    {
        if (clientes[i].cantCompras > MaxCompra)
        {
            MaxCompra = clientes[i].cantCompras;
            indiceCliente = i;
        }
        
     
        }

        if (indiceCliente != -1)
        {
            printf("\n Cliente con mas Compras realizadas: \n");
            printf("\t - Nombre: %s\n", clientes[indiceCliente].Nombre);
            printf("\t - DNI: %d\n", clientes[indiceCliente].DNI);
        }
        
        
    }
    

void ClienteConMayorCantJuegos (Cliente * clientes, int cantClientes) {

int MayorCantJuegos = 0;
int indiceMayorJuegos = -1;

    for (int i = 0; i < cantClientes; i++)
    {
       int TotalJuegos = 0;
       for (int j = 0; j < clientes[i].cantCompras ; i++)
       {
        TotalJuegos += clientes[i].compras[j].CantJuegosComprados;
        
       }
       if (TotalJuegos > MayorCantJuegos)
       {
        MayorCantJuegos = TotalJuegos;
        indiceMayorJuegos = i;
       }
       
    }
    
    if (indiceMayorJuegos != -1)
    {
        printf("\n El cliente que ha comprado la mayor cantidad de juegos es: \n");
        printf("Dni: %d\n", clientes[indiceMayorJuegos].DNI);
        printf("Nombre: %s\n", clientes[indiceMayorJuegos].DNI);
        printf("Total de Juegos comprados: %d\n", MayorCantJuegos);
    } else {
        printf("No hay clientes que hayan realizado compras. \n");
    }
    

}


void main()
{

    int cantidadClientes;
    printf("Ingresar el numero de clientes: ");
    scanf("%d", &cantidadClientes);

    Cliente *clientes = malloc(sizeof(Cliente) * cantidadClientes);

    CargarCliente(clientes, cantidadClientes);
    CompraClienteJoven(clientes, cantidadClientes);

    printf("\n");
    ClienteConMasCompras(clientes, cantidadClientes);

    printf("\n");
    ClienteConMayorCantJuegos(clientes, cantidadClientes);
}