#ifndef DISPOSITIVOCOMUNICACION_H
#define DISPOSITIVOCOMUNICACION_H
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <stdexcept>
#include <chrono>

class DispositivoComunicacion {
protected:
	std::string id;
	std::string tipo;
	
public:
	DispositivoComunicacion(std::string _id, std::string _tipo);
	
	// Destructor virtual: indispensable para liberación polimórfica en el Heap
	virtual ~DispositivoComunicacion() = default;
	// Método virtual puro: define la interfaz obligatoria
	virtual void transmitir() = 0;
	std::string getId() const;
	std::string getTipo() const;
};

#endif

