#include "Concurrencia.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <stdexcept>

std::mutex mtx_consola;// Protege la salida estándar compartida
std::mutex mtx_contador;//protege el contador compartido de transmisiones

void registrarEventoSeguro(const std::string& mensaje) {
	// RAII: Bloquea mtx_consola al crearse y lo desbloquea automáticamente al salir
	std::lock_guard<std::mutex> lock(mtx_consola);
	std::cout << "[HILO " << std::this_thread::get_id() << "] "
		<< mensaje << std::endl;
}

void tareaTransmisionHilo(DispositivoComunicacion* dev, int& transmisionesExistosas) {
	try {
		// Guarda defensiva contra punteros nulos
		if (dev == nullptr) {
			throw std::invalid_argument("ERROR: Puntero nulo pasado al hilo.");
		}
		
		// Invocación polimórfica del método virtual
		dev->transmitir();
		{
		std::lock_guard<std::mutex>lockcontador(mtx_contador);
		transmisionesExistosas++;
		}
		
		registrarEventoSeguro("Transmision exitosa del dispositivo: " + dev->getId());
	}
	catch (const std::exception& e) {
		// Captura y aislamiento de la excepción dentro del hilo
		registrarEventoSeguro(std::string("EXCEPCION EN HILO: ") + e.what());
	}
}
