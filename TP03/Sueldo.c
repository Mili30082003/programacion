#include <stdio.h>

int main() {
    const float G = 350000.0;
    const float A = 250000.0;
    const float M = 100000.0;
    int antiguedad;
    float sueldo_final;
    char categoria;
    int titulo;
    float Total_gastado = 0.0;
    int empleado = 1;

    while (empleado > 0) {
        // Ingresar datos del empleado
        printf("Ingresar categoria (G/A/M): ");
        scanf(" %c", &categoria);

        printf("Ingrese la antigüedad (años): ");
        scanf("%d", &antiguedad);

        // Si es administrativo o gerencial, preguntar si tiene título
        if (categoria == 'A' || categoria == 'G') {
            printf("¿Tiene título universitario? (1: SI, 0: NO): ");
            scanf("%d", &titulo);
        } else {
            titulo = 0;  // No se aplica a Maestranza
        }

        // Calcular el sueldo básico
        switch (categoria) {
            case 'G':
                sueldo_final = G + (G * antiguedad * 0.02);  // 2% por año de antigüedad
                if (titulo == 1) {
                    sueldo_final += G * 0.25;  // 25% si tiene título universitario
                }
                break;

            case 'A':
                sueldo_final = A + (A * antiguedad * 0.02);
                if (titulo == 1) {
                    sueldo_final += A * 0.25;
                }
                break;

            case 'M':
                sueldo_final = M + (M * antiguedad * 0.02);
                sueldo_final += M * 0.15;  // 15% extra por ropa de trabajo
                break;

            default:
                printf("Categoria no válida.\n");
                continue;
        }

        // Aplicar el descuento del 12% por obra social y ART
        sueldo_final -= sueldo_final * 0.12;

        // Mostrar sueldo del empleado
        printf("El sueldo final del empleado es: %.2f\n", sueldo_final);

        // Acumular el gasto total en sueldos
        Total_gastado += sueldo_final;

        // Preguntar si se desea ingresar otro empleado
        printf("¿Desea ingresar otro empleado? (1 para sí, 0 para no): ");
        scanf("%d", &empleado);
    }

    // Mostrar el total gastado en sueldos
    printf("Total gastado en sueldos: %.2f\n", Total_gastado);

    return 0;
}