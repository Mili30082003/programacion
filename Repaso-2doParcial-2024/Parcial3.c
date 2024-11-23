#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*--------------ESTRUCTURAS----------------------*/
struct FechaVuelo
{
    int dia;
    int mes;
    int anio;
} typedef FechaVuelo;

struct Pasajeros
{
    char Nombre[50];
    char Apellido[50];
    int dni;
    float costoPasaje;
} typedef Pasajeros;

struct Vuelo
{
    int num_vuelo;
    char origen[80];
    char destino[50];
    FechaVuelo fechavuelo;
    int cantAsientos;
    Pasajeros *pasajeros;

} typedef Vuelo;

/*----------------------- FUNCIONES-----------------------------*/
Vuelo *CargarDatos();
void MostrarVuelosConDestinoCordoba(Vuelo *vuelos, int cantVuelos);
void DescontarPasaje(Vuelo *vuelos, int cantVuelos);
void LiberarMemoria(Vuelo *vuelos, int cantVuelos);

/*-----------------------------------------------------------------*/
void main()
{

    Vuelo *vuelos = CargarDatos();
    MostrarVuelosConDestinoCordoba(vuelos, 5);
    DescontarPasaje(vuelos, 5);
    LiberarMemoria(vuelos, 5);
}

Vuelo *CargarDatos()
{

    int cantvuelos = 5;

    Vuelo vuelo1 = {1, "Ezeiza", "Brasil", {18, 11, 2024}, 2, malloc(sizeof(Pasajeros) * 2)};
    vuelo1.pasajeros[0] = (Pasajeros){"Milagros", "Antoni", 4512266, 2500};
    vuelo1.pasajeros[1] = (Pasajeros){"Ivan", "Pineda", 4022233, 6000};

    Vuelo vuelo2 = {2, "Tucuman", "Cordoba Capital", {25, 11, 2024}, 3, malloc(sizeof(Pasajeros) * 3)};
    vuelo2.pasajeros[0] = (Pasajeros){"Jungkook", "Jeon", 44102, 2600};
    vuelo2.pasajeros[1] = (Pasajeros){"Taehyung", "Kim", 122233, 3600};
    vuelo2.pasajeros[2] = (Pasajeros){"Namjoon", "Kim", 256453, 4000};

    Vuelo vuelo3 = {3, "Tucuman", "Cordoba Capital", {26, 11, 2024}, 4, malloc(sizeof(Pasajeros) * 4)};
    vuelo3.pasajeros[0] = (Pasajeros){"Luissina", "Latina", 4512236, 6000};
    vuelo3.pasajeros[1] = (Pasajeros){"Sebastian", "Jimenez", 451223, 5000};
    vuelo3.pasajeros[2] = (Pasajeros){"Gaston", "Garau", 451112, 4500};
    vuelo3.pasajeros[3] = (Pasajeros){"Victoria", "Sanchez", 451113, 7850};

    Vuelo vuelo4 = {4, "Tucuman", "Corea", {12, 11, 2024}, 3, malloc(sizeof(Pasajeros) * 3)};
    vuelo4.pasajeros[0] = (Pasajeros){"SeokJin", "Kim", 451220, 5500};
    vuelo4.pasajeros[1] = (Pasajeros){"Yoongi", "Min", 451339, 4500};
    vuelo4.pasajeros[2] = (Pasajeros){"Jimin", "Park", 45333, 7800};

    Vuelo vuelo5 = {5, "Tucuman", "Buenos Aires", {15, 11, 2024}, 1, malloc(sizeof(Pasajeros) * 1)};
    vuelo5.pasajeros[0] = (Pasajeros){"Rodrigo", "Toledo", 451222, 4513};

    Vuelo *vuelos = malloc(sizeof(Vuelo) * cantvuelos);

    vuelos[0] = vuelo1;
    vuelos[1] = vuelo2;
    vuelos[2] = vuelo3;
    vuelos[3] = vuelo4;
    vuelos[4] = vuelo5;

    return vuelos;
}

void MostrarVuelosConDestinoCordoba(Vuelo *vuelos, int cantVuelos)
{

    for (int i = 0; i < cantVuelos; i++)
    {
        if (strcmp(vuelos[i].origen, "Tucuman") == 0 && strcmp(vuelos[i].destino, "Cordoba Capital") == 0)
        {
            printf("Numero de vuelo: %d\n", vuelos[i].num_vuelo);
            printf("Origen: %s\n", vuelos[i].origen);
            printf("Destino: %s\n", vuelos[i].destino);
            printf("Fecha Vuelo: %d/%d/%d\n", vuelos[i].fechavuelo.dia, vuelos[i].fechavuelo.mes, vuelos[i].fechavuelo.anio);
            printf("Cantidad de Asientos: %d\n", vuelos[i].cantAsientos);
            printf("\n");
        }
    }
}

void DescontarPasaje(Vuelo *vuelos, int cantVuelos)
{

    printf("\n ***** Vuelos ***** \n");
    for (int i = 0; i < cantVuelos; i++)
    {
        for (int j = 0; j < vuelos[i].cantAsientos; j++)
        {
            if (vuelos[i].pasajeros[j].costoPasaje > 5800)
            {
                vuelos[i].pasajeros[j].costoPasaje -= 5;
                printf("Vuelo %d (%s -> %s):\n", vuelos[i].num_vuelo, vuelos[i].origen, vuelos[i].destino);
                printf("   Pasajero: %s %s | Costo Pasaje: %.2f\n", vuelos[i].pasajeros[j].Nombre, vuelos[i].pasajeros[j].Apellido, vuelos[i].pasajeros[j].costoPasaje);
                printf("\n");
            }
        }
    }
}

void LiberarMemoria(Vuelo *vuelos, int cantVuelos)
{

    for (int i = 0; i < cantVuelos; i++)
    {

        // Libero la memoria para los pasajeros del vuelo actual
        free(vuelos[i].pasajeros);

    // libero todos los vuelos
        free(vuelos);
    }
}