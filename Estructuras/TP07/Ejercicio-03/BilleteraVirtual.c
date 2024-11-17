#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <misFunciones.h>

struct DatosCuenta
{
    char CVU[10];
    float Saldo;
    char *historialTransacciones;
    int cantidadTransacciones;
    
}typedef DatosCuenta;


struct Fechas
{
    int dia;
    int mes;
    int anio;
} typedef Fechas;

struct tCliente
{
    char Apellido [50];
    char Nombre[50];
    int dni;
    Fechas fechas;
    char contra[20];
    DatosCuenta cuenta;
} typedef tCliente;

void MostrarCliente (tCliente cliente){
    printf("\n Informacion del Cliente: \n");
    printf("Nombre: %s %s\n", cliente.Nombre, cliente.Apellido);
    printf("DNI: %d\n", cliente.dni);
    printf("Fecha de Nacimiento: %02d/%02d/%02d\n", cliente.fechas.dia, cliente.fechas.mes, cliente.fechas.anio);
    printf("$Saldo: %.2f\n", cliente.cuenta.Saldo);
}

void Menu (tCliente clientes[], int numClientes){
        printf("\n ---- Seleccionar Perfil -----\n");
    for (int i = 0; i < numClientes; i++)
    {
    
    printf("\t - Usuario %d: [%s, %s, %d]\n", i + 1, clientes[i].Apellido, clientes[i].Nombre, clientes[i].dni);

    
    }
     printf("Ingrese 0 para Finalizar: ");
    
   
}

/*
● Cambiarcontraseña: Permite ingresar una nueva contraseña.
 ● Agregar fondos: Permite agregar dinero en la billetera del perfil seleccionado.
 ● Retirar fondos: Permite retirar dinero de su billetera, verificando que haya saldo disponible.
 ● Consultar saldo: Muestra el saldo actual.
 ● Información de la cuenta: Muestra el nombre del perfil y el CVU.
 ● Historial de transacciones: Muestra el historial de transacciones en la billetera.
 ● Volver al menú principal: Permite regresar al menú principal para seleccionar otro perfil.
*/

void CambiarContraseña (tCliente * pCliente, char NuevaContra[]){
    
    // pCliente->contra = NuevaContra;

    strcpy(pCliente->contra, NuevaContra); // copiar el arreglo llamado fuente, en el arreglo destino 
    // la funcion sirve para sobreescribir el arreglo contra con lo que paso como parametro

    printf("\nLa contraseña ha sido cambiada con exito");
}

void AgregarFondos(tCliente * pCliente, float saldo){

        // pCliente->cuenta.Saldo = pcliente.cuenta.saldo + saldo;
        pCliente->cuenta.Saldo += saldo;

}

void RetirarFondos( tCliente * pCliente, float retiro) {

            if (pCliente->cuenta.Saldo >= retiro )
            {
                pCliente->cuenta.Saldo -= retiro;
                printf("\nRetiro de dinero exitoso");
            } else {
                printf("\nNo tiene saldo suficiente");
            }
            
}

void consultarSaldo (tCliente * pCliente){

    printf("El saldo es: %.2f\n", pCliente->cuenta.Saldo);
}

void InfoCuenta (tCliente *pCliente) {

    printf(" - Cliente %s %s\n",pCliente->Nombre, pCliente->Apellido );
    printf(" - CVU: %s\n", pCliente->cuenta.CVU);
}


void HistorialTransacciones ( tCliente * pCliente){


    printf("\n-------------- Listado de Transacciones ------------- \n");
    for (int i = 0; i < pCliente->cuenta.historialTransacciones; i++)
    {
       printf("Transaccion : %s", pCliente->cuenta.historialTransacciones[i]);
    }
    
}

void main () {

  struct tCliente clientes[4] = {
 {"Gonzalez", "Juan", 12345678, {15, 5, 1990}, "pass123", {"123456789",
 1000.0, NULL, 0}},
 {"Lopez", "Maria", 87654321, {10, 8, 1985}, "pass456", {"987654321",
 1500.0, NULL, 0}},
 {"Navarro", "Marcelo", 85651321, {19, 2, 1979}, "pass450", {"987654321",
 41500.0, NULL, 0}},
 {"Medina", "Nazareno", 87654321, {21, 10, 1980}, "pass999", {"987654321",
 25500.0, NULL, 0}}
 };

Menu( clientes,4);
}