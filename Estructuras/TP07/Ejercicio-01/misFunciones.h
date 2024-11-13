#include <stdio.h>

struct DatosEmpleado {
    char Nombre[50];
    char Puesto[100];
} typedef DatosEmpleado;

struct FechaInicioProyecto {
    int dia;
    int mes;
    int anio;
} typedef FechaInicioProyecto;

struct registroProyecto {
    char NombreProyecto[100];
    int mes;
    int horasTrabajadas[12];
    struct DatosEmpleado Datos;
    struct FechaInicioProyecto Fecha;
} typedef registroProyecto;

void cargarDatos(registroProyecto arreglo[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Ingrese los datos del proyecto: \n");
        
        printf("\t - Nombre del proyecto: ");
        fflush(stdin);
        gets(arreglo[i].NombreProyecto);

        // Validación de duración en meses
        do {
            printf("\t - Meses de duración (1 a 12): ");
            scanf("%d", &arreglo[i].mes);
            if (arreglo[i].mes < 1 || arreglo[i].mes > 12) {
                printf("Duración inválida. Debe estar entre 1 y 12.\n");
            }
        } while (arreglo[i].mes < 1 || arreglo[i].mes > 12);

        // Cargar horas trabajadas por mes
        printf("\t - Horas Trabajadas por cada mes:\n");
        for (int j = 0; j < arreglo[i].mes; j++) {
            printf("\t   Mes %d: ", j + 1);
            scanf("%d", &arreglo[i].horasTrabajadas[j]);
        }

        // Validación de fecha de inicio
        do {
            printf("\t - Fecha de Inicio del Proyecto:\n");
            printf("\t   Mes (debe ser 1): ");
            scanf("%d", &arreglo[i].Fecha.mes);
            printf("\t   Día: ");
            scanf("%d", &arreglo[i].Fecha.dia);
            printf("\t   Año (debe ser 2024): ");
            scanf("%d", &arreglo[i].Fecha.anio);

            if (arreglo[i].Fecha.mes != 1 || arreglo[i].Fecha.anio != 2024) {
                printf("Fecha inválida. Debe ser en enero de 2024.\n");
            }
        } while (arreglo[i].Fecha.mes != 1 || arreglo[i].Fecha.anio != 2024);

        // Cargar datos del empleado
        printf("\t - Datos del Empleado:\n");     
        printf("\t   Nombre: ");
        fflush(stdin);
        gets(arreglo[i].Datos.Nombre);

        printf("\t   Puesto: ");
        fflush(stdin);
        gets(arreglo[i].Datos.Puesto);
    }
}

void mostrarDatos(registroProyecto arreglo[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nombre Proyecto: %s\n", arreglo[i].NombreProyecto);
        printf("\t - Meses de duración: %d\n", arreglo[i].mes);

        printf("\t - Horas Trabajadas:\n");
        for (int j = 0; j < arreglo[i].mes; j++) {
            printf("\t   Mes %d: %d horas\n", j + 1, arreglo[i].horasTrabajadas[j]);
        }

        printf("\t - Fecha de Inicio del Proyecto: %02d/%02d/%d\n",
               arreglo[i].Fecha.dia, arreglo[i].Fecha.mes, arreglo[i].Fecha.anio);

        printf("\t - Datos del Empleado:\n");
        printf("\t   Nombre: %s\n", arreglo[i].Datos.Nombre);
        printf("\t   Puesto: %s\n", arreglo[i].Datos.Puesto);
    }
}
