#ifndef CONCURRENCIA_H
#define CONCURRENCIA_H

#include <string>
#include <vector>
#include <mutex>
#include "DispositivoComunicacion.h"
#include "EventoIngenieria2027.h"

// Mutex globales (definidos en Concurrencia.cpp)
extern std::mutex mtx_consola;    // Protege std::cout
extern std::mutex mtx_contador;   // Protege el contador compartido

// Registro seguro en consola (RAII con lock_guard)
void registrarEventoSeguro(const std::string& mensaje);

// Tarea de hilo: guarda defensiva + try-catch interno
void tareaTransmisionHilo(DispositivoComunicacion* dev, int& contador);

// Hilo dedicado a la agenda de eventos 2027
void mostrarAgendaEventos(const std::vector<EventoIngenieria2027>& agenda);

#endif
