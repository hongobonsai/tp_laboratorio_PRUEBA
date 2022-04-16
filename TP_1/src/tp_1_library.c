/*
 * tp_1_library.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Hongo
 */

#include "tp_1_library.h"

int tp_Uno_PrintPreciosDelMenu(float precioVueloAerolineas,
		float precioVueloLatam, float precioTarjetaDebitoAerolineas,
		float precioTarjetaDebitoLatam, float precioTarjetaCreditoAerolineas,
		float precioTarjetaCreditoLatam, float precioBitcoinAerolineas,
		float precioBitcoinLatam, float precioPorKmAerolineas,
		float precioPorKmLatam, float diferenciaLatamAerolineas) {
	printf("   \nPrecio Aerolineas: $%.2f\n"
			"   a) Precio con tarjeta de débito: $%.2f\n"
			"   b) Precio con tarjeta de crédito: $%.2f\n"
			"   c) Precio pagando con bitcoin: %.8f BTC\n"
			"   d) Precio unitario: $%.2f\n\n"
			"   Precio Latam: $%.2f\n"
			"   a) Precio con tarjeta de débito: $%.2f\n"
			"   b) Precio con tarjeta de crédito: $%.2f\n"
			"   c) Precio pagando con bitcoin: %.8f BTC\n"
			"   d) Precio unitario: $%.2f\n\n"
			"   La diferencia de precio es: $%.2f\n\n", precioVueloAerolineas,
			precioTarjetaDebitoAerolineas, precioTarjetaCreditoAerolineas,
			precioBitcoinAerolineas, precioPorKmAerolineas, precioVueloLatam,
			precioTarjetaDebitoLatam, precioTarjetaCreditoLatam,
			precioBitcoinLatam, precioPorKmLatam, diferenciaLatamAerolineas);
	return 0;
}

int tp_Uno_MenuPrincipal(float kilometrosIngresados, float precioVueloAerolineas, float precioVueloLatam){
	int auxOpcionMenuPrincipal;
	printf(
					"\n******************************************************************************"
							"\n1. Ingresar Kilómetros: (km= %.2f)\n\n",
							kilometrosIngresados);

			printf(
					"2. Ingresar Precio de Vuelos: (Aerolíneas= $%.2f, Latam= $%.2f) \n\n",
					precioVueloAerolineas, precioVueloLatam);

			printf("3. Calcular todos los costos: \n"
					"   a) Tarjeta de débito\n"
					"   b) Tarjeta de crédito\n"
					"   c) Bitcoin\n"
					"   d) Mostrar precio por km\n"
					"   e) Mostrar diferencia de precio ingresada\n\n");

			printf("4. Informar Resultados\n");
			printf("5. Carga forzada de datos \n");
			printf(
					"6. Salir \n******************************************************************************\n");

			scanf("%d", &auxOpcionMenuPrincipal);


	return auxOpcionMenuPrincipal;
}
