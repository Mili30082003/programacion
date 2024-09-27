#include <stdio.h>
#include <math.h>

// Declaración de las funciones
int suma(int a, int b);
int resta(int a, int b);
int producto(int a, int b);
int division(int a, int b);
int potencia(int a, int b);

int main(void) {
    int operacion;
    int a, b;
    int resultado;


    do {
        // Pedimos al usuario que ingrese una operación
        printf("Ingresar una operacion :\n 1: suma\n 2: resta\n 3: producto\n 4: division\n 5: potencia\n 0: salir\n");
        scanf("%d", &operacion);

        if (operacion == 0) {
            break; // Si la operación es 0, salir del ciclo
        }

        // Pedimos al usuario que ingrese dos números
        printf("Ingresar dos numeros: ");
        scanf("%d", &a);
        scanf("%d", &b);

        // Ejecutamos la operación correspondiente
        switch (operacion) {
            case 1:
                resultado = suma(a, b);
                printf("El resultado de la suma es: %d\n", resultado);
                break;
            case 2:
                resultado = resta(a, b);
                printf("El resultado de la resta es: %d\n", resultado);
                break;
            case 3:
                resultado = producto(a, b);
                printf("El resultado del producto es: %d\n", resultado);
                break;
            case 4:
                if (b != 0) {
                    resultado = division(a, b);
                    printf("El resultado de la division es: %d\n", resultado);
                } else {
                    printf("Error: division por cero.\n");
                }
                break;
            case 5:
                resultado = potencia(a, b);
                printf("El resultado de la potencia es: %d\n", resultado);
                break;
            default:
                printf("Operacion no valida.\n");
        }

    } while (operacion != 0); // Continuar hasta que el usuario elija salir

    return 0;
}

// Implementación de las funciones
int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}

int producto(int a, int b) {
    return a * b;
}

int division(int a, int b) {
    return a / b; // División entera
}

int potencia(int a, int b) {
    return (int)pow(a, b); // Función de potencia, convertida a entero
}