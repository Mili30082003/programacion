 
 /*e.Muestre las direcciones de memoria de p y q. */
 
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

      // 5 - Muestro los valores por pantalla
      printf("Valor de n1: %d\n" , n1); 
      printf("Valor de n2: %d\n", n2);
      printf("Valor de a: %d\n", a);
      printf("Valor de b: %d\n", b);
      printf("Direccion de memoria de a: %p\n", p);
      printf("Direccion de memoria de b: %p\n", q);

      // 6- Muestro el contenido de p y q 
     // Contenido de p y q: Esto se refiere al valor de los punteros p y q mismos, es decir, las direcciones de memoria que almacenan.
      printf("Contenido de a: %p\n",*p);
      printf("Contenido de b: %p\n",*q);

      // 7 - Muestro el contenido apuntado por p y q 
    // Esto se refiere al valor que está almacenado en las direcciones de memoria a las que p y q apuntan. Usamos el operador de indirección * para obtener este valor.
     printf("Contenido de a: %d\n",*p);
     printf("Contenido de b: %d\n",*q);

     // 8 - Muestro las direcciones de memoria de p y q
     // tengo que utilizar ---> & para obtener la direccion de memoria 
      printf("Contenido de a: %p\n",&p);
     printf("Contenido de b: %p\n",&q);






    return 0;
 }