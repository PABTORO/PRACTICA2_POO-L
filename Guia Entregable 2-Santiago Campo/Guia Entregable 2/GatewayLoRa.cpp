#include "GatewayLoRa.h"

GatewayLoRa::GatewayLoRa(std::string _id, float _freq):DispositivoComunicacion(_id, "Gateway LoRaWAN"), frecuenciaMHz(_freq){
	
}

void GatewayLoRa::transmitir(){
	// Lógica de transmisión de larga distancia y bajo consumo
	//std::this_thread::sleep_for(std::chrono::milliseconds(200));
}
