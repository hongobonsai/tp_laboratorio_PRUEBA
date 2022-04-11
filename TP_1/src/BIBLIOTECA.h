/*
 * BIBLIOTECA.h
 *
 *  Created on: 7 abr. 2022
 *      Author: Hongo
 */

//EN EL .H SE PONEN LOS PROTOTIPOS/FIRMAS
//se escribe en el .h la documentacion
//ponerle UTN_getInt (por ejemplo)

#include <stdio.h>
#include <stdlib.h>
#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

int funcionSumaDosEnteros(int primerNumero, int segundoNumero, int *resultado);

int funcionRestaDosEnteros(int primerNumero, int segundoNumero, int *resultado);

int funcionRealiceDescuento(int numero, float porcentajeDescuento,
		float *valorDescuento, float *numeroConDescuento);

int getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,
		int maximo, int minimo, int maximoDeReintentos);


#endif /* BIBLIOTECA_H_ */
