#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void cargarNotas(float *notas, int alumnos);    // Función para simular las notas
void mostrarNotas(float *notas, int alumnos);    // Función para mostrar las notas
float calcularPromedio(float *notas, int alumnos, float *promedio);   // Función que calcula y guarda el promedio, además retorna la mejor nota.

int main(){
    int alumnos;
    float *notas, promedio=0, mejor=0;
    
    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &alumnos);

    notas = malloc(sizeof(float)*alumnos);  //reserva dinámica de memoria
    cargarNotas(notas, alumnos);            //funcion para cargar las notas al arreglo dinamico de notas, pasando la cantidad de alumnos
    mostrarNotas(notas, alumnos);

    mejor= calcularPromedio(notas, alumnos, &promedio );  //promedio es una variable float que se pasa como puntero (la dirección)
    printf("==> Promedio del curso: %.2f \n", promedio);
    printf("==> Mejor nota: %.2f \n", mejor);
    
    free(notas);  //se libera la memoria asignada dinámicamente
    return 0;
}

void cargarNotas(float *notas, int alumnos){
    srand(time(NULL));              //varía la generación de aletorios en cada ejecución
    for (int i = 0; i < alumnos; i++)
    {
        notas[i]=(rand()%1001) * 0.01;
    }
}


void mostrarNotas(float *notas, int alumnos){
   for (int i = 0; i < alumnos; i++)
    {
        printf("%.2f ", notas[i]);
    }
    printf("\n");
}


float calcularPromedio(float *notas, int alumnos, float *promedio){
    
    float mayor=0;
    for (int i = 0; i < alumnos; i++)
    {
        *promedio = *promedio + *notas;
        if (*notas>mayor)       //busco la mayor nota partiendo de la nota 0
            mayor=*notas;
        
        notas++;                //desplazamiento del puntero notas (dentro de la función)
    }
    *promedio =  *promedio / alumnos;
    return mayor;
}