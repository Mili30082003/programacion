#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"


void main () {

int cantViajes = 1;

InfoAgencia * vaijes = malloc(sizeof(InfoAgencia) * cantViajes);

CargarDatosViaje(vaijes, cantViajes);

MostrarInfoViaje(vaijes, cantViajes);


}