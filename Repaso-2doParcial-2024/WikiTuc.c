#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ----------------------------------------------------ESTRUCTURAS-------------------------------------------------------------------------------------*/
struct DatosControlador
{
    char Nombre[50];
    char Apellido[50];
} typedef Datos;

struct FechaControl
{
    int dia;
    int mes;
    int anio;
} typedef Fecha;

struct Articulo
{
    char nombreArticulo[100];
    char Deestinatarios[20];
    char Nivel[50];
    char cursosAnios[100];
    char Area[50];
    char descripcion[200];
    Datos datos;
    Fecha fecha;
    char Estado[30];
} typedef Articulo;

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------FUNCIONES--------------------------------------------------------------------------------------------------*/

Articulo *cargarDatos();
void MostrarDatos(Articulo *articulos, int cantArticulos);
void Articulosrobotica(Articulo *articulos, int cantArticulos);
void ArticulosControlados(Articulo *articulos, int cantArticulos);
void ArticulosDestinados5toGrado(Articulo *articulos, int cantArticulos);
void CantidadArticulosSegunArea(Articulo *articulos, int cantArticulos);
void CantidadArticulosSegunNivel(Articulo *articulos, int cantArticulos);
void Tarea6y7(Articulo *articulos, int cantArticulos);
void EstadoArticulo (Articulo * articulos, int cantArticulos);

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

void main()
{

    int opcion;
    int cantArticulos = 4;
    Articulo *articulos = cargarDatos();

    MostrarDatos(articulos, cantArticulos);
    Articulosrobotica(articulos, cantArticulos);
    ArticulosControlados(articulos, cantArticulos);
    ArticulosDestinados5toGrado(articulos, cantArticulos);
    // CantidadArticulosSegunArea(articulos, cantArticulos);
    // CantidadArticulosSegunNivel(articulos, cantArticulos);
    Tarea6y7(articulos, cantArticulos);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/
Articulo *cargarDatos()
{

    int cantArticulos = 4;

    Articulo articulo1 = {"Gramatica", "Alumnos", "Primario", "5to grado", "Lengua", "Material Sobre Verbos", {"Milagros", "Antoni"}, {18, 11, 2024}, "Cargado"};

    Articulo articulo2 = {"Ecuacion Matematicas", "Directivos", "Secundario", "6to año", "Matematicas", "Material sobre ecuaciones", {"Gabriel", "Samayoa"}, {16, 11, 2024}, "controlado"};

    Articulo articulo3 = {"Cuentos", "Alumnos", "Secundario", "5to grado", "Lengua", "Material sobre literatura", {"Luissina", "Latina"}, {15, 11, 2024}, "controlado"};

    Articulo articulo4 = {"Avances en robotica", "Docentes", "Primario", "6to grado", "robotica", "Introduccion a la robotica", {"Rodrigo", "Toledo"}, {17, 11, 2024}, "publicado"};

    Articulo *articulos = (Articulo *)malloc(sizeof(Articulo) * cantArticulos);

    articulos[0] = articulo1;
    articulos[1] = articulo2;
    articulos[2] = articulo3;
    articulos[3] = articulo4;

    return articulos;
}

void MostrarDatos(Articulo *articulos, int cantArticulos)
{
    for (int i = 0; i < cantArticulos; i++)
    {
        printf("\n Articulo %d\n", i + 1);
        printf("\t - Nombre Articulo: %s\n ", articulos[i].nombreArticulo);
        printf("\t - Destinatarios: %s\n", articulos[i].Deestinatarios);
        printf("\t - Nivel: %s\n", articulos[i].Nivel);
        printf("\t - Cursos/Año: %s\n", articulos[i].cursosAnios);
        printf("\t Area: %s\n", articulos[i].Area);
        printf("\t - Descripcion: %s\n", articulos[i].descripcion);
        printf("\t - Nombre y apellido de quien controla el articulo: %s %s\n", articulos[i].datos.Nombre, articulos[i].datos.Apellido);
        printf("\t - Fecha: %d/%d/%d\n", articulos[i].fecha.dia, articulos[i].fecha.mes, articulos[i].fecha.anio);
        printf("\t - Estado: %s\n", articulos[i].Estado);
    }
}

/*Liste los artículos de robótica destinados a docentes.*/
void Articulosrobotica(Articulo *articulos, int cantArticulos)
{

    printf("Articulos de Robotica destinados a docentes: \n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < cantArticulos; i++)
    {
        if (strcmp(articulos[i].Area, "robotica") == 0 && strcmp(articulos[i].Deestinatarios, "Docentes") == 0)
        {

            printf("Titulo: %s\n", articulos[i].nombreArticulo);
            printf("Nivel %s\n", articulos[i].Nivel);
            printf("Cursos: %s\n", articulos[i].cursosAnios);
            printf("Descripcion: %s\n", articulos[i].descripcion);
            printf(" Autor: %s %s\n", articulos[i].datos.Nombre, articulos[i].datos.Apellido);
            printf("Fecha: %d/%d/%d\n", articulos[i].fecha.dia, articulos[i].fecha.mes, articulos[i].fecha.anio);
            printf("Estado: %s\n", articulos[i].Estado);
            printf("--------------------------------------------------------------\n");
        }
    }
}

/* Liste los artículos controlados.*/
void ArticulosControlados(Articulo *articulos, int cantArticulos)
{

    printf("Articulos controlados: \n");
    printf("****************************\n");
    for (int i = 0; i < cantArticulos; i++)
    {
        if (strcmp(articulos[i].Estado, "controlado") == 0)
        {
            printf("Articulo %d\n", i + 1);
            printf("Titulo: %s\n", articulos[i].nombreArticulo);
            printf("Nivel %s\n", articulos[i].Nivel);
            printf("Cursos: %s\n", articulos[i].cursosAnios);
            printf("Descripcion: %s\n", articulos[i].descripcion);
            printf(" Autor: %s %s\n", articulos[i].datos.Nombre, articulos[i].datos.Apellido);
            printf("Fecha: %d/%d/%d\n", articulos[i].fecha.dia, articulos[i].fecha.mes, articulos[i].fecha.anio);
            printf("Estado: %s\n", articulos[i].Estado);
            printf("****************************\n");
        }
    }
}

/*Liste los artículos de nivel primario destinados a alumnos de 5° grado*/
void ArticulosDestinados5toGrado(Articulo *articulos, int cantArticulos)
{

    printf("Articulos de nivel primario destinados a Alumnos de 5to grado: \n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < cantArticulos; i++)
    {
        if (strcmp(articulos[i].Nivel, "Primario") == 0 && strcmp(articulos[i].cursosAnios, "5to grado") == 0)
        {
            printf("Articulo %d\n", i + 1);
            printf("Titulo: %s\n", articulos[i].nombreArticulo);
            printf("Nivel %s\n", articulos[i].Nivel);
            printf("Cursos: %s\n", articulos[i].cursosAnios);
            printf("Descripcion: %s\n", articulos[i].descripcion);
            printf(" Autor: %s %s\n", articulos[i].datos.Nombre, articulos[i].datos.Apellido);
            printf("Fecha: %d/%d/%d\n", articulos[i].fecha.dia, articulos[i].fecha.mes, articulos[i].fecha.anio);
            printf("Estado: %s\n", articulos[i].Estado);
            printf("-------------------------------------------\n");
        }
    }
}

/* Escriba un módulo que muestre la cantidad de artículos según el área ingresada como
 dato*/
void CantidadArticulosSegunArea(Articulo *articulos, int cantArticulos)
{

    int cantiArticulos = 0;
    char Area[50];
    printf("Ingresa el Area: ");
    fflush(stdin);
    gets(Area);

    for (int i = 0; i < cantArticulos; i++)
    {
        if (strcmp(Area, articulos[i].Area) == 0)
        {
            cantiArticulos++;
        }
    }

    printf("La cantidad de articulos de %s es: %d\n", Area, cantiArticulos);
}

/*Escriba un módulo que muestre la cantidad de artículos según el nivel ingresado como
 dato.*/
void CantidadArticulosSegunNivel(Articulo *articulos, int cantArticulos)
{

    int cantidadArticulos = 0;
    char Nivel[50];
    printf("Ingresa el Nivel: ");
    fflush(stdin);
    gets(Nivel);

    for (int i = 0; i < cantArticulos; i++)
    {
        if (strcmp(Nivel, articulos[i].Nivel) == 0)
        {
            cantidadArticulos++;
        }
    }

    printf("La cantidad de articulos de %s es: %d\n", Nivel, cantidadArticulos);
}

/* . Escriba un único módulo que haga la tarea de 6 y 7*/
void Tarea6y7(Articulo *articulos, int cantArticulos)
{

    int opcion;

    do
    {
        printf(" 1 . Mostrar cantidad de Articulos por Area \n");
        printf(" 2 . Mostrar cantidad de Articulos por Nivel\n");
        printf(" 3 .  Salir\n");
        printf("Selecciona una opcion : ");
        scanf("%d", &opcion);
        fflush(stdin);
        switch (opcion)
        {
        case 1:
            CantidadArticulosSegunArea(articulos, cantArticulos);
            break;
        case 2:
            CantidadArticulosSegunNivel(articulos, cantArticulos);
            break;
        case 3:
            printf("Saliendo del programa\n");
        default:
            printf("Opcion no valida");
            break;
        }
    } while (opcion != 3);
}

/* Escriba un módulo que modifique el estado de un artículo. Como parámetros de búsqueda
 tener en cuenta nivel, área y destinatarios (todos a la vez). Indicar también por qué valor
 desea modificar el estado.
 Ejemplo de prueba: Poner en estado publicado los artículos de nivel secundario, área
 robótica destinado a estudiantes */
void EstadoArticulo (Articulo * articulos, int cantArticulos) {

    char nivel[50];
    char area[50];
    char destinatarios[50];
    int indiceEstado = -1;

    printf("Ingresar el nivel: ");
    fflush(stdin);
    gets(nivel);

    printf("Ingresar Area: ");
    fflush(stdin);
    gets(area);

    printf("Ingresar Destinatario: ");
    fflush(stdin);
    gets(destinatarios);

    for (int i = 0; i < cantArticulos ; i++)
    {
        if (strcmp(nivel, articulos[i].Nivel) == 0)
        {
            /* code */
        }
        
    }
    

}