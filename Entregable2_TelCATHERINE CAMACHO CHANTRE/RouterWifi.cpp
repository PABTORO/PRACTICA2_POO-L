#include "RouterWiFi.h"
#include <thread>
#include <chrono>

RouterWiFi::RouterWiFi(std::string _id, int _canales)
	: DispositivoComunicacion(_id, "Router WiFi 6"), canalesActivos(_canales) {}

void RouterWiFi::transmitir() {
	// Lógica de transmisión específica sobre la banda de 5 GHz
	std::this_thread::sleep_for(std::chrono::milliseconds(150));
}
