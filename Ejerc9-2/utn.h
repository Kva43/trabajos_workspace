/*
 * funciones.h
 *
 *  Created on: 23 abr. 2022
 *      Author: USUARIO
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNombre(char* pResultado,char* mensaje,char* mensajeError, int longitud, int reintentos);


#endif /* UTN_H_ */
