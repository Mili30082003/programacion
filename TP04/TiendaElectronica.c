#include <stdio.h>

void menuElectrodomesticos ();
void MenuInformatica ();
void FormaDePago ();
float ObtenerPrecioProducto (int categoria, int producto);
float PrecioFinal_por_FormaDePago(float precioProducto, int medioPago);

int main () {

    int categoria;
    int productoSeleccionado;
    float precioProducto;
    int formaPago;
    float precioFinal;
    float totalDiario = 0;

    do {
        printf ("Elije la categoria:\n ");
        printf ("\t-1: Electrodomesticos\n");
        printf ("\t-2: Informatica\n");
        printf ("\t-3: Finalizar\n");
        fflush(stdin);
        scanf ("%d", &categoria);

        switch (categoria)
        {
            case 1:
                menuElectrodomesticos();
                break;
            case 2:
                MenuInformatica();
                break; 
            default:
                if (categoria != 3)
                {
                    printf ("Categoria no valida\n");
                }
                break;
        }

        if (categoria == 1 || categoria == 2)
        {
            scanf("%d", &productoSeleccionado);
            if (1 <= productoSeleccionado && productoSeleccionado <= 3)
            {
                FormaDePago();
                fflush(stdin);
                scanf("%d", &formaPago);

                if (1 <= formaPago && formaPago <= 4)
                {
                    precioProducto = ObtenerPrecioProducto(categoria, productoSeleccionado);
                    precioFinal = PrecioFinal_por_FormaDePago(precioProducto, formaPago);
                    totalDiario += precioFinal;
                    printf("El precio final del producto es: %.2f\n", precioFinal);
                }
                else
                {
                    printf("Forma de pago no válida\n");
                }
            }
            else
            {
                printf("Producto no válido\n");
            }
        }
    } while (categoria != 3);

    printf("Total recaudado durante el dia es: %.2f\n", totalDiario);

    return 0;
}

void menuElectrodomesticos() {
    printf("Seleccione el Producto:\n");
    printf("-----Electrodomesticos-----\n");
    printf("\t 1 - Heladera: %c 850.000\n", 36);  // Código ASCII $
    printf("\t 2 - Lavarropas: %c 759.000\n", 36);
    printf("\t 3 - Microondas: %c 520.000\n", 36);
}

void MenuInformatica() {
    printf("Seleccione el Producto:\n");
    printf("-----Informatica-----\n");
    printf("\t 1 - Laptop: %c 1.500.000\n", 36);  // Código ASCII $
    printf("\t 2 - Tablet: %c 755.000\n", 36);
    printf("\t 3 - Smartphone: %c 539.000\n", 36);
}

void FormaDePago() {
    printf("Seleccione la Forma de Pago:\n");
    printf("\t 1 - Efectivo (10%% descuento)\n");
    printf("\t 2 - Tarjeta de crédito a 1 cuota\n");
    printf("\t 3 - Tarjeta de crédito a 3 cuotas (15%% interés)\n");
    printf("\t 4 - Tarjeta de crédito a 6 cuotas (25%% interés)\n");
}

float ObtenerPrecioProducto(int categoria, int producto) {
    float precio_producto = 0;

    switch (categoria)
    {
        case 1:  // Electrodomésticos
            switch (producto)
            {
                case 1:
                    precio_producto = 850000;
                    break;
                case 2:
                    precio_producto = 759000;
                    break;
                case 3:
                    precio_producto = 520000;
                    break;
            }
            break;
        case 2:  // Informática
            switch (producto)
            {
                case 1:
                    precio_producto = 1500000;
                    break;
                case 2:
                    precio_producto = 755000;
                    break;
                case 3:
                    precio_producto = 539000;
                    break;
            }
            break;
    }
    return precio_producto;
}

float PrecioFinal_por_FormaDePago(float precioProducto, int medioPago) {
    float precioFinal;

    switch (medioPago)
    {
        case 1:
            precioFinal = precioProducto * 0.9;  // 10% de descuento por pago en efectivo
            break;
        case 2:
            precioFinal = precioProducto;  // Sin cambios para 1 cuota
            break;
        case 3:
            precioFinal = precioProducto * 1.15;  // 15% de interés por 3 cuotas
            break;
        case 4:
            precioFinal = precioProducto * 1.25;  // 25% de interés por 6 cuotas
            break;
        default:
            precioFinal = precioProducto;  // Por si acaso, aunque no debería llegar aquí
            break;
    }
    return precioFinal;
}