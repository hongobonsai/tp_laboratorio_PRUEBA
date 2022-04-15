/*
 * biblioteca_utn.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Hongo
 */

#include "biblioteca_utn.h"

///@brief Realiza un descuento a un flotante, y devuelve el resultado por puntero.
///@param numero: Trae el flotante a realizar el descuento.
///@param porcentajeDescuento: Trae el porcentaje (1 = 100%, 0.5 = 50%, 0.0 = 5%, etc)
///@param *numeroConDescuento: Te devuelve el resultado por puntero.
///@return Retorna 0 si finalizó la función.
int utn_RealizarDescuento(float numero, float porcentajeDescuento, float *numeroConDescuento) {
	float valorDescuento;
	valorDescuento = numero * porcentajeDescuento;
	*numeroConDescuento = numero - valorDescuento;

	return 0;
}

int utn_RealizarInteres(float numero, float porcentajeInteres, float *numeroConInteres) {
	float valorInteres;
	valorInteres = numero * porcentajeInteres;
	*numeroConInteres = numero + valorInteres;

	return 0;
}

int utn_CalcularConversionValor(float valorInicial, float relacionConversion, float *valorConvertido){

	*valorConvertido = valorInicial / relacionConversion;


	return 0;
}

int utn_ValorPorUnidad(float cantidadUnidades, float valorTotal, float *valorPorUnidad){

	*valorPorUnidad = valorTotal / cantidadUnidades;

	return 0;

}

int utn_ObtenerDiferenciaEntreValores(float primerValor, float segundoValor, float *valorDiferencia){

	if (primerValor >= segundoValor){
		*valorDiferencia = primerValor - segundoValor;
	} else {
		*valorDiferencia = segundoValor - primerValor;
	}
	return 0;
}

int utn_HardcodearTresFloat(float valorUno, float valorDos,
		float valorTres, float *varUno, float *varDos, float *varTres){

	*varUno = valorUno;
	*varDos = valorDos;
	*varTres = valorTres;

	return 0;
}

int utn_tpUno_LlamarTodosLosCalculos(){

	return 0;
}
