/*
Tarea:
Dado un arreglo de 10 números enteros positivos de como máximo 3 digitos.
Realice un programa en C que calcule:
-La cantidad total de numeros primos en el arreglo.
-La suma total de los dígitos impares de  los numeros primos que se encuentren en los indices impares del arreglo.

Implemente las siguientes  funciónes:
int EsPrimo(int numero);
int EsPar(int numero)
*/

#include <stdio.h>
#include <stdbool.h>
#define tama 10

int EsPrimo(int numero);
int EsPar(int numero);
int SumaDigitos(int arreglo[]);

void main()
{
    int numero = 0;
    int arreglo[tama];

    puts("ingrese 10 numeros enteros positivos : ");
    for (int i = 0; i < tama; i++)
    {
        scanf("%d", &numero);
        while (numero < 0)
        {
            puts("no es positivo, vuelva ingresar el numero: ");
            scanf("%d", &numero);
        }
        arreglo[i] = numero;
    }

    int cantidadPrimos = 0;
    int sumaImpar = 0;

    for (int i = 0; i < tama; i++)
    {
        int numeroProbado = arreglo[i];

        if (EsPrimo(numeroProbado))
        {
            cantidadPrimos++;
        }
    }
    printf("\n la cantidad de numeros primos es: %d", cantidadPrimos);

    int total = SumaDigitos(arreglo);

    printf("\n la suma de los digitos es: %d", total);
}

//----------------------------------------------------------------------------------------------------//

int EsPar(int numero)
{
    return numero % 2 == 0 ? 1 : 0;
}
//---------------------------------------------------------------------------------------------------//
int SumaDigitos(int arreglo[])
{
    int suma = 0;
    for (int i = 0; i < tama; i++)
    {

        if (i % 2 != 0)
        {
            if (EsPrimo(arreglo[i]))
            {
                int n = arreglo[i];
                while (n > 0)
                {
                    if (!EsPar(arreglo[i] % 10))
                    {
                        suma += arreglo[i] % 10;
                    }
                    n=arreglo[i] / 10;
                }
            }
        }
    }
    return suma;
}
//----------------------------------------------------------------------------------------------------//

int EsPrimo(int numero)
{

    bool primo = true;

    int numeroaux = numero - 1;

    if (EsPar(numero) && numero != 2)
    {
        primo = false;
    }
    else
    {
        while (numeroaux > 1)
        {
            int resto = numero % (numeroaux);

            if (resto == 0)
            {
                primo = false;
                break;
            }
            numeroaux--;
        }
    }

    return primo;
}