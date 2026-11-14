#ifndef DCOMUNICACION_H
#define DCOMUNICACION_H
#include <string>
#include <thread>
#include <chrono>
class ITransmisible {
public:
	virtual ~ITransmisible() = default;
	virtual void transmitir() = 0;
};

class DispositivoComunicacion : public ITransmisible {
protected:
	std::string id;
	std::string tipo;
public:
	DispositivoComunicacion(std::string _id, std::string _tipo)
		: id(_id), tipo(_tipo) {}
	
	virtual ~DispositivoComunicacion() = default;

	virtual void transmitir() = 0;
	
	std::string getId() const { return id; }
	std::string getTipo() const { return tipo; }
};

class RouterWiFi : public DispositivoComunicacion {
private:
	int canalesActivos;
public:
	RouterWiFi(std::string _id, int _canales)
		: DispositivoComunicacion(_id, "router wifi 6"), canalesActivos(_canales) {}
	
	void transmitir() override {
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
};

class GatewayLoRa : public DispositivoComunicacion {
private:
	float frecuenciaMHz;
public:
	GatewayLoRa(std::string _id, float _freq)
		: DispositivoComunicacion(_id, "Gateway LoRaWAN"), frecuenciaMHz(_freq) {}
	
	void transmitir() override {
	
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
};

class SwitchFibra : public DispositivoComunicacion {
private:
	int puertos;
public:
	SwitchFibra(std::string _id, int _puertos)
		: DispositivoComunicacion(_id, "switch de fibra optica"), puertos(_puertos) {}
	
	void transmitir() override {
		
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
};
#endif
