#include "TareasConcurrentes.h"
#include <iostream>
#include <thread>
#include <stdexcept>

// Definicion unica del mutex global de consola.
std::mutex mtx_consola;


// Registro seguro 

void registrarEventoSeguro(const std::string& mensaje) {

	std::lock_guard<std::mutex> lock(mtx_consola);
	std::cout << "[HILO " << std::this_thread::get_id() << "] "
		<< mensaje << std::endl;
}


// Tarea ejecutada por cada hilo

void tareaTransmisionHilo(DispositivoComunicacion* dev, EstadisticasRed& estadisticas) {
	try {
		// 1. Guarda defensiva: evita desreferenciar nullptr.
		if (dev == nullptr) {
			throw std::invalid_argument("ERROR: Puntero nulo pasado al hilo.");
		}
		
		// 2. Invocacion polimorfica 
		dev->transmitir();
		
		// 3. Recurso compartido: el mutex vive dentro de EstadisticasRed
		//    y se toma con lock_guard en registrarExito().
		estadisticas.registrarExito(dev->getId());
		
		registrarEventoSeguro("Transmision exitosa del dispositivo: "
							  + dev->getId() + " (" + dev->getTipo() + ")");
	}
	catch (const std::invalid_argument& e) {
		registrarEventoSeguro(std::string("[Argumento Invalido] ") + e.what());
	}
	catch (const std::exception& e) {
		registrarEventoSeguro(std::string("[Excepcion Generica] ") + e.what());
	}
	catch (...) {
		registrarEventoSeguro("[Excepcion Desconocida] Error no estandar en hilo.");
	}
}
