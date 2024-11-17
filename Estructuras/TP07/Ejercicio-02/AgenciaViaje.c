#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"


void main () {

int cantViajes = 1;

InfoAgencia * vaijes = malloc(sizeof(InfoAgencia) * cantViajes);

CargarDatosViaje(vaijes, cantViajes);

MostrarInfoViaje(vaijes, cantViajes);

InfoAgencia viajeEmjemplo;

viajeEmjemplo.CostoViaje = vaijes->CostoViaje;

printf("Costo inicial del viaje: %.2f\n", viajeEmjemplo.CostoViaje);
ActualizarCostos(&viajeEmjemplo);

}