#include <stdio.h>

//Definicion de estructura
struct Persona // Defino el nuevo tipo de dato 
{
    char Nombre[50]; // Campos de la estructura
    char Apellido[50];
    int dia;
    int mes;
    int anio;
    double dni;

};


/*¿Que es una Estructura? 
|
| --> Es un conjunto de Datos Agrupados por el mismo nombre

*/

void main () {

// Tipos de Datos: 
/*
Simples: int, float, double, caracter
Derivados: arreglo, puntero, estructura
Tipo de datos definidos por los usuarios


Persona: nombre, apellido, fecha de nacimiento, dni 
 */

// Utilizamos el tipo de dato nuevo: 
// Declaracion: 
struct Persona Mili; // Estoy diciendo el tipo de dato

// Operador punto '.': me permite ingresar a los campos de una estructura

printf("Ingrese el nombre: ");
fflush(stdin); // Limpio el buffer
gets(Mili.Nombre);

printf("Ingrese el apellido: ");
fflush(stdin);
gets(Mili.Apellido);

printf("Ingrese el dia de nacimiento: ");
fflush(stdin);
scanf("%d", &Mili.dia);

printf("Ingrese el DNI: ");
fflush(stdin);
scanf("%lf",&Mili.dni);

printf("Los datos de la persona son:\n ");
printf("\t Nombre completo: %s %s\n", Mili.Apellido, Mili.Nombre);
printf("\t Fecha de Nacimiento: %d/-/-\n", Mili.dia);
printf("\t DNI: %lf\n", Mili.dni);




}