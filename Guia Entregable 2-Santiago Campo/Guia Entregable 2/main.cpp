#include<iostream>
#include <mutex>
#include "DispositivoComunicacion.h"
#include "RouterWiFi.h"
#include "GatewayLoRa.h"
#include "EventoIngenieria2027.h"
// MUTEX GLOBAL Y REGISTRO CONCURRENTE PROTEGIDO (RAII)

std::mutex mtx_consola; // Protege la salida estándar compartida

void registrarEventoSeguro(const std::string& mensaje) {
	// RAII: Bloquea mtx_consola al crearse y lo desbloquea automáticamente al salir
	std::lock_guard<std::mutex> lock(mtx_consola);
	std::cout << "[HILO " << std::this_thread::get_id() << "] "
	  << mensaje << std::endl;
}

// FUNCIÓN ENVOLVENTE CON GUARDA Y CONTROL INTERNO DE EXCEPCIONES

void tareaTransmisionHilo(DispositivoComunicacion* dev) {
	try {
		// Guarda defensiva contra punteros nulos
		if (dev == nullptr) {
			throw std::invalid_argument("ERROR: Puntero nulo pasado al hilo.");
		}
	// Invocación polimórfica del método virtual
		dev->transmitir();
		registrarEventoSeguro("Transmisión exitosa del dispositivo: " + dev->getId());
	}
	catch (const std::exception& e) {
		// Captura y aislamiento de la excepción dentro del hilo
		registrarEventoSeguro(std::string("EXCEPCIÓN EN HILO: ") + e.what());
	}
}

//Guardia defensiva para lso eventos que se registran en EventoIngenieria2027
void registarEventos(EventoIngenieria2027&d,const std::string& evento){
	try{
		if(evento.length()==0){
			throw std::invalid_argument("No se Puede registra un evento vacio\n");
		}
		d.registrarEvento(evento);
	}catch(const std::invalid_argument& e){
		std::cout<<"[ERROR]"<<e.what();
	}
}
	


	int main (int argc, char *argv[]) {
		
		std::vector<DispositivoComunicacion*> red;
		red.push_back(new RouterWiFi("RTR-01", 12));
		red.push_back(new GatewayLoRa("GW-868", 868.1f));
		red.push_back(nullptr); 
		
		std::vector<std::thread> hilos;
		for (DispositivoComunicacion* dev : red) {
			hilos.push_back(std::thread(tareaTransmisionHilo, dev));
		}
		
		
		for (auto& t : hilos) {
			if (t.joinable()) {
				t.join(); 
			}
		}
		
        std::cout<<"\n\n=====PUNTO 4-EVENTOS 2027======\n\n";
		
		EventoIngenieria2027 santiago;
		registarEventos(santiago,"");
		registarEventos(santiago,"ANDICOM 2027 (Septiembre, Cartagena)");
		registarEventos(santiago,"Andina Link 2027 (8 al 11 de marzo, Cartagena)");
		registarEventos(santiago,"WRO Colombia");
		
	
		std::thread hiloEventos(&EventoIngenieria2027::mostrarEvento, &santiago);
		if (hiloEventos.joinable()) {
			hiloEventos.join();
		}
		

		for (DispositivoComunicacion* dev : red) {
			delete dev;
			dev = nullptr;
		}
		red.clear();
		std::cout << "Sistema finalizado correctamente." << std::endl;
		
		return 0;
	}
