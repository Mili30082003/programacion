#include <stdio.h>

int main () {
    char frase;
    int cant_P = 0;
    char MF = '.';
    char anterior = ' ';

    printf ("Ingresar una frase terminada en un punto: ");
    scanf ("%c", &frase);

    while (frase != MF)
    {
        if (anterior == ' ')
        {
            cant_P++;
        }
        anterior = frase;

        scanf ("%c", &frase);
    }
    
    printf ("La cantidad de palabras es: %d", cant_P);

    return 0;

}