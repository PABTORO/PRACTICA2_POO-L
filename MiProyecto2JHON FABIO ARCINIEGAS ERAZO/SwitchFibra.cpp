#include "SwitchFibra.h"
#include <thread>
#include <chrono>

SwitchFibra::SwitchFibra(const std::string& _id, int _vel)
	: DispositivoComunicacion(_id, "Switch Fibra Optica"), velocidadGbps(_vel) {}

void SwitchFibra::transmitir() {
	// Conmutacion optica
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
