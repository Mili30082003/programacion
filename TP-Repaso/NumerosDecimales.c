/*Ingresar 5 numeros decimales por teclado, almacenarlos n un vecto y luego imprimirlos por Pantalla*/

#include <stdio.h>


 
int main () {

float VectorDecimales [5];

for (int i = 0; i < 5; i++)
{
    printf ("Ingresar 5 numeros decimales: ");
    scanf ("%f", &VectorDecimales[i]);
}



for (int i = 0; i < 5; i++)
{

printf ("\nNumeros: %.2f\n", VectorDecimales[i]);


}

return 0;
}

