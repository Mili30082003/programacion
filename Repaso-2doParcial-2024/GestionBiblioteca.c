#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------ESTRUCTURAS-----------------------------------*/
struct FechaPrestamo
{
    int dia;
    int mes;
    int anio;
} typedef FechaPrestamo;

struct FechaDevolucion
{
    int dia;
    int mes;
    int anio;
} typedef FechaDevolucion;

struct Prestamo
{
    char NombreUsuario[50];
    FechaPrestamo fechaprestamo;
    FechaDevolucion fechadevolucion;
    char Estado[30]; // pendiente / devuelto
} typedef Prestamo;

struct libro
{
    char TituloLibro[50];
    char Autor[100];
    char Genero[50];
    int anioPublicacion;
    int CantEjemplares;
    float PrecioPorPrestamos;
    Prestamo *prestamos;
    int cantPrestamo;

} typedef Libro;

/*----------FUNCIONES-----------------------------*/

Libro *cargarDatos(int *cantLibros);
void MostrarLibrosDisponibles(Libro *libros, int cantLibros);
void BuscarLibroPorGeneroAutor(Libro *libros, int cantLibros);
void RealizarPrestamo(Libro *libros, int cantLibros);
void MostrarPrestamo(Libro *libros, int cantLibros);
void RegistrarDevolucion(Libro *libros, int cantLibros);
void ActualizarEjemplares(Libro *libros, int cantLibros);
void LiberarMemoria();
/*------------------------------------------------*/

void main()
{

    int cantLibros = 0;
    Libro *libros = cargarDatos(&cantLibros);

    MostrarLibrosDisponibles(libros, cantLibros);
    BuscarLibroPorGeneroAutor(libros, cantLibros);
    RealizarPrestamo(libros, cantLibros);
    MostrarPrestamo(libros, cantLibros);
    RegistrarDevolucion(libros, cantLibros);
    ActualizarEjemplares(libros, cantLibros);
}

/*-------------------------------------------------*/
Libro *cargarDatos(int *cantLibros)
{

    *cantLibros = 4;
    Libro *libros = malloc(sizeof(Libro) * (*cantLibros));

    Libro libro1 = {"It (Eso)", "Stephen King", "Terror", 1999, 5, 1200, malloc(sizeof(Prestamo) * 2), 2};
    libro1.prestamos[0] = (Prestamo){"Milagros", {10, 11, 2024}, {14, 11, 2024}, "devuelto"};
    libro1.prestamos[1] = (Prestamo){"Jungkook", {23, 11, 2024}, {26, 11, 2024}, "pendiente"};

    Libro libro2 = {"Im Still", "Milagros Antoni", "Romance", 2020, 10, 2000, malloc(sizeof(Prestamo) * 1), 1};
    libro2.prestamos[0] = (Prestamo){"Taehyung", {18, 11, 2024}, {22, 11, 2024}, "pendiente"};

    Libro libro3 = {"The Police", "Rodrigo Toledo", "Policial", 2006, 4, 1900, malloc(sizeof(Prestamo) * 3), 3};
    libro3.prestamos[0] = (Prestamo){"Namjoon", {22, 11, 2024}, {25, 11, 2024}, "pendiente"};
    libro3.prestamos[1] = (Prestamo){"SeokJin", {24, 11, 2024}, {28, 11, 2024}, "pendiente"};
    libro3.prestamos[2] = (Prestamo){"Yoongi", {25, 11, 2024}, {30, 11, 2024}, "pendiente"};

    Libro libro4 = {"Bts: tour", "Milagros Antoni", "Romance", 2024, 5, 9600, malloc(sizeof(Prestamo) * 2), 2};
    libro4.prestamos[0] = (Prestamo){"Luissina", {2, 11, 2024}, {10, 11, 2024}, "devuelto"};
    libro4.prestamos[1] = (Prestamo){"Milagros", {10, 11, 2024}, {20, 11, 2024}, "devuelto"};

    libros[0] = libro1;
    libros[1] = libro2;
    libros[2] = libro3;
    libros[3] = libro4;

    return libros;
}

