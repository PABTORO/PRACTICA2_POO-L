#ifndef GATEWAYLORA_H
#define GATEWAYLORA_H

#include "DispositivoComunicacion.h"
#include <string>


// SUBCLASE CONCRETA: Gateway LoRaWAN (largo alcance, bajo consumo)

class GatewayLoRa : public DispositivoComunicacion {
private:
	float frecuenciaMHz;  
public:
	// Lanza std::invalid_argument si la frecuencia está fuera de banda 
	GatewayLoRa(const std::string& _id, float _freq);
	
	~GatewayLoRa() override = default;
	
	void transmitir() override;
	
	float getFrecuenciaMHz() const;
};

#endif
