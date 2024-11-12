#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarNotas(float *notas, int alumnos);

float calcularPromedio(float *notas, int alumnos, float *promedio);

float *CrearArreglo(int cant_alumnos);

void MostrarNotas ( float *notas, int alumnos);

// --------------------------------------------------------------------


void main () {

    int cant_alumnos;
    float promedio;
    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &cant_alumnos);

    float *nota_alumnos = CrearArreglo(cant_alumnos);
    
    cargarNotas(nota_alumnos, cant_alumnos);
    
   float mejorNota = calcularPromedio(nota_alumnos, cant_alumnos, &promedio);

   MostrarNotas(nota_alumnos, cant_alumnos);

   printf("Promedio curso: %.2f | Mejor Nota: %.2f", promedio, mejorNota );
}



// ------------------------------------------------------------------

float *CrearArreglo(int cant_alumnos) {
    return malloc(sizeof(int) * cant_alumnos);
}

void cargarNotas(float *notas, int alumnos) {

    for (int i = 0; i < alumnos; i++)
    {
        *notas = rand()%10+1;
        notas++;
    }
    
}

float calcularPromedio(float *notas, int alumnos, float *promedio) {


    float  mejorNota=0, sumaNotas = 0;


    for (int i = 0; i < alumnos; i++)
    {
        sumaNotas = sumaNotas + *notas;
        if (*notas > mejorNota)
        {
            mejorNota = *notas;
        }
        
        notas++;
    }
    
    *promedio = sumaNotas / alumnos;

    return mejorNota;
}


void MostrarNotas ( float *notas, int alumnos){

    for (int i = 0; i < alumnos; i++)
    {
        printf("Nota de los Alumnos: %.2f\n", *notas);
        notas++;
    }
    
}