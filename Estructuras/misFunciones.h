#include <stdio.h>
#include <string.h>

struct Fecha
{
    int dia;
    int mes;
    int anio;
} typedef Fecha; // Fecha sera un sinonimo de struct Fecha

struct Persona // Defino el nuevo tipo de dato
{
    char Nombre[50]; // Campos de la estructura
    char Apellido[50];
    struct Fecha fechaAlta;
    int dni;
    float sueldo;
} typedef Persona;

void CargarDatos(Persona arreglo[], int n)
{

    for (int i = 0; i < n; i++)
    {

        printf("Ingrese el empleado numero '%d'\n", i + 1);
        printf("\tIngrese el nombre: ");
        fflush(stdin); // Limpio el buffer
        gets(arreglo[i].Nombre);

        printf("\tIngrese el apellido: ");
        fflush(stdin);
        gets(arreglo[i].Apellido);

        printf("\tIngrese el dia de nacimiento: ");
        fflush(stdin);
        scanf("%d", &arreglo[i].fechaAlta.dia);

        printf("\tIngrese el DNI: ");
        fflush(stdin);
        scanf("%lf", &arreglo[i].dni);

        arreglo[i].sueldo = 500000;
    }
}

void mostrarDatos(Persona arreglo[], int n)
{

    for (int i = 0; i < n; i++)
    {

        printf("Empleado nro: %d\n ", i + 1);
        printf("\t - Nombre completo: %s %s\n", arreglo[i].Apellido, arreglo[i].Nombre);
        printf("\t - Fecha de Nacimiento: %d/-/-\n", arreglo[i].fechaAlta.dia);
        printf("\t - DNI: %d || Sueldo: %.2f\n", arreglo[i].dni, arreglo[i].sueldo);
    }
}

void mostrarEmpleado(Persona empleado)
{
    printf("\t - Nombre completo: %s %s\n", empleado.Apellido, empleado.Nombre);
    printf("\t - Fecha de Nacimiento: %d/-/-\n", empleado.fechaAlta.dia);
    printf("\t - DNI: %d || Sueldo: %.2f\n", empleado.dni, empleado.sueldo);
}

void MostrarDatoEmpleadoxNombre(Persona arreglo[], char *nombre, char *apellido, int n ){

    for (int i = 0; i < n; i++)
    {
        if (strcmp(arreglo[i].Nombre,nombre)==0 && strcmp(arreglo[i].Apellido,apellido)==0)
        {
            mostrarEmpleado(arreglo[i]);
            break;
        }
        
    }
    
}