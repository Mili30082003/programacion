#include <stdio.h>

/* Operaciones que se pueden realizar con las estructuras:

- Se pueden asignar entre ellas:
    struct Persona persona1 = {.....};
    struct Persona persona2 = persona1;

- Acceder a sus campos y tambien se puede trabajar con esos campos:
      printf("\t Nombre completo: %s %s\n", Mili.Apellido, Mili.Nombre);

 - Se pueden usar las estructuras como argumento en una funcion:

   ----> La estructura completa

    ---> Estructura por partes (es decir, pasar campos de la estructura como argumento de funcion)

    ---> Una funcion puede retornar un tipo de struct

    ---> Puedo apuntar a una estructura o tomar su direccion de memoria



 */

// Estructuras anidadas:
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
    struct Fecha fechaNacimiento;
    double dni;
    float sueldo;
} typedef Persona;

// -----------------------------------------------------------------

Persona cargarDatos();

void MostrarDatos(Persona persona);

void ModificarSueldo(float *sueldoPersona, int porcentaje);


// --------------------------------------------------------------------



void main()
{

    // Inicializar una Estructura
    Persona Mili = cargarDatos();

    MostrarDatos(Mili);

    //otraFuncion(Mili.fechaNacimiento) // si necesito como parametro un dato de una estructura
    

    ModificarSueldo(&Mili.sueldo,50);
  
      printf("\n");

    MostrarDatos(Mili);
}




// -------------------------------------------------------------------

Persona cargarDatos()
{

    Persona persona;

    printf("Ingrese el nombre: ");
    fflush(stdin); // Limpio el buffer
    gets(persona.Nombre);

    printf("Ingrese el apellido: ");
    fflush(stdin);
    gets(persona.Apellido);

    printf("Ingrese el dia de nacimiento: ");
    fflush(stdin);
    scanf("%d", &persona.fechaNacimiento.dia);

    printf("Ingrese el DNI: ");
    fflush(stdin);
    scanf("%lf", &persona.dni);

    persona.sueldo = 50000; // Inicializo el valor

    return persona;
}


void MostrarDatos(Persona persona)
{

    printf("Los datos de la persona son:\n ");
    printf("\t Nombre completo: %s %s\n", persona.Apellido, persona.Nombre);
    printf("\t Fecha de Nacimiento: %d/-/-\n", persona.fechaNacimiento.dia);
    printf("\t DNI: %0.lf || Sueldo: %.2f\n", persona.dni, persona.sueldo);
}

void ModificarSueldo(float *sueldoPersona, int porcentaje) {

    float variacionSueldo = ((*sueldoPersona)*porcentaje)/100;

    *sueldoPersona = *sueldoPersona + variacionSueldo;
    // Ingreso la direccion de memoria 
    // Tomo el valor que tiene dentro
    // a ese valor le calculo un porcentaje


}