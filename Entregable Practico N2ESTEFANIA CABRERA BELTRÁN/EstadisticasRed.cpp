#include "EstadisticasRed.h"
#include "TareasConcurrentes.h"   // extern std::mutex mtx_consola
#include <iostream>
#include <stdexcept>

EstadisticasRed::EstadisticasRed() : transmisionesExitosas(0) {}

void EstadisticasRed::registrarExito(const std::string& idDispositivo) {
	// Guarda defensiva ANTES de tomar el lock.
	if (idDispositivo.empty()) {
		throw std::invalid_argument("ERROR: Id de dispositivo vacio en estadisticas.");
	}
	
	std::lock_guard<std::mutex> lock(mtx);
	++transmisionesExitosas;
	bitacora.push_back(idDispositivo);
}

int EstadisticasRed::getExitosas() const {
	std::lock_guard<std::mutex> lock(mtx);
	return transmisionesExitosas;
}

std::size_t EstadisticasRed::getTamanoBitacora() const {
	std::lock_guard<std::mutex> lock(mtx);
	return bitacora.size();
}

void EstadisticasRed::imprimirResumen() const {
	// Bloqueo atomico de ambos mutex: sin riesgo de deadlock 
	std::lock(mtx, mtx_consola);
	
	// Se adoptan los mutex ya bloqueados para liberacion RAII.
	std::lock_guard<std::mutex> lockEstadisticas(mtx, std::adopt_lock);
	std::lock_guard<std::mutex> lockConsola(mtx_consola, std::adopt_lock);
	
	std::cout << "=== RESUMEN DE TRANSMISIONES ===" << std::endl;
	std::cout << "Exitosas: " << transmisionesExitosas << std::endl;
	for (std::size_t i = 0; i < bitacora.size(); ++i) {
		std::cout << "  " << (i + 1) << ". " << bitacora[i] << std::endl;
	}
	std::cout << "================================" << std::endl;
}
