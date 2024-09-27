
/*
Escriba un algoritmo que reciba una temperatura en grados Celsius y determine el
estado de la temperatura según los siguientes criterios:
- Frío: si la temperatura es menor a 10 grados.
- Templado: si la temperatura está entre 10 y 25 grados.
- Caliente: si la temperatura es mayor a 25 grados.
*/
/*
ALGORITMO: Determinar_temperatura_estado
ENTRADA: GradosC: real
SALIDA: estado : cc
 A1_ LEER (GradosC)
 A2_ Determinar_Estado
    SEGUN GradosC
        GradosC < 10 : estado <-- 'Frio'
        10 < GradosC < 25 : estado <-- 'Templado'
        GradosC > 25 : estado <-- caliente
     FIN_SEGUN
  A3_ ESCRIBIR (estado)
  A4_PARAR      
*/


#include <stdio.h>
int main () {

float GradosC;
char estado; /*Guarda solo un caracter*/

printf ("Ingresar Temperatura en Grados Celsius: ");
scanf ("%f", &GradosC); 

if (GradosC < 10)
{
    estado = 'F'; /*No puedo poner 'Frio' porque no guarda una cadena de caracteres*/
} else
if (GradosC >= 10 && GradosC < 25) /*En C se compara asi */
{
    estado = 'T';
} else 
{
    estado = 'C';
}

printf("El estado es : %c\n", estado);  /*%c\n significa que muestra mi salida con un caracter y '\n' es una salto de linea */


    return 0; 
}