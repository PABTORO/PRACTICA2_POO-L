#ifndef GATEWAYLORA_H
#define GATEWAYLORA_H

#include <thread>
#include <chrono>
#include "DispositivoComunicacion.h"

class GatewayLoRa : public DispositivoComunicacion{
private:
	float frecuenciaMHz;
public:
	GatewayLoRa(std::string _id, float _freq)
		: DispositivoComunicacion(_id, "Gateway LoRaWAN"), frecuenciaMHz(_freq){}
	
	void transmitir() override{
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
};
#endif
