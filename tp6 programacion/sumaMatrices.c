/*Escriba un programa en C que permita al usuario ingresar dos matrices cuadradas y calcular su
suma. Las tres matrices deben mostrarse en pantalla. Realice las funciones para cargar una
matriz, mostrar una matriz y sumar dos matrices.
Una matriz A es cuadrada si el número de filas es igual al número de columnas.
Siendo A y B matrices de igual dimensión, la suma de A y B se obtiene sumando los términos
situados en el mismo lugar.*/

#include<stdio.h>
#define tama 4

void cargarMatriz(int matriz1[tama][tama], int matriz2[tama][tama]);
void mostrarMatriz(int matriz1[tama][tama], int matriz2[tama][tama],int matrizSUMA[tama][tama]);
void suma(int matriz1[tama][tama], int matriz2[tama][tama], int matrizSUMA[tama][tama]);

void main()
{
    //---varaibles---//
    int matriz1[tama][tama];
    int matriz2[tama][tama]; 
    int matrizSUMA[tama][tama];
    
    cargarMatriz( matriz1, matriz2);
    suma( matriz1, matriz2,matrizSUMA);
    mostrarMatriz( matriz1, matriz2,matrizSUMA);


}


//---------------------------------------------------------------------------------------------------//
void cargarMatriz(int matriz1[tama][tama], int matriz2[tama][tama])
{
    puts("ingrese los numeros de la primera matriz cuadrada de orden 2");
    
    for (int i = 0; i < 2; i++)
    {
       for (int j = 0; j < 2; j++)
       {
            scanf("%d",&matriz1[i][j]);
       }
       
    }

    puts("ingrese los numeros de la segundamatriz cuadrada de orden 2");
    
    for (int i = 0; i < 2; i++)
    {
       for (int j = 0; j < 2; j++)
       {
            scanf("%d",&matriz2[i][j]);
       }
       
    }
    
}
//---------------------------------------------------------------------------------------------------//

void mostrarMatriz(int matriz1[tama][tama], int matriz2[tama][tama],int matrizSUMA[tama][tama])
{
    puts("****************  PRIMERA MATRIZ   *************************************");
   

    for (int i = 0; i < 2; i++)
    {
        printf("\n");
        for (int j = 0; j < 2; j++)
        {
            printf("{%d}",matriz1[i][j]);
        }
        
    }
    printf("\n");
     puts("****************  SEGUNDA MATRIZ   *************************************");

    for (int i = 0; i < 2; i++)
    {   
        printf("\n");
        for (int j = 0; j < 2; j++)
        {
            printf("{%d}",matriz2[i][j]);
        }
        
    }
    printf("\n");
     puts("****************  SUMA MATRIZ   *************************************");

    for (int i = 0; i < 2; i++)
    {   
        printf("\n");
        for (int j = 0; j < 2; j++)
        {
            printf("{%d}",matrizSUMA[i][j]);
        }
        
    }
    
    
}
//-------------------------------------------------------------------------------------------//
void suma(int matriz1[tama][tama], int matriz2[tama][tama],  int matrizSUMA[tama][tama])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
           matrizSUMA[i][j]=matriz1[i][j]+matriz2[i][j];
        }
        
    }
    
}
