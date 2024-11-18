#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CuentaBancaria
{
    char *cbu;
    char *tipo_cuenta;
    float SaldoActual;
} typedef CuentaBancaria;

struct Cliente
{
    char *Sucursal;
    int Dni;
    char *Nombre;
    CuentaBancaria *cuentas;
    int cantCuenta;

} typedef Cliente;

void cargarClientes(Cliente *clientes, int cantClientes)
{

    for (int i = 0; i < cantClientes; i++)
    {
        clientes[i].Sucursal = malloc(sizeof(char) * 50);
        clientes[i].Nombre = malloc(sizeof(char) * 50);

        printf("\n ----- Cliente %d ------\n", i + 1);
        printf("\n - Sucursal: ");
        fflush(stdin);
        gets(clientes[i].Sucursal);
        printf("\n - DNI: ");
        fflush(stdin);
        scanf("%d", &clientes[i].Dni);
        printf("\n - Nombre del Cliente: ");
        fflush(stdin);
        gets(clientes[i].Nombre);

        printf("\nCantidad de cuentas bancarias: ");
        scanf("%d", &clientes[i].cantCuenta);

        //  libros[i].TituloLibro = realloc(libros[i].TituloLibro, strlen(libros[i].TituloLibro) + 1);

        clientes[i].Sucursal = realloc(clientes[i].Sucursal, strlen(clientes[i].Sucursal) + 1);
        clientes[i].Nombre = realloc(clientes[i].Nombre, strlen(clientes[i].Nombre) + 1);

        clientes[i].cuentas = malloc(sizeof(CuentaBancaria) * clientes[i].cantCuenta);

        for (int j = 0; j < clientes[i].cantCuenta; j++)
        {
            clientes[i].cuentas[j].cbu = malloc(sizeof(char) * clientes[i].cantCuenta);

            clientes[i].cuentas[j].tipo_cuenta = malloc(sizeof(char) * clientes[i].cantCuenta);

            printf("Cuenta %d: \n", j + 1);
            printf("Numero de cuenta/CBU: ");
            fflush(stdin);
            gets(clientes[i].cuentas[j].cbu);
            printf("\nTipo de Cuenta: (Ahorro / Corriente / Dolares): ");
            fflush(stdin);
            gets(clientes[i].cuentas[j].tipo_cuenta);
            printf("\nSaldo Actual: ");
            fflush(stdin);
            scanf("%f", &clientes[i].cuentas[j].SaldoActual);

            clientes[i].cuentas[j].cbu = realloc(clientes[i].cuentas[j].cbu, strlen(clientes[i].cuentas[j].cbu));
            clientes[i].cuentas[j].tipo_cuenta = realloc(clientes[i].cuentas[j].tipo_cuenta, strlen(clientes[i].cuentas[j].tipo_cuenta) + 1);
        }
    }
}

//  1. Módulo para mostrar el cliente con el mayor número de cuentas bancarias

void MayorNumeroCuentasBancarias(Cliente *clientes, int cantClientes)
{

    int maxCuentas = 0, pos = -1;

    for (int i = 0; i < cantClientes; i++)
    {
        if (clientes[i].cantCuenta > maxCuentas)
        {
            maxCuentas = clientes[i].cantCuenta;
            pos = i;
        }
    }

    if (maxCuentas > 1)
    {
        printf("\nCliente con mayor número de cuentas:\n");
        printf("Nombre: %s\nSucursal: %s\nNúmero de cuentas: %d\n",
               clientes[pos].Nombre,
               clientes[pos].Sucursal,
               clientes[pos].cantCuenta);
    }
    else
    {
        printf("\nNo hay clientes con más de 1 cuenta bancaria.\n");
    }
}

void CuentaSaldoMayor(Cliente *clientes, int cantClientes, float valor)
{

    printf("\n Cuentas con saldo mayor a %.2f: \n", valor);
    for (int i = 0; i < cantClientes; i++)
    {
        for (int j = 0; j < clientes[i].cantCuenta; j++)
        {
            if (clientes[i].cuentas[j].SaldoActual > valor)
            {
                printf("Cliente: %s | CBU %s | Saldo: %.2f", clientes[i].Nombre, clientes[i].cuentas[j].cbu, clientes[i].cuentas[j].SaldoActual);
            }
        }
    }
}
// void MostrarClientes (Cliente * clientes, int cantClientes){

//         for (int i = 0; i < cantClientes; i++)
//         {
//             printf("\n Cliente %s : \n", clientes[i].Nombre);
//             printf("  Sucursal: %s\n", clientes[i].Sucursal);
//             printf("  DNI: %d\n", clientes[i].Dni);
//             printf("  Cuentas Bancarias: \n");

//             for (int j = 0; j < clientes[i].cantCuenta; j++)
//             {
//                 printf("    Cuenta %d\n", j + 1);
//                 printf("    Numero de Cuenta/CBU : %s\n", clientes[i].cuentas[j].cbu);
//                 printf("    Tipo de Cuenta: %s\n", clientes[i].cuentas[j].tipo_cuenta);
//                 printf("    Saldo Actual: %.2f", clientes[i].cuentas[j].SaldoActual);
//             }

//         }
// }

void clientesCentroDolares(Cliente *clientes, int cantClientes)
{
    for (int i = 0; i < cantClientes; i++)
    {
        if (strcmp(clientes[i].Sucursal, "Centro") == 0)
        {
            for (int j = 0; j < clientes[i].cantCuenta; j++)
            {
                if (strcmp(clientes[i].cuentas[j].tipo_cuenta, "Dolares") == 0 && clientes[i].cuentas[j].SaldoActual > 10000)
                {
                    printf("Cliente: %s | CBU: %s | Saldo %.2f\n", clientes[i].Nombre, clientes[i].cuentas[j].cbu, clientes[i].cuentas[j].SaldoActual);
                }
            }
        }
    }
}

void LiberarMemoria(Cliente *clientes, int cantClientes)
{
    for (int i = 0; i < cantClientes; i++)
    {
        for (int j = 0; j < clientes[i].cantCuenta; i++)
        {
            free(clientes[i].cuentas[j].cbu);
            free(clientes[i].cuentas[j].tipo_cuenta);
        }
        free(clientes[i].cuentas);
        free(clientes[i].Nombre);
        free(clientes[i].Sucursal);
    }
    free(clientes);
}

void main()
{

    int cantiClientes;

    printf("Ingrese La cantidad de Clientes:\n ");
    scanf("%d", &cantiClientes);

    Cliente *clientes = malloc(sizeof(Cliente) * cantiClientes);

    cargarClientes(clientes, cantiClientes);
    // MostrarClientes(clientes, cantiClientes);
    MayorNumeroCuentasBancarias(clientes, cantiClientes);

    float Saldo;
    printf("Ingresar un saldo para buscar cuentas: ");
    scanf("%f", &Saldo);
    CuentaSaldoMayor(clientes, cantiClientes, Saldo);

    clientesCentroDolares(clientes, cantiClientes);

    LiberarMemoria(clientes, cantiClientes);
}