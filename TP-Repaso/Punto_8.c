/*
 Julia, encargada de ventas de ropa en una feria, quiere lanzar una serie de descuentos para incentivar
    al publico comprador y atraer nuevos clientes.

    la ropa que vende pertenece a 3 categorias: 1: invierno, 2:verano, 3: multiestacion.
    las formas de pago son: 1: efectivo, 2:debito, 3:tarjeta de credito.

    para calcular el monto final a pagar por un producto, julia propone los siguientes descuentos
    sobre el precio lista o base:

    -   Si el producto es de invierno y se vende entre los meses de septiembre y marzo tienen un descuento
        del 30% sobre el precio lista.
    -   Si el producto es de verano y se vende entre los meses de abril y agosto tienen un descuento
        del 35 % sobre el precio lista.
    -   Para los productos multiestacion el descuento es de 20% sobre el precio lista.

    a la hora de pagar segun la forma de pagom si se paga en efectivo tiene un descuento del 10%
    si abona con debito tiene un 5% de descuento, pero si paga con tareta de credito tiene un recargo
    del un 5% sobre el monto total.

    Realice un algoritmo para el problema de julia tal que ingrese el monto base de la prenda, el mes,
    la categoria y la forma de pago. luego calcule el monto final a pagar por el cliente.
    debe incluir al menos una funcion para el calculo de descuento por categoria y una funcion 
    para el descuento segun la forma de pago.


    Calcule el monto total recayudado durante el dia para una cantidad no determinada de clientes

categoria: z+ {1: invierno, 2:verano, 3: multiestacion }
FUNCION calculo_descuento (categoria, precio_base) : z+ --> r+
    precio_descuento: r+;
    mes: z+;

SEGUN categoria   
1: SI (1<=mes <= 3 OR 9<=mes<=12)  ENTONCES
        precio_descuento <-- precio_base - (precio_base*0.30) SINO
            precio_descuento <-- precio_base;

FIN_SEGUN

RETORNAR precio_descuento;


formaPago : z+ {1:efectivo, 2: debito, 3:credito}
FUNCION formaPago (formaPago, precio_base) z+ --> r+
var_aux: descuento

SEGUN formaPago
    1: descuento <-- precio_base - (precio_base*0.10)
    2: descuento <-- precio_base - (precio_base*0.5)
    3: descuento <-- precio_base + (precio_base*0.5)
SINO
    precio_base;

 FIN_sEGUN

    RETORNAR descuento:
 FIN_FUNCION


ALGORITMO: Venta_Ropa
ENTRADA: categoria: z+ {1: invierno, 2:verano, 3: multiestacion }
        formaPago
        precio_base
        cliente
        mes
 SALIDA:precio_final, total_recaudado
 VAR_AUX: precio_descuento_base, precio_descuento_pago:   

 A0_INCIALIZAR
    precio_final <-- 0
A1_ calcular_Precio_Final
    LEER (cliente)
         Mientras cliente < 0
                LEER (categoria, formaPago, precio_base, mes)
                        precio_descuento_base <-- calculo_descuento (categoria, precio_base);
                        precio_descuento_pago <-- FormaPago (formaPago, precio_base);
            precio_final <-- precio_descuento_base + precio_descuento_pago;
                    ESCRIBIRA (precio_final)
                            LEER (cliente)
             Total_recaudado <-- total_recaudado + precio_final    
                            precio_final <-- 0

           FIN_MIENTRAS

    A2_ ESCRIBIR (total_recaudado)
    A3_PARAR           
                
                
                */

#include <stdio.h>

int calculo_Descuento_Categoria(int categoria, int mes, float precio_base);
int ElegirFormaPago (int formaPago, float precio_base);

int main() {
    int categoria;
    int mes;
    int formaPago;
    float precio_base, precio_Descuento;
    float Forma_Pago_Descuento;
    float total_Recaudado;
    float precio_Final_cliente;


    do  {
        printf("Ingresar Precio Base (Ingresar '0' para salir): ");
        scanf("%f", &precio_base);

        if (precio_base == 0)
        {
            break;
        }
        

        printf("Ingresar Categoria: \n");
        printf("\t 1- 'Invierno'\n");
        printf("\t 2- 'Verano'\n");
        printf("\t 3- 'Multiestacion'\n");
        scanf("%d", &categoria);
  
        printf("Ingresar Mes:\n ");
        printf ("\t 1- Septiembre - Marzo");
        printf ("\t 2- Abril - Agosto");
        printf ("\t 3 - Multiestacion ");
        scanf("%d", &mes);

         printf("Ingresar Forma de Pago: \n");
        printf("\t 1- 'Efectivo'\n");
        printf("\t 2- 'Debito'\n");
        printf("\t 3- 'Credito (Recargo)'\n");
        scanf("%d", &formaPago); 

      
   precio_Descuento = calculo_Descuento_Categoria( categoria,  mes,  precio_base);
    Forma_Pago_Descuento = ElegirFormaPago (formaPago, precio_base);
    precio_Final_cliente = Forma_Pago_Descuento;
        printf("El precio final a pagar es: %.2f\n", precio_Final_cliente);

         total_Recaudado += precio_Final_cliente; 

       
         
          
    } while (1);

    printf ("El final recaudado es: %.2f", total_Recaudado);
   
    


    return 0;
}

int calculo_Descuento_Categoria (int categoria, int mes, float precio_base){
float Precio_Descuento = precio_base;


    switch (categoria)
    {
    case 1:
            if ((1<=mes && mes<=3) || (9<=mes && mes<=12))
            {
               Precio_Descuento = precio_base*0.70;
            } else {
                Precio_Descuento = precio_base;
            }           
        break;
          case 2:
            if ((1<=mes && mes<=4) || (8<=mes && mes<=12))
            {
               Precio_Descuento = precio_base*0.70;
            } else {
                Precio_Descuento = precio_base*0.65;
            }           
        break;
       case 3:
            if (mes == 3)
            {
               Precio_Descuento = precio_base;
            }            
        break;
   
    }

return Precio_Descuento;

}

int ElegirFormaPago (int formaPago, float precio_base){

float descuento = precio_base;

switch (formaPago)
{
case 1:
        descuento = precio_base*0.90;
    break;
case 2:
        descuento = precio_base*0.95;
    break;    
case 3:
        descuento = precio_base*1.05;
    break;  
}

return descuento;
}
