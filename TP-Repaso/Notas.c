/*Solicitar el ingreso de notas (que pueden tener decimales) y almacenarlas en un vector hasta que el usuario ingrese 0 (Se permite hasta un maximo de 30 notas), luego mostrar por pantalla el listado de notas ingresadas*/

#include <stdio.h>

int main () {

float Notas [30];
float promedio;

for (int i = 0; i < 30; i++)
{
    printf ("Ingresar hasta 30 notas: ");
    scanf ("%f", &Notas[i]);
    if (Notas [i] == 0)
{
   break;
} 
    
}


for (int i = 0; i < 30; i++)
{

if (Notas [i] == 0)
{
   break;
} else {  

    printf ("\nNota: %.2f\n", Notas [i]);}

}




    return 0;
}