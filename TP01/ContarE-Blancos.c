#include <stdio.h>

int main () {
    char frase;
    int cant_blancos = 0;
    char MF = '.';

    printf ("Ingresa una frase terminada en un punto : ");
    scanf ("%c", &frase);
 
    while (frase != MF)
    {
            if (frase == ' ')
            {
               cant_blancos++;
            }
             scanf ("%c", &frase);
    }
    
    printf ("La cantidad de espacios en blancos es : %d", cant_blancos);

    return 0;

}