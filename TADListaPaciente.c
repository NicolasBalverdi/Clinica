#include "TADListaPaciente.h"

TLista IniciaLista()	
{
	TLista aux;
	aux.tam = 0;
	return aux;
}

int ListaLlena(TLista a)	
{
	if (a.tam < MAX)
		return 1;
	else return 0;
}

int ListaVacia(TLista a)	
{
	if (a.tam != 0)
		return 1;
	else return 0;
}

int VerificarCargado(LPaciente a, int tam, Paciente b)
{
	if(tam > 0 && (ComparaRegistroRegistro(a[tam], b) != 0)) 
		return VerificarCargado(a, tam - 1, b);
	else printf("\nSe termino la carga\n");
	
	if(tam > 0) 
		return tam;
	else return -1;
}

void CargarLista_rec(LPaciente aux, int ini, int fin)
{
	Paciente nvo;
	if(ini <= fin)
	{
		nvo = CargarRegistro();
		if(VerificarCargado(aux, ini, nvo) != -1)
		{
			printf("\nEl paciente con ese DNI ya se encuentra en la lista");
			printf("\nPor favor vuelva a cargar los datos\n");
			ini--;
		}
		else aux[ini] = nvo;
		CargarLista_rec(aux, ini + 1, fin);
	}
	else printf("\nSe termino la carga\n");
}

TLista CargarLista()
{
	TLista aux;
	
	printf("\n________CARGA DE LOS 5 PRIMEROS PACIENTES________"); aux.tam = 5;
	
	CargarLista_rec(aux.lis, 1, aux.tam);

	return aux;
}
	
void QSort_rec(LPaciente a, int ini, int fin){
	Paciente piv;
	int izq, der, med;
	if(ini<fin){
		piv=a[ini];
		izq=ini;
		der= fin;
		
		while(izq<der){
			while(der>izq && (ComparaRegistroRegistro(a[der], piv) == 1))
				der--;
			if(der>izq){
				a[izq]=a[der];
				izq++;
			}
			while(izq<der && (ComparaRegistroRegistro(a[izq], piv) == -1))
			   izq++;
			if(izq<der){
				a[der]=a[izq];
				der--;
			}
		}
		a[der]=piv;
		med=der;
		QSort_rec(a, ini, med-1);
		QSort_rec(a, med+1, fin);
	}
}
	
void OrdenaPaciente(TLista *a){
	QSort_rec(a->lis, 1, a->tam);
}	
	
int Busqueda_Binaria_rec_agrega(TLista a, int ini, int fin, Paciente bus){
	int med;
	med =(ini+fin)/2;
	if(ini<=fin)
		if(ComparaRegistroRegistro(a.lis[med], bus)== 0) return med;
		else if(ComparaRegistroRegistro(a.lis[med], bus) == 1) return Busqueda_Binaria_rec_agrega(a, ini, (med-1), bus);
			else return Busqueda_Binaria_rec_agrega(a, (med+1), fin, bus);
	else return -1;
}	
	
void AgregarPaciente(TLista* a) 
{
	int pos;
	Paciente nvo;
	
	printf("\nIngrese los datos del paciente nuevo\n");
	nvo = CargarRegistro();
	
	pos = Busqueda_Binaria_rec_agrega(*a, 1, a->tam, nvo);
	
	if(pos == -1)
	{
		a->lis[a->tam + 1] = nvo;
		a->tam = a->tam + 1;
	}
	else printf("\nEl paciente con ese numero de DNI ya se encuentra en la lista");
	
	OrdenaPaciente(a);
}

int Busqueda_Binaria_rec(TLista a, int ini, int fin, long bus){
	int med;
	med =(ini+fin)/2;
	if(ini<=fin)
		if(ComparaRegistroDNI(a.lis[med], bus)== 0) return med;
		else if(ComparaRegistroDNI(a.lis[med], bus) == 1) return Busqueda_Binaria_rec(a, ini, (med-1), bus);
		else return Busqueda_Binaria_rec(a, (med+1), fin, bus);
	else return -1;
}	

void EliminarRecursivamente(LPaciente a, int n, int pos){	if(pos!=n){		a[pos]=a[pos+1];		EliminarRecursivamente(a, n, pos+1);	}}
	
void EliminarPaciente(TLista *a)
{
	int pos;
	long bus;
	
	printf("\nIngrese el DNI del paciente a eliminar: ");scanf("%ld", &bus);
	pos = Busqueda_Binaria_rec(*a, 1, a->tam, bus);
	
	if(pos!=-1){
		printf("\n Los datos del paciente a eliminar son: \n");
		MostrarRegistro(a->lis[pos]);
		EliminarRecursivamente(a->lis, a->tam, pos);		a->tam=a->tam-1;
	}
	else printf("\n No se encuentra Paciente\n");
}

void MostrarPaciente(TLista a) 
{
	int pos;
	long bus;

	printf("\nIngrese el DNI del Paciente: "); scanf("%ld", &bus);
	
	pos= Busqueda_Binaria_rec(a, 1, a.tam, bus);

	if (pos != -1)
	{
		MostrarRegistro(a.lis[pos]);
	}
	else printf("\nEl paciente no se encuentra en la lista\n");
}

void ModificarPaciente(TLista *a)
{
	int pos;
	long bus;

	printf("\nIngrese el DNI del Paciente: "); scanf("%ld", &bus);

	pos= Busqueda_Binaria_rec(*a, 1, a->tam, bus);

	if (pos != -1)
	{
		printf("\n Los datos del paciente a modificar son: \n");
		MostrarRegistro(a->lis[pos]);
		ModificaRegistro(&a->lis[pos]);
	}
	else printf("\nEl paciente no se encuentra en la lista\n");
}

void MostrarLista_rec(TLista a, int tam){
	if(tam > 0 ){
		MostrarLista_rec(a, tam-1);
		MostrarRegistro(a.lis[tam]);
	}
}

void MostrarLista(TLista a)
{
	MostrarLista_rec(a, a.tam);
}


