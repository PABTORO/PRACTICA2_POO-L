#include "TareasHilo.h"
#include "Logger.h"
#include <stdexcept>
#include <string>
#include <thread>
#include <chrono>

void tareaTransmisionHilo(DispositivoComunicacion* dev, EstadisticasRed& stats){
	try{
		if (dev == nullptr){
			throw std::invalid_argument("ERROR: Puntero nulo pasado al hilo.");
		}
		dev->transmitir();
		registrarEventoSeguro("Transmision exitosa del dispositivo: " + dev->getId());
		stats.sumarExitosa();
	}
	catch (const std::exception& e) {
		registrarEventoSeguro(std::string("EXCEPCION EN HILO: ") + e.what());
		stats.sumarFallida();
	}
}
void tareaAgendaHilo(const std::vector<EventoIngenieria2027>& agenda){
	try {
		for (size_t i = 0; i < agenda.size(); i++) {
			registrarEventoSeguro(agenda[i].getResumen());
			std::this_thread::sleep_for(std::chrono::milliseconds(80));
		}
	}
	catch (const std::exception& e) {
		registrarEventoSeguro(std::string("EXCEPCION EN AGENDA: ") + e.what());
	}
}
