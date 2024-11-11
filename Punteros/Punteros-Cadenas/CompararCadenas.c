#include <stdio.h>
#include <stdlib.h>


int CompararCadenas(const char *cadena1, const char *cadena2){ 

        while (*cadena1 && (*cadena1 == *cadena2)) /* MIentras cadena1 no sea el caracter nulo \0, que indica el final de la cadena
 */
        {
            cadena1++; // Avanzan ambos al siguiente carcater 
            cadena2++; // Solo avanzan si los caracter actuales de ambas coinciden 
        }
        
        return *cadena1 - *cadena2; // retorna 0 <-- Si ambas son identicas
        // retorna un valor negativo si *cadena1 es menor que cadena2
        // retorna un valor positivo si *cadena1 es mayor que *cadnea2

}

void main () {

char *cad1 = malloc(100 * sizeof(cad1));

printf("Ingresar la Cadena 1: ");
fgets(cad1, 100, stdin);

char *cad2 = malloc(100 * sizeof(cad2));

printf("Ingresar la Cadena 2: ");
fgets(cad2, 100, stdin);

int resultadoCadenas = CompararCadenas(cad1, cad2);

if (resultadoCadenas == 0)
{
    printf("Las cadenas son iguales \n");

} else if (resultadoCadenas < 0)
{
    printf("La cadena 1 es menor que la cadena 2\n");
} else {

    printf("La cadena 1 es mayor que la cadena 2");
}

free(cad1);
free(cad2);



}