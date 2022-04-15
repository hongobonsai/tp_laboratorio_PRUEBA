/*
 ============================================================================
1 Enunciado
Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.  El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar Kilómetros: ( km=x)

2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:

3. Calcular todos los costos:
 a) Tarjeta de débito (descuento 10%)
 b) Tarjeta de crédito (interés 25%)
 c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
 d) Mostrar precio por km (precio unitario)
 e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
 a) Precio con tarjeta de débito: r
 b) Precio con tarjeta de crédito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r
 Aerolíneas:
 a) Precio con tarjeta de débito: r
 b) Precio con tarjeta de crédito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r
 La diferencia de precio es : r “
5. Carga forzada de datos
6. Salir

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int utn_RealizarDescuento(float numero, float porcentajeDescuento, float *numeroConDescuento);
int utn_RealizarInteres(float numero, float porcentajeInteres, float *numeroConInteres);
int utn_CalcularConversionValor(float valorInicial, float relacionConversion, float *valorConvertido);
int utn_ValorPorUnidad(float cantidadUnidades, float valorTotal, float *valorPorUnidad);
int utn_ObtenerDiferenciaEntreValores(float primerValor, float segundoValor, float *valorDiferencia);

int main(void) {
	setbuf(stdout, NULL);
	//1.
	float kilometrosIngresados = 0;
	//2.
	float precioVueloAerolineas;
	float precioVueloLatam;
	//3 y 4
	float precioTarjetaDebitoAerolineas;
	float precioTarjetaDebitoLatam;
	float precioTarjetaCreditoAerolineas;
	float precioTarjetaCreditoLatam;
	float precioBitcoinAerolineas;
	float precioBitcoinLatam;
	float precioPorKmAerolineas;
	float precioPorKmLatam;

	float diferenciaLatamAerolineas;

	int flagIngresoKilometros = 0;
	int flagIngresoPrecioAerolineas = 0;
	int flagIngresoPrecioLatam = 0;




	int opcionMenuPrincipal;
	int opcionSubMenuInformar;
	int opcionSubMenuPrecios;
	do{
		printf("\n1. Ingresar Kilómetros: (km= %.2f)\n\n", kilometrosIngresados);

		printf("2. Ingresar Precio de Vuelos: (Aerolíneas= $%.2f, Latam= $%.2f) \n\n",
				precioVueloAerolineas, precioVueloLatam);

		printf("3. Calcular todos los costos: \n"
				"   a) Tarjeta de débito\n"
				"   b) Tarjeta de crédito\n"
				"   c) Bitcoin\n"
				"   d) Mostrar precio por km\n"
				"   e) Mostrar diferencia de precio ingresada\n\n");

		printf("4. Informar Resultados\n");
		printf("5. Carga forzada de datos \n");
		printf("6. Salir \n");
		scanf("%d", &opcionMenuPrincipal);

		//COMIENZO DE CADA ITEM DEL MENÚ
		switch(opcionMenuPrincipal){

		case 1:
			do{
			printf("\nPor Favor, Ingrese kilómetros: \n");
			flagIngresoKilometros = 1;
			scanf("%f", &kilometrosIngresados);

			} while (kilometrosIngresados <= 0);
			break;
		case 2:
			do {
				do {
					fflush(stdin);
					printf("\nOprima '1' para ingresar el precio de vuelo para Aerolineas.\n"
							"Oprima '2' para ingresar el precio de vuelo para Latam.\n"
							"Oprima '0' para volver al menu principal.\n");
					scanf("%d", &opcionSubMenuPrecios);
					if (opcionSubMenuPrecios != 1
						&& opcionSubMenuPrecios != 2
						&& opcionSubMenuPrecios != 0){

						printf("\n¡INGRESE UNA OPCIÓN VÁLIDA!\n");
					}
				} while (opcionSubMenuPrecios != 1
						&& opcionSubMenuPrecios != 2
						&& opcionSubMenuPrecios != 0);

				if (opcionSubMenuPrecios == 1) {
					do{
					printf("\nIngrese el precio de vuelo para Aerolineas: \n");
					scanf("%f", &precioVueloAerolineas);
					flagIngresoPrecioAerolineas = 1;
						if (precioVueloAerolineas <= 0){
							printf("\n¡INGRESE UNA OPCIÓN VÁLIDA!\n");
						}
					} while (precioVueloAerolineas <= 0);
				} else if (opcionSubMenuPrecios == 2) {
					do{
					printf("\nIngrese el precio de vuelo para Latam: \n");
					scanf("%f", &precioVueloLatam);
					flagIngresoPrecioLatam = 1;
					if (precioVueloLatam <= 0){
							printf("\n¡INGRESE UNA OPCIÓN VÁLIDA!\n");
											}
					} while (precioVueloLatam <= 0);
				}
			} while(opcionSubMenuPrecios != 0);
			break;


		case 3:

			utn_RealizarDescuento(precioVueloAerolineas, 0.10, &precioTarjetaDebitoAerolineas);
			utn_RealizarDescuento(precioVueloLatam, 0.10, &precioTarjetaDebitoLatam);
			utn_RealizarInteres(precioVueloAerolineas,  0.25, &precioTarjetaCreditoAerolineas);
			utn_RealizarInteres(precioVueloLatam,  0.25, &precioTarjetaCreditoLatam);
			utn_CalcularConversionValor(precioVueloAerolineas, 4606954.55, &precioBitcoinAerolineas);
			utn_CalcularConversionValor(precioVueloLatam, 4606954.55, &precioBitcoinLatam);
			utn_ValorPorUnidad(kilometrosIngresados, precioVueloAerolineas, &precioPorKmAerolineas);
			utn_ValorPorUnidad(kilometrosIngresados, precioVueloLatam, &precioPorKmLatam);
			utn_ObtenerDiferenciaEntreValores(precioVueloAerolineas, precioVueloLatam, &diferenciaLatamAerolineas);
			break;
		case 4:

			if (flagIngresoKilometros == 0 || flagIngresoPrecioAerolineas == 0 ||
					flagIngresoPrecioLatam == 0){
				do{
					printf("\nNO SE INGRESARON LOS SIGUIENTES DATOS: \n\n");
					if (flagIngresoKilometros == 0){
						printf("-Kilometros totales. \n");
					}
					if (flagIngresoPrecioAerolineas == 0){
						printf("-Precio del viaje por Aerolineas. \n");
					}
					if (flagIngresoPrecioLatam == 0){
						printf("-Precio del viaje por Latam. \n\n");
					}
					printf("1. ACEPTAR");
					scanf("%d", &opcionSubMenuInformar);
				} while (opcionSubMenuInformar != 1);
			}else {
				do {

					fflush(stdin);
					printf(
							"   \n\nPrecio Aerolineas: $%.2f\n"
							"   a) Precio con tarjeta de débito: $%.2f\n"
							"   b) Precio con tarjeta de crédito: $%.2f\n"
							"   c) Precio pagando con bitcoin: %.8f BTC\n"
							"   d) Precio unitario: $%.2f\n\n"
							"   Precio Latam: $%.2f\n"
							"   a) Precio con tarjeta de débito: $%.2f\n"
							"   b) Precio con tarjeta de crédito: $%.2f\n"
							"   c) Precio pagando con bitcoin: %.8f BTC\n"
							"   d) Precio unitario: $%.2f\n\n"
							"   La diferencia de precio es: $%.2f\n\n",
							precioVueloAerolineas, precioTarjetaDebitoAerolineas,
							precioTarjetaCreditoAerolineas, precioBitcoinAerolineas,
							precioPorKmAerolineas, precioVueloLatam, precioTarjetaDebitoLatam,
							precioTarjetaCreditoLatam, precioBitcoinLatam, precioPorKmLatam,
							diferenciaLatamAerolineas);
					printf("\n0. Volver al menú principal\n");
					scanf("%d", &opcionSubMenuInformar);
				} while(opcionSubMenuInformar != 0);
				break;
			case 5:
				break;
			case 6:
				break;


			}
		}






	}while(opcionMenuPrincipal != 6);


	return EXIT_SUCCESS;
}

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

/*
"   Latam: \n"
				"   a) Precio con tarjeta de débito: \n"
				"   b) Precio con tarjeta de crédito: \n"
				"   c) Precio pagando con bitcoin: \n"
				"   d) Precio unitario: \n"
				"   Aerolíneas: \n"
				"   a) Precio con tarjeta de débito: \n"
				"   b) Precio con tarjeta de crédito: \n"
				"   c) Precio pagando con bitcoin: \n"
				"   d) Precio unitario: \n"
				"   La diferencia de precio es: \n\n\n"
*/



