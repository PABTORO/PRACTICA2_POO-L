#include "gatewaylora.h"
#include <thread>
#include <chrono>

GatewayLoRa::GatewayLoRa(string _id, float _freq): DispositivoComunicacion(_id, "Gateway LoRaWAN"), frecuenciaMHz(_freq) {
	
}

void GatewayLoRa::transmitir() {
	this_thread::sleep_for(chrono::milliseconds(200));
}
