#include <stdio.h>

int main() {
    float dni, cbu, saldo, deposito, retiro;
    int operacion;

    printf("Ingrese su DNI: ");
    scanf("%f", &dni);

    printf("Ingrese su CBU: ");
    scanf("%f", &cbu);

    printf("Ingrese su Saldo: ");
    scanf("%f", &saldo);

    printf("\nIngrese el Numero de Operaciones que quiera realizar: ");
    printf("\n1_Depositar Dinero \n2_Retirar Dinero \n3_Consultar Saldo \n4_Mostrar Datos de la Cuenta \n5_Salir\n");
    scanf("%d", &operacion);

    switch (operacion) {
        case 1:
            printf("Ingrese el Monto que quiera Depositar: ");
            scanf("%f", &deposito);
            saldo += deposito;
            printf("\nEste es el monto de su cuenta: %.2f\n", saldo);
            break;

        case 2:
            printf("Ingrese el Monto que quiera Retirar: ");
            scanf("%f", &retiro);
            if (retiro <= saldo) {
                saldo -= retiro;
                printf("\nEste es el monto de su cuenta: %.2f\n", saldo);
            } else {
                printf("No se puede retirar, saldo insuficiente.\n");
            }
            break;

        case 3:
            printf("\nEste es su Saldo: %.2f\n", saldo);
            break;

        case 4:
            printf("Su DNI es: %.0f \nEste es su CBU: %.0f\n", dni, cbu);
            break;

        case 5:
            printf("Saliendo...\n");
            break;

        default:
            printf("Opción no válida. Por favor, elija una opción del 1 al 5.\n");
            break;
    }

    return 0;
}

