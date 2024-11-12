#include <stdio.h>
#include "misFunciones.h"
#define TAMA 2


void main()
{

    char nombre[50];
    char apellido[50];

    Persona personas[TAMA]; // Si necesito representar mas de una persona
                          // por ejemplo, si necesito 10 personas
                          /* hare un arreglo de 10 personas
                          |
                          |---> tengo el objeto 'Persona' entonces      llamare al arreglo : 'personas'
                           */

CargarDatos( personas, TAMA);

mostrarDatos(personas, TAMA);

printf("Ingrese el nombre del empleado que desea ver: ");
fflush(stdin);
gets(nombre);
printf("Ingrese el apellido: ");
fflush(stdin);
gets(apellido);

MostrarDatoEmpleadoxNombre(personas, nombre, apellido, TAMA);




    
}


