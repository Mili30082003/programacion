
/*
Un empleado quiere saber cúal será su salario neto conociendo los descuentos
que le van a realizar a partir del sueldo básico. Diseñe un algoritmo que resuelva
este problema sabiendo que se aplican los siguientes descuentos:
- Seguridad social: 6%
- Aportes jubilatorios: 11%
- Asociación al gremio: 2%
- Fondo Nacional de Empleo: 1,5%
*/
/*
ALGORITMO: Calcular_Salario_Empleado
ENTRADA: sueldo_basico:real
SALIDA: sueldo_neto: real
CONSTANTES: SegSocial : 6
            AportesJ: 11;
            AsosiacionG: 2, 
            FNE: 1,5

A1_LEER (sueldo_basico)
A2_Calcular_Descuntos
    sueldo_neto <-- (sueldo_basico*SegSocial)
    sueldo_neto <-- (sueldo_basico*AportesJ)
     sueldo_neto <-- (sueldo_basico*AsociacionG)
      sueldo_neto <-- (sueldo_basico*FNE)

A3_ESCRIBIR (sueldo_neto)
A4_PARAR

*/


#include <stdio.h>
int main () {

float sueldo_basico; /*entrada*/
float sueldo_neto;/*salida*/

 const float SEGSOCIAL = 6.0 / 100;      // Convertimos los porcentajes a decimales
    const float APORTESJ = 11.0 / 100;
    const float ASOCIACIONG = 2.0 / 100;
    const float FNE = 1.5 / 100;

printf ("Ingresar sueldo basico: ");
scanf ("%f", &sueldo_basico);

     
    sueldo_neto = sueldo_basico - (sueldo_basico * SEGSOCIAL) 
                               - (sueldo_basico * APORTESJ) 
                               - (sueldo_basico * ASOCIACIONG) 
                               - (sueldo_basico * FNE);

printf ("El Sueldo Neto es : %.2f", sueldo_neto);



    return 0; 
}