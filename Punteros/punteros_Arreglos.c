// correspondencia entre arrays y punteros 

#include <stdio.h>

void main() {
    int numeros [5] = {1,2,3,4,5};

    int *dir_numeros;

   // dir_numeros = &numeros[0]; --> es lo mismo que hacer esto :

   dir_numeros = numeros; // apunta el primero elemento del Array numeros

   for (int i = 0; i < 5; i++)
   {
        // Imprimir todos los elementos del vector pero utilizando punteros
        printf("Elementos del Vector [%d]: %d\n", i, *dir_numeros);
        dir_numeros++; // Avanza al elemento siguiente
        
        
   }
   



}