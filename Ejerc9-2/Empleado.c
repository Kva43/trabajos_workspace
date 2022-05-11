/*
 * Empleado.c
 *
 *  Created on: 6 may. 2022
 *      Author: USUARIO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Empleado.h"
#define CANT_EMPLEADOS 2
#define TAM_CHAR 51

int initArray(eEmpleado array[], int cantidad)
{
	int ret=-1;
	int i;
	int id=1;
	if(array!=NULL && cantidad>0)
	{
		for(i=0;i<cantidad;i++)
		{
			array[i].isEmpty=0;
			array[i].id=id;
			id++;
		}
		ret=0;
	}
	return ret;
}
int pedirCargarDatosEmpleados(eEmpleado*aux, int longitud, int cantidad)
{
	int ret=-1;
	int i;
	char seguir;

	for(i=0;i<cantidad;i++)
	{
		printf("Empleado: %d\n",i+1);
		if(utn_getNombre(aux[i].name, "Nombre: ", "\nError", longitud, 2)==0
		&& utn_getNombre(aux[i].lastName, "Apellido: ", "\nError", longitud, 2)==0
		&& utn_getNumero(&aux[i].salary, "Su salario: $ ", "\nError", 1, 3000, 2)==0
		&& utn_getNumero(&aux[i].sector, "Sector: ", "\nError", 1, 3, 2)==0)
		{
			ret=0;
			aux[i].isEmpty=-1;
		}
	}
	return ret;
}
int mostrarDatos(eEmpleado*aux, int cantidad)
{
	int i;
	int ret=-1;

	for(i=0;i<cantidad;i++)
	{
		if(aux[i].isEmpty==-1)
		{
			printf("\nID automatico: %d",aux[i].id);
			printf("\nNombre ingresado: %s",aux[i].name);
			printf("\nApellido ingresado: %s",aux[i].lastName);
			printf("\nSalario ingresado: %d",aux[i].salary);
			printf("\nSector ingresado: %d",aux[i].sector);
		}
	}
	ret=0;
	return ret;
}

int modificarPorId(eEmpleado aux[], int limite, int id, int len)
{
	int ret=-1;
	int i;
	int auxOpcion;
	if(aux!=NULL && limite>=0 && id>=0)
	{
		for(i=0;i<limite;i++)
		{
			if(aux[i].id == id)
			{
				if(utn_getNumero(&auxOpcion, "Que desea modificar: \n'1' (nombre)\n'2' (apellido)\n'3' (salario)\n'4' (sector)", "Error", 1, 4, 3)==0)
				{
					switch(auxOpcion)
					{
					case 1:
						if(utn_getNombre(aux[i].name, "Nombre: ", "\nError", len, 3)==0)
						{
							ret=0;
							break;
						}
						break;
					case 2:
						if(utn_getNombre(aux[i].lastName, "Apellido: ", "\nError", len, 3)==0)
						{
							ret=0;
							break;
						}
						break;
					case 3:
						if(utn_getNumero(&aux[i].salary, "Su salario: $ ", "\nError", 1, 9999, 3)==0)
						{
							ret=0;
							break;
						}
						break;
					case 4:
						if(utn_getNumero(&aux[i].sector, "Sector: ", "\nError", 1, 9999, 3)==0)
						{
							ret=0;
							break;
						}
						break;
					}
				}
				break;
			}
		}
	}

	return ret;
}

int darDeBaja(eEmpleado aux[], int limite, int id)
{
	int ret=-1;
	int i;
	if(aux!=NULL && limite>=0 && id>=0)
	{
		for(i=0;i<limite;i++)
		{
			if(aux[i].id == id && aux[i].isEmpty==-1)
			{
				ret=0;
				aux[i].isEmpty=0;
			}
		}
	}

	return ret;
}

int ordenarPorApellidoYSector(eEmpleado* aux, int limite)
{
	int ret=-1;
	int i;
	int flagSwap;
	eEmpleado buffer;

	if(aux!=NULL && limite>=0)
	{
		do
		{
			flagSwap=0;
			for(i=0;i<limite-1;i++)
			{
				if((strncmp(aux[i].lastName,aux[i+1].lastName, TAM_CHAR)<0)
				|| (strncmp(aux[i].lastName,aux[i+1].lastName, TAM_CHAR)==0 && aux[i].sector < aux[i+1].sector))
				{
					flagSwap=1;
					buffer=aux[i];
					aux[i]=aux[i+1];
					aux[i+1]=buffer;
					ret=0;
				}
			}
			limite--;
		} while(flagSwap);
	}

	return ret;
}




