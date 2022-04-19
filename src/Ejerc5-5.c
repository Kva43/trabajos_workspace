/*
 ============================================================================
 Name        : Ejerc5-5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Ejercicio 5-5: Pedir 10 números enteros distintos de cero entre -50 y 75. La carga
deberá ser aleatoria (todos los elementos se inicializan en cero por default).
Determinar el promedio de los positivos. Desde el mayor de los negativos los
números negativos hasta llegar a cero.
 */

#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 10

int main(void) {
	setbuf(stdout, NULL);

	int i;
	int numeros[CANTIDAD];
	char seguir;

	for(i=0;i<CANTIDAD;i++)
	{
		numeros[i]=0;

		printf("Ingrese valor: ");
		scanf("%d",&numeros[i]);
	}
	if()

	return EXIT_SUCCESS;
}
