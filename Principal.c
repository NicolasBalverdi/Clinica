#include "TADListaPaciente.h"

int menu();

void menuSwitch(TLista);

int main()
{
	
	TLista L1;

	L1 = IniciaLista();
	L1 = CargarLista();
	OrdenaPaciente(&L1);
	
	menuSwitch(L1);


	return 0;
}

int menu()
{
	int ele;

	printf("\n1-Agregar paciente nuevo");
	printf("\n2-Eliminar paciete dado el DNI");
	printf("\n3-Mostrar un paciente dado el DNI");
	printf("\n4-Modificar dato de paciente dado el DNI");
	printf("\n5-Mostrar lista");
	printf("\n0-Salir");

	printf("\n\nIngrese su eleccion: "); scanf("%d", &ele);

	system("cls");
	
	return ele;
}

void menuSwitch(TLista L1){
	int ele;
	ele = menu();
	
	if (ele!=0){
		switch (ele){
		case 1:	if (ListaLlena(L1)) AgregarPaciente(&L1); else printf("\nLa lista esta llena"); break;
		case 2:	if (ListaVacia(L1)) EliminarPaciente(&L1); else printf("\nLa lista esta vacia"); break;
		case 3:	if (ListaVacia(L1)) MostrarPaciente(L1); else printf("\nLa lista esta vacia"); break;
		case 4:	if (ListaVacia(L1)) ModificarPaciente(&L1); else printf("\nLa lista esta vacia"); break;
		case 5: if (ListaVacia(L1)) MostrarLista(L1); else printf("\nLa lista esta vacia"); break;
		default: printf("\nIngreso un valor no valido\n"); break;
		}
		menuSwitch(L1);
	}
	else printf("\nSaliendo de la lista");
	
}
