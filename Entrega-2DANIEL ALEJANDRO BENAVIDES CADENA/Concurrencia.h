#ifndef CONCURRENCIA_H
#define CONCURRENCIA_H
#include <string>
#include "DispositivosComunicacionE2.h"
using namespace std;

void registrarEventoSeguro(const string& mensaje);
void tareaTransmisionHilo(DispositivoComunicacion* dev);

#endif