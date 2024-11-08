#include <stdio.h>
#include <stdlib.h>


void cargarArreglo2 (int *pArreglo, int n) {
    for (int i = 0; i < n; i++)
    {
            *pArreglo = 1 + rand()%10;
            pArreglo++;
    }
    
}

void mostrarArreglo (int *pArreglo, int n) {
    for (int i = 0; i < n; i++)
    {
             printf("Arreglo: %d\n", *pArreglo);
             pArreglo++;
    }
    
}
void main (){

        int n;
        printf("Ingresar el Tamaño del Arreglo: ");
        scanf("%d", &n);

        // Ahora que tengo el tamaño del arreglo puedo generar un puntero dinamico
        int *p_numeros = malloc(sizeof(int)*n);
        cargarArreglo2(p_numeros, n);
        mostrarArreglo(p_numeros, n);
        int cantPars = 0;
        for (int i = 0; i < n; i++)
        {
            if ((*p_numeros % 2 == 0))
            {
                cantPars++;
            }
            p_numeros++;
        }
        
        printf("La cantidad de numeros pares es: %d\n", cantPars);
        free(p_numeros); // Libera espacio en la memoria 
}