#ifndef TAREASCONCURRENTES_H
#define TAREASCONCURRENTES_H

#include <mutex>
#include <string>
#include "DispositivoComunicacion.h"
#include "EstadisticasRed.h"


// MUTEX DE CONSOLA (definido una sola vez en el .cpp).

extern std::mutex mtx_consola;

// Imprime un mensaje de forma segura (seccion critica con RAII).
void registrarEventoSeguro(const std::string& mensaje);

void tareaTransmisionHilo(DispositivoComunicacion* dev, EstadisticasRed& estadisticas);

#endif 
