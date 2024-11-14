/*
struct Auto {
int codigo;
char marca[50];
char modelo[50];
stock
Unidad *disponible// hago un arreglo dinamico de unidades
// si yo tengo 3 unidades disponibles ahi guardo las 3 unidades

}

struct Unidad {
int año;
int km;
float precio;

}


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Unidad
{
    int year;
    int km;
    float precio;
} typedef Unidad;

struct Auto
{
    int codigo;
    char *marca;
    char *modelo;
    int stock;
    Unidad *disponibles;

} typedef Auto;

void cargarDatos(Auto *arreglo, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("Auto nro %d", i + 1);

        arreglo->codigo = i + 1;

        arreglo->marca = malloc(sizeof(char) * 50);
        arreglo->modelo = malloc(sizeof(char) * 50);
        printf("Ingrese la marca: ");
        fflush(stdin);
        gets(arreglo->marca);

        printf("Ingrese el modelo: ");
        fflush(stdin);
        gets(arreglo->modelo);

        arreglo->marca = realloc(arreglo->marca, strlen(arreglo->marca) + 1);
        arreglo->modelo = realloc(arreglo->modelo, strlen(arreglo->modelo) + 1); // + 1 es para la marca final

        printf("Ingrese el stock: ");
        fflush(stdin);
        scanf("%d", &arreglo->stock);

        arreglo->disponibles = malloc(sizeof(Unidad) * arreglo->stock);

        for (int j = 0; j < arreglo->stock; j++)
        {
            printf("Unidad nro '%d'\n", j + 1);
            printf("Ingrese el año: ");
            scanf("%d", &arreglo->disponibles[j].year);

            printf("Ingrese el Kilometraje:\n ");
            scanf("%d", &arreglo->disponibles[j].km);
        }
        //  printf("Ingrese el Kilometraje:\n ");
        // scanf("%d", &arreglo->disponibles[j].precio);
    }
}

void mostrarDatos(Auto *arreglo, int n)
{

    for (int i = 0; i < n; i++)
    {

        printf("Auto codigo: %d\n", arreglo[i].codigo);
        printf("Marca: %s | Modelo: %s\n", arreglo[i].marca);
    }
}

void liberarMemoria (Auto *arreglo, int n ) {
    for (int i = 0; i < n; i++)
    {
        free(arreglo[i].disponibles);
        free(arreglo[i].marca);
        free(arreglo[i].modelo);
        arreglo++;

    }
    free(arreglo);
    
}

void main()
{

    int cantidadAutos = 3;

    Auto *autos = malloc(sizeof(Auto) * cantidadAutos);

    cargarDatos(autos, cantidadAutos);
    mostrarDatos(autos, cantidadAutos);

    liberarMemoria(autos, cantidadAutos);
    // Primer Auto: toyota - etios | unidades disponibles = 3
}
