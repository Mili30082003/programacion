#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cliente
{
    char razonSocial[50];
    char telefono[20];
} typedef Cliente;

struct Empleado
{
    char Nombre[50];
    char Apellido[50];

} typedef Empleado;

struct Pedido
{
    Cliente cliente;
    Empleado empleado;
    int cantidad;

} typedef Pedido;

struct Especie
{
    char Ncientifico[30];
    char categoria[20];
    char Nvulgar[30];
} typedef Especie;

struct Arbol
{
    Especie especie;
    int stock;
    float precio;
    int cantPedidos;
    Pedido *pedidos;
} typedef Arbol;

Arbol *cargarDatos()
{
    int cantidadArboles = 3; // Cantidad de arboles a cargar

    // Inicializo la memoria para los arboles
    Arbol *parbol = malloc(sizeof(Arbol) * cantidadArboles);

    // Datos para el arbol "Roble Americano"
    parbol[0].especie = (Especie){"Quercus rubra", "caduca", "Roble Americano"};
    parbol[0].stock = 10;
    parbol[0].precio = 10000;
    parbol[0].cantPedidos = 2;
    parbol[0].pedidos = (Pedido *)malloc(sizeof(Pedido) * 2);
    parbol[0].pedidos[0] = (Pedido){{"ASRR", "3814499121"}, {"Milagros", "Antoni"}, 3};
    parbol[0].pedidos[1] = (Pedido){{"BRSS", "3812236"}, {"Gabriel", "Saloa"}, 2};

    // Datos para el arbol "Arce Rojo"
    parbol[1].especie = (Especie){"Robleis Americano", "perenne", "Arce Rojo"};
    parbol[1].stock = 15;
    parbol[1].precio = 20000;
    parbol[1].cantPedidos = 3;
    parbol[1].pedidos = (Pedido *)malloc(sizeof(Pedido) * 3);
    parbol[1].pedidos[0] = (Pedido){{"MRSS", "3812215"}, {"Josefa", "Sansone"}};
    parbol[1].pedidos[1] = (Pedido){{"LRSS", "3814556"}, {"Anahi", "Del Valle"}, 4};
    parbol[1].pedidos[2] = (Pedido){{"LRSS", "3814562"}, {"Victor", "Antoni"}, 5};

    // Datos para el arbol "Pino"
    parbol[2].especie = (Especie){"Pinus sylvestris", "perenne", "Pino"};
    parbol[2].stock = 20;
    parbol[2].precio = 30000;
    parbol[2].cantPedidos = 1;
    parbol[2].pedidos = (Pedido *)malloc(sizeof(Pedido) * 1);
    parbol[2].pedidos[0] = (Pedido){{"HRSS", "3815692"}, {"Luissina", "Latina"}, 3};

    return parbol;
}

void MostrarArboles(Arbol *parbol)
{
    for (int i = 0; i < 3; i++)
    {
        printf("Arbol %d: \n", i + 1);
        printf("\t Especie: %s\n", parbol[i].especie);
        printf("\t Categoria: %s\n", parbol[i].especie.categoria);
        printf("\t Precio %.2f\n", parbol[i].precio);
    }
}
void MostrarStock(Arbol *parbol)
{
    int cantStock = 0;
    printf("Ingresar Stock a buscar: ");
    scanf("%d", &cantStock);

    printf("Arboles con stock menor a %d\n", cantStock);
    int encontrados = 0;

    for (int i = 0; i < 3; i++)
    {
        if (parbol[i].stock < cantStock)
        {
            encontrados = 1;
            printf("Arbol %d: \n", i + 1);
            printf("\t Especie: %s\n", parbol[i].especie);
            printf("\t Categoria: %s\n", parbol[i].especie.categoria);
            printf("\t Precio %.2f\n", parbol[i].precio);
            printf("\t Stock: %d\n", parbol[i].stock);
        }
    }

    if (!encontrados)
    {
        printf("No se encontraron arboles");
    }
}

void MostrarPedidos(Arbol *parbol)
{

    for (int i = 0; i < 3; i++)
    {

        printf("\n Nombre Vulgar: %s\n", parbol[i].especie.Nvulgar);

        if (parbol[i].cantPedidos > 0 && parbol[i].especie.Nvulgar != NULL)
        {

            printf("\n ***** PEDIDOS *****\n");
            for (int j = 0; j < parbol[i].cantPedidos; j++)
            {
                float totalPedido = parbol[i].pedidos[j].cantidad * parbol[i].precio;
                printf("\t Cliente %d\n ", j + 1);
                printf("\t Razon Social: %s\n", parbol[i].pedidos[j].cliente.razonSocial);
                printf("\t Telefono: %s\n", parbol[i].pedidos[j].cliente.telefono);
                printf("\t Empleado: %s %s\n", parbol[i].pedidos[j].empleado.Nombre, parbol[i].pedidos[j].empleado.Apellido);
                printf("\t Cantidad: %d\n", parbol[i].pedidos[j].cantidad);
                printf("Total: %.2f\n", totalPedido);
            }
        }
    }
}

void AgregarPedidos (Arbol * parbol, int cantArboles  ) {
char NombreVulgar[30];
printf("Ingrese el nombre vulgar de la especie: ");
fflush(stdin);
gets(NombreVulgar);


// Buscar el arbol por su nombre vulgar
int indideArbol = -1;

for (int i = 0; i < cantArboles; i++)
{
    if (strcmp(parbol[i].especie.Nvulgar, NombreVulgar) == 0)
    {
        indideArbol = i;
        break;
    }
    
}

// Si no encuentra el arbol, muestro un mensaje
if (indideArbol == -1)
{
    printf("La especie con nombre vulgar %s no fue encontrada. \n", NombreVulgar);
    return;
}

// Verifico si hya stock disponible 
if (parbol[indideArbol].stock <= 0)
{
    printf("No hay stock disponible para la especie %s \n", parbol[indideArbol].especie.Nvulgar);
    return;
}

// Crear Pedido
Pedido nuevoPedido;

printf("Ingrese la razon social del cliente: ");
gets(nuevoPedido.cliente.razonSocial);
printf("Ingrese el telefono celular: ");
gets(nuevoPedido.cliente.telefono);

printf("Ingrese el nombre del empleado: ");
gets(nuevoPedido.empleado.Nombre);
printf("Ingrese el Apellido del empleado: ");
gets(nuevoPedido.empleado.Apellido);

printf("Ingrese la cantidad de pedidos: ");
scanf("%d", &nuevoPedido.cantidad);

// Verifico si la cantidad pedida supera el stock
if (nuevoPedido.cantidad > parbol[indideArbol].stock)
{
    printf("No hay suficiente stock. Stock disponibe: %d\n", parbol[indideArbol].stock);
    return;
}

// Restar el stock y agregar el pedido
parbol[indideArbol].stock -= nuevoPedido.cantidad;
parbol[indideArbol].pedidos = (Pedido *)malloc(sizeof(Pedido));
parbol[indideArbol].pedidos[0] = nuevoPedido;
parbol[indideArbol].cantPedidos = 1;

printf("Pedido agregado a la especie '%s'. \n", parbol[indideArbol].especie.Nvulgar);

}

void ActualizarStock (Arbol *parbol, int cantArboles){

        char NombreVulgar[30];
        printf("Ingrese el nombre vulgar de la especie: ");
        getchar();
        gets(NombreVulgar);

        // Buscar el arbol por su nombre vulgar
        int indiceArbol = -1;

        for (int i = 0; i < cantArboles; i++)
        {
            if (strcmp(parbol[i].especie.Nvulgar, NombreVulgar) == 0)
            {
                indiceArbol = i;
                break;
            }
            
        }
        
        // Si no se encuentra el arbol
        if (indiceArbol == -1)
        {
            printf("La especie con nombre %s no fue encontrada\n", NombreVulgar);
            return;
        }
        
    int NuevoStock;
    printf("Ingrese el nuevo stock para la especie '%s': ", parbol[indiceArbol].especie.Nvulgar);
    scanf("%d", &NuevoStock);

    // Calculo la cantidad total de pedidos
    int totalPedidos = 0;
    for (int i = 0; i < parbol[indiceArbol].cantPedidos; i++)
    {
        totalPedidos += parbol[indiceArbol].pedidos[i].cantidad;
    }

    if (NuevoStock < totalPedidos)
    {
        printf("El nuevo stock no puede ser inferior a los pedidos vigentes (%d) \n", totalPedidos);
        return;
    }
    
 // Actualizar el stock

 parbol[indiceArbol].stock = NuevoStock;
    printf("El stock de la especie '%s' ha sido actualizado a %d\n", parbol[indiceArbol].especie.Nvulgar, NuevoStock);
}

void ActualizarPrecio (Arbol * parbol, int cantArboles) {

    char NombreVulgar[30];
    printf("Introduce el Nombre vulgar de la espcie: ");
   fflush(stdin);
    gets(NombreVulgar);

    // Busco el Arbol por su nombre Vulgar
    int indice = -1;
    for (int i = 0; i < cantArboles; i++) 
    {
        if (strcmp(parbol[i].especie.Nvulgar, NombreVulgar) == 0)
        {
            indice = i;
            break;
        }
              
    }

        if (indice == -1)
        {
            printf("El arbol no fue encontrado \n");
            return;
        } 
    
    float NuevoPrecio;
    printf("Ingrese el nuevo precio para la especie: ");
    scanf("%f", &NuevoPrecio);

  parbol[indice].precio = NuevoPrecio;
  printf("El nuevo precio de la especie %s es: %.2f\n", parbol[indice].especie.Nvulgar, NuevoPrecio);

}


void main()
{

    Arbol *parbol = cargarDatos();

int opcion;

do
{
   printf(" *** Gestion de Operacion ***\n");
   printf("Ingrese: \n");
   printf("\t 1 - Mostrar todos los arboles/especies disponibles\n");
   printf("\t 2 - Mostrar arboles/especies segun stock\n");
   printf(" \t 3 - Agregar pedidos\n");
   printf("\t 4 -Mostrar todos los pedidos\n");
   printf("\t 5 -Actualizar stock de un especie\n");
   printf("\t 6 - Actualizar el precio de una especie\n");
   printf("\t 7 - Salir\n");
   printf("Opcion: ");
   scanf("%d", &opcion);

   switch (opcion)
   {
   case 1:
        MostrarArboles(parbol);
    break;
      case 2:
        MostrarStock(parbol);
    break;
       case 3:
      AgregarPedidos(parbol, 3 );
    break;
       case 4:
       MostrarPedidos(parbol);
       
    break;
      case 5:
       ActualizarStock(parbol, 3);
    break;
       case 6:
     ActualizarPrecio(parbol, 3);
       
    break;
           case 7:
    printf("Saliendo...");
    break;

   default:
   printf("Opcion No Valida");
    break;
   }

} while (opcion != 7);


}