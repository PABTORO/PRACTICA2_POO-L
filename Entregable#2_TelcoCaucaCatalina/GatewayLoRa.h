#ifndef GATEWAYLORA_H
#define GATEWAYLORA_H
#include "DispositivoComunicacion.h"
#include <iostream>
#include <string>
using namespace std;

class GatewayLoRa : public DispositivoComunicacion {
private:
	float frecuenciaMHz;
	
public:
	GatewayLoRa(string id, float frecuenciaMHz);
	
	void transmitir() override;
};

#endif

