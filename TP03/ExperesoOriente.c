/*
Algoritmo: Expreso Oriente
Entrada: CantAgua,CantCarbon, DistanciaTotal
Salida:CantAgua, CantCarbon

	5 litros de agua*15 kilometros
	2 kilos de carbon* 10 kilometros
A0_INICIALIZAR
A1_calcular
	LEER ()
		Mientras Distancia <> 0
			SI cantAgua < 5 AND cantCarbon < 2
				ESCRIBIR ("No hay suficiente agua o carbon para continuar el viaje");
			FIN_SI
			
		CantAgua <-- CantAgua - 5;
		CantCarbonn <-- CantCarbon - 2
		DistanciaTotal <-- DistanciaTotal - 10
	
			ESCRIBIR (CantAgua, CantCarbon, DistanciaTotal)
		FIN_MIENTRAS
A2_ ESCRIBIR (cantCarbon, CantAgua)
A3_PARAR
		
*/
#include <stdio.h> 

int main (){


}