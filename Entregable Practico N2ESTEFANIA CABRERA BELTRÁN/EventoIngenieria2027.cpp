#include "EventoIngenieria2027.h"
#include "TareasConcurrentes.h"   // registrarEventoSeguro (mutex de consola)
#include <stdexcept>
#include <sstream>

void EventoIngenieria2027::registrar(const std::string& nombre,
									 const std::string& organizador,
									 const std::string& lugar,
									 const std::string& periodo)
{
	// Guarda defensiva: se valida ANTES de tomar el lock.
	if (nombre.empty() || organizador.empty() || lugar.empty() || periodo.empty()) {
		throw std::invalid_argument("ERROR: Evento 2027 con campos vacios.");
	}
	
	DatosEvento d;
	d.nombre = nombre;
	d.organizador = organizador;
	d.lugar = lugar;
	d.periodo = periodo;
	
	std::lock_guard<std::mutex> lock(mtx_agenda);
	eventos.push_back(d);
}

std::size_t EventoIngenieria2027::cantidad() const {
	std::lock_guard<std::mutex> lock(mtx_agenda);
	return eventos.size();
}

void EventoIngenieria2027::procesarAgenda() const {
	try {
		// 1. Copia local bajo lock; el lock se libera al cerrar el bloque.
		std::vector<DatosEvento> copia;
		{
			std::lock_guard<std::mutex> lock(mtx_agenda);
			copia = eventos;
		}
		
		// 2. Despliegue fuera del lock de la agenda (sin anidar mutex).
		registrarEventoSeguro("=== AGENDA DE INGENIERIA ELECTRONICA Y TELECOMUNICACIONES 2027 ===");
		if (copia.empty()) {
			registrarEventoSeguro("La agenda no tiene eventos registrados.");
			return;
		}
		for (std::size_t i = 0; i < copia.size(); ++i) {
			std::ostringstream linea;
			linea << (i + 1) << ". " << copia[i].nombre
				<< " | " << copia[i].organizador
				<< " | " << copia[i].lugar
				<< " | " << copia[i].periodo;
			registrarEventoSeguro(linea.str());
		}
		registrarEventoSeguro("=== FIN DE LA AGENDA 2027 ===");
	}
	catch (const std::exception& e) {
		registrarEventoSeguro(std::string("[Excepcion en hilo de eventos] ") + e.what());
	}
	catch (...) {
		registrarEventoSeguro("[Excepcion desconocida en hilo de eventos]");
	}
}
