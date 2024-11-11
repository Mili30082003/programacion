#include <stdio.h>
#include <stdlib.h>

int LongitudCadena(const char *str);


int main () {

    char *Frase = malloc(100 * sizeof(char)); // Reserva de memoria 
   

    printf("Ingrese una cadena: ");
    fgets(Frase, 100, stdin); // Leo la cadena 

    int len = LongitudCadena(Frase);

    // Elimino el caracter de nueva linea si esta presente
    if (Frase[len-1] == '\n')
    {
        Frase[len-1] = '\0';
        
        len--; // Ajusto la longitud si se elimino el salto de linea
    }
    
    printf("Longitud: %d", len);

    free(Frase);

    return 0;
}

int LongitudCadena(const char *str){

    int len=0; // Inicializo la Longitud en 0

    while (*str != '\0') // Mientras el caracter actual sea distino de nulo ---> \0
    {
        len++; // Incremento la longitud
        str++; // avanzo al siguiente caracter 
    }
    
    return len;

}