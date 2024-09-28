#include <stdio.h>


int calcularTriangular(int n) {
    return (n * (n + 1)) / 2;
}


int main () {
int n1, n2;

printf ("Introduce el primer numero ");
scanf ("%d", &n1);
printf ("Introduce el segundo numero ");
scanf ("%d", &n2);


printf ("Los numeros triangulares e %d y %d son: \n", n1, n2 );
  for (int i = n2; i >= n1; i--) {
        printf("%d ", calcularTriangular(i)); 
    }
  printf("\n");

return 0;
}