#include <stdio.h>

// Estructuras anidadas: 
    struct Fecha
    {
        int dia;
        int mes;
        int anio;
    };
    

struct Persona // Defino el nuevo tipo de dato
{
    char Nombre[50]; // Campos de la estructura
    char Apellido[50];
    struct Fecha fechaNacimiento;
    double dni;
};



void main()
{

    // Inicializar una Estructura
    struct Persona Mili = {"Mili", "Antoni",{30,8,2003},45122852};

    printf("Los datos de la persona son:\n ");
    printf("\t Nombre completo: %s %s\n", Mili.Apellido, Mili.Nombre);
    printf("\t Fecha de Nacimiento: %d/%d/%d\n", Mili.fechaNacimiento.dia, Mili.fechaNacimiento.mes, Mili.fechaNacimiento.anio);
    printf("\t DNI: %0.lf\n", Mili.dni);
}