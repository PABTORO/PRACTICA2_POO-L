#include "Concurrencia.h"
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
#include <stdexcept>

std::mutex mtx_consola;
std::mutex mtx_contador;

void registrarEventoSeguro(const std::string& mensaje) {
	std::lock_guard<std::mutex> lock(mtx_consola);
	std::cout << "[HILO " << std::this_thread::get_id() << "] "
		<< mensaje << std::endl;
}

void tareaTransmisionHilo(DispositivoComunicacion* dev, int& contador) {
	try {
		// Guarda defensiva contra punteros nulos
		if (dev == nullptr) {
			throw std::invalid_argument("ERROR: Puntero nulo pasado al hilo.");
		}
		
		// Invocacion polimorfica (ligadura tardia)
		dev->transmitir();
		
		// Seccion critica protegida (RAII)
		{
			std::lock_guard<std::mutex> lock(mtx_contador);
			++contador;
		}
		
		registrarEventoSeguro("Transmision exitosa del dispositivo: " +
							  dev->getId() + " (" + dev->getTipo() + ")");
	}
	catch (const std::exception& e) {
		// Se captura DENTRO del hilo para evitar std::terminate()
		registrarEventoSeguro(std::string("EXCEPCION EN HILO: ") + e.what());
	}
}

void mostrarAgendaEventos(const std::vector<EventoIngenieria2027>& agenda) {
	try {
		registrarEventoSeguro("=== AGENDA DE EVENTOS DE INGENIERIA 2027 ===");
		for (size_t i = 0; i < agenda.size(); ++i) {
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
			std::ostringstream ss;
			ss << "Evento " << (i + 1) << ": " << agenda[i].descripcion();
			registrarEventoSeguro(ss.str());
		}
	}
	catch (const std::exception& e) {
		registrarEventoSeguro(std::string("EXCEPCION EN AGENDA: ") + e.what());
	}
}
