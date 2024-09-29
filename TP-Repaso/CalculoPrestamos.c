#include <stdio.h>

float CalculoCuotas (int cuota, float sueldo_neto);
int main () {
float total_invertido = 0, porcentaje= 0;
float sueldo_neto;
int antiguedad, totalempleados;; 
float calculoInteres ;
int cuotas;
int empleados_calificados = 0,
empleados_nocalificados = 0, totalempleados_nocalificados= 0;
 // empleado esta en verdadero

while (1)
{
        printf ("\nIngresar el Sueldo Neto (0 para salir) :\n ");
        scanf ("%f", &sueldo_neto);
        if (sueldo_neto == 0 )
        {
           break;
        }
        
         printf ("Ingresar años trabajados:\n ");
        scanf ("%d", &antiguedad);
 
          
       
        if (sueldo_neto <= 150000 && antiguedad >= 5)
        {
            printf ("Inngresar cuotas:\n ");
        printf("\t 1- 12 cuotas\n");
        printf("\t 2- 24 cuotas\n");
        printf("\t 3- 48 cuotas\n");
        scanf ("%d", &cuotas);

        calculoInteres = CalculoCuotas(cuotas, sueldo_neto);

        printf ("El total a pagar es: %.2f", calculoInteres);

        total_invertido = totalempleados + calculoInteres;

        empleados_calificados++;
} else { 
      
        empleados_nocalificados++;
         printf ("\nDebe al menos tener 5 años de antiguedad y el Sueldo Neto no debe superar los 150.000\n");}

         totalempleados = empleados_calificados + empleados_nocalificados;
        }
        
       

       



printf ("\nEl total de empleados es: %d\n", totalempleados);

printf ("\nTotal Invertido es:  %.2f", total_invertido);

totalempleados_nocalificados += empleados_nocalificados;
porcentaje = empleados_nocalificados/ totalempleados_nocalificados*100; // tengo que calcular el porcentaje de los que no pueden tener el interes
    printf ("\nporcentaje de empleados no calificados: %.2f", porcentaje);


    return 0;
}

float CalculoCuotas (int cuotas, float sueldo_neto){
float total_cuota = sueldo_neto;
switch ( cuotas)
{
case 1:
       
        total_cuota = total_cuota + total_cuota* 0.34;

        
    break;

case 2:
       
        total_cuota = total_cuota + total_cuota* 0.48;

       
    break;
case 3:
       
        total_cuota = total_cuota + total_cuota* 0.48;

        
    break; 
case 4:
       
        total_cuota = total_cuota + total_cuota* 0.48;

        
    break;        
default:
    break;
}

return total_cuota;

}