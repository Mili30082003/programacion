#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct
{
    int dia;
    int mes;
    int anio;
} typedef tipoFecha;

struct
{
    char apellido[MAX];
    char nombre[MAX];
    int dni;
}typedef tipoGuia;

struct
{
    char destino[MAX];
    tipoGuia guia;                  
    tipoFecha fechaSalida;
    tipoFecha fechaRegreso;
    float costo;
    int cantHabitaciones;
    int *habitaciones;
} typedef tipoAgencia;

tipoAgencia cargarDatos();   //retorna tipo de dato tipoAgencia, se usa para cargar todos los datos
void mostrarDatos(tipoAgencia viaje); 
tipoAgencia actualizarCosto(tipoAgencia viaje);  
int validarFecha(tipoFecha fecha);             //control de fecha correcta
void habitacionesByPiso(tipoAgencia viaje);   //muestra las habitaciones

int main()
{
    tipoAgencia dato;

    dato = cargarDatos();
    mostrarDatos(dato);

    dato = actualizarCosto(dato);
    printf("\nVIAJE CON COSTO ACTUALIZADO---------------- \n");
    mostrarDatos(dato);

    habitacionesByPiso(dato);

    //liberar memoria
    free(dato.habitaciones);

    return 0;
}

tipoAgencia cargarDatos()
{
    tipoAgencia aux;

    printf("Ingrese nombre del destino: ");
    gets(aux.destino);
    printf("Datos del guia: \n");
        printf("\tApellido: ");
        gets(aux.guia.apellido);   // no usa & porque es un arreglo
        printf("\tNombre: ");
        gets(aux.guia.nombre);
        printf("\tDNI: ");
        scanf("%d", &aux.guia.dni);  // utiliza & para obtener la dirección de memoria

    do
    {
        printf("Fecha de Salida (dd mm aaaa): ");
        scanf("%d %d %d", &aux.fechaSalida.dia, &aux.fechaSalida.mes, &aux.fechaSalida.anio );
    } while (!validarFecha(aux.fechaSalida));   //invoca a la funcion para validar, sino es correcto vuelve a cargar

    do
    {
        printf("Fecha de Regreso (dd mm aaaa): ");
        scanf("%d %d %d", &aux.fechaRegreso.dia, &aux.fechaRegreso.mes, &aux.fechaRegreso.anio );
    } while (!validarFecha(aux.fechaRegreso));   //invoca a la funcion para validar, sino es correcto vuelve a cargar

    printf("Costo: ");
    scanf("%f", &aux.costo);

    printf("Cantidad de habitaciones: ");
    scanf("%d", &aux.cantHabitaciones);         //segun lo ingresado se creará un arreglo dinámico para habitaciones

    //reserva de espacio para arreglo de habitaciones
    aux.habitaciones = malloc(aux.cantHabitaciones * sizeof(int));
    
    //completar arreglo aleatoriamente
    int numero, existe;
    for (int i = 0; i < aux.cantHabitaciones; i++)
    {   
        do
        {
            existe = 0;
            numero = rand() % 301 + 100;
            //controlo si ya existe, recorriendo desde el inicio los numeros ya generados
            int j=0;
            for (j = 0; j < i; j++){
                if (numero == aux.habitaciones[j])
                    existe==1;
            }
        } while (existe);
        aux.habitaciones[i] = numero;
    }

    return aux;   //retorna la variable con todos los datos de la estructura cargada.
}




void mostrarDatos(tipoAgencia viaje){
    printf("\n---------- DATOS DEL VIAJE ------------- \n");
    
    printf("\nDestino: %s \n", viaje.destino);
    printf("Guia: \n");
    printf("\t- Nombre: %s, %s - DNI: %d\n", viaje.guia.apellido, viaje.guia.nombre, viaje.guia.dni);

    printf("Fecha de Salida: %d / %d / %d \n", viaje.fechaSalida.dia, viaje.fechaSalida.mes, viaje.fechaSalida.anio);
    printf("Fecha de Regreso: %d / %d / %d \n", viaje.fechaRegreso.dia, viaje.fechaRegreso.mes, viaje.fechaRegreso.anio);

    printf("Costo: %.2f \n", viaje.costo);
    printf("Cantidad de habitaciones: %d \n", viaje.cantHabitaciones);

    printf("Habitaciones reservadas: \n");
    for (int i = 0; i < viaje.cantHabitaciones; i++)
    {
        printf("\t %d \n", viaje.habitaciones[i]);
    }
}

tipoAgencia actualizarCosto(tipoAgencia viaje){
    float porcen;

    printf("Ingrese el porcentaje para incremento: ");
    scanf("%f", &porcen);
    viaje.costo = viaje.costo + viaje.costo * porcen/100;

    return viaje;

}

int validarFecha(tipoFecha fecha){
    int dias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //el primero de sobra para que el indice coincida con el mes

    // Ajuste para febrero en años bisiestos
    // Un año es bisiesto si es divisible por 4.
    // Pero si es divisible por 100, también debe ser divisible por 400 para ser bisiesto.
    if ((fecha.anio % 4 == 0 && fecha.anio % 100 != 0) || (fecha.anio % 400 == 0)) {
        dias[2] = 29;
    }

    if (fecha.anio>=2023 && fecha.anio<=2025){
        if (fecha.mes >=1 && fecha.mes <=12){
            if (fecha.dia >=1 && fecha.dia <= dias[fecha.mes]){
                return 1;
            }
        }
    }
    return 0;
}

void habitacionesByPiso(tipoAgencia viaje){
    int piso1=0, piso2=0, piso3=0, piso4=0, piso;
    for (int i = 0; i < viaje.cantHabitaciones; i++)
    {
        piso = viaje.habitaciones[i] / 100;
        switch (piso)
        {
            case 1: piso1++; break;
            case 2: piso2++; break;
            case 3: piso3++; break;
            case 4: piso4++; break;
        }
    }
    printf("Habitaciones Piso 1: %d \n", piso1);
    printf("Habitaciones Piso 2: %d \n", piso2);
    printf("Habitaciones Piso 3: %d \n", piso3);
    printf("Habitaciones Piso 4: %d \n", piso4);
}
