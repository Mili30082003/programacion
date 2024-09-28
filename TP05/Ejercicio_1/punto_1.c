#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMA 15

void cargarArreglo(int arreglo[], int tama, int num1, int num2);
void mostrarArreglo(int arreglo[], int tama);
int buscarMayor(int arreglo[], int tama);
void mostrarPromedio(int arreglo[], int tama);
void reemplazarNumero(int arreglo[], int tama, int numeroNuevo);
void IncrementarImpares(int arreglo[], int tama);





int main () {

int CargarArreglos;

int arreglo[TAMA];
int num1 = 10;
int num2 = 350;
int numeroNuevo;
int numeroAntiguo;


  srand(time(NULL));

cargarArreglo( arreglo, TAMA, num1, num2);
mostrarArreglo( arreglo, TAMA);
mostrarPromedio( arreglo, TAMA);
int mayor = buscarMayor(arreglo, TAMA);
printf ("El valor mayor del arreglo es : %d\n",mayor);
IncrementarImpares( arreglo, TAMA);

printf ("Ingrese un numero: ");
scanf ("%d", &numeroNuevo);
reemplazarNumero(arreglo, TAMA, numeroNuevo);

printf ("Arreglo modificado: \n");
for (int i = 0; i < TAMA; i++)
{
    printf ("%d\n",arreglo[i]);
}
printf ("\n");

 return 0;   
}





void cargarArreglo(int arreglo[], int tama, int num1, int num2){

if (num1 < num2) { 
for (int i = 0; i < tama; i++)
{
    arreglo [i] = num1 + rand () % (num2 - num1 + 1);

}
} else { /*Hago este control para verificar si num1 es menor que num2 entonces funciona bien a la hora de cargar el arreglo, si num1 es mayor que num2 entonces se intercambian las posiciones de la formula para buscar rango */

}
for (int i = 0; i < tama; i++)
{
    arreglo [i] = num2 + rand () % (num1 - num2 + 1);

}
 }

 void mostrarArreglo(int arreglo[], int tama)
{

printf ("Arreglo cargado: \n ");

for (int i = 0; i < TAMA; i++)
{
    printf ("%d",&arreglo[i]);
}

printf ("\n");


}

int buscarMayor(int arreglo[], int tama){

int mayor = 0;
for (int i = 0; i < tama; i++)
{
    if ( arreglo[i] > mayor)
    {
          mayor = arreglo[i];
    }
    

}
 return mayor;
     
}

void mostrarPromedio(int arreglo[], int tama){
int sumaImpares = 0;
int contadorImpares = 0;

for (int i = 0; i < tama; i++)
{
    if (i % 2 != 0 )
    {
         sumaImpares += arreglo [i];
         contadorImpares++;
    }
}
    printf ("El promedio de los numeros impares es : %d\n",sumaImpares/contadorImpares);
}


void reemplazarNumero(int arreglo[], int tama, int numeroNuevo){
for (int i = 0; i < tama; i++)
{
    if (arreglo[i] > 300)
    {
      arreglo[i] = numeroNuevo;      
    }
    
}


}

void IncrementarImpares(int arreglo[], int tama){


for (int i = 0; i < tama; i++)
{
    if ( arreglo[i] % 2 != 0 )
    {
    
        arreglo[i]++;
    }
    printf("arreglo (%d): %d\n", arreglo[i]);

} }