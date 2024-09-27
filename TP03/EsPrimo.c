/*
Algoritmo: Numeros_Primos
Entrada:, num: z
Salida: TotalP, SumaP: z mensaje:cc

A0_INICIALIZAR

	TotalP <-- 0
	SumaP <-- 0
A1_calcular_total_suma
	LEER (num)
		HACER 10 veces
			SI n <= 1 AND n = 2 AND n%2=0 ENTONCES 
				mensaje <- "Es primo"
				TotalP++
				SumaP++
			SINO
				mensaje <-- "No es primo"
			FIN_SI
		FIN_HACER
A2_ESCRIBIR (TotalP, SumaP)
A3_PARAR
*/
#include <stdio.h>

int main () {

    int num;
    int totalP = 0, sumaP = 0; 

 

    for (int i = 1; i <11; i++)
    {
   printf ("Ingresar un numero: ");
    scanf ("%d", &num);
            if ( num <= 1 || num == 2 || num % 2 == 0)
            {
              printf ("Es primo");
              totalP++;
              sumaP = sumaP + num;  
            }
            
    }
    printf ("el total es: %d", totalP);
    printf ("La suma de primos es: %d", sumaP);
}