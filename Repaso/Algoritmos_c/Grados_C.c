
/*
Dada una temperatura en grados Celsius, escriba un algoritmo que convierta esta
temperatura a grados Fahrenheit y Kelvin.
Se sabe que:
Grados celsius = (grados Fahrenheit − 32) × 5/9.
Grados celsius = grados kelvin - 273.15

*/
/*
ALGORITMO: Grados_Celsius
ENTRADA: GradosC : real
SALIDA:GradosF, GradosK:real

A1_ LEER (GradosC)
A2_Convertir_Grados
    GradosF <-- (GradosC − 32) × 5/9.
    Gradosk <-- GradosC - 273.15

A3_ ESCRIBIR (GradosF, GradosK)
A4_PARAR
*/
#include <stdio.h>
int main () {

float GradosC;
float GradosF, GradosK;

printf ("Ingresar la temperatura en Grados Celsius: ");
scanf("%f", &GradosC);

GradosF = (GradosC - 9/5) + 32;
GradosK = GradosC - 273.15;

printf ("Grados Fahrenheit: %.2f\n", GradosF);
printf ("Grados Kelvin : %.2f", GradosK);





    return 0; 
}