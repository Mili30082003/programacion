#include <stdio.h>
int main () {
  
    int suma = 0; /*Siempre hay que inicializar en 0,  lo que es más apropiado para un acumulador.*/
  
    
    for (int i = 0; i <= 10; i++)
    {
        suma = suma + i;

    }
    printf ("La suma de los primeros 10  Numeros es : %d", suma);
    

    return 0; 
}