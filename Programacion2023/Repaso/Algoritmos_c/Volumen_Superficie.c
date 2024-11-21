
/*
 Dado el radio y la altura de un cilindro, escriba un algoritmo que calcule el
volumen y el área de se superficie. Use las siguientes fórmulas:
-Volumen = PI * radio² * altura
-Superficie = 2 * PI * radio * (radio + altura)
Nota: PI puede ser una constante de valor fijo 3,14.

*/
/*
PSEUDOCODIGO

ALGORITMO: Volumen_superficie_cilindro
ENTRADA: radio, altura: real
SALIDA: volumen, superficie: real
CONSTANTE: PI = 3,14

A1_ LEER (radio, altura)
A2_Calcular_radio_superficie
    volumen <-- (PI*radio*radio*altura)
    superficie <-- (2*PI*radio*(radio + altura))

A3_ ESCRIBIR (volumen, superficie)
A4_PARAR
*/
#include <stdio.h>
int main () {

float radio, altura; /*entrada*/
float volumen, superficie; /*salida*/

const float PI = 3.14; /*tengo que declarar el tipo de dato, en este caso declare que PI es tipo float (real)*/

printf ("Ingrese el radio : ");
scanf ("%f", &radio);
printf ("Ingrese la altura : ");

scanf("%f", &altura);

volumen = (PI * radio *radio * altura);
superficie = (2*PI*radio*(radio + altura));

 printf("El volumen es: %.2f\n", volumen); /*%.2f\n  <-- \n significa salto de linea*/
    printf("La superficie es: %.2f\n", superficie);




    return 0; 
}