/* Escriba un programa en C que permita al usuario ingresar un arreglo de numeros enteros de tamaño variable y luego encuntre y muestre el subarreglo contiguo de dos numeros con la suma maxima.
Adicionalmente, guarde en el arreglo de salida la posicion de cada numero respecitvamente y al final el valor de la suma.

- Use asignacion dinamica de memoria para el manejo de los arreglos.
-Implemente un modulo para cargar el arreglo de entrada y otro para mostrar arreglos ---> funcion

 */

#include <stdio.h>
#include <stdlib.h>

void CargarArreglo(int *pArreglo, int n){

    printf("Ingrese los valores del Arreglo: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", pArreglo);
        pArreglo++;
    }
}

void MostrarArreglo(int *pArreglo, int n){
    
        for (int i = 0; i < n; i++)
        {
            printf("%d", *pArreglo);
            pArreglo++;
        }
        

}

void ObtenerSubArreglo(int *pArreglo, int * SubArreglo, int tama_Arreglo){

        int SumaMaxima = 0;
        int SumaMaximaAux;
        int indice1, indice2;
        int num1, num2;
     for (int i = 0; i < tama_Arreglo ; i++)
     {
       SumaMaximaAux = *pArreglo + *(pArreglo + 1);
       if (SumaMaximaAux > SumaMaxima)
       {
            SumaMaxima = SumaMaximaAux;
            num1 = *pArreglo;
            num2 = *(pArreglo + 1);
            indice1 = i;
            indice2 = i + 1;
       }
       pArreglo++;
       
     }

    SubArreglo[0] = num1;
    SubArreglo[1] = num2;
    SubArreglo[2] = indice1;
    SubArreglo[3] = indice2;
    SubArreglo[4] = SumaMaxima;
}

void main () {

    int n;
    printf("Ingresar el Tamaño del Arreglo: ");
    scanf("%d", &n);

    int * p_numeros = malloc(sizeof(int)*n); // Puntero Dinamico
    int *sub_Arreglo = malloc(sizeof(int)*n);

     CargarArreglo(p_numeros, n);
     printf("\n Arreglo Original: ");
     MostrarArreglo(p_numeros, n);
   
   
   
     ObtenerSubArreglo(p_numeros, sub_Arreglo, n);

    printf("\nSub Arreglo: ");
    MostrarArreglo(sub_Arreglo, 5);
    printf("\n");

    MostrarArreglo(p_numeros, 5);


    free(p_numeros);
    free(sub_Arreglo);
    

}