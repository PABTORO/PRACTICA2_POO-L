#include "RouterWiFi.h"
#include "DispositivoComunicacion.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

RouterWiFi::RouterWiFi(string id, int canalesActivos)
	: DispositivoComunicacion(id, "Router WiFi 6") {
	
this-> canalesActivos = canalesActivos;
}

void RouterWiFi::transmitir() {
	this_thread::sleep_for(chrono::milliseconds(150));
}
