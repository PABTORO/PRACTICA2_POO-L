#include <iostream>
#include <vector>
#include <thread>
#include <functional>  
#include "dcomunicacion.h"
#include "exclucion.h"
#include "excepciones.h"
#include "hilos.h"
#include "eventoingenieria.h"

int main() {
	std::vector<DispositivoComunicacion*> red;
	red.push_back(new RouterWiFi("RTR-01", 12));
	red.push_back(new GatewayLoRa("GW-868", 868.1f));
	red.push_back(new SwitchFibra("SW-FO-01", 24));
	red.push_back(nullptr); 
	
	
	EstadisticasRed estadisticas;
	std::vector<std::thread> hilos = lanzarTransmisiones(red, estadisticas);
	EventoIngenieria2027 agenda2027;
	
	EventoIngenieria2027::Evento icassp  = { "IEEE ICASSP", 2027 };
	EventoIngenieria2027::Evento icc     = { "IEEE ICC", 2027 };
	EventoIngenieria2027::Evento wfiot   = { "IEEE WF-IoT", 2027 };
	EventoIngenieria2027::Evento invalido = { "", 2027 }; 
	
	std::vector<EventoIngenieria2027::Evento> eventos;
	eventos.push_back(icassp);
	eventos.push_back(icc);
	eventos.push_back(wfiot);
	eventos.push_back(invalido);
	
	std::thread hiloAgenda(&EventoIngenieria2027::procesarAgenda,
						   &agenda2027, eventos, std::ref(estadisticas));
	
	sincronizarHilos(hilos);         
	if (hiloAgenda.joinable()) {     
		hiloAgenda.join();
	}
	
	procesarErroresTransportados(agenda2027.getErrores());
	
	registrarEventoSeguro(estadisticas.resumen());
	
	for (DispositivoComunicacion* dev : red) {
		delete dev; 
	}
	red.clear();
	
	std::cout << " el sistema ha finalizado correctamente :3" << std::endl;
	return 0;
}
