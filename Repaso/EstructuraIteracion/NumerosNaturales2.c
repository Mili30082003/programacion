#include <stdio.h>
int main () {
    
    int num;
        printf("Introduce un número positivo (o 0 o negativo para terminar): ");
        scanf ("%d", &num);
    int suma = 0; /*Siempre hay que inicializar en 0,  lo que es más apropiado para un acumulador.*/
   
    while (num > 0)
    {
        suma = suma + num;
             printf("Introduce otro número (o 0 o negativo para terminar): ");
            scanf ("%d", &num);
        
    }
      
     printf ("La suma de los  Numeros es : %d", suma);

    

    return 0; 
}