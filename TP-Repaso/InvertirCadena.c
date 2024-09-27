#include <stdio.h>
#include <string.h>

int main () {
char frase [] = "Hola Mundo";
int longitud, mitad, i;
char FraseInvertida;



longitud = strlen (frase);
mitad = longitud / 2;

printf ("La frase original es:%s\n ", frase);

for ( i = 0; i < mitad; i++)
{
        FraseInvertida = frase[i];
         frase[i] = frase[longitud - i - 1];
        frase[longitud - i - 1] = FraseInvertida;
}
printf ("La frase invertida es: %s\n", frase);

return 0;
}
