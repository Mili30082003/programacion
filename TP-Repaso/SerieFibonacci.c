/*Ejercicio 3: Serie de Fibonacci
Crea un programa que muestre los primeros 𝑁
números de la serie de Fibonacci, donde cada número es la suma de los dos anteriores.
 Pide al usuario que ingrese 𝑁



*/

    #include <stdio.h>

    void mostrarNumeros(int a, int b, int siguiente, int numeros){
        a = 0;
        b = 1; 
        printf ("Numero de la serie: ");
        
    for (int i = 0; i < numeros; i++)
    {
        printf("%d ", a);
        siguiente = a + b;
        a = b;
        b = siguiente;
        printf("\n");
    }


    }
    int main (){

    int numeros;
    printf ("Ingresar un numero: ");
    scanf ("%d", &numeros);
    int a, b, siguiente; 

    if (numeros < 1)
    {
    printf ("No se puede imprimir\n");
    } else { mostrarNumeros(a, b, siguiente, numeros);}



    return 0;
    }