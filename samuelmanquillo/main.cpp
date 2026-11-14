#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include "Dispositivos.h"
#include "Eventos.h"
#include "Concurrencia.h"

using namespace std;

int main() {
	cout << "TELCOCAUCA: Motor concurrente de transmision" << endl << endl;
	vector<DispositivoComunicacion*> red;
	red.push_back(new RouterWiFi("RTR-01", 12));
	red.push_back(new GatewayLoRa("GW-868", 868.1f));
	red.push_back(new SwitchFibra("SW-10G", 24));
	red.push_back(nullptr);
	vector<EventoIngenieria2027> agenda2027 = {
		{"IEEE Andescon 2027", "Popayan, Colombia", "15-18 Mayo 2027"},
	{"Congreso Nacional ACIEM Telecom 2027", "Bogota, Colombia", "20-22 Septiembre 2027"},
		{"Simposio Internacional Redes IoT & 6G", "Medellin, Colombia", "10-12 Noviembre 2027"}
	};
	vector<thread> hilos;
	
	hilos.push_back(thread(procesarEventos2027, ref(agenda2027)));
	for (DispositivoComunicacion* dev : red) {
		hilos.push_back(thread(tareaTransmisionHilo, dev));
	}
	for (auto& t : hilos) {
		if (t.joinable()) {
			t.join();
		}
	}
	for (DispositivoComunicacion* dev : red) {
		delete dev;
	}
	red.clear();
	
	cout << endl << "Sistema finalizado correctamente sin fugas de memoria." << endl;
	return 0;
}
