#include "GatewayLoRa.h"
#include <thread>
#include <chrono>

GatewayLoRa::GatewayLoRa(const std::string& _id, float _freq)
	: DispositivoComunicacion(_id, "Gateway LoRaWAN"), frecuenciaMHz(_freq) {}

void GatewayLoRa::transmitir() {
	// Transmision de larga distancia y bajo consumo
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
}
