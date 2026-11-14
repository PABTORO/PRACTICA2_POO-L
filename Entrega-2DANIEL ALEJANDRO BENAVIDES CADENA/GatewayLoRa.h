#ifndef GATEWAYLORA_H
#define GATEWAYLORA_H
#include "DispositivosComunicacionE2.h"
using namespace std;

class GatewayLoRa : public DispositivoComunicacion {
private:
    float frecuenciaMHz;

public:
    GatewayLoRa(string _id, float _freq);
    void transmitir() override;
};

#endif