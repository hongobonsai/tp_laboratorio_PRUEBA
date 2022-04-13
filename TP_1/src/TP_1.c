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

int utn_funcionRealiceDescuento(float numero, float porcentajeDescuento, float *numeroConDescuento);

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
	char opcionSubMenuPrecios;
	do{
		printf("1. Ingresar Kilómetros: (km= %.2f)\n\n", kilometrosIngresados);

		printf("2. Ingresar Precio de Vuelos: (Aerolíneas=$%.2f, Latam=$%.2f) \n\n",
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
			printf("\n Por Favor, Ingrese kilómetros: \n\n");
			scanf("%f", &kilometrosIngresados);
			} while (kilometrosIngresados <= 0);
			break;
		case 2:
			do {
				do {
					fflush(stdin);
					printf(
							"Oprima 'a' para ingresar el precio de vuelo para Aerolineas.\n"
							"Oprima 'b' para ingresar el precio de vuelo para Latam.\n"
							"Oprima 'c' para volver al menu principal.\n");
					scanf("%c", &opcionSubMenuPrecios);
					if (opcionSubMenuPrecios != 'a'
						&& opcionSubMenuPrecios != 'b'
						&& opcionSubMenuPrecios != 'c'){

						printf("¡INGRESE UNA OPCIÓN VÁLIDA!\n\n");
					}
				} while (opcionSubMenuPrecios != 'a'
						&& opcionSubMenuPrecios != 'b'
						&& opcionSubMenuPrecios != 'c');

				if (opcionSubMenuPrecios == 'a') {
					do{
					printf("Ingrese el precio de vuelo para Aerolineas: \n");
					scanf("%f", &precioVueloAerolineas);
						if (precioVueloAerolineas <= 0){
							printf("¡INGRESE UNA OPCIÓN VÁLIDA!\n\n");
						}
					} while (precioVueloAerolineas <= 0);
				} else if (opcionSubMenuPrecios == 'b') {
					do{
					printf("Ingrese el precio de vuelo para Latam: \n");
					scanf("%f", &precioVueloLatam);
					if (precioVueloLatam <= 0){
							printf("¡INGRESE UNA OPCIÓN VÁLIDA!\n\n");
											}
					} while (precioVueloLatam <= 0);
				}
			} while(opcionSubMenuPrecios != 'c');
			break;

			/*
			3. Calcular todos los costos:
			 a) Tarjeta de débito (descuento 10%)
			 b) Tarjeta de crédito (interés 25%)
			 c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
			 d) Mostrar precio por km (precio unitario)
			 e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
			 ============================================================================
			float precioTarjetaDebitoAerolineas;
			float precioTarjetaDebitoLatam;
			float precioTarjetaCreditoAerolineas;
			float precioTarjetaCreditoLatam;
			float precioBitcoinAerolineas;
			float precioBitcoinLatam;
			float precioPorKmAerolineas;
			float precioPorKmLatam;

			float diferenciaLatamAerolineas;

			 */


		case 3:

			utn_funcionRealiceDescuento(precioVueloAerolineas, 0.10, &precioTarjetaDebitoAerolineas);

/*control*/		printf("%fPrecio tarjeta debito aerolineas: \n", precioTarjetaDebitoAerolineas);

			utn_funcionRealiceDescuento(precioVueloLatam, 0.10, &precioTarjetaDebitoLatam);

/*control*/		printf("%fPrecio tarjeta debito latam: \n", precioTarjetaDebitoLatam);





			break;
		case 4:
			do {

				fflush(stdin);
				printf(
						"   Latam: \n"
						"   a) Precio con tarjeta de débito: \n"
						"   b) Precio con tarjeta de crédito: \n"
						"   c) Precio pagando con bitcoin: \n"
						"   d) Precio unitario: \n\n"
						"   Aerolíneas: \n"
						"   a) Precio con tarjeta de débito: \n"
						"   b) Precio con tarjeta de crédito: \n"
						"   c) Precio pagando con bitcoin: \n"
						"   d) Precio unitario: \n"
						"   La diferencia de precio es: \n\n\n");
				scanf("%c", &opcionSubMenuPrecios);
			} while(opcionSubMenuPrecios != 'a'
					&& opcionSubMenuPrecios != 'b'
					&& opcionSubMenuPrecios != 'c');
			break;
		case 5:
			break;
		case 6:
			break;


		}






	}while(opcionMenuPrincipal != 6);


	return EXIT_SUCCESS;
}

int utn_funcionRealiceDescuento(float numero, float porcentajeDescuento, float *numeroConDescuento) {
	float valorDescuento;
	valorDescuento = numero * porcentajeDescuento;
	*numeroConDescuento = numero - valorDescuento;

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



