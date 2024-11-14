#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DatosCoordinador
{
    char *Nombre;
    char *Apellido;
    int Dni;

} typedef DatosCoordinador;
struct Fechas
{
    int FechaSalida;
    int FechaVuelta;
} typedef Fechas;

struct InfoAgencia
{
    char *Destino; 
    DatosCoordinador Coordinador;
    Fechas fechas;
    float CostoViaje;
    int HabitacionesReservadas;
    int *ListaHab;


} typedef InfoAgencia;



void CargarDatosViaje (InfoAgencia *arreglo, int n){

        for (int i = 0; i < n; i++)
        {
        printf("\n--- Cargando datos para el viaje %d ----\n", i + 1);

        // Asignacion de memoria para Destino
        arreglo[i].Destino =(char *) malloc(sizeof(char) * 100);

        printf("Ingrese el Destino: ");
        fflush(stdin);
        gets(arreglo[i].Destino);

        //Asignacion de Memoria y carga de Datos para el nombre y apellido del Coordinador
        arreglo[i].Coordinador.Nombre = (char *) malloc(sizeof(char) * 50);
        arreglo[i].Coordinador.Apellido = (char *) malloc(sizeof(char) * 50);

        printf("\tIngrese el Nombre del Coordinador:\n ");
        fflush(stdin);
        gets(arreglo[i].Coordinador.Nombre);

        printf("\tIngrese el Apellido del Coordinador: \n");
        fflush(stdin);
        gets(arreglo[i].Coordinador.Apellido);

        printf("\tIngrese el DNI del coordinador: \n");
        fflush(stdin);
        scanf("%d", &arreglo[i].Coordinador.Dni);
     
        // Fechas 
    
        printf("Ingrese la Fecha de Salida (AAAAMMDD): ");
        fflush(stdin);
        scanf("%d", &arreglo[i].fechas.FechaSalida);

        printf("Ingrese la Fecha de Vuelta (AAAAMMDD): ");
        fflush(stdin);
        scanf("%d", &arreglo[i].fechas.FechaVuelta);

        // Costo Viaje
        printf("Ingrese el Costo del Viaje: ");
        fflush(stdin);
        scanf("%f", &arreglo[i].CostoViaje);

        // Habitaciones Reservadas 
        printf("Ingrese el numero de Habitaciones reservadas:  ");
        fflush(stdin);
        scanf("%d", &arreglo[i].HabitacionesReservadas);

        // Asignacion de memoria para la lista de habitaciones
        arreglo[i].ListaHab = (int *)malloc(sizeof(int) * arreglo[i].HabitacionesReservadas);

        for (int j = 0; j < arreglo[i].HabitacionesReservadas; j++)
        {
            printf("Ingrese el numero de la habitacion %d: ", j + 1);
            fflush(stdin);
            scanf("%d", &arreglo[i].ListaHab[j]);
        }
        
        }
        

}

void MostrarInfoViaje(InfoAgencia *arreglo, int n) {

    for (int i = 0; i < n; i++)
    {
        printf("\n ------- Viaje ----------\n");
        printf("Destino: %s\n", arreglo[i].Destino);
        printf("Coordinador: \n");
        printf("\t Nombre: %s ", arreglo[i].Coordinador.Nombre);
        printf("\t Apellido: %s\n",arreglo[i].Coordinador.Apellido);
        printf("\n --------- Fechas ------- \n");
        printf("\tFecha de Salida: %d\n", arreglo[i].fechas.FechaSalida);
        printf("\t Fecha de Vuelta: %d\n", arreglo[i].fechas.FechaVuelta);
        printf("\n -------------- Costo del Viaje -----------");
        printf("Costo: %.2f\n", arreglo[i].CostoViaje);
        printf("\n--------- Habitaciones Reservadas --------------");
        printf("Reservadas: %d\n", arreglo[i].HabitacionesReservadas);

    }
    
}

