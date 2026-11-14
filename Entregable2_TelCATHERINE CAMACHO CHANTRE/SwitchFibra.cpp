#include "SwitchFibra.h"
#include <thread>
#include <chrono>

SwitchFibra::SwitchFibra(std::string _id, int _velocidad)
	: DispositivoComunicacion(_id, "Switch de Fibra"), velocidadGbps(_velocidad) {}

void SwitchFibra::transmitir() {
	// Transmisión por fibra óptica
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
