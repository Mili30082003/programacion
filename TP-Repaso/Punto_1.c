/*Diseñar un algoritmo que dada una frase terminada en un punto cuente la cantidad de vocales,
   consonantes y espacios en blanco.
   
   ALGORITMO: Consonantes_vocales_blancos
   ENTRADA: frase: cc con MF '.'
   SALIDA: cantVocales, cantConsonantes, cantBlancos: z+
   VAR_AUX: anterior <-- ' '
   A0_INICIALIZAR
    cantVocales <-- 0
    cantConsonantes <-- 0
    cantBlancos <-- 0

A1_Contar_consonantes_vocales_blancos
        LEER (frase)
            MIENTRAS frase <> MF
                SI frase = 'a' vocales ENTONCES
                    cant_vocales++
                    SINO
                        SI anterior = ' ' ENTONCES
                            cantConsonantes++
                        SINO SI frase = ' ' ENTONCES
                                cantBlancos++
                                FIN_SI
                LEER (frase)
            FIN_MIENTRAS
A2_ESCRIBIR (cant_vocales, cant_consonantes, cantBlancos)
A3_PARAR
   */

#include <stdio.h>

int main () {

char frase;
int cant_consonante = 0;
int cant_blancos = 0;
int cant_vocales = 0; 
char MF = '.';
char anterior = ' ';

printf ("Ingresar una frase terminada en un punto: ");
scanf ("%c", &frase);


        while (frase != MF)
        {
            if (frase == 'a' || frase == 'e' || frase == 'i' || frase == 'o' || frase == 'u')
            {
                cant_vocales++;
            } else if (frase == ' ')
            {
                cant_blancos++;
            }else{
                cant_consonante++;
            }
            
            /*else if ( anterior = ' ')
            {
               cant_consonante++;
            }
           
             if (frase == ' ')
            {
                cant_blancos++;
            }*/
              anterior = frase;
            scanf ("%c", &frase);          

        }

        printf ("La cantidad de vocales es: %d\n", cant_vocales);
        printf ("La cantidad de blancos es: %d\n", cant_blancos);
        printf ("La cantidad de consonantes es: %d\n", cant_consonante);
        
return 0;
}

