#ifndef CONCURRENCIA_H
#define CONCURRENCIA_H

#include <string>
#include <vector>
#include <mutex>
#include "Dispositivos.h"
#include "Eventos.h"

using namespace std;
extern mutex mtx_consola;
void registrarEventoSeguro(const string& mensaje);
void procesarEventos2027(const vector<EventoIngenieria2027>& listaEventos);
void tareaTransmisionHilo(DispositivoComunicacion* dev);

#endif
