#ifndef DISPOSITIVOS_H
#define DISPOSITIVOS_H

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

class DispositivoComunicacion {
protected:
	string id;
	string tipo;
	
public:
	DispositivoComunicacion(string _id, string _tipo)
		: id(_id), tipo(_tipo) {}
	
	virtual ~DispositivoComunicacion() = default;
	virtual void transmitir() = 0;
	
	string getId() const { return id; }
	string getTipo() const { return tipo; }
};

class RouterWiFi : public DispositivoComunicacion {
private:
	int canalesActivos;
	
public:
	RouterWiFi(string _id, int _canales)
		: DispositivoComunicacion(_id, "Router WiFi 6"), canalesActivos(_canales) {}
	
	void transmitir() override {
		this_thread::sleep_for(chrono::milliseconds(150));
	}
};

class GatewayLoRa : public DispositivoComunicacion {
private:
	float frecuenciaMHz;
	
public:
	GatewayLoRa(string _id, float _freq)
		: DispositivoComunicacion(_id, "Gateway LoRaWAN"), frecuenciaMHz(_freq) {}
	
	void transmitir() override {
		this_thread::sleep_for(chrono::milliseconds(200));
	}
};

class SwitchFibra : public DispositivoComunicacion {
private:
	int puertosGiga;
	
public:
	SwitchFibra(string _id, int _puertos)
		: DispositivoComunicacion(_id, "Switch Fibra Optica"), puertosGiga(_puertos) {}
	
	void transmitir() override {
		this_thread::sleep_for(chrono::milliseconds(100));
	}
};

#endif
