#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------ESTRUCTURAS-----------------------------*/
struct Carrera
{
    char nombreCarrera[80];
    int anioIngreso;
} typedef Carrera;

struct Estudiante
{
    char NombreEstudiante[50];
    int edad;
    float Promedio;
    Carrera carrera;
    
} typedef Estudiante;

/*-----------------FUNCIONES---------------------------*/

Estudiante * cargarDatos(int * cantEstudiantes);
void MostrarMayorPromedio(Estudiante * estudiantes, int cantEstudiantes);
void MostrarAnioIngre(Estudiante * estudiantes, int cantEstudiantes);
void LiberarMemoria (Estudiante * estudiantes, int cantEstudiantes);
/*-----------------------------------------------*/

void main () {

int cantEstudiantes = 0;
Estudiante * estudiantes = cargarDatos(&cantEstudiantes);
MostrarMayorPromedio(estudiantes, cantEstudiantes);
MostrarAnioIngre(estudiantes, cantEstudiantes);


}
 // Incializo Datos
Estudiante * cargarDatos(int * cantEstudiantes) {

    *cantEstudiantes = 3;

    Estudiante * estudiantes = malloc(sizeof(Estudiante) * (* cantEstudiantes));

    Estudiante estudiante1 = {"Milagros", 21, 8.9, {"Programador Universitario", 2023}};

    Estudiante estudiante2 = {"Jungkook", 27, 10.0, {"Cine", 2019}};

    Estudiante estudiante3 = {"Taehyung", 25, 5.0, {"Ing. Industrial", 2019}};

    estudiantes[0] = estudiante1;
    estudiantes[1] = estudiante2;
    estudiantes[2] = estudiante3;


    return estudiantes;

}

void MostrarMayorPromedio(Estudiante * estudiantes, int cantEstudiantes) {
    float MayorPromedio = estudiantes[0].Promedio;

    int indicePromedio = 0;

   for (int i = 0; i < cantEstudiantes; i++)
   {
        if (estudiantes[i].Promedio > MayorPromedio)
        {
            MayorPromedio = estudiantes[i].Promedio;
            indicePromedio = i;
              
        }
        
   }
     printf("El mayor Promedio es: %s | Promedio: %.2f\n", estudiantes[indicePromedio].NombreEstudiante, estudiantes[indicePromedio].Promedio);
}

/*Módulo 2: Determinar el porcentaje de estudiantes mayores de 25 años 
que ingresaron antes del año 2020. */
void MostrarAnioIngre(Estudiante * estudiantes, int cantEstudiantes) {

    float Porcentaje;

    for (int i = 0; i < cantEstudiantes; i++)
    {
        if (estudiantes[i].carrera.anioIngreso > 2020 && estudiantes[i].edad > 25)
        {

      
            printf("Nombre: %s\n", estudiantes[i].NombreEstudiante);
            printf("Edad: %d\n", estudiantes[i].edad);
            printf("Anio Ingreso: %d\n", estudiantes[i].carrera.anioIngreso);

        }
        
        
    
    }
    

}