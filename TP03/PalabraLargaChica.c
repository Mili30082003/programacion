#include <stdio.h>

int main() {
    char frase;
    int palabraLarga = 0;
    int palabraCorta = 0;
    int contador = 0;

    printf("Ingresar una frase terminada en un punto: ");
    scanf("%c", &frase);
    
    while (frase != '.') {
        if (frase != ' ') {
            contador++;
        } else {
            if (contador > 0) {
                if (contador > palabraLarga) {
                    palabraLarga = contador;
                }
                if (palabraCorta == 0 || contador < palabraCorta) {
                    palabraCorta = contador;
                }
                contador = 0;  // Reinicia el contador para la siguiente palabra
            }
        }
        scanf("%c", &frase);
    }
    
    // Considera la última palabra si no termina con un espacio
    if (contador > 0) {
        if (contador > palabraLarga) {
            palabraLarga = contador;
        }
        if (palabraCorta == 0 || contador < palabraCorta) {
            palabraCorta = contador;
        }
    }
    
    printf("Palabra larga: %d\n", palabraLarga);
    printf("Palabra corta: %d\n", palabraCorta);

    return 0;
}