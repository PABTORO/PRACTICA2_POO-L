#include "Concurrencia.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <stdexcept>

using namespace std;
mutex mtx_consola;

void registrarEventoSeguro(const string& mensaje) {
	lock_guard<mutex> lock(mtx_consola);
	cout << "[HILO " << this_thread::get_id() << "] " << mensaje << endl;
}

void procesarEventos2027(const vector<EventoIngenieria2027>& listaEventos) {
	registrarEventoSeguro("Registros academicos 2027");
	for (const auto& ev : listaEventos) {
		this_thread::sleep_for(chrono::milliseconds(120));
		string detalle = "Evento 2027: " + ev.nombre + " | Fecha: " + ev.fecha + " | Lugar: " + ev.lugar;
		registrarEventoSeguro(detalle);
	}
	registrarEventoSeguro("Fin registros 2027");
}

void tareaTransmisionHilo(DispositivoComunicacion* dev) {
	try {
		if (dev == nullptr) {
			throw invalid_argument("ERROR: Puntero nulo pasado al hilo.");
		}
		
		dev->transmitir();
		registrarEventoSeguro("Transmisión exitosa del dispositivo [" + dev->getTipo() + "]: " + dev->getId());
	}
	catch (const exception& e) {
		registrarEventoSeguro("Excepcion en hilo: " + string(e.what()));
	}
}
