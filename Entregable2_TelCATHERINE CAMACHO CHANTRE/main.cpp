#include <iostream>
#include <vector>
#include <thread>
#include <functional>//std::ref
#include "RouterWiFi.h"
#include "GatewayLoRa.h"
#include "SwitchFibra.h"
#include "Concurrencia.h"
#include "EventoIngenieria2027.h"


int main() {
	// 1. Vector heterogéneo de dispositivos en el Heap
	std::vector<DispositivoComunicacion*> red;
	red.push_back(new RouterWiFi("RTR-01", 12));
	red.push_back(new GatewayLoRa("GW-868", 868.1f));
	red.push_back(new SwitchFibra("SWF-10", 10));
	red.push_back(nullptr); // Provocación intencional para probar la guarda defensiva
	
	// Agenda de eventos 2027 en Colombia (orden cronologico)
	std::vector<EventoIngenieria2027> agenda;
	agenda.push_back(EventoIngenieria2027("XII Congreso Iberoamericano de Innovacion en Salud, Discapacidad y Medicina de Precision", "2-3 marzo 2027", "Bogota, Colombia"));
	agenda.push_back(EventoIngenieria2027("IEEE PES GT&D Latinoamerica 2027", "8-10 marzo 2027", "Medellin, Colombia"));
	agenda.push_back(EventoIngenieria2027("IV Congreso Internacional de Ciencia e Ingenieria CICI 2027 (Universidad Mariana)", "14-16 abril 2027", "Pasto, Colombia"));
	agenda.push_back(EventoIngenieria2027("XIII Congreso Internacional de Ingenieria Mecanica, Mecatronica y Automatizacion CIMM", "26-28 mayo 2027", "Medellin, Colombia"));
	
	//variable compartida por los hilos( protegida con mtx_contador)
	int transmisionesExitosas = 0;
	
	// 2. Vector de hilos independientes
	std::vector<std::thread> hilos;
	for (DispositivoComunicacion* dev : red) {
		hilos.push_back(std::thread(tareaTransmisionHilo, dev, std::ref(transmisionesExitosas)));
	}
	
	// Hilo dedicado a los eventos 2027 (la agenda se pasa por referencia con std::ref)
	hilos.push_back(std::thread(tareaEventos2027, std::ref(agenda)));
	
	// 3. Sincronización obligatoria de hilos
	for (auto& t : hilos) {
		if (t.joinable()) {
			t.join();
		}
	}
	// Resultado del contador compartido(despues del join, ya no hay hilos activos)
	std::cout<<"transmisiones Exitosas: "<< transmisionesExitosas
		 << " de " << red.size() << std::endl;
	
	// 4. Liberación limpia de memoria dinámica
	for (DispositivoComunicacion* dev : red) {
		delete dev;
	}
	red.clear();
	
	std::cout << "Sistema finalizado correctamente." << std::endl;
	return 0;
}
