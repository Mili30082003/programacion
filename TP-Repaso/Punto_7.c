/*. Considere una frase como una secuencia de caracteres con marca final. las palabras que la componen
    estan separadas por uno o mas blancos.
    diseñar y escribir un algoritmo para calcular y mostrar la cantidad total de palabras que finalizan en "on"
    el algoritmo debe procesar cualquier frase con las caracteristicas descriptas.

    por ejemplo, si la frase ingresada es:
    
    La_ _cancion_ _es_ _una_ _ _composicion.
    
    la cantidad total de palabras terminadas en "on": 2
    
    ALGORITMO:
    
    
    */

   
#include <stdio.h>



int main()
{

    char frase, anterior = ' ';
    int cantON = 0;
    char MF = '.';

       printf("Ingresar una frase Terminada en un '.': ");
                    frase = getchar(); 


    while (frase != MF)
    {
     
            if (anterior == 'n' && frase == ' ' )
               {
                 cantON++;
               }

            anterior = frase;  
  
             
            
   
       frase = getchar();
    }
    
  

   
   printf ("Palabras Terminadas en ON: %d", cantON);

    return 0;
}
