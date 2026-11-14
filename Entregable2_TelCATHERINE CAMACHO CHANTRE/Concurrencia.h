#ifndef CONCURRENCIA_H
#define CONCURRENCIA_H

#include <string>
#include "DispositivoComunicacion.h"


void registrarEventoSeguro(const std::string& mensaje);
void tareaTransmisionHilo(DispositivoComunicacion* dev, int& transmisionesExitosas);

#endif