/* 1. Mostrar todos los libros disponibles*/
void MostrarLibrosDisponibles(Libro *libros, int cantLibros)
{

    printf("-------LIBROS-------\n");
    printf("--------------------\n");
    for (int i = 0; i < cantLibros; i++)
    {
        printf("Libro: %s\n", libros[i].TituloLibro);
        printf("Autor: %s\n", libros[i].Autor);
        printf("Genero: %s\n", libros[i].Genero);
        printf("Anio de Publicacion: %d\n", libros[i].anioPublicacion);
        printf("Ejemplares Disponibles: %d\n", libros[i].CantEjemplares);
        printf("Precio por Prestamo: %.2f\n", libros[i].PrecioPorPrestamos);
        printf("Cantidad de prestamos: %d\n", libros[i].cantPrestamo);
        printf("----------------------------\n");
        printf("\n");
    }
}

/* 2. Buscar libros por género o autor*/
void BuscarLibroPorGeneroAutor(Libro *libros, int cantLibros)
{

    char Genero[50];
    char Autor[100];

    printf("Ingrese el Genero: ");
    fflush(stdin);
    gets(Genero);

    printf("Ingrese el Autor: ");
    fflush(stdin);
    gets(Autor);

    int LibroEncontrado = 0;

    for (int i = 0; i < cantLibros; i++)
    {
        if (strcmp(libros[i].Genero, Genero) == 0 && strcmp(libros[i].Autor, Autor) == 0)
        {
            LibroEncontrado = 1;

            printf("Libro: %s\n", libros[i].TituloLibro);
            printf("Genero: %s\n", libros[i].Genero);
            printf("Autor: %s\n", libros[i].Autor);
            printf("\n");
        }
    }

    if (LibroEncontrado != 1)
    {
        printf("No hay Libros con Genero '%s' y Autor '%s'\n", Genero, Autor);
    }
}

/* 3. Realizar un préstamo (solo si hay ejemplares disponibles).*/
void RealizarPrestamo(Libro *libros, int cantLibros)
{

    char TItuloLibro[50];
    printf("Ingrese el Libro: ");
    fflush(stdin);
    gets(TItuloLibro);

    int LibroEncontrado = 0;

    for (int i = 0; i < cantLibros; i++)
    {
        if (strcmp(libros[i].TituloLibro, TItuloLibro) == 0)
        {
            LibroEncontrado = 1;

            Prestamo nuevoPrestamo;
            if (libros[i].CantEjemplares > 0)
            {
                printf("Ingrese el nombre de usuario: ");
                fflush(stdin);
                gets(nuevoPrestamo.NombreUsuario);

                printf("Ingrese la fecha de Prestamo (dd mm aaa): ");
                fflush(stdin);
                scanf("%d %d %d", &nuevoPrestamo.fechaprestamo.dia, &nuevoPrestamo.fechaprestamo.mes, &nuevoPrestamo.fechaprestamo.anio);

                printf("Ingrese la Fecha de Devolucion (dd mm aaa): ");
                fflush(stdin);
                scanf("%d %d %d", &nuevoPrestamo.fechadevolucion.dia, &nuevoPrestamo.fechadevolucion.mes, &nuevoPrestamo.fechadevolucion.anio);

                // estado prestamo
                strcpy(nuevoPrestamo.Estado, "pendiente");

                libros[i].prestamos = realloc(libros[i].prestamos, sizeof(Prestamo) * (libros[i].cantPrestamo + 1));

                libros[i].prestamos[libros[i].cantPrestamo] = nuevoPrestamo;

                // Agregar Nuevo prestamo al arreglo
                libros[i].cantPrestamo++;
                libros[i].CantEjemplares--;

                printf("Prestamo registrado\n");
                printf("\n");

                printf("Libro: %s | Nuevo Prestamo: %s | Fecha Prestamo: %d /%d / %d, | Fecha Devolucion: %d / %d / %d\n", TItuloLibro, nuevoPrestamo.NombreUsuario, nuevoPrestamo.fechaprestamo.dia, nuevoPrestamo.fechadevolucion.mes, nuevoPrestamo.fechaprestamo.anio, nuevoPrestamo.fechadevolucion.dia, nuevoPrestamo.fechadevolucion.mes, nuevoPrestamo.fechadevolucion.anio);
                return;
            }
            else
            {
                printf("No hay ejemplares disponibles para el libro %s\n", TItuloLibro);
            }
        }
    }

    if (!LibroEncontrado)
    {
        printf("El libro no se encontro\n");
    }
}

