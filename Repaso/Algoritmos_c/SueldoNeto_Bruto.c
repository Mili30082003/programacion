/*
Modifique el algoritmo del punto 5 sabiendo que el sueldo bruto se compone del
sueldo básico que se lee de entrada y se aumenta un porcentaje según la
categoría:
Categoría 1: se aumenta un 5% del básico.
Categoría 2: se aumenta un 10% del básico.
Categoría 3: se aumenta un 30% del básico.
Categoría 4: se aumenta un 40% del básico.
En otro caso, no hay aumento de sueldo. Los descuentos se realizan en base al
monto bruto. Muestre el sueldo neto y el bruto
*/
/*
ALGORITMO: Calcular_Salario_Empleado
ENTRADA: sueldo_basico:real, categoria:entero
SALIDA: sueldo_neto, sueldo_bruto: real
CONSTANTES: SegSocial : 6
            AportesJ: 11;
            AsosiacionG: 2, 
            FNE: 1,5

A1_LEER (sueldo_basico)
A2_Calcular_Descuntos
    LEER (categoria)
    SEGUN categoria
            1: sueldo_bruto <-- sueldo_basico + (sueldo_basico*0.5)
            2: sueldo_bruto <-- sueldo_basico + (sueldo_basico*0.10)
            3: sueldo_bruto <-- sueldo_basico + (sueldo_basico*0.30)
            4: sueldo_bruto <-- sueldo_basico + (sueldo_basico*0.40)
           SINO
                sueldo_neto <-- (sueldo_basico*SegSocial)
                sueldo_neto <-- (sueldo_basico*AportesJ)
                sueldo_neto <-- (sueldo_basico*AsociacionG)
                sueldo_neto <-- (sueldo_basico*FNE)
    FIN_SEGUN
A3_ESCRIBIR (sueldo_bruto, sueldo_neto)
A4_PARAR
*/
#include <stdio.h>
int main () {
int categoria;
float sueldo_basico; /*entrada*/
float sueldo_neto, sueldo_bruto;/*salida*/

 const float SEGSOCIAL = 6.0 / 100;      // Convertimos los porcentajes a decimales
    const float APORTESJ = 11.0 / 100;
    const float ASOCIACIONG = 2.0 / 100;
    const float FNE = 1.5 / 100;

printf ("Ingresar sueldo basico: ");
scanf ("%f", &sueldo_basico);
printf ("Ingresar categoria del 1 al 4: ");
scanf ("%d", &categoria);

switch (categoria)
{
case 1:
    sueldo_bruto = sueldo_basico + (sueldo_basico*0.5);
    break;
    case 2:
    sueldo_bruto = sueldo_basico + (sueldo_basico*0.10);
    break;
    case 3:
    sueldo_bruto = sueldo_basico + (sueldo_basico*0.30);
    break;
    case 4:
    sueldo_bruto = sueldo_basico + (sueldo_basico*0.40);
    break;

default:
sueldo_neto = sueldo_basico - (sueldo_basico * SEGSOCIAL) 
                               - (sueldo_basico * APORTESJ) 
                               - (sueldo_basico * ASOCIACIONG) 
                               - (sueldo_basico * FNE);

    break;
}
     
printf ("El Sueldo Bruto es : %.2f\n", sueldo_bruto);
printf ("El Sueldo Neto es : %.2f", sueldo_neto);



    return 0; 
}