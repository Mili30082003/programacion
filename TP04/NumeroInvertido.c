#include <stdio.h>
#include <stdlib.h>

int invertirNumero (int num);
void digitosImpares ( num);

int main () {

int num_invertido;
int num;
int numerosImpares = 0;


printf ("Ingresar un numero: ");
scanf ("%d", &num);


    num_invertido = invertirNumero ( num);
     digitosImpares(num, &numerosImpares); 
  

printf ("digito invertido: %d\n", num_invertido);
printf ("La cantidad de impares es : %d", numerosImpares);
  
    



return 0;
}

int invertirNumero (int num) {
 int i = 0;
 while ( num != 0)
 {
   

i = i * 10 + num % 10;
num = num / 10;

 }
 
 


return i;




}

void digitosImpares(int num, int *cantImpares) {
    *cantImpares = 0;  // Asegura que el contador comience en 0

    while (num != 0) {
        int digito = num % 10;
        if (digito % 2 == 1) {  // Verifica si el dígito es impar
            (*cantImpares)++;  // Incrementa el valor apuntado por 'cantImpares'
        }
        num = num / 10;  // Elimina el último dígito
    }
}