#include "GatewayLoRa.h"
#include <stdexcept>
#include <thread>
#include <chrono>

GatewayLoRa::GatewayLoRa(const std::string& _id, float _freq)
	: DispositivoComunicacion(_id, "Gateway LoRaWAN"), frecuenciaMHz(_freq)
{
	if (_freq < 863.0f || _freq > 928.0f) {
		throw std::invalid_argument("ERROR: Frecuencia LoRa fuera de banda ISM");
	}
}

void GatewayLoRa::transmitir() {
	// Simula transmisión de larga distancia y bajo consumo (200 ms).
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

float GatewayLoRa::getFrecuenciaMHz() const {
	return frecuenciaMHz;
}