/*  4. Mostrar los préstamos realizados, indicando los usuarios y las fechas*/
void MostrarPrestamo(Libro *libros, int cantLibros)
{

    printf("*** PRESTAMOS ***\n");

    for (int i = 0; i < cantLibros; i++)
    {
        for (int j = 0; j < libros[i].cantPrestamo; j++)
        {
            printf("Usuario: %s\n", libros[i].prestamos[j].NombreUsuario);
            printf("Fecha prestamo: %d/ %d / %d\n", libros[i].prestamos[j].fechaprestamo.dia, libros[i].prestamos[j].fechadevolucion.mes, libros[i].prestamos[j].fechaprestamo.anio);
            printf("Fecha Devolucion: %d / %d / %d\n", libros[i].prestamos[j].fechadevolucion.dia, libros[i].prestamos[j].fechadevolucion.dia, libros[i].prestamos[j].fechadevolucion.mes, libros[i].prestamos[j].fechadevolucion.anio);
            printf("***************************\n");
            printf("\n");
        }
    }
}

/*5. Registrar la devolución de un préstamo*/
void RegistrarDevolucion(Libro *libros, int cantLibros)
{

    char NombreLibro[50];
    char Estado[30];
    char NombreUsuario[50];
    printf("Ingrese el nombre dle Libro:  ");
    fflush(stdin);
    gets(NombreLibro);

    printf("Ingrese el nombre del Usuario: ");
    fflush(stdin);
    gets(NombreUsuario);

    printf("Ingrese el Estado : ");
    fflush(stdin);
    gets(Estado);

    int LibroEncontrado = 0;

    printf(" ----- REGISTRO DE DEVOLUCION -----\n");
    printf("\n ------------------------\n");

    for (int i = 0; i < cantLibros; i++)
    {
        if (strcmp(libros[i].TituloLibro, NombreLibro) == 0)
        {
            LibroEncontrado = 1;

            for (int j = 0; j < libros[i].cantPrestamo; i++)
            {
                if (strcmp(libros[i].prestamos[j].NombreUsuario, NombreUsuario) == 0 && strcmp(libros[i].prestamos[j].Estado, "pendiente") == 0)
                {
                    strcpy(libros[i].prestamos[j].Estado, "devuelto");
                    libros[i].CantEjemplares++;

                    printf("\nDevolución registrada:\n");
                    printf("Título del libro: %s\n", libros[i].TituloLibro);
                    printf("Usuario: %s\n", libros[i].prestamos[j].NombreUsuario);
                    printf("Estado: %s\n", libros[i].prestamos[j].Estado);

                    return;
                }
            }
        }
    }

    if (!LibroEncontrado)
    {
        printf("No se encontro el nombre del libro");
    }
}

/*6 . Actualizar la cantidad de ejemplares de un libro.*/

void ActualizarEjemplares(Libro *libros, int cantLibros)
{

    char NombreLibro[50];
    printf("Ingrese el Libro: ");
    fflush(stdin);
    gets(NombreLibro);

    int cantEjemplares;
    printf("Ingrese la cantidad de ejemplares: ");
    fflush(stdin);
    scanf("%d", &cantEjemplares);

    int LibroEncontrado = 0;

    for (int i = 0; i < cantLibros; i++)
    {
        if (strcmp(libros[i].TituloLibro, NombreLibro) == 0)
        {
            LibroEncontrado = 1;

            libros[i].CantEjemplares += cantEjemplares;

            printf("Libro: %s\n", NombreLibro);
            printf("Cantidad de Ejemplares: %d\n", libros[i].CantEjemplares);
        }
    }
}