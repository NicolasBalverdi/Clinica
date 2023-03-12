#include "TADCadena.h"

typedef long TDni;

typedef struct
{
	TCad nombre;
	int edad;
	TDni DNI;
}Paciente;

Paciente CargarRegistro();
void ModificaRegistro(Paciente *);
void MostrarRegistro(Paciente);
int ComparaRegistroRegistro(Paciente, Paciente);
int ComparaRegistroDNI(Paciente, long);

