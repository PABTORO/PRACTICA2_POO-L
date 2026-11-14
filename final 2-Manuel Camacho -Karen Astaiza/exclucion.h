#ifndef EXCLUCION_H
#define EXCLUCION_H
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

std::mutex mtx_consola;

inline void registrarEventoSeguro(const std::string& mensaje) {
	std::lock_guard<std::mutex> lock(mtx_consola);
	std::cout << " [hilo " << std::this_thread::get_id() << "] "
		<< mensaje << std::endl;
}

class EventoIngenieria2027;
class EstadisticasRed;
inline std::string informeConsolidado(const EventoIngenieria2027& agenda,
									  const EstadisticasRed& est);

class EstadisticasRed {
private:
	int exitosas;
	int fallidas;
	mutable std::mutex mtx; 
	
	friend std::string informeConsolidado(const EventoIngenieria2027&,
										  const EstadisticasRed&);
public:
	EstadisticasRed() : exitosas(0), fallidas(0) {}
	
	void sumarExito() {
		std::lock_guard<std::mutex> lock(mtx);
		++exitosas;
	}
	void sumarFallo() {
		std::lock_guard<std::mutex> lock(mtx);
		++fallidas;
	}
	std::string resumen() const {
		std::lock_guard<std::mutex> lock(mtx);
		return "transmisiones exitosas:  " + std::to_string(exitosas) +
			" fallidas  " + std::to_string(fallidas);
	}
};
#endif
