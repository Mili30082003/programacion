 /*b. Cree dos punteros enteros llamados p y q. Asigne en los punteros p y q la dirección de
 memoria de a y b respectivamente.*/

  #include <stdio.h>

 int main () {

    // 1 - Declaro dos numeros enteros
       int n1 = 3;
       int n2 = 5;

      // 2 - Almaceno los numeros en las variables a y b
      int a = n1;
      int b = n2;

      // 3 - Declaro dos punteros p y q
      int *p;
      int *q;

      // 4 - Asigno a los punteros la Direccion de Memoria de a y b
      p = &a;
      q = &b;

      // 3 - Muestro los valores por pantalla
      printf("Valor de n1: %d\n" , n1); 
      printf("Valor de n2: %d\n", n2);
      printf("Valor de a: %d\n", a);
      printf("Valor de b: %d\n", b);
      printf("Direccion de memoria de a: %p\n", p);
      printf("Direccion de memoria de b: %p\n", q);



    return 0;
 }