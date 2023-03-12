#include "TADPaciente.h"

Paciente CargarRegistro()
{
	Paciente aux;

	LimpiarBuffer();
	printf("\nIngrese el nombre del paciente: "); LeeCad(aux.nombre, CMAX, 0);
	printf("\nIngrese la edad del paciente: "); scanf("%d", &aux.edad);
	printf("\nIngrese el DNI del paciente: "); scanf("%ld", &aux.DNI);

	return aux;
}

void ModificaRegistro(Paciente *a)
{
	LimpiarBuffer();
	printf("\nIngrese el nombre del paciente: "); LeeCad(a->nombre, CMAX, 0);
	printf("\nIngrese la edad del paciente: "); scanf("%d", &a->edad);
}

void MostrarRegistro(Paciente a)
{
	printf("\nNombre: "); MostraCad(a.nombre);
	printf("\nEdad: %d", a.edad);
	printf("\nDNI: %ld", a.DNI);
	printf("\n");
}

int ComparaRegistroRegistro(Paciente a, Paciente bus) {
	if (a.DNI > bus.DNI) return 1;
	else if (a.DNI == bus.DNI) return 0;
	else return -1;
}

int ComparaRegistroDNI(Paciente a, long bus) {
	if (a.DNI > bus) return 1;
	else if (a.DNI == bus) return 0;
	else return -1;
}
