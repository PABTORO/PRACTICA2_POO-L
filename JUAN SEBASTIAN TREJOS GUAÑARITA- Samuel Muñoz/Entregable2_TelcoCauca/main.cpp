#include <iostream>
#include <vector>
#include <thread>
#include <functional>

#include "DispositivoComunicacion.h"
#include "RouterWiFi.h"
#include "GatewayLoRa.h"
#include "SwitchFibra.h"
#include "TareaTransmision.h"
#include "EventoIngenieria2027.h"
#include "Registro.h"

int main() {
    std::vector<DispositivoComunicacion*> red;
    red.push_back(new RouterWiFi("RTR-01", 12));
    red.push_back(new GatewayLoRa("GW-868", 868.1f));
    red.push_back(new SwitchFibra("SW-FO-01", 24));
    red.push_back(nullptr);

    int transmisionesExitosas = 0;

    std::vector<EventoIngenieria2027> agenda;
    agenda.push_back(EventoIngenieria2027("IEEE ANDESCON 2027 (por confirmar)", "Segundo semestre 2027", "Latinoamerica", "Congreso IEEE Region 9"));
    agenda.push_back(EventoIngenieria2027("Congreso ACIEM de Telecomunicaciones", "2027 (por confirmar)", "Colombia", "Congreso nacional de ingenieria"));
    agenda.push_back(EventoIngenieria2027("Simposio de Redes IoT", "2027 (por confirmar)", "Virtual/Presencial", "Redes IoT, LoRaWAN y 5G"));

    std::vector<std::thread> hilos;
    for (std::size_t i = 0; i < red.size(); ++i) {
        hilos.push_back(std::thread(tareaTransmisionHilo, red[i], std::ref(transmisionesExitosas)));
    }
    hilos.push_back(std::thread(procesarAgendaEventos2027, std::cref(agenda)));

    for (std::size_t i = 0; i < hilos.size(); ++i) {
        if (hilos[i].joinable()) {
            hilos[i].join();
        }
    }

    registrarEventoSeguro("Transmisiones exitosas: " + std::to_string(transmisionesExitosas));

    for (std::size_t i = 0; i < red.size(); ++i) {
        delete red[i];
    }
    red.clear();

    std::cout << "Sistema finalizado correctamente." << std::endl;
    return 0;
}
