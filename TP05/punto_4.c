#include <stdio.h>
#include <stdbool.h>
#define F 2
#define C 2


void CargarDatos (int Matriz [][C]);
void MostrarMatriz (int Matriz [][C]);
void SumarMatriz (int Matriz [][C], int MatrizB[][C], int ResultadoSuma[][C]);
bool CompararMatrices ( int Matriz[][C],int MatrizB[][C]  );



void main () {

int Matriz[F][C];
int MatrizB [F][C];
int ResultadoSuma [F][C];

printf ("Cargar datos para la primera matriz:\n");
CargarDatos(Matriz);

printf ("\n Cargar datos para la segunda matriz: \n");
CargarDatos(MatrizB);

printf ("\n Matriz A:\n");
MostrarMatriz(Matriz);

printf ("\n Matriz B: \n");
MostrarMatriz(MatrizB);

if (CompararMatrices(Matriz, MatrizB))
{
    printf ("\n Las matrices sn iguales. \n");
} else{
    printf ("\n Las matrices son distintas.\n");
}


SumarMatriz( Matriz , MatrizB, ResultadoSuma);

printf ("\n El resultado de la suma es: \n");
MostrarMatriz(ResultadoSuma);


}

void CargarDatos (int Matriz [][C] ){

for (int i = 0; i < F; i++)
{
    for (int j = 0; j< C; j++)
    {
        printf ("Ingresar el valor de la posicion(%d, %d): ",i,j);
        scanf("%d", &Matriz[i][j]);
    }   
}
}

void MostrarMatriz (int Matriz [][C]){

for (int i = 0; i < F; i++)
{
    for (int j = 0; j < C; j++)
    {
       printf ("%d", Matriz[i][j]);
    }
    printf ("\n");
}

}

void SumarMatriz (int Matriz [][C], int MatrizB[][C], int ResultadoSuma[][C]){
int Suma = 0;

for (int i = 0; i < F; i++)
{
    for (int j = 0; j < C; j++)
    {
        ResultadoSuma[i][j] = Matriz[i][j] +MatrizB[i][j] ;
    }   
}
}

bool CompararMatrices ( int Matriz[][C],int MatrizB[][C]  ){

for (int i = 0; i < F; i++)
{
    for (int j = 0; j < C; j++)
    {
        if (Matriz[i][j] != Matriz[i][j])
        {
            return false;
        }       
    }
    return true;
}
}