#include "routerwifi.h"
#include <thread>
#include <chrono>

RouterWiFi::RouterWiFi(string _id, int _canales): DispositivoComunicacion(_id, "Router WiFi 6"), canalesActivos(_canales) {
	
}

void RouterWiFi::transmitir() {
	this_thread::sleep_for(chrono::milliseconds(150));
}
