#include "mutex.h"
#include <iostream>
#include <thread>
#include <stdexcept>

mutex mtx_consola;
mutex mtx_datos;

void registrarEventoSeguro(const string& mensaje){
	lock_guard<mutex> lock(mtx_consola);
	cout << "HILO " << this_thread::get_id() << " ---- " << mensaje << endl;
}

void tareaTransmisionHilo(DispositivoComunicacion* dev, int& exitosas) {
	try {
		if (dev==nullptr) {
			throw invalid_argument(",Puntero nulo");
		}
		dev->transmitir();
		{
			lock_guard<mutex> lock(mtx_datos);
			exitosas++;
		}
		registrarEventoSeguro("Transmision exitosa " + dev->getId());
	} catch (const exception& e) {
		registrarEventoSeguro(string("Error: ") + e.what());
	}
}
