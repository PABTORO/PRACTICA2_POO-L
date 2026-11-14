#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include "dispositivocomunicacion.h"
#include "routerwifi.h"
#include "gatewaylora.h"
#include "switchfibra.h"
#include "eventos2027.h"
#include "mutex.h"

using namespace std;

int main(){
	vector<DispositivoComunicacion*> red;
	red.push_back(new RouterWiFi("RTR-01", 12));
	red.push_back(new GatewayLoRa("GW-868", 868.1f));
	red.push_back(new SwitchFibra("SW-01", 24));
	red.push_back(nullptr);
	
	int exitosas = 0;
	vector<thread> hilos;
	for (DispositivoComunicacion* dev : red) {
		hilos.push_back(thread(tareaTransmisionHilo, dev, ref(exitosas)));
	}
	
	vector<EventoIngenieria2027> agenda;
	agenda.push_back(EventoIngenieria2027("Andina link expo 2027", "Ingenieria y tecnologia", "8 al 11 de marzo", "Cartagena" ));
	agenda.push_back(EventoIngenieria2027("IEEE Colombian caribbean conference (c3) 2027", "Ingenieria, investigacion y tecnologia", "15 al 18 de septiembre de 2027", "Cartagena, universidad Tecnologica de Bolivar" ));
	agenda.push_back(EventoIngenieria2027("Conecta Colombia - Colombia Telecom Forum 2027 ", "Telecomunicaciones y conectividad", "fecha por confirmar", "Bogota"));
	hilos.push_back(thread(mostrarAgenda, ref(agenda)));
	
	
	for (auto& t : hilos) {
		if (t.joinable()) t.join();
	}
	
	for (DispositivoComunicacion* dev : red) {
		delete dev;
	}
	
	red.clear();
	
	cout << "Transmisiones exitosas: " << exitosas << endl;
	cout << "finalizado correctamente";
	
	return 0;
	
	
	
}
