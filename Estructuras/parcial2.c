#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ginecologica, adbominal, renal, tiroidea

struct Medico
{
    char nombre[50];
    char apellido[50];
    int matricula;
} typedef Medico;

struct Paciente
{
    char nombre[50];
    char apellido[50];
    int dni;
    int edad;
    char ecografia[50];
} typedef Paciente;

struct ObraSocial
{
    char nombre_OS[50];
    int mesFacturacion;
    int nroFactura;
    float importe;
    Medico medico;
    int cantidadPacientes;
    Paciente *pacientes;
} typedef ObraSocial;

// ginecologica, abdominal, renal, tiroidea

ObraSocial *cargarDatos();
void informe1(ObraSocial *obrasSociales, int cantidadOS, char *obra_social, char *tipoEcografia, int mes);
void informe2(ObraSocial *obrasSociales, int cantidadOS, int mesAtencion, int edadPaciente);
void mostrarPaciente(Paciente paciente);
void liberarMemoria(ObraSocial *obrasSociales, int cantidadOS);

int main()
{
    int cantidad_OS = 3;
    ObraSocial *obrasSociales = cargarDatos();

    informe1(obrasSociales, cantidad_OS, "osde", "abdominal", 11);
    informe2(obrasSociales, cantidad_OS, 11, 60);

    liberarMemoria(obrasSociales,cantidad_OS);

    return 0;
}

ObraSocial *cargarDatos()
{
    int cantidad_OS = 3;

    ObraSocial asunt = {"asunt", 11, 1, 1000, {"Juan", "Perez", 1234}, 3, malloc(sizeof(Paciente) * 3)};
    asunt.pacientes[0] = (Paciente){"Maria", "Del valle", 1234, 60, "adbominal"};
    asunt.pacientes[1] = (Paciente){"Lucas", "Alarcon", 1234, 70, "tiroidea"};
    asunt.pacientes[2] = (Paciente){"Lucas", "Diaz", 1234, 70, "tiroidea"};

    ObraSocial osde = {"osde", 11, 1, 1500, {"Julian", "Alvarez", 4567}, 3, malloc(sizeof(Paciente) * 3)};
    osde.pacientes[0] = (Paciente){"Lucia", "Del valle", 1234, 65, "abdominal"};
    osde.pacientes[1] = (Paciente){"Carmen", "Del valle", 1234, 50, "abdominal"};
    osde.pacientes[2] = (Paciente){"Estela", "Del valle", 1234, 60, "abdominal"};

    ObraSocial pami = {"pami", 1, 1, 900, {"Enzo", "Perez", 7890}, 3, malloc(sizeof(Paciente) * 3)};
    pami.pacientes[0] = (Paciente){"Lucas", "Perez", 1234, 70, "tiroidea"};
    pami.pacientes[1] = (Paciente){"Luis", "Perez", 1234, 25, "abdominal"};
    pami.pacientes[2] = (Paciente){"Martin", "Perez", 1234, 80, "tiroidea"};

    ObraSocial *obrasSociales = malloc(sizeof(ObraSocial) * cantidad_OS);

    obrasSociales[0] = pami;
    obrasSociales[1] = asunt;
    obrasSociales[2] = osde;

    return obrasSociales;
}

void informe1(ObraSocial *obrasSociales, int cantidadOS, char *obraSocial, char *tipoEcografia, int mes)
{
    printf("****** Informe 1 ******");
    printf("Obra social:%s - Mes de atencion:%d\n", obraSocial, mes);
    printf("Tipo de ecografia: %s\n", tipoEcografia);
    printf("Listado de pacientes:\n");
    for (int i = 0; i < cantidadOS; i++)
    {
        if (strcmp(obrasSociales->nombre_OS, obraSocial) == 0 && obrasSociales->mesFacturacion == mes)
        {
            for (int j = 0; j < obrasSociales->cantidadPacientes; j++)
            {
                if (strcmp(obrasSociales->pacientes[j].ecografia, tipoEcografia) == 0)
                {
                    mostrarPaciente(obrasSociales->pacientes[j]);
                }
            }
        }
        obrasSociales++;
    }
}

void informe2(ObraSocial *obrasSociales, int cantidadOS, int mes, int edadPaciente)
{
    printf("****** Informe 2 ******\n");
    printf("Listado de pacientes atendidos en el mes %d mayores a %d anios\n", mes, edadPaciente);
    for (int i = 0; i < cantidadOS; i++)
    {
        if (obrasSociales->mesFacturacion == mes)
        {
            for (int j = 0; j < obrasSociales->cantidadPacientes; j++)
            {
                if (obrasSociales->pacientes[j].edad > edadPaciente)
                {
                    mostrarPaciente(obrasSociales->pacientes[j]);
                }
            }
        }
        obrasSociales++;
    }
}

void mostrarPaciente(Paciente paciente)
{
    printf("\t- Nombre: %s %s\n", paciente.apellido, paciente.nombre);
    printf("\t- DNI:%d | Edad:%d\n", paciente.dni, paciente.edad);
    printf("\n");
}

void liberarMemoria(ObraSocial *obrasSociales, int cantidadOS)
{
    for (int i = 0; i < cantidadOS; i++)
    {
        free(obrasSociales[i].pacientes);
    }
    free(obrasSociales);
}