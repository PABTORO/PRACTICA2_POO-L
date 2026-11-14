#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <stdexcept>
#include <string>
#include <functional>

#include "DispositivoComunicacion.h"
#include "RouterWiFi.h"
#include "GatewayLoRa.h"
#include "SwitchFibra.h"
#include "EventoIngenieria2027.h"

using namespace std;

mutex mtx_consola;
mutex mtx_red;

void registrarEventoSeguro(const string& mensaje) {
	
	lock_guard<mutex> bloqueo(mtx_consola);
	
	cout << "[HILO " << this_thread::get_id() << "] "
		<< mensaje << endl;
}

void tareaTransmisionHilo(vector<DispositivoComunicacion*>& red, unsigned int indice) {
	try {
		
		DispositivoComunicacion* dev = nullptr;
		
		{
			lock_guard<mutex> bloqueo(mtx_red);
			
			if (indice >= red.size()) {
				throw out_of_range("Indice fuera del vector.");
			}
			
			dev = red[indice];
		}
		
		if (dev == nullptr) {
			throw invalid_argument("Puntero nulo pasado al hilo.");
		}
		
		dev->transmitir();
		
		registrarEventoSeguro("Transmision exitosa del dispositivo: " + dev->getId() );
		
	}
	catch (const exception& e) {
		
		registrarEventoSeguro(string("Error en el hilo: ") + e.what());
		
	}
}

void tareaEventos(EventoIngenieria2027* agenda) {
	try {
		 if (agenda == nullptr) {
		throw invalid_argument("Puntero nulo de la agenda de eventos.");
    }

	 registrarEventoSeguro("Iniciando agenda de eventos 2027.");
	 agenda->mostrarEventos(mtx_consola);
	}
	
	catch (const exception& e) {
	
	 registrarEventoSeguro(string("Error en el hilo de eventos: ") + e.what());
	 
	 }
 }
	
int main() {
	
	vector<DispositivoComunicacion*> red;
	
	red.push_back(new RouterWiFi("RTR-01", 12));
	red.push_back(new GatewayLoRa("GW-868", 868.1f));
	red.push_back(new SwitchFibra("SW-01", 24));
	red.push_back(nullptr);
	
	vector<thread> hilos;
	
	for (unsigned int i = 0; i < red.size(); i++) {
	 
	hilos.push_back(thread(tareaTransmisionHilo, ref(red), i));
 
	 }
	
	EventoIngenieria2027* agenda = new EventoIngenieria2027();
	thread hiloEventos(tareaEventos, agenda);
	
	for (thread& t : hilos) {
	
		if (t.joinable()) {
		 t.join();
	 }
}
	
	hiloEventos.join();
	
	for (DispositivoComunicacion* dev : red) {
		delete dev;
	}
 
	delete agenda;
	 
	red.clear();
	hilos.clear();
	
	registrarEventoSeguro("Sistema finalizado correctamente.");
	
	return 0;
}
	
	
