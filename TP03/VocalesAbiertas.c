#include <stdio.h>
#include <ctype.h>
int main () {

char oracion;
char MF = '.';
int cant_a=0, cant_e=0, cant_o=0;
int cant_total=0;

printf ("Ingresar una oracion terminada en un punto: ");
scanf ("%c", &oracion);

while (oracion != MF)
{
     oracion = tolower(oracion);
    switch (oracion)
    {
    case 'a':
            cant_a++;
        break;
        case 'e':
            cant_e++;
        break;
            case 'o':
            cant_o++;
        break;

    }
    scanf("%c", &oracion);
}

cant_total = (cant_a + cant_e + cant_o);

printf ("La cantidad de a es : %d\n", cant_a);
printf ("La cantidad de e es: %d\n", cant_e);
printf("La cantidad de o es: %d\n", cant_e);
printf("La cantidad total es: %d\n", cant_total);


}