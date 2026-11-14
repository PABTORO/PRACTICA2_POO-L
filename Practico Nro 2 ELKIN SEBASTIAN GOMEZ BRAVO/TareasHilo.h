#ifndef TAREASHILO_H
#define TAREASHILO_H
#include <vector>
#include "DispositivoComunicacion.h"
#include "EstadisticasRed.h"
#include "EventoIngenieria2027.h"

void tareaTransmisionHilo(DispositivoComunicacion* dev, EstadisticasRed& stats);
void tareaAgendaHilo(const std::vector<EventoIngenieria2027>& agenda);

#endif
