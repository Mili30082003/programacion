#include <stdio.h>
#define FILAS 3
#define COLUMNAS 3

void cargarMatriz (int matriz [][COLUMNAS]){
    for (int i = 0; i < FILAS ;i++)
    {
            for (int j = 0; j < COLUMNAS; j++)
            {
                printf ("Ingresar el valor de la posicion (%d,%d): ", i, j);
                scanf("%d", &matriz[i][j]);
            }
            printf ("\n");
    }
}
void mostrarMatriz (int matriz [][COLUMNAS]){

for (int i = 0; i < FILAS; i++)
{
    for (int j = 0; j < COLUMNAS; j++)
    {
        printf ("%d", matriz[i][j]);
    }
    printf ("\n");
    
}

}

void PasarMatrizTranspuesta (int matriz [][COLUMNAS], int matrizb [][COLUMNAS]){
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
         matrizb [j][i]= matriz [i][j];
        }

    }
}

   void mostrarMatrizTranspuesta (int matriz [][COLUMNAS],int matrizb [][COLUMNAS]){

for (int i = 0; i < FILAS; i++)
{
    for (int j = 0; j < COLUMNAS; j++)
    {
        printf ("%d", matrizb[i][j]);
    }
    printf ("\n");
    
}


}


void main (void) {

int matriz[FILAS][COLUMNAS];
int matrizb [FILAS][COLUMNAS];


cargarMatriz(matriz);
printf("Matriz original:\n");
mostrarMatriz(matriz);

PasarMatrizTranspuesta(matriz, matrizb);
 printf("Matriz transpuesta:\n");
mostrarMatrizTranspuesta(matriz, matrizb);


}