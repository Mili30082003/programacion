#include <stdio.h>

int EsVocal (char letra);

int main () {
char estrofa;
char letra;
char vocal;

printf ("Ingresar una Vocal: ");
scanf ("%c", &vocal);
 getchar();
printf ("Ingresar una etsrofa de una cancion ");
scanf ("%c", &estrofa);

while (estrofa != '.')
{
 
     
        if ( EsVocal(estrofa) )
        {
         estrofa = vocal;
        }
        printf ("%c", estrofa);
        scanf ("%c", &estrofa);
   }
 
   return 0;
}



int EsVocal (char letra) {

if (letra == 'a' || letra == 'e' || letra == 'i'|| letra == 'o'|| letra == 'u' )
{
        return 1;
} else {
    return 0;
}

}