#include "GatewayLoRa.h"
using namespace std;

GatewayLoRa::GatewayLoRa(string _id, float _freq)
    : DispositivoComunicacion(_id, "Gateway LoRaWAN"), frecuenciaMHz(_freq) {}

void GatewayLoRa::transmitir() override {
}