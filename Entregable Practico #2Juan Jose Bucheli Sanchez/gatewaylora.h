#ifndef GATEWAYLORA_H
#define GATEWAYLORA_H
#include "dispositivocomunicacion.h"

class GatewayLoRa : public DispositivoComunicacion{
private:
	float frecuenciaMHz;
	
public:
	GatewayLoRa(string _id, float _freq);
	void transmitir() override;
};

#endif

