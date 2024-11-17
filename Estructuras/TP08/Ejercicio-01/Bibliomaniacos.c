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
    int  Edad;
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

        printf("Ingrese el Genero: ");
        fflush(stdin);
        gets(libros[i].Genero);

        libros[i].TituloLibro = realloc(libros[i].TituloLibro, strlen(libros[i].TituloLibro) + 1);
        libros[i].Genero = realloc(libros[i].Genero, strlen(libros[i].Genero) + 1);

        printf("\n-------------------------------- \n");
        printf("Ingrese la cantidad de lectores para el libro '%s': ",libros[i].TituloLibro);
        scanf("%d", &libros[i].num_lectores);

        libros[i].Lectores = malloc(sizeof(Lector) * libros[i].num_lectores);

        for (int j = 0; j < libros[i].num_lectores; j++)
        {
            libros[i].Lectores[j].Nombre = malloc(sizeof(char) * 100 );
           printf("\n ----------------------- \n");
            printf("Ingrese el Nombre del Lector: ", j + 1);
            fflush(stdin);
            gets(libros[i].Lectores[j].Nombre);

            printf("Ingrese la edad: ", j + 1);
            fflush(stdin);
            scanf("%d", &libros[i].Lectores[j].Edad);

                printf("Ingrese la fecha de préstamo (DD MM AAAA): ");
            scanf("%d %d %d", &libros[i].Lectores[j].fechaPrestamo.dia,
                              &libros[i].Lectores[j].fechaPrestamo.mes,
                              &libros[i].Lectores[j].fechaPrestamo.anio);

            printf("\n-----------------------\n");
        libros[i].Lectores[j].Nombre = realloc(libros[i].Lectores[j].Nombre, strlen(libros[i].Lectores[j].Nombre) + 1);

        }
        
    }

}

/*void MostrarLibro (Libro *libros, int cant_libros){

    for (int i = 0; i < cant_libros; i++)
    {
        printf("\n ---- Libros ----- \n", i + 1);
        printf("Libro: %s\n", libros[i].TituloLibro);
        printf("Genero: %s\n", libros[i].Genero);
        printf("Cantidad de Lectores: %d", libros[i].num_lectores);

        for (int j = 0; j < libros[i].num_lectores; j++)
        {
            printf("\n --- Lectores --- \n", j + 1);
        printf("Nombre del Lector: %s\n", libros[i].Lectores[j].Nombre);
        printf("Edad: %d\n", libros[i].Lectores[j].Edad);
        printf("Fecha de Prestamo: %d/%d/%d", libros[i].Lectores[j].fechaPrestamo.dia, libros[i].Lectores[j].fechaPrestamo.mes, libros[i].Lectores[j].fechaPrestamo.anio);
        }
        
        
    }
    

}
*/
void MayorCantidadLectores(Libro * Libros, int cantLibros){

    int Mx_Lectores = 0;
    int aux_max = 0;

    for (int i = 0; i < cantLibros; i++)
    {
        if (Libros[i].num_lectores > Mx_Lectores)
        {
            Mx_Lectores = Libros[i].num_lectores;
            aux_max = i;
        }
        
    }
    
    printf("El libro con mayor cantidad de lectores es: \n");
    printf("Titulo: %s\n", Libros[aux_max].TituloLibro);
    printf("Genero: %s\n",Libros[aux_max].Genero );
    printf("Cantidad de Lectores: %d\n", Libros[aux_max].num_lectores);
}

void MostrarLibrosLectoresMayor21 (Libro *libros , int cantLibros){

for (int i = 0; i < cantLibros; i++)
{
    int Menor21 = 0;
    for (int j = 0; j < libros[i].num_lectores; j++)
    {
        if (libros[i].Lectores[j].Edad < 21)
        {
            Menor21 = 1;
            break;
        }
        
    }

    if (Menor21)
    {
        printf("Titulo: %s", libros[i].TituloLibro);
        printf("Genero: %s", libros[i].Genero);
    }
    
    
}


}

void liberarMemoria (Libro * libros, int cantlibros){

    for (int i = 0; i < cantlibros ; i++)
    {
        free(libros[i].Lectores);
        free(libros[i].TituloLibro);
        free(libros[i].Genero);

        for (int j = 0; j < libros[i].num_lectores; j++)
        {
            free(libros[i].Lectores[j].Nombre);
        }
        
    }
    
    free(libros);
}

void main () {


int cantlibros;
printf("Ingrese la cantidad de libros a cargar: ");
scanf("%d", &cantlibros);



Libro *libros = malloc(sizeof(Libro) * cantlibros);

cargarLibro(libros, cantlibros);
// MostrarLibro(libros, cantlibros);
MayorCantidadLectores(libros, cantlibros);
MostrarLibrosLectoresMayor21(libros, cantlibros);
liberarMemoria(libros, cantlibros);



}