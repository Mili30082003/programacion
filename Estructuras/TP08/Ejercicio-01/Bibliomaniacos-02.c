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
    char Nombre[50];
    int edad;
    FechaPrestamo fecha;
} typedef Lector;

struct Libro
{
    char TituloLibro[100];
    char Genero[50];
    int CantLectores;
    Lector *lectores;
} typedef Libro;

Libro *CargarDatos();
void MayorCantLectores(Libro *libros, int cantLectores);
void LibrosPrestadosSociosMenos21(Libro *libros, int cantLibros);
void LibrosGeneroPolicial (Libro * libros, int cantLibros);
void LiberarMemoria(Libro * libros, int cantLibros);

/*---------------------------------------------------------------------*/

void main()
{
    int cantLectores = 5;
    Libro *libros = CargarDatos();
    printf("\n");
    MayorCantLectores(libros, cantLectores);
    printf("\n");
    LibrosPrestadosSociosMenos21(libros, cantLectores);
    printf("\n");
    LibrosGeneroPolicial(libros, cantLectores);
    LiberarMemoria(libros, cantLectores);
}

/*-------------------------------------------------------------------- */

Libro *CargarDatos()
{

    Libro libro1 = {"It (Eso)", "terror", 2, malloc(sizeof(Lector) * 2)};
    libro1.lectores[0] = (Lector){"Milagros", 21, {18, 11, 2024}};
    libro1.lectores[1] = (Lector){"Rodrigo", 19, {17, 11, 2024}};

    Libro libro2 = {"Im Still", "romance", 1, malloc(sizeof(Lector) * 1)};
    libro2.lectores[0] = (Lector){"Luissina", 23, {16, 11, 2024}};

    Libro libro3 = {"Carrie", "terror", 3, malloc(sizeof(Lector) * 3)};
    libro3.lectores[0] = (Lector){"Gabriel", 17, {15, 11, 2024}};
    libro3.lectores[1] = (Lector){"Mitsu", 20, {20, 11, 2024}};
    libro3.lectores[2] = (Lector){"carlos", 16, {20, 11, 2024}};

    Libro libro4 = {"Policia", "policial", 1, malloc(sizeof(Lector) * 1)};
    libro4.lectores[0] = (Lector){"Kike", 22, {21, 11, 2023}};

    Libro libro5 = {"el misterio", "policial", 4, malloc(sizeof(Lector) * 4)};
    libro5.lectores[0] = (Lector){"Gabriel", 17, {15, 11, 2023}};
    libro5.lectores[1] = (Lector){"Mitsu", 20, {25, 11, 2024}};
    libro5.lectores[2] = (Lector){"carlos", 16, {27, 11, 2024}};
    libro5.lectores[3] = (Lector){"josefa", 15, {20, 11, 2023}};

    Libro *libros = malloc(sizeof(Libro) * 5);

    libros[0] = libro1;
    libros[1] = libro2;
    libros[2] = libro3;
    libros[3] = libro4;
    libros[4] = libro5;

    return libros;
}

void MayorCantLectores(Libro *libros, int cantLectores)
{

    int MayorCantLectores = 0;
    int indiceMayor = 0;

    for (int i = 0; i < cantLectores; i++)
    {
        if (libros[i].CantLectores > MayorCantLectores)
        {
            MayorCantLectores = libros[i].CantLectores;
            indiceMayor = i;
        }
    }

    printf("El libro con mayor cantidad de lectores es: %s\n", libros[indiceMayor].TituloLibro);
    printf("Cantidad de Lectores: %d\n", libros[indiceMayor].CantLectores);
}

void LibrosPrestadosSociosMenos21(Libro *libros, int cantLibros)
{

    for (int i = 0; i < cantLibros; i++)
    {

        for (int j = 0; j < libros[i].CantLectores; j++)
        {
            if (libros[i].lectores[j].edad < 21)
            {

                printf("Es menor de 21: \n");
                printf("\t   - Nombre: %s\n", libros[i].lectores[j].Nombre);
                printf("\t   - Edad: %d\n", libros[i].lectores[j].edad);
                printf("\t   - Libro: %s\n", libros[i].TituloLibro);
            }
        }
    }
}

void LibrosGeneroPolicial (Libro * libros, int cantLibros) {

int cantGeneroPolicial = 0;


for (int i = 0; i < cantLibros; i++)
{
 
        if (strcmp(libros[i].Genero, "policial") == 0)
        {
            cantGeneroPolicial++;
              
            printf("Titutlo Libro: %s\n", libros[i].TituloLibro);
         
        }
        
    }
     printf("La cantidad de Libros prestados de Genero 'Policial' es: %d\n", cantGeneroPolicial);
}


void LiberarMemoria(Libro * libros, int cantLibros) {

    for (int i = 0; i < cantLibros; i++)
    {
        free(libros[i].lectores);
        
    }
    
    free(libros);
}