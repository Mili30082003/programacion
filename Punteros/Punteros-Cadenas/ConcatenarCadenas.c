#include <stdio.h>
#include <stdlib.h>

void Concatenar (char *cadena1, const char *cadena2){

        while (*cadena1)
        {
            cadena1++;
        }

        while (*cadena2)
        {
            *cadena1 = *cadena2;
            cadena1++;
            cadena2++;
        }
        
        *cadena1 = '\0';

}



void main () {

char *cad1 = malloc(100 * sizeof(char));

printf("Ingresar la cadena 1: ");
fgets(cad1, 100, stdin);

char *cad2 = malloc(100 * sizeof(char));

printf("Ingresar la Cadena 2: ");
fgets(cad2, 100, stdin);


Concatenar(cad1, cad2);
printf("Cadena Concatenada: %s\n", cad1);



free(cad1);
free(cad2);

}