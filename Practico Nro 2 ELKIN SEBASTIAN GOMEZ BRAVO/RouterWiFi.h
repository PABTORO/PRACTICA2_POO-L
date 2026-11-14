#ifndef ROUTERWIFI_H
#define ROUTERWIFI_H
#include <thread>
#include <chrono>
#include "DispositivoComunicacion.h"

class RouterWiFi : public DispositivoComunicacion{
private:
	int canalesActivos;
public:
	RouterWiFi(std::string _id, int _canales)
		: DispositivoComunicacion(_id, "Router WiFi 6"), canalesActivos(_canales) {}
	
	void transmitir() override {
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
};

#endif
