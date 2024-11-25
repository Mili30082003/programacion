#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------ESTRUCTURAS-----------------*/

struct Paquete
{
    int codigoUnico;
    char Destino[50];
    int Duracion;
    float Precio;
    int plazasDispo;
} typedef Paquete;

struct Cliente
{
    char Nombre[50];
    char telefono[15];

} typedef Cliente;

struct Reserva
{
    Cliente * cliente;
    Paquete  paquetes;
    int cantPlazas;
} typedef Reserva;


/*-----------FUNCIONES-------------------------*/
Reserva * cargarDatos (int * cantReservas);
void BuscarPaquetes(Reserva * reservas, int cantReservas);
void LiberarMemoria();
/*-------------------------------------------*/


void main () {

int cantReserva = 0;

Reserva * reservas = cargarDatos(&cantReserva);




}

Reserva * cargarDatos (int * cantReservas) {

* cantReservas = 2;

Reserva * reservas = malloc(sizeof(Reserva) * (*cantReservas));

Reserva reserva1 = {malloc(sizeof(Cliente) * 2), {0011, "Brasil", 15,12000, 5}, 2};
reserva1.cliente[0] = (Cliente) {"Milagros", "3814499121"};
reserva1.cliente[1] = (Cliente) {"Jungkook", "38145020"};

Reserva reserva2 = {malloc(sizeof(Cliente) * 1), {0215, "Londres", 20, 20255, 6}, 1};
reserva2.cliente[0] = (Cliente) {"Taehyung", "3810220"};

reservas[0] = reserva1;
reservas[1] = reserva2;

return reservas;


}