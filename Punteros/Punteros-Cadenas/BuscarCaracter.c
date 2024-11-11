#include <stdio.h>
#include <stdlib.h>

int BuscarCaracter(const char *frase,char caracter ){
    int posicion = 0;
        while (*frase)
        {
            if (*frase == caracter)
            {
               return posicion; 
            }
            frase++;
            posicion++;
        }
        return 1; // retorna 1 si no se encuentra el caracter
}

void main () {

char *frase = malloc(100 * sizeof(char));
char caracter;
printf("Ingresar Caracter : ");
scanf("%c", &caracter);
getchar();
printf("Ingresar frase: ");
fgets(frase, 100, stdin);

int pos = BuscarCaracter(frase, caracter);

if (pos != 1)
{
    printf("El caracter '%c' se encuentra en la posicion: %d\n", caracter, pos);

} else {
    printf("El caracter '%c' no se encuentra en la frase \n", caracter);
}

free(frase);


}