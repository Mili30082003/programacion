
/*
Algoritmo:IncrementoDecremento 
Entrada: incremento, decremento: z
Salida: incremento, decremento: z
Var_Auxiliar: cambio: z

A1_ LEER (incremento, decremento)
A2_Calcular_Numeros
	incremento <- incremento + 1
	decremento <- decremento - 1
A3_ESCRIBIR (incremento, decremento)
A4_ Cambiar_Variables
			cambio <- incremento
			incremento <- decremento
			decremento <- cambio
A5_ ESCRIBIR (incremento, decremento)
A4_PARAR

*/
#include <stdio.h>

int main() {
    int incremento, decremento;
    int cambio;
    
    printf ("Ingrese dos numeros enteros: ");
    scanf ("%d", &incremento);
    scanf ("%d", &decremento);

    incremento++;
    decremento--;

    printf ("El valor de incremento es: %d\n", incremento);
    printf ("El valor de decremento es: %d\n", decremento);

   cambio = incremento;
   incremento = decremento;
   decremento = cambio;
    printf ("El nuevo valor de incremento es: %d\n", incremento);
    printf ("El nuevo valor de decremento es: %d\n", decremento);


    return 0;
}
