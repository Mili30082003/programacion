/*
Un alumno necesita saber la nota final de una materia que se calcula
promediando las notas de los 3 parciales. Diseñe un algoritmo que muestre la
nota final ingresando como dato las 3 notas de parciales.
*/
/*
PSEUDOCODIGO

ALGORITMO: Nota_parciales
ENTRADA: nota_1, nota_2, nota_3: real
SALIDA: nota_final: real

A1_ LEER (nota_1, nota_2, nota_3)

A2_Calcular_nota_final
    nota_final <-- (nota_1, nota_2, nota_3)/3

A3_ESCRIBIR (nota_final);
A4_PARAR
*/
#include <stdio.h>
int main () {
    
float nota_1, nota_2, nota_3; /* float --> convierte entero a real*/
float nota_final; /* mi salida*/

    printf ("Ingresar la nota de los 3 parciales: ");
    scanf ("%f", &nota_1); /*lee las notas, '%f significa que lee la nota_1 como real'*/ 
    scanf ("%f", &nota_2);
    scanf ("%f", &nota_3);

    nota_final = (nota_1 + nota_2 + nota_3)/3;

    printf ("La nota final es: %.2f", nota_final); /* %.2f me da dos decimales */



    return 0; /*Siempre tiene que retornar 0*/
}