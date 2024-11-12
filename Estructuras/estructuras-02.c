#include <stdio.h>


struct Persona // Defino el nuevo tipo de dato 
{
    char Nombre[50]; // Campos de la estructura
    char Apellido[50];
    int dia;
    int mes;
    int anio;
    double dni;

};



void main()
{

    // Inicializar una Estructura
    struct Persona Mili = {"Mili", "Antoni",30,8,2003,45122852};

    printf("Los datos de la persona son:\n ");
    printf("\t Nombre completo: %s %s\n", Mili.Apellido, Mili.Nombre);
    printf("\t Fecha de Nacimiento: %d/%d/%d\n", Mili.dia, Mili.mes, Mili.anio);
    printf("\t DNI: %0.lf\n", Mili.dni);
}