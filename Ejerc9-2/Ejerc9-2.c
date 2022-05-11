/*
 ============================================================================
 Name        : Ejerc9-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Empleado.h"

int main(void)
{
	setbuf(stdout, NULL);
	char seguir;
	int opciones;
	int auxId;
	int auxIdDos;
	int auxSubMenu;
	eEmpleado empleado[CANT_EMPLEADOS];

	if(initArray(empleado, CANT_EMPLEADOS)==0)
	{
		printf("Se inicializó correctamente");
	}
	do
	{
		if(utn_getNumero(&opciones, "\n1.ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMAR", "\nError\n", 1, 4, 2)==0)
		{
			switch(opciones)
			{
				case 0:
					printf("0");
					break;
				case 1:
					if(pedirCargarDatosEmpleados(empleado,TAM_CHAR,CANT_EMPLEADOS)==0)
					{
						printf("\nSe cargó correctamente");
					}
					break;
				case 2:
					if(utn_getNumero(&auxId, "ID de empleado a modificar: ", "\nError\n", 1, 2, 3)==0)
					{
						if(modificarPorId(empleado,CANT_EMPLEADOS, auxId, TAM_CHAR)==0)
						{
							printf("Se actualizó");
						}
					}
					break;
				case 3:
					if(utn_getNumero(&auxIdDos, "ID del empleado a dar de baja: ", "\nError\n", 1, 2, 3)==0)
					{
						if(darDeBaja(empleado, CANT_EMPLEADOS, auxId)==0)
						{
							printf("Se eliminó con exito");
						}
						else
						{
							printf("Sin datos que eliminar");
						}
					}

					break;
				case 4:
					if(utn_getNumero(&auxSubMenu, "\n1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.", "Error", 1, 2, 3)==0)
					{
						switch(auxSubMenu)
						{
						case 1:
							if(ordenarPorApellidoYSector(empleado, CANT_EMPLEADOS)==0)
							{
								if(mostrarDatos(empleado,CANT_EMPLEADOS)==0)
								{
									printf("\nSe mostró todo ok");
								}
							}
							break;
						case 2:
							break;
						}
					}
			}
		}
		seguir='s';
	} while(seguir=='s');
	return 0;
}


