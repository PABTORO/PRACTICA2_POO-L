#ifndef MUTEX_H
#define MUTEX_H
#include <string>
#include <mutex>
#include "dispositivocomunicacion.h"
using namespace std;

extern mutex mtx_consola;
extern mutex mtx_datos;

void registrarEventoSeguro(const string& mensaje);
void tareaTransmisionHilo(DispositivoComunicacion* dev, int& exitosas);

#endif
