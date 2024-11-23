#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DatosProveedor
{
    char Nombre[50];
    char telefono[20];

} typedef DatosProveedor;

struct fechaVentaProducto
{
    int dia;
    int mes;
    int anio;

} typedef fechaProducto;

struct Producto
{
    char Nombre[50];
    float precioUnitario;
    int cantVentas;
    DatosProveedor datosproveedor;
    fechaProducto fecha;

} typedef Producto;

Producto *cargarDatos()
{

    int cantProductos = 5;

    Producto producto1 = {"Labial", 5000, 2, {"Milagros", "3814499121"}, {18, 11, 2024}};

    Producto producto2 = {"Rubor", 6000, 1, {"Luissina", "38145562"}, {19, 11, 2024}};

    Producto producto3 = {"Paleta de Ojos", 8134, 5, {"Lucero", "3814556"}, {20, 11, 2024}};

    Producto producto4 = {"Brochas", 7000, 4, {"Ailin", "3814563"}, {22, 11, 2024}};

    Producto producto5 = {"Brillos", 4000, 3, {"Martina", "38145610"}, {14, 11, 2024}};

    Producto *productos = malloc(sizeof(Producto) * cantProductos);

    productos[0] = producto1;
    productos[1] = producto2;
    productos[2] = producto3;
    productos[3] = producto4;
    productos[4] = producto5;

    return productos;
}

void MostrarDatos(Producto *productos, int cantProductos)
{

    for (int i = 0; i < cantProductos; i++)
    {
        printf("Producto %d\n", i + 1);
        printf("\t - Nombre: %s\n", productos[i].Nombre);
        printf("\t - Precio: %.2f\n", productos[i].precioUnitario);
        printf("\t - Cantidad Ventas: %d\n", productos[i].cantVentas);
        printf("\n *** Datos Proveedor ***\n");
        printf("\t - Nombre: %s\n", productos[i].datosproveedor.Nombre);
        printf("\t - Telefono: %s\n", productos[i].datosproveedor.telefono);
        printf("\t - Fecha: %d/%d/%d\n", productos[i].fecha.dia, productos[i].fecha.mes, productos[i].fecha.anio);
    }
}

void ModificarPrecio(Producto *productos, int cantProductos)
{

    char NombreProducto[50];
    printf("Ingresar el Nombre del producto: ");
    fflush(stdin);
    gets(NombreProducto);

    int indice = -1;

    for (int i = 0; i < cantProductos; i++)
    {
        if (strcmp(productos[i].Nombre, NombreProducto) == 0)
        {
            indice = i;
            break;
        }
    }

    float NuevoPrecio;
    printf("Ingrese el Nuevo precio para el producto '%s': ", NombreProducto);
    scanf("%f", &NuevoPrecio);

    productos[indice].precioUnitario = NuevoPrecio;

    printf("El nuevo precio del producto '%s': %.2f\n", NombreProducto, NuevoPrecio);
}

void CalcularMonto(Producto *productos, int cantProductos)
{

    float TotalMonto = 0;

    for (int i = 0; i < cantProductos; i++)
    {
        TotalMonto += productos[i].cantVentas * productos[i].precioUnitario;
    }
    printf("Monto total es: %.2f\n", TotalMonto);
}

void ProductoConMasVentas (Producto * productos, int cantProductos)
{

    int MaxVenta = 0;
    int indice = -1;


    for (int i = 0; i < cantProductos; i++)
    {

        if ( productos[i].cantVentas > MaxVenta )
        {
             MaxVenta = productos[i].cantVentas;
            indice = i;
        }
        
        
    }

if (indice != -1)
{
     printf(" El producto con mas ventas es: %s\n cantidad de ventas: %d\n", productos[indice].Nombre, MaxVenta);
} else {
    printf("No hay producto registrado\n");
}

   

    
}
void main()
{

    int cantProductos = 4;
    Producto *productos = cargarDatos();

    int opcion;
    do
    {
        printf("\n *** Menu ****\n");
        printf("Elige una opcion \n");
        printf("\t . Mostrar productos\n");
        printf("\t . Modificar Precio\n");
        printf("\t . Calcular Monto Total\n");
        printf("\t . Mostrar el Mes con mas Ventas\n");
        printf("\t - Salir del programa\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            MostrarDatos(productos, cantProductos);
            break;
        case 2:
            ModificarPrecio(productos, cantProductos);
            break;
        case 3:
            CalcularMonto(productos, cantProductos);
            break;
        case 4:
            CalcularMonto(productos, cantProductos);
            break;
        case 5:
           ProductoConMasVentas(productos, cantProductos);

            break;
                   case 6:
          printf("Salir del programa\n");

            break;
        default:
        printf("Opcion invalida");
            break;
        }
    } while (opcion != 6);
}