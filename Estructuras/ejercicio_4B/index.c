#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char razonsocial[100];
    int telefono;
} datoCliente;

typedef struct
{
    char apellido[100];
    char nombre[100];
} datoEmpleado;

typedef struct
{
    int cantidad;
    datoEmpleado empleado;
    datoCliente *cliente;
} pedidos;

typedef struct
{
    char nombrecientifico[100];
    char categoria[100];
    char nombrevulgar[100];

} datoEspecie;

typedef struct
{
    int stock;
    float precio;
    int cantPed;
    pedidos *ped;
    datoEspecie *especie;
} producto;
void agregar(producto *agregar, int cant);
void mostar(producto *mostar, int cant);
void mostrarPedidos(producto *pedido, int cant);
void mostrarStock(producto *mostrar, int cant);
int main()
{
    int cant = 5;
    producto *produc = (producto *)malloc((size_t)cant * sizeof(producto));
    produc[0] = (producto){2, 500, 2, NULL, NULL};

    produc[0].ped = (pedidos *)malloc((size_t)produc[0].cantPed * sizeof(pedidos));

    produc[0].ped[0] = (pedidos){2, {"juan", "gomez"}, NULL};
    produc[0].ped[0].cliente = (datoCliente *)malloc((size_t)produc[0].ped[0].cantidad * sizeof(datoCliente));
    produc[0].ped[0].cliente[0] = (datoCliente){"SRA", 526556};
    produc[0].ped[0].cliente[1] = (datoCliente){"SRA", 526556};

    produc[0].ped[1] = (pedidos){2, {"juan", "gomez"}, NULL};
    produc[0].ped[1].cliente = (datoCliente *)malloc((size_t)produc[0].ped[1].cantidad * sizeof(datoCliente));
    produc[0].ped[1].cliente[0] = (datoCliente){"SRA", 526556};
    produc[0].ped[1].cliente[1] = (datoCliente){"SRA", 526556};

    produc[0].especie = (datoEspecie *)malloc((size_t)produc[0].cantPed * sizeof(datoEspecie));
    produc[0].especie[0] = (datoEspecie){"hoja ancha", "caduca", "Roble americano"};
    produc[0].especie[1] = (datoEspecie){"conífera", "perenne", "Pino silvestre"};
    //************************************************* */

    *(produc + 1) = (producto){2, 844, 2, NULL, NULL};
    (produc + 1)->ped = (pedidos *)malloc(2 * sizeof(pedidos));
    *(produc + 1)->ped = (pedidos){2, {"juan", "gomez"}, NULL};
    (produc + 1)->ped->cliente = (datoCliente *)malloc(2 * sizeof(datoCliente));
    *(produc + 1)->ped->cliente = (datoCliente){"SRA", 545451};
    *(((produc + 1)->ped)->cliente + 1) = (datoCliente){"SRA", 4854};
    *((produc + 1)->ped + 1) = (pedidos){2, {"juan", "gomez"}, NULL};
    ((produc + 1)->ped + 1)->cliente = (datoCliente *)malloc(2 * sizeof(datoCliente));
    *((produc + 1)->ped + 1)->cliente = (datoCliente){"SRA", 545451};
    *(((produc + 1)->ped + 1)->cliente + 1) = (datoCliente){"SRA", 4854};

    produc[1].especie = (datoEspecie *)malloc((size_t)produc[1].cantPed * sizeof(datoEspecie));
    produc[1].especie[0] = (datoEspecie){"hoja ancha", "caduca", "Roble americano"};
    produc[1].especie[1] = (datoEspecie){"conífera", "perenne", "Pino silvestre"};

    //********************************************************************************************* */
    produc[2] = (producto){2, 500, 2, NULL, NULL};

    produc[2].ped = (pedidos *)malloc((size_t)produc[2].cantPed * sizeof(pedidos));

    produc[2].ped[0] = (pedidos){2, {"juan", "gomez"}, NULL};
    produc[2].ped[0].cliente = (datoCliente *)malloc((size_t)produc[2].ped[0].cantidad * sizeof(datoCliente));
    produc[2].ped[0].cliente[0] = (datoCliente){"SRA", 526556};
    produc[2].ped[0].cliente[1] = (datoCliente){"SRA", 526556};

    produc[2].ped[1] = (pedidos){2, {"juan", "gomez"}, NULL};
    produc[2].ped[1].cliente = (datoCliente *)malloc((size_t)produc[2].ped[1].cantidad * sizeof(datoCliente));
    produc[2].ped[1].cliente[0] = (datoCliente){"SRA", 526556};
    produc[2].ped[1].cliente[1] = (datoCliente){"SRA", 526556};

    produc[2].especie = (datoEspecie *)malloc((size_t)produc[2].cantPed * sizeof(datoEspecie));
    produc[2].especie[0] = (datoEspecie){"hoja ancha", "caduca", "Roble americano"};
    produc[2].especie[1] = (datoEspecie){"conífera", "perenne", "Pino silvestre"};
    //************************************************************************************************ */
    produc[3] = (producto){2, 500, 2, NULL, NULL};

    produc[3].ped = (pedidos *)malloc((size_t)produc[3].cantPed * sizeof(pedidos));

    produc[3].ped[0] = (pedidos){2, {"juan", "gomez"}, NULL};
    produc[3].ped[0].cliente = (datoCliente *)malloc((size_t)produc[3].ped[0].cantidad * sizeof(datoCliente));
    produc[3].ped[0].cliente[0] = (datoCliente){"SRA", 526556};
    produc[3].ped[0].cliente[1] = (datoCliente){"SRA", 526556};

    produc[3].ped[1] = (pedidos){2, {"juan", "gomez"}, NULL};
    produc[3].ped[1].cliente = (datoCliente *)malloc((size_t)produc[3].ped[1].cantidad * sizeof(datoCliente));
    produc[3].ped[1].cliente[0] = (datoCliente){"SRA", 526556};
    produc[3].ped[1].cliente[1] = (datoCliente){"SRA", 526556};

    produc[3].especie = (datoEspecie *)malloc((size_t)produc[3].cantPed * sizeof(datoEspecie));
    produc[3].especie[0] = (datoEspecie){"hoja ancha", "caduca", "Roble americano"};
    produc[3].especie[1] = (datoEspecie){"conífera", "perenne", "Pino silvestre"};

    produc[4] = (producto){50, 500, 0, NULL, NULL};
    agregar(produc, cant);
    mostar(produc, cant);
    mostrarPedidos(produc, cant);
    mostrarStock(produc, cant);
    return 0;
}
void agregar(producto *agregar, int cant)
{
    int cantidad, indiceI = 0, telefono, opcion;
    char nombre[100], apellido[100], razonSocial[100];
    printf("Si desea realizar una nueva compra precione 1: ");
    scanf("%d", &opcion);
    if (opcion == 1)
    {

        printf("\nIngrese la cantidad deseada: ");
        scanf("%d", &cantidad);
        for (int i = 0; i < cant; i++)
        {
            if (agregar[i].cantPed == 0)
            {
                if (agregar[i].stock < cantidad)
                {
                    printf("\nno se puede realizar la compra por falta de stock");
                    break;
                }
            }
        }

        indiceI = cant - 1;

        printf("\nPARTE DEL VENDEDOR....");
        getchar();
        printf("\nIndique el nombre del vendedor: ");
        gets(nombre);
        printf("\nIndique el apellido del vendedor: ");
        gets(apellido);
        printf("\nPARTE DEL CLIENTE....");
        printf("\nIngrese su razon social: ");
        gets(razonSocial);
        printf("\nIndique su numero de telefono: ");
        scanf("%d", &telefono);
        agregar[indiceI].ped = (pedidos *)malloc(1 * sizeof(pedidos));
        agregar[indiceI].ped[0].cantidad = 1;
        strcpy(agregar[indiceI].ped[0].empleado.apellido, apellido);
        strcpy(agregar[indiceI].ped[0].empleado.nombre, nombre);
        agregar[indiceI].ped[0].cliente = (datoCliente *)malloc(1 * sizeof(datoCliente));
        strcpy(agregar[indiceI].ped[0].cliente[0].razonsocial, razonSocial);
        agregar[indiceI].ped[0].cliente[0].telefono = telefono;
        agregar[indiceI].cantPed = 1;
        agregar[indiceI].especie = (datoEspecie *)malloc((size_t)agregar[indiceI].cantPed * sizeof(datoEspecie));
        agregar[indiceI].especie[0] = (datoEspecie){"hoja ancha", "caduca", "Olmo siberiano"};

        agregar[indiceI].stock -= cantidad;
        printf("\ndatos de la compra");
        printf("\nNuevo stock disponible: %d", agregar[indiceI].stock);
        printf("\nNombre del vendedor: ");
        puts(agregar[indiceI].ped[0].empleado.nombre);
        printf("\nApellido del vendedor: ");
        puts(agregar[indiceI].ped[0].empleado.apellido);
        printf("\nRazon social del cliente: ");
        puts(agregar[indiceI].ped[0].cliente[0].razonsocial);
        printf("\nTelefono del cliente: %d", agregar[indiceI].ped[0].cliente[0].telefono);
    }
}
void mostar(producto *mostar, int cant)
{
    int r = 1;
    for (int i = 0; i < cant; i++)
    {
        for (int d = 0; d < mostar[i].cantPed; d++)
        {
            printf("\ncompra numero %d: ", r);
            printf("\nCategoria: ");
            puts(mostar[i].especie[d].categoria);
            printf("\nNombre cientifico: ");
            puts(mostar[i].especie[d].nombrecientifico);
            printf("\nNombre vulgar: ");
            puts(mostar[i].especie[d].nombrevulgar);
            r++;
        }
    }
}
void mostrarPedidos(producto *pedido, int cant)
{
    int y = 0;
    for (int i = 0; i < cant; i++)
    {
        for (int d = 0; d < pedido[i].cantPed; d++)
        {
            for (int c = 0; c < pedido[i].ped[d].cantidad; c++)
            {
                printf("La compra numero %d fue realizaca por el cliente de numero de telefono %d, con total a pagar de: %2.f y de razon social: ", y + 1, pedido[i].ped[d].cliente[c].telefono, pedido[i].precio);
                puts(pedido[i].ped[d].cliente[c].razonsocial);
                y++;
            }
        }
    }
}
void mostrarStock(producto *mostrar, int cant)
{
    int num;
    printf("Ingrese un numero para comparar: ");
    scanf("%d", &num);
    for (int i = 0; i < cant; i++)
    {
        for (int d = 0; d < mostrar[i].cantPed; d++)
        {
            if (num > mostrar[i].stock)
            {

                printf("Los arboles disponibles (nombre cientifico) son: ");
                puts(mostrar[i].especie[d].nombrecientifico);
                printf("Los arboles disponibles (nombre vulgar) som :");
                puts(mostrar[i].especie[d].nombrevulgar);
                printf("las categorias de los arboles son: ");
                puts(mostrar[i].especie[d].categoria);
            }
        }
    }
}