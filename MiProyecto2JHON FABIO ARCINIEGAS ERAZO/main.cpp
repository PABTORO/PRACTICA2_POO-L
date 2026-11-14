// Universidad del Cauca - Programacion Orientada a Objetos 2026.2
// Entregable Practico N 2: Polimorfismo + std::thread + std::mutex
// Compilar con -std=c++11 -pthread (Zinjai: mingw64-gcc7)
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <functional>   // std::ref, std::cref
#include <stdexcept>

#include "DispositivoComunicacion.h"
#include "RouterWiFi.h"
#include "GatewayLoRa.h"
#include "SwitchFibra.h"
#include "EventoIngenieria2027.h"
#include "Concurrencia.h"

int main() {
	// 1. Vector heterogeneo de dispositivos en el Heap
	std::vector<DispositivoComunicacion*> red;
	red.push_back(new RouterWiFi("RTR-01", 12));
	red.push_back(new GatewayLoRa("GW-868", 868.1f));
	red.push_back(new SwitchFibra("SW-CORE-01", 10));
	red.push_back(nullptr);   // Provocacion intencional de la guarda defensiva
	
	int transmisionesExitosas = 0;   // Variable compartida (std::ref)
	
	// 2. Vector de hilos independientes
	std::vector<std::thread> hilos;
	for (size_t i = 0; i < red.size(); ++i) {
		hilos.push_back(std::thread(tareaTransmisionHilo, red[i],
									std::ref(transmisionesExitosas)));
	}
	
	// 3. Hilo dedicado para la agenda de eventos 2027
	std::vector<EventoIngenieria2027> agenda;
	try {
		agenda.push_back(EventoIngenieria2027("IEEE ANDESCON 2027", "IEEE Region 9",
											  "Fecha por confirmar", "Electronica y Telecom"));
		agenda.push_back(EventoIngenieria2027("Congreso Nacional de Telecomunicaciones", "ACIEM",
											  "Fecha por confirmar", "Telecomunicaciones"));
		agenda.push_back(EventoIngenieria2027("IEEE LatinIoT 2027 (Santiago, Chile)", "IEEE IoT Technical Community",
											  "28-30 abril 2027", "Internet de las Cosas"));
	} catch (const std::exception& e) {
		registrarEventoSeguro(std::string("Error creando agenda: ") + e.what());
	}
	std::thread hiloEventos(mostrarAgendaEventos, std::cref(agenda));
	
	// 4. Sincronizacion con join()
	for (size_t i = 0; i < hilos.size(); ++i) {
		if (hilos[i].joinable()) hilos[i].join();
	}
	if (hiloEventos.joinable()) hiloEventos.join();
	
	std::cout << "Transmisiones exitosas: " << transmisionesExitosas
		<< " de " << red.size() << " hilos." << std::endl;
	
	// 5. Liberacion limpia de memoria dinamica
	for (size_t i = 0; i < red.size(); ++i) {
		delete red[i];       // delete nullptr es seguro
		red[i] = nullptr;
	}
	red.clear();
	
	std::cout << "Sistema finalizado correctamente." << std::endl;
	return 0;
}
