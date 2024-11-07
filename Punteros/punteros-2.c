#include <stdio.h>

int main () {


//int numero;

/*printf("Ingresar un valor: ");
scanf("%d", &numero);*/

/*El nombre del arreglo es una referencia a la direccion de memoria a la primera componente del arreglo
<--- el nombre es un Puntero de la primera componente del Arreglo
   */


int numeros[5] = {2,4,6,8,10}; /* Al arreglo lo puedo manipular como un puntero */

int CantPares = 0;


for (int i = 0; i < 5; i++)
{
    CantPares++;
}


// Apuntar a un arreglo : 

// Forma 1 : 
int *p_arreglo =  numeros; // numeros ya va la direccion de memoria 
//Apunto al primero elemento del arreglo

// Forma 2 :
//int *p_arreglo2 = &numeros[0];

//Notacion de subIndice
for (int i = 0; i < 5; i++)
{
    printf("numeros[%d=%d]", i, numeros[i]); // Estoy Ingresando a la primera direccion, cuando hago *p_arreglo se va a mostrar el primer elemento

}

int *pAux = p_arreglo;// cuando recorro el arreglo y despues pierdo la direccion debo tener un puntero auxiliar
//p_arreglo siempre va a apunatr el primer elemento del arreglo y el que se movera sera *pAux
// Este no va a importar que pierda la direccion de memoria 
printf("\n");
//Notacion de Punteros
for (int i = 0; i < 5; i++)
{
    printf("numeros[%d=%d]", i, *pAux); // Estoy Ingresando a la primera direccion, cuando hago *p_arreglo se va a mostrar el primer elemento

    pAux++; // para mostrar otros elementos del arreglo
}


// Si necesito seguir trabajando con el arreglo
int *p_Aux2 = p_arreglo; // declaro otro auxiliar 

  


    return 0;
}