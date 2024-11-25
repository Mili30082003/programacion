#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ----------- ESTRUCTURAS -----------------*/
struct FechaInscripcion
{
    int dia;
    int mes;
    int anio;
} typedef FechaInscripcion;

struct Miembro
{
    char Nombre[50];
    int edad;
    char telefono[15];
    FechaInscripcion fechainscripcion;

} typedef Miembro;

struct Plan
{
    char NombrePlan[30];
    float Precio;

} typedef Plan;

struct FechaPago
{
    int dia;
    int mes;
    int anio;
} typedef FechaPago;

struct Pago
{
    Miembro * miembros;
    int cantMiembros;
    FechaPago fechapago;
    Plan plan;


} typedef Pago;

/* ------------ FUNCIONES ------------------*/

Pago * CargarDatos(int * cantPagos);

/*-----------------------------------------*/

void main () {





}

/*--------------------------------------------------*/

Pago * CargarDatos(int * cantPagos) {

    * cantPagos = 4;
    Pago * pagos = malloc(sizeof(Pago) * (*cantPagos));

    Pago pago1 = {malloc(sizeof(Miembro) * 2), 2, {25, 11, 2024}, {"Mensual", 6500}};
    pago1.miembros[0] = (Miembro) {"Milagros", 21, "3814499121", {25, 10, 2024}};
    pago1.miembros[1] = (Miembro) {"Rodrigo", 22, "3814023", {25,10,2024}};
    p


}