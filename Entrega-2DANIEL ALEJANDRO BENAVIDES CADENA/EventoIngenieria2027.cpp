#include "EventoIngenieria2027.h"
#include "Concurrencia.h"

using namespace std;

EventoIngenieria2027::EventoIngenieria2027() {
    listaEventos.push_back("Colombia 5.0");
    listaEventos.push_back("Global Encryption Day - Comunidad ISOC");
    listaEventos.push_back("Explorando el Futuro EF202X");
}

void EventoIngenieria2027::agregarEvento(const string& evento) {
    listaEventos.push_back(evento);
}

void EventoIngenieria2027::procesarYDesplegarAgenda() const {
    registrarEventoSeguro("=== INICIO AGENDA DE EVENTOS 2027 ===");
    for (const auto& ev : listaEventos) {
        registrarEventoSeguro("Evento Programado 2027: " + ev);
    }
    registrarEventoSeguro("=== FIN AGENDA DE EVENTOS 2027 ===");
}