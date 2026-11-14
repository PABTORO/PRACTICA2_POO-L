#include <iostream>
#include <vector>
#include <thread>
#include <functional>   // std::ref
#include <stdexcept>
#include <system_error>

#include "DispositivoComunicacion.h"
#include "RouterWiFi.h"
#include "GatewayLoRa.h"
#include "SwitchFibra.h"
#include "TareasConcurrentes.h"
#include "EstadisticasRed.h"
#include "EventoIngenieria2027.h"

int main() {
	// ========================================================
	// 1. VECTOR HETEROGENEO 
	std::vector<DispositivoComunicacion*> red;
	
	try {
		red.push_back(new RouterWiFi("RTR-01", 12));
	} catch (const std::invalid_argument& e) {
		std::cerr << "[Construccion] " << e.what() << std::endl;
	}
	
	try {
		red.push_back(new GatewayLoRa("GW-868", 868.1f));
	} catch (const std::invalid_argument& e) {
		std::cerr << "[Construccion] " << e.what() << std::endl;
	}
	
	try {
		red.push_back(new SwitchFibra("SW-FO-01", 24, 10.0));
	} catch (const std::invalid_argument& e) {
		std::cerr << "[Construccion] " << e.what() << std::endl;
	}
	
	// Prueba de parametros fuera de rango: el constructor lanza, 'new'
	// libera la memoria y el programa continua sin este dispositivo.
	try {
		red.push_back(new RouterWiFi("RTR-02", 500));
	} catch (const std::invalid_argument& e) {
		std::cerr << "[Construccion] " << e.what() << std::endl;
	}
	
	// Provocacion intencional para probar la guarda defensiva del hilo.
	red.push_back(nullptr);
	
	// ========================================================
	// 2. AGENDA DE EVENTOS 2027

	EventoIngenieria2027 agenda;
	try {
		agenda.registrar("IEEE ICC 2027", "IEEE Communications Society",
						 "Washington DC, EE.UU.", "30 may - 3 jun 2027");
		agenda.registrar("IEEE ICASSP 2027", "IEEE Signal Processing Society",
						 "Toronto, Canada", "16 - 21 may 2027");
		agenda.registrar("IEEE LatinIoT 2027", "LatinIoT",
						 "Santiago de Chile", "28 al 30 de abril de 2027");
	} catch (const std::invalid_argument& e) {
		std::cerr << "[Registro de evento] " << e.what() << std::endl;
		std::cerr <<std::endl;
	}
	// ========================================================
	// 3. HILOS: transmision (uno por dispositivo) + eventos

	EstadisticasRed estadisticas;        // Recurso compartido (mutex interno)
	std::vector<std::thread> hilos;
	std::thread hiloEventos;             // Objeto vacio 
	
	try {
		// Reserva previa
		hilos.reserve(red.size());
		
		// Hilo dedicado a la agenda 2027 (funcion miembro + instancia).
		hiloEventos = std::thread(&EventoIngenieria2027::procesarAgenda, &agenda);
		
		// Un hilo por dispositivo; 'estadisticas' pasa por referencia con std::ref.
		for (std::size_t i = 0; i < red.size(); ++i) {
			hilos.push_back(std::thread(tareaTransmisionHilo, red[i], std::ref(estadisticas)));
		}
	} catch (const std::system_error& e) {
		// El sistema no pudo crear un hilo: se informa y se sigue al join
		// de los hilos que si se crearon (evita std::terminate).
		std::cerr << "[Creacion de hilo] " << e.what() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "[Preparacion de hilos] " << e.what() << std::endl;
	}
	
	// ========================================================
	// 4. SINCRONIZACION OBLIGATORIA

	for (std::size_t i = 0; i < hilos.size(); ++i) {
		if (hilos[i].joinable()) {
			hilos[i].join();
		}
	}
	if (hiloEventos.joinable()) {
		hiloEventos.join();
	}
	
	// Resumen final
	estadisticas.imprimirResumen();
	std::cout << "Eventos 2027 registrados: " << agenda.cantidad() << std::endl;
	
	// ========================================================
	// 5. LIBERACION LIMPIA DEL HEAP 
	
	for (std::size_t i = 0; i < red.size(); ++i) {
		delete red[i];      // delete sobre nullptr es seguro (no hace nada)
		red[i] = nullptr;   // Elimina punteros colgantes
	}
	red.clear();
	
	std::cout << "Sistema finalizado correctamente." << std::endl;
	return 0;
}
