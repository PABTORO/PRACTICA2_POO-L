#ifndef GATEWAYLORA_H
#define GATEWAYLORA_H
#include "DispositivoComunicacion.h"

class GatewayLoRa:public DispositivoComunicacion {
public:
	GatewayLoRa(std::string _id, float _freq);
	void transmitir()override;
private:
	float frecuenciaMHz;
};

#endif

