#include "Concurrencia.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <stdexcept>
using namespace std;

mutex mtx_consola;

void registrarEventoSeguro(const string& mensaje) {
    // Protección de sección crítica con RAII mediante lock_guard
    lock_guard<mutex> lock(mtx_consola);
    cout << "[HILO " << this_thread::get_id() << "] "
         << mensaje << endl;
}

void tareaTransmisionHilo(DispositivoComunicacion* dev) {
    try {
        if (dev == nullptr) {
            throw invalid_argument("ERROR: Puntero nulo pasado al hilo.");
        }
        dev->transmitir();
        registrarEventoSeguro("Transmisión exitosa del dispositivo: " + dev->getId());
    }
    catch (const exception& e) {
        registrarEventoSeguro(string("EXCEPCIÓN EN HILO: ") + e.what());
    }
}