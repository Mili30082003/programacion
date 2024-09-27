#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarArreglo(int arreglo[], int tama, int num1, int num2);
void mostrarArreglo(int arreglo[], int tama);
int buscarMayor(int arreglo[], int tama);
void mostrarPromedio(int arreglo[], int tama);
void reemplazarNumero(int arreglo[], int tama, int numeroNuevo);
void IncrementarImpares(int arreglo[], int tama);





int main () {

int CargarArreglos;

int arreglo[];
int tamaño;
int num1 = 10;
int num2 = 350;
int numeroNuevo;
int numeroAntiguo;

printf ("Ingrese un numero: ");
scanf ("%d", &tamaño);

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


for (int i = 0; i < tama; i++)
{
    arreglo [i] = num1 + rand () % (num2 - num1 + 1);

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

int mayor = arreglo[0];
for (int i = 1; i < tama; i++)
{
    if ( arreglo[0] > mayor)
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
    if ( arreglo[i] % 2 != 0 )
    {
         sumaImpares += arreglo [i];
         contadorImpares++;
    }
    

}
if (contadorImpares > 0)
{
    float promedio = (float)sumaImpares / contadorImpares;
    printf ("El promedio de los numeros impares es : %.2f\n",promedio);
} else {
    printf ("No hay numeros impares en el arreglo.\n");
}


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

int contadorImpares = 0;
for (int i = 0; i < tama; i++)
{
    if ( arreglo[i] % 2 != 0 )
    {
    
         contadorImpares++;
    }
    printf("Numeros Impares: %d\n");

} }