#include <stdio.h>

int main() {
    char frase;
    char MF = '.';  // Marca final (punto)
    int cantB = 0;  // Contador de espacios
    int cantP = 0;  // Contador de palabras que comienzan con la letra inicializada
    char letraInicializada;  // Para almacenar la primera letra de la primera palabra
    char palabraIniciada = ' ';  // Variable para detectar el inicio de una palabra

    printf("Ingresar una oración terminada en un punto: ");
    
    // Leer el primer carácter (la primera letra de la palabra inicializada)
    scanf("%c", &frase);
    letraInicializada = frase;  // Guardamos la primera letra
    
    // Procesamos el resto de la oración
    while (frase != MF) {
        // Contar espacios en blanco
        if (frase == ' ') {
            cantB++;
        }
        
        // Detectar el inicio de una palabra
        if (frase != ' ' && palabraIniciada == ' ') {
            // Si la palabra empieza con la misma letra que la inicializada
            if (frase == letraInicializada) {
                cantP++;  // Contamos la palabra si la primera letra coincide
            }
        }
        
        // Actualizar la última posición para detectar cambios de palabra
        palabraIniciada = frase;

        // Leer el siguiente carácter
        scanf("%c", &frase);
    }

    // Mostrar los resultados
    printf("La cantidad de espacios en blanco es: %d\n", cantB);
    printf("La cantidad de palabras que comienzan con la letra '%c' es: %d\n", letraInicializada, cantP);
    
    return 0;
}