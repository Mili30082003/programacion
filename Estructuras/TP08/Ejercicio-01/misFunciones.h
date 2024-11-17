#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FechaPrestamo
{
    int dia;
    int mes;
    int anio;
} typedef FechaPrestamo;


struct Lector
{
    char *Nombre;
    char *Edad;
    FechaPrestamo fechaPrestamo;
} typedef Lector;


struct Libro
{
    char *TituloLibro;
    char *Genero;
    int num_lectores;
    Lector * Lectores;
    
} typedef Libro;

void cargarLibro (Libro *libros, int cant_libros){

    for (int i = 0; i < cant_libros; i++)
    {
        libros[i].TituloLibro = malloc(sizeof(char) * 100);
        libros[i].Genero = malloc(sizeof(char) * 50);

        printf("Ingrese el Nombre del Libro: ");
        fflush(stdin);
        gets(libros[i].TituloLibro);
 

        
    }
    
}

