#include "SwitchFibra.h"
#include <stdexcept>
#include <thread>
#include <chrono>

SwitchFibra::SwitchFibra(const std::string& _id, int _puertos, double _velocidadGbps)
	: DispositivoComunicacion(_id, "Switch Fibra Optica"),
	puertos(_puertos), velocidadGbps(_velocidadGbps)
{
	if (_puertos <= 0) {
		throw std::invalid_argument("ERROR: El switch debe tener al menos un puerto.");
	}
	if (_velocidadGbps <= 0.0) {
		throw std::invalid_argument("ERROR: La velocidad del switch debe ser positiva.");
	}
}

void SwitchFibra::transmitir() {
	// Simula conmutación de alta velocidad sobre fibra (100 ms)
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

int SwitchFibra::getPuertos() const {
	return puertos;
}

double SwitchFibra::getVelocidadGbps() const {
	return velocidadGbps;
}
