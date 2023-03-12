#include "TADCadena.h"

void LeeCad(TCad a, int tam, int j){	int m;
		m=getchar();
		if(j < tam && m != EOF && m != '\n')	{		a[j]=m;		LeeCad(a, tam, j+1);	}	else	{		a[j] = '\0';		LimpiarBuffer();	}}


void LimpiarBuffer()
{
	fflush(stdin);
}

void MostraCad(TCad s)
{
	printf("%s", s);
}

