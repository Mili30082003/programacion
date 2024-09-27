/*
Algoritmo:Notas_Materias
Entrada:nota_lengua, nota_matematicas, nota_ciencias: R+
Salida: promedio: R, mensaje: cc
A1_ LEER (nota_lengua, nota_matematicas, nota_ciencias)
A2_ calcular_promedio
	Promedio <- (nota_lengua+ nota_matematicas+ nota_ciencias)/3
	SEGUN promedio
		promedio >= 5: mensaje <-- "Reprobado"
		 5<=promedio<=7: mensaje <-- "Regular"
		7>=promedio<=8: mensaje <-- "Muy Bueno"
		promedio <= 9: mensaje <-- "Excelente"
	FIN_SEGUN
A3_ ESCRIBIR (promedio, mensaje)
A4_PARAR
		*/
#include <stdio.h>

int main() {
    float nota_lengua, nota_matematicas, nota_ciencias;
    float promedio;

    printf("Ingrese la nota de Lengua: ");
    scanf("%f", &nota_lengua);

    printf("Ingrese la nota de Matematicas: ");
    scanf("%f", &nota_matematicas);

    printf("Ingrese la nota de Ciencias: ");
    scanf("%f", &nota_ciencias);

    promedio = (nota_lengua + nota_matematicas + nota_ciencias) / 3;

    if (promedio < 5) {
        printf("El promedio es: %.2f - Clasificacion: Reprobado\n", promedio);
    } else if (promedio < 7) {
        printf("El promedio es: %.2f - Clasificacion: Regular\n", promedio);
    } else if (promedio < 9) {
        printf("El promedio es: %.2f - Clasificacion: Muy bueno\n", promedio);
    } else {
        printf("El promedio es: %.2f - Clasificacion: Excelente\n", promedio);
    }
    return 0;
}
