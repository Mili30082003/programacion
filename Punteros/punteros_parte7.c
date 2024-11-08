#include <stdio.h>
#include <time.h>
/*void cargarArreglo (int arreglo [], int n){
    for (int i = 0; i < n; i++)
    {
        arreglo[i] = 1 + rand()%10;
    }
}*/

/*void mostrarArreglo(int arreglo[], int n) {
    for (int i = 0; i < n; i++)
    {
       printf("Arreglo: %d\n",arreglo[i]);
        
    }
    
}*/

void cargarArreglo2 (int *pArreglo, int n) {
    for (int i = 0; i < n; i++)
    {
            *pArreglo = 1 + rand()%10;
            pArreglo++;
    }
    
}
void mostrarArreglo(int arreglo[], int n){
    
}

void main () {
        srand(time(NULL));
        int numeros[5];
       // cargarArreglo(numeros, 5);
       cargarArreglo2(numeros,5);
        mostrarArreglo(numeros,5);

}