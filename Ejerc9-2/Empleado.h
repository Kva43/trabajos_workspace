/*
 * Empleado.h
 *
 *  Created on: 6 may. 2022
 *      Author: USUARIO
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

#define CANT_EMPLEADOS 2
#define TAM_CHAR 51

typedef struct
{
	int id;
	char name[TAM_CHAR];
	char lastName[TAM_CHAR];
	int salary;
	int sector;
	int isEmpty;
}eEmpleado;

int initArray(eEmpleado array[], int cantidad);
int pedirCargarDatosEmpleados(eEmpleado*aux, int longitud, int cantidad);
int mostrarDatos(eEmpleado*aux, int cantidad);
int modificarPorId(eEmpleado aux[],int limite, int id, int len);
int darDeBaja(eEmpleado aux[], int limite, int id);
int ordenarPorApellidoYSector(eEmpleado aux[], int limite);

#endif /* EMPLEADO_H_ */
