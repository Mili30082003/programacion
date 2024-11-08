#include <stdio.h>
#include <stdbool.h>

int main () {

    char frase[100]; // 1 - Defino un arreglo de caracteres que contendrá la frase que el usuario ingrese 
    int cant_palabras = 0;  // 2 - Contador para el número total de palabras en la frase 
    int esPalabra = false;  // 3 - Indica si estoy dentro de una palabra
    int cant_on = 0; // 4 - Contador para el número de palabras que terminan en ON

    printf("Ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin); // Corregido: usar fgets para capturar la entrada del usuario

    // Contar la cantidad de palabras que finalizan en ON

    char *p_frase = frase; // 5 - Defino un puntero que apunta al inicio de frase
    // FACILITA EL DESPLAZAMIENTO A TRAVÉS DE LA CADENA 

    while (*p_frase != '\0') // Se ejecuta hasta que p_frase apunte al carácter de fin de cadena '\0' <-- RECORRE TODA LA FRASE 
    {
        while (*p_frase != ' ' && *p_frase != '\0') // Procesa cada palabra 
        {
            esPalabra = true; // Si encontré una palabra

            if (*p_frase == 'o') 
            {
                p_frase++; // leer <-- avanzar al siguiente casillero
                if (*p_frase == 'n')
                {
                    p_frase++;
                    if (*p_frase == ' ' || *p_frase == '\0') // Verifica si la palabra termina en "ON"
                    {
                        cant_on++; // Incrementa el contador de palabras que terminan en "ON"
                    }
                }
            }
            
            // Si no es un espacio ni el final de la cadena, p_frase se incrementará para continuar leyendo la palabra actual
            if (*p_frase != ' ' && *p_frase != '\0')
            {
                p_frase++;
            }
        }

        // Si esPalabra = true significa que encontré una palabra completa por lo que se incrementa cant_palabras
        if (esPalabra)
        {
            cant_palabras++;
        }
        
        esPalabra = false; // Se establece esPalabra = false para la próxima palabra 

        if (*p_frase == ' ') // Si el carácter actual es un espacio, avanza a la siguiente palabra
        {
            p_frase++; 
        }
    }

    // Imprime los resultados
    printf("Cantidad de palabras: %d\n", cant_palabras);
    printf("Cantidad de palabras que terminan en 'ON': %d\n", cant_on);

    return 0;
}
