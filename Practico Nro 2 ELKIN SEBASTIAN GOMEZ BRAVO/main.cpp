#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include "DispositivoComunicacion.h"
#include "RouterWiFi.h"
#include "GatewayLoRa.h"
#include "SwitchFibra.h"
#include "EstadisticasRed.h"
#include "EventoIngenieria2027.h"
#include "TareasHilo.h"

int main(){
	std::vector<DispositivoComunicacion*> red;
	red.push_back(new RouterWiFi("RTR-01", 12));
	red.push_back(new GatewayLoRa("GW-868", 868.1f));
	red.push_back(new SwitchFibra("SW-FO-01", 24));
	red.push_back(nullptr); 
	
	EstadisticasRed stats;

	std::vector<EventoIngenieria2027> agenda;
	agenda.push_back(EventoIngenieria2027("IEEE ANDESCON 2027", "Congreso de electronica y telecomunicaciones", "Fecha por confirmar"));
	agenda.push_back(EventoIngenieria2027("Congreso ACIEM", "Congreso nacional de telecomunicaciones", "Fecha por confirmar"));
	agenda.push_back(EventoIngenieria2027("Simposio de Redes IoT", "Simposio sobre redes IoT", "Fecha por confirmar"));

	std::vector<std::thread> hilos;
	for (size_t i = 0; i < red.size(); i++){
		hilos.push_back(std::thread(tareaTransmisionHilo, red[i], std::ref(stats)));
	}
	hilos.push_back(std::thread(tareaAgendaHilo, std::ref(agenda)));

	for (size_t i = 0; i < hilos.size(); i++){
		if (hilos[i].joinable()) {
			hilos[i].join();
		}
	}
	
	std::cout << "Exitosas: " << stats.getExitosas()
		<< " | Fallidas: " << stats.getFallidas() << std::endl;

	for (size_t i = 0; i < red.size(); i++){
		delete red[i];
	}
	red.clear();
	std::cout<<"Sistema finalizado correctamente."<< std::endl;
	return 0;
}
