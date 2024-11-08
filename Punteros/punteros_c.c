/* Nuestro pc Necesita saber que celda de memoria almacena un determinado valor para poder acceder a el.

venatajas : 
            - manipulacion de memoria dinamica con funciones como
                malloc o free
                para reservar espacio de memoria 

            - Me permiten manipular espacios de memoria 
            - Manipulacion de estructuras de datos complejas

            * <-- Accede al valor de la variable de lo que estoy apuntando
            & <-- Obtiene la direccion de memoria de la variable de lo que estoy apuntando 
        */

       #include <stdio.h>

       int main () {

            int valor = 10;
            /*int *puntero;  manera mas sencilla de declarar un puntero */
            int *puntero = &valor;
            
            printf("Direccion de Memoria: %p", puntero);


        return 0;
       }