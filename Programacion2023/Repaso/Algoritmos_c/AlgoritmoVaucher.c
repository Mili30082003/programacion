#include <stdio.h>
int main () {

int residente, edad, datos, cbu;
double ingresos;
  char mensaje[50];

printf ("¿Eres Residente?, marcar con 1:Si o 0:no: ");
scanf ("%d", &residente);

printf ("¿Eres Mayor de 18 años?, marcar con 1:Si o 0:no: ");
scanf ("%d", &edad);

printf ("¿Tienes los datos acreditados en mi ANSES?, marcar con 1:Si o 0:no: ");
scanf ("%d", &datos);

printf ("Ingresar el Ingreso Familiar: ");
scanf ("%lf", &ingresos);

printf ("¿Cuenta con CBU?, marcar con 1:Si o 0:no: ");
scanf ("%d", &cbu);

  
    if (residente == 1 && edad == 1 && datos == 1 && ingresos < 1500000 && cbu == 1) {
        sprintf(mensaje, "Puede Inscribirse");
    } else {
        sprintf(mensaje, "No puede Inscribirse");
    }


    printf("%s\n", mensaje);

    return 0; 
}