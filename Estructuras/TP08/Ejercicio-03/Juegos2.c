#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Juego
{
    char Nombre[50];
    char Genero[30];
    char Plataforma[30];
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
    char Nombre[50];
    int edad;
    int cantCompras;
    Compra *compras;

} typedef Cliente;

Cliente *CargarDatos(int CantidadClientes);

void main()
{
}

Cliente *CargarDatos(int CantClientes)
{
     CantClientes = 3;
     Cliente *clientes = malloc(sizeof(Cliente) * CantClientes);

    Cliente cliente1 = {45122852, "Milagros", 21, 2, malloc(sizeof(Compra) * 2)};
    cliente1.compras[0] = (Compra) {{21, 1, 2024}, 2, malloc(sizeof(Juego) * 2), 0};
    cliente1.compras[0].juegos[0] = (Juego) {"Call of Duty", "Accion", "PlayStation", 1000};
    cliente1.compras[0].juegos[1] = (Juego) {"Lol", "Accion", "PC", 5200};


  


    // Juego juego1 = {"call of duty", "accion", "PlayStation", 15000};
    // Juego juego2 = {"pes", "deporte", "PC", 10000};
    // Juego juego3 = {"Mario bros", "aventura", "Xbox", 20000};
    // Juego juego4 = {"Lol", "accion", "PC", 50000};
    // Juego juego5 = {"Fifa", "deporte", "PlayStation", 12000};

    // Compra compra1 = {{2, 1, 2024}, 0, 2, malloc(sizeof(Juego) * 2)};
    // compra1.juegos[0] = juego1;
    // compra1.juegos[1] = juego2;

    // Compra compra2 = {{7, 1, 2024}, 0, 1, malloc(sizeof(Juego) * 1)};
    // compra1.juegos[0] = juego5;

    // Cliente cliente1 = {12356, "Mili", 18, 2, malloc(sizeof(Compra) * 2)};
    // cliente1.compras[0] = compra1;
    // cliente1.compras[0] = compra2;

    // Compra compra3 = {{8, 1, 2024}, 0, 1, malloc(sizeof(Juego) * 1)};
    // compra1.juegos[0] = juego5;

    // Cliente cliente2 = {45122852, "Gabriel", 21, 1, malloc(sizeof(Compra) * 1)};
    // cliente2.compras[0] = compra3;


    // Compra compra4 = {{9, 1, 2024}, 0, 1, malloc(sizeof(Juego) * 1)};
    // compra4.juegos[0] = juego3;

    // Compra compra5 = {{10, 1, 2024}, 0, 1, malloc(sizeof(Juego) * 1)};
    // compra4.juegos[1] = juego3;
    
    // Cliente cliente3 = {451225, "Luissina", 17, 3, malloc(sizeof(Compra) * 3)};

   
}