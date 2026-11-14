#include <iostream>
#include <vector>
#include <thread>
#include "DispositivosComunicacionE2.h"
#include "RouterWiFiE2.h"
#include "GatewayLoRa.h"
#include "EventoIngenieria2027.h"
#include "Concurrencia.h"
using namespace std;

int main() {
    vector<DispositivoComunicacion*> red;
    red.push_back(new RouterWiFi("RTR-01", 12));
    red.push_back(new GatewayLoRa("GW-868", 868.1f));
    red.push_back(nullptr); 

    EventoIngenieria2027 agenda;

    vector<thread> hilos;
    for (DispositivoComunicacion* dev : red) {
        hilos.push_back(thread(tareaTransmisionHilo, dev));
    }

    thread hiloEventos(&EventoIngenieria2027::procesarYDesplegarAgenda, &agenda);

    for (auto& t : hilos) {
        if (t.joinable()) {
            t.join();
        }
    }

    if (hiloEventos.joinable()) {
        hiloEventos.join();
    }

    for (DispositivoComunicacion* dev : red) {
        delete dev;
    }
    red.clear();

    cout << "Sistema finalizado correctamente." << endl;
    return 0;
}