/*ALGORTIMO: Calculando_Descuentos
ENTRADA:precio_base, categoria : c
SALIDA: precio_final: R
CONSTANTE: IVA = 0.21
A1_LEER (precio_base, categoria)
A2_Calcular_Descuentos
	precio_final <- precio_final+ (precio_final *IVA)
	SEGUN categoria
		'A': precio_final <- precio_base - (precio_base*0.20)
		'B':precio_final <-  precio_base - (precio_base*0.10)
		'C': precio_final <- precio_base
	FIN_SEGUN
A3_Calcular_IVA_descuentos
	SI precio_final < 10.000 ENTONCES
		precio_final <- precio_final - (precio_final*0.05)
	FIN_SI
A4_ESCRIBIR (precio_final)
A5_PARAR
*/

#include <stdio.h>

int main() {
    float precio_base;
    char categoria;
    float precio_final;
    const float IVA = 0.21;

    printf ("Ingresar precio base: ");
       scanf("%f", &precio_base);
    printf ("Ingresar Categoria A - C: ");
 
    scanf (" %c", &categoria);

   
    switch (categoria)
    {
    case 'A':
                precio_final = precio_base - (precio_base*0.20);
        break;
    case 'B':
                precio_final = precio_base - (precio_base*0.10);
        break;
        case 'C':
                precio_final = precio_base;
        break;
        default:
        break;
    }
 precio_final = precio_final + (precio_final*IVA);
    if (precio_final < 10000)
    {
        precio_final = precio_final - (precio_final*0.05);
    }
    
    printf ("El precio final es : %.2f", precio_final);
    return 0;
}
