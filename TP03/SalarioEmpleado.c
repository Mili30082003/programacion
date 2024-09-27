#include <stdio.h>
int main () {


    float salario;
    float Aumento;
    long codigo;


    printf ("Ingrese el codigo del empleado: ");
    scanf ("%li", &codigo);
    printf ("Ingrese su salario : ");
    scanf ("%f", &salario);

    while (codigo != 000)
    {
        Aumento = (salario*.1) + salario;
        printf ("Felicidades, su sueldo es de : %2.f\n",Aumento);
    
       
           printf ("Ingrese el codigo del empleado: ");
        scanf ("%li", &codigo);
             if (codigo == 000) {
                printf ("Saliendo...");
            break;
        }
       
        printf("Ingrese su salario: ");
        scanf("%f", &salario);
           
    }
 
    return 0;
}