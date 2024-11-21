
/*
. Contar la cantidad de números pares y la suma de los impares en un rango de enteros. Por
ejemplo para el rango [-2,10], Cantidad de Pares: 7, Suma de Impares: 24.
*/
/*
ALGORITMO: Calculo_rango
ENTRADA: min, max: z
SALIDA: cantidadP, sumaI: z
VAR_AUX: num: z
A0_INICIALIZAR
cantidadP <-- 0
sumaI <-- 0
min <-- num
A1_Calcular_Rango
    LEER (min,max)
        MIENTRAS (num >= max)
            SI (num MOD 2 = 0) ENTONCES
                cantidadP <-- cantidadP + 1
            SINO
                sumaI <-- sumaI + 1
            FIN_SI
            num <-- num + 1
        FIN_MIENTRAS
A2_ ESCRIBIR (cantidadP, sumaI)
A3_PARAR
        
*/
#include <stdio.h>
int main () {
    
  int min, max;
  printf ("Ingresar 2 numeros enteros: ");
  scanf("%d", &min);
  scanf("%d", &max);

  int cantidadP, sumaI;

  cantidadP = 0;
  sumaI = 0;


    // Iteramos desde min hasta max
    for (int num = min; num <= max; num++) {
        if (num % 2 == 0) {
            cantidadP++;  // Si es par, incrementa la cantidad de pares
        } else {
            sumaI += num;  // Si es impar, suma el valor
        }
    }
printf("La cantidad de Numeros Pares es: %d\n", cantidadP);
printf("La Suma de Impares es: %d", sumaI);
    return 0; 
}