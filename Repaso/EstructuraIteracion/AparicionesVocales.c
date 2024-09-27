/*Lea una oración terminada en un punto y cuente la cantidad de espacios en blanco, la
cantidad de apariciones de cada vocal y el total de todas las vocales presentes en la oración.
*/
/* 
ALGORITMO:Vocales_Frase
ENTRADA: frase : cc con MF '.'
SALIDA: cant_a, cant_e, cant_i, cant_o, cant_u, cante, cant_b, totalV: z+

A0_INICIALIZAR
    cant_a <-- 0;
    cant_e <-- 0;
    cant_i <-- 0;
    cant_o <-- 0;
    cant_u <-- 0;
    cant_b <-- 0;
    totalV <-- 0;
A1_Contar_Vocales
    LEER (frase)
        MIENTRAS (frase <> MF)
            SEGUN frase
                'a' : cant_a++
                'e': cant_e++
                'i': cant_i++
                'o': cant_o++
                'u': cant_u++
                ' ': cant_b++
            FIN_SEGUN
    LEER (frase)
        FIN_MIENTRAS
A3_ totalV <--  (cant_a + cant_e + cant_i + cant_o + cant_u)
A4_ ESCRIBIR (cant_a,cant_e,cant_i,cant_o,cant_u,cant_b,totalV)
A5_PARAR

*/

#include <stdio.h>
int main () {
    char frase;
    int cant_a, cant_e, cant_i, cant_o, cant_u, cante, cant_b;
    int totalV;
    char MF = '.';
printf ("Ingresar una frase con un '.' : ");
scanf ("%c", &frase);


    cant_a = 0;
    cant_e = 0;
    cant_i = 0;
    cant_o = 0;
    cant_u = 0;
    cant_b = 0;
    totalV = 0;

while (frase != MF)
{
   switch (frase)
   {
   case 'a':
        cant_a++;
    break;
   case 'e':
        cante++;
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
   case ' ':
        cant_b++;
    break;
   

   }
   scanf ("%c", &frase);
}

totalV = (cant_a + cant_e + cant_i + cant_o + cant_u);

printf ("La cantidad de 'a' es: %d\n", cant_a);
printf ("La cantidad de 'e' es: %d\n", cante);
printf ("La cantidad de 'i' es: %d\n", cant_i);
printf ("La cantidad de 'o' es: %d\n", cant_o);
printf ("La cantidad de 'u' es: %d\n", cant_u);
printf ("La cantidad de Espacios en Blanco es: %d\n", cant_b);
printf ("La cantidad de Total de Vocales es: %d\n", totalV);

    
    return 0; 
}