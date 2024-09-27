/*
Diseñe un algoritmo que cuente la cantidad de palabras que comienzan con vocal en una
oración. Además, muestre que porcentaje representan estas respecto al total de palabras. Por
ejemplo:
En un atardecer de otoño comer churros con chocolate es el mejor plan.
- Cantidad de palabras que comienzan con vocal: 6
- Porcentaje sobre el total (13): 46.15%
*/
/*
ALGORITMO: Contar_Vocales_Frase
ENTRADA: frase: cc con MF '.'
SALIDA: cantV: z+, porcentaje: z+, total_P

A0_ INICIALIZAR
    cantV <-- 0
    porcentaje <-- 0
    total_P <-- 0 
A1_ calcular_Apariciones
    LEER (frase)
        MIENTRAS (frase <> MF)
            MIENTRAS (frase == '' && frase <> MF)
                SEGUN frase
                'a' : cant_a++
                'e': cant_e++
                'i': cant_i++
                'o': cant_o++
                'u': cant_u++
                FIN_SEGUN
            total_P <-- total_P++
            SI (frase <> MF) ENTONCES 
                LEER (frase)
                FIN_SI
        FIN_MIENTRAS 

A2_ porcentaje <-- total_P / 100
A3_ ESCRIBIR (cantV, porcentaje, total_P)
A4_PARAR

            
*/
#include <stdio.h>
int main () {
char frase;
int cantV, porcentaje;
int contador;
char MF = '.';
int cant_a = 0, cant_e = 0, cant_i= 0, cant_o = 0, cant_u = 0;
cantV = 0;
contador = 0;

printf ("Ingresar una frase con '.' : ");
scanf ("%c, &frase");

while (frase != MF)
{
    
    while (frase != ' ' && frase != ' ')
    {
        contador++;
        scanf ("%c", &frase);
    }

       switch (frase)
   {
   case 'a':
        cant_a++;
    break;
   case 'e':
        cant_e++;
    break;
   case 'i':
        cant_i++;
    break;
    case 'o':
        cant_o++;
    break;
    case 'u':
        cant_u++;
    break;
   
   

   }
    if (frase != MF)
    {
   scanf ("%c, &frase");
    }
    
}
co

printf ("palabras: %d",cantV );
    
    return 0; 
}
