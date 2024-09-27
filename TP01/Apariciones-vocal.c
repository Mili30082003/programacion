#include <stdio.h>

int main() {
    char frase;
    char vocal;
    int cant_vocal = 0;
    char MF = '.';

    // Leer la vocal a buscar
    printf("Ingrese una vocal: ");
    scanf(" %c", &vocal);

    // Validar que la vocal ingresada es una vocal
    if (vocal != 'a' && vocal != 'e' && vocal != 'i' && vocal != 'o' && vocal != 'u' &&
        vocal != 'A' && vocal != 'E' && vocal != 'I' && vocal != 'O' && vocal != 'U') {
        printf("El carácter ingresado no es una vocal.\n");
        return 1; // Terminar el programa con error
    }

    // Limpiar el buffer después de leer la vocal
    while ((getchar()) != '\n');

    // Leer la frase hasta encontrar un punto
    printf("Ingrese una frase terminada en un punto: ");
    while ((frase = getchar()) != MF) { 
        if (frase == vocal) {
            cant_vocal++;
        }
    }

    // Mostrar el resultado
    printf("La cantidad de apariciones es: %d\n", cant_vocal);

    return 0;
}