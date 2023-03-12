#include "TADPaciente.h"

typedef Paciente LPaciente[MAX];

typedef struct
{
	LPaciente lis;
	int tam;
}TLista;

TLista IniciaLista();
int ListaLlena(TLista);
int ListaVacia(TLista);
TLista CargarLista();
void OrdenaPaciente(TLista *);
void AgregarPaciente(TLista *);
void EliminarPaciente(TLista *);
void MostrarPaciente(TLista);
void ModificarPaciente(TLista *a);
void MostrarLista(TLista);
