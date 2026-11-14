#include "GatewayLoRa.h"
#include "DispositivoComunicacion.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

GatewayLoRa::GatewayLoRa(string id, float frecuenciaMHz)
	: DispositivoComunicacion(id, "Gateway LoRaWAN") {
	
	this-> frecuenciaMHz = frecuenciaMHz ;
}

void GatewayLoRa::transmitir() {
	this_thread::sleep_for(chrono::milliseconds(200));
}

