#include "RouterWiFi.h"
#include <stdexcept>
#include <thread>
#include <chrono>

RouterWiFi::RouterWiFi(const std::string& _id, int _canales)
	: DispositivoComunicacion(_id, "Router WiFi 6"), canalesActivos(_canales)
{
	if (_canales < 1 || _canales > 165) {
		throw std::invalid_argument("ERROR: Canales WiFi fuera de rango (1-165).");
	}
}

void RouterWiFi::transmitir() {
	std::this_thread::sleep_for(std::chrono::milliseconds(150));
}

int RouterWiFi::getCanalesActivos() const {
	return canalesActivos;
}
