/* 1- Desarrollar un programa que al ingresar una palabra por teclado informe por pantalla la cantidad de vocales que contiene
    2- Modificar el programa anterior para que informe tambien cuente la cantidad total de plabras, la cantidad de consonantes y reemplace todas las vocales por 'X'*/

    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>


int EsVocal (char letra);
int main () {

char palabra [20];
int i = 0;
int Vocal;
int CantConsonantes = 0;
int CantLetras;


printf ("Ingrese una palabra: ");
scanf ("%s", palabra);

while (palabra[i] != '\0')
{
    printf ("%c\n", palabra[i]);

Vocal = EsVocal (palabra[i] );
    if (Vocal == 1)
    {
        palabra[i] = 'X';
    } else {

    CantConsonantes++;
    }
    
    i++;
}

CantLetras = strlen (palabra);
    printf("\nLa palabra modificada es: %s\n", palabra);
printf ("La cantidad de letras es: %d\n", CantLetras);
printf ("La cantidad de consonantes es: %d\n",CantConsonantes);

return 0;
}
 
int EsVocal (char letra) { 
 letra = tolower(letra);

switch (letra)
{
    case 'a':
                return 1;
        break;
    case 'e':
                return 1;
        break;
    case 'i':
            return 1;
    break;
    case 'o':
            return 1;
    break;
    case 'u':
            return 1;
    break;
default:
            return 0;
    break;
}


}