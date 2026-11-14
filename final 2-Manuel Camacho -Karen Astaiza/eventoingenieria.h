#ifndef EVENTOINGENIERIA_H
#define EVENTOINGENIERIA_H
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include <stdexcept>
#include <exception>
#include "exclucion.h"

class EventoIngenieria2027 {
public:
	struct Evento {
		std::string nombre;  
		int         anio;   
	};
	
private:
	std::vector<Evento> agenda;
	mutable std::mutex mtx_agenda;
	std::vector<std::exception_ptr> errores;  

	friend std::string informeConsolidado(const EventoIngenieria2027&,
										  const EstadisticasRed&);
public:
	
	void registrar(const Evento& ev) {
		if (ev.nombre.empty()) {
			throw std::invalid_argument("error: eventos sin nombre, no registra");
		}
		std::lock_guard<std::mutex> lock(mtx_agenda);
		agenda.push_back(ev);
	}
	
	
	std::vector<Evento> copiarAgenda() const {
		std::lock_guard<std::mutex> lock(mtx_agenda);
		return agenda;
	}
	
	const std::vector<std::exception_ptr>& getErrores() const { return errores; }
	
	
	void procesarAgenda(std::vector<Evento> eventos, EstadisticasRed& est) {
		try {
			
			for (size_t i = 0; i < eventos.size(); ++i) {
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				try {
					registrar(eventos[i]);
					registrarEventoSeguro("evento 2027 registrado:  " + eventos[i].nombre);
				}
				catch (const std::exception& e) {
					
					errores.push_back(std::current_exception());
					registrarEventoSeguro(std::string("excepcion en resgistro de evento ") + e.what());
				}
			}
			
			
			std::vector<Evento> lista = copiarAgenda();
			if (lista.empty()) {
				throw std::runtime_error("la agenda de los eventos 2027 esta vacia : ");
			}
			std::sort(lista.begin(), lista.end(),
					  [](const Evento& a, const Evento& b) {
						  if (a.anio != b.anio) return a.anio < b.anio;
						  return a.nombre < b.nombre;
					  });
			
						std::string bloque = "\n agenta 2027, ingeniera electronica y telecominicaciones \n";
			for (size_t i = 0; i < lista.size(); ++i) {
				bloque += "  " + std::to_string(i + 1) + ". " + lista[i].nombre +
					" - " + std::to_string(lista[i].anio) + "\n";
			}
			bloque += "  total de eventos:  " + std::to_string(lista.size()) +
				"\n";
			registrarEventoSeguro(bloque);
			
			registrarEventoSeguro(informeConsolidado(*this, est));
		}
		catch (const std::exception& e) {
			registrarEventoSeguro(std::string("excepcion en hilo de la agenda:  ") + e.what());
		}
		catch (...) {
			registrarEventoSeguro("excepcion desconocida del hilo de la agenda");
		}
	}
};

inline std::string informeConsolidado(const EventoIngenieria2027& ag, const EstadisticasRed& est) {
	std::lock(ag.mtx_agenda, est.mtx);
	std::lock_guard<std::mutex> lockAgenda(ag.mtx_agenda, std::adopt_lock);
	std::lock_guard<std::mutex> lockEst(est.mtx, std::adopt_lock);
	return "informe terminado, eventos 2027 registrados: " + std::to_string(ag.agenda.size()) +
		" transmisiones exitosas  " + std::to_string(est.exitosas) +
		" fallidas " + std::to_string(est.fallidas);
}
#endif
