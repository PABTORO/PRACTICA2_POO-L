#ifndef ESTADISTICASRED_H
#define ESTADISTICASRED_H

#include <mutex>
#include <string>
#include <vector>
#include <cstddef>


class EstadisticasRed {
private:
	int transmisionesExitosas;
	std::vector<std::string> bitacora;   // Vector dinamico compartido
	mutable std::mutex mtx;              // Protege contador y bitacora
	
public:
	EstadisticasRed();
	
	// Registra una transmision exitosa. Lanza std::invalid_argument
	void registrarExito(const std::string& idDispositivo);
	
	int getExitosas() const;
	std::size_t getTamanoBitacora() const;
	
	void imprimirResumen() const;
};

#endif 
