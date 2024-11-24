#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*---------------------ESTRUCTURAS---------------------------*/
struct Medico
{
    char ApellidoMedico[50];
    char NombreMedico[50];
    int matricula;

} typedef Medico;

struct Paciente
{
    char ApellidoPaciente[50];
    char NombrePaciente[50];
    int dni;
    int edad;
    char TipoEcografia[50];
} typedef Paciente;

struct ObraSocial
{
    char NombreObraSocial[50];
    char mesFacturacion[30];
    int numFactura;
    float ImportePesos;
    Medico medico;
    int cantPacientes;
    Paciente *paciente;
} typedef ObraSocial;

/*--------------------FUNCIONES-----------------------*/

ObraSocial *cargarDatos();
void PacientesEcografiaObraSocial(ObraSocial *obrasSociales, int cantObrasSocial);
void CantPacientesMayorA60(ObraSocial *obrasSociales, int cantObrasSociales);

void main()
{
    ObraSocial *obrasSociales = cargarDatos();
    PacientesEcografiaObraSocial(obrasSociales, 3);
    CantPacientesMayorA60(obrasSociales, 3);
}

ObraSocial *cargarDatos()
{
    int cantObrasSociales = 3;

    ObraSocial asunt = {"asunt", "Noviembre", 2, 6500, {"Antoni", "Milagros", 12368}, 5, malloc(sizeof(Paciente) * 5)};
    asunt.paciente[0] = (Paciente){"Jeon", "Jungkook", 45122852, 27, "abdominal"};
    asunt.paciente[1] = (Paciente){"Kim", "Taehyung", 4518962, 28, "tiroidea"};
    asunt.paciente[2] = (Paciente){"Latina", "Luissina", 445210, 53, "ginecologica"};
    asunt.paciente[3] = (Paciente){"Min", "Yoongi", 442110, 60, "tiroidea"};
    asunt.paciente[4] = (Paciente){"key", "Sara", 435210, 68, "ginecologica"};

    ObraSocial obraSocial2 = {"obraSocial2", "Noviembre", 6, 9500, {"Samayoa", "Gabriel", 52631}, 5, malloc(sizeof(Paciente) * 5)};
    obraSocial2.paciente[0] = (Paciente){"Kim", "Namjoon", 448995, 28, "abdominal"};
    obraSocial2.paciente[1] = (Paciente){"Kim", "Jennie", 125622, 69, "abdominal"};
    obraSocial2.paciente[2] = (Paciente){"Manoban", "Lalisa", 178522, 40, "tiroidea"};
    obraSocial2.paciente[3] = (Paciente){"Kim", "Jisoo", 124596, 39, "ginecologica"};
    obraSocial2.paciente[4] = (Paciente){"Anahi", "Del Valle", 125691, 69, "tiroidea"};

    ObraSocial obraSocial3 = {"obraSocial3", "Diciembre", 9, 1000, {"Anahi", "Del Valle", 10258}, 5, malloc(sizeof(Paciente) * 5)};
    obraSocial3.paciente[0] = (Paciente){"Kim", "Namjoon", 448995, 28, "abdominal"};
    obraSocial3.paciente[1] = (Paciente){"Kim", "Jennie", 125622, 69, "abdominal"};
    obraSocial3.paciente[2] = (Paciente){"Manoban", "Lalisa", 178522, 40, "tiroidea"};
    obraSocial3.paciente[3] = (Paciente){"Kim", "Jisoo", 124596, 39, "ginecologica"};
    obraSocial3.paciente[4] = (Paciente){"Anahi", "Del Valle", 125691, 69, "tiroidea"};

    ObraSocial *obrasSociales = malloc(sizeof(ObraSocial) * cantObrasSociales);

    obrasSociales[0] = asunt;
    obrasSociales[1] = obraSocial2;
    obrasSociales[2] = obraSocial3;

    return obrasSociales;
}

void PacientesEcografiaObraSocial(ObraSocial *obrasSociales, int cantObrasSocial)
{

    for (int i = 0; i < cantObrasSocial; i++)
    {

        for (int j = 0; j < obrasSociales[i].cantPacientes; j++)
        {
            if (strcmp(obrasSociales[i].NombreObraSocial, "asunt") == 0 && strcmp(obrasSociales[i].mesFacturacion, "Noviembre") == 0 && strcmp(obrasSociales[i].paciente[j].TipoEcografia, "tiroidea") == 0)
            {
                printf("\n ***** Paciente %d ****\n", j + 1);
                printf("Obra Social: %s\n", obrasSociales[i].NombreObraSocial);
                printf("Mes: %s\n", obrasSociales[i].mesFacturacion);
                printf("Nombre y Apellido: %s %s\n", obrasSociales[i].paciente[j].NombrePaciente, obrasSociales[i].paciente[j].ApellidoPaciente);
                printf("DNI: %d\n", obrasSociales[i].paciente[j].dni);
                printf("Edad: %d\n", obrasSociales[i].paciente[j].edad);
                printf("Tipo de Ecografia: %s\n", obrasSociales[i].paciente[j].TipoEcografia);
                printf("\n");
            }
        }
    }
}

void CantPacientesMayorA60(ObraSocial *obrasSociales, int cantObrasSociales) {

    printf("Pacientes Mayores de 60: \n");
    printf(" -----------------------\n");
    for (int i = 0; i < cantObrasSociales; i++)
    {
        for (int j = 0; j < obrasSociales[i].cantPacientes; j++)
        {
            if (strcmp(obrasSociales[i].mesFacturacion, "Noviembre") == 0 && obrasSociales[i].paciente[j].edad > 60)
            {
                printf("Paciente %d\n", j + 1);
                printf("Obra Social: %s\n", obrasSociales[i].NombreObraSocial);
                printf("Apellido y Nombre: %s %s\n", obrasSociales[i].paciente[j].ApellidoPaciente, obrasSociales[i].paciente[j].NombrePaciente);
                printf("Edad: %d\n", obrasSociales[i].paciente[j].edad);
                printf("Mes: %s\n", obrasSociales[i].mesFacturacion);
                printf("\n");
            }
            
        }
        
    }
    
}