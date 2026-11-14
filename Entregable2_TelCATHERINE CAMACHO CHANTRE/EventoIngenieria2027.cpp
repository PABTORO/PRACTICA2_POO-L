#include "EventoIngenieria2027.h"   
#include "Concurrencia.h"

EventoIngenieria2027::EventoIngenieria2027(std::string _nombre, std::string _fecha, std::string _lugar)
	: nombre(_nombre), fecha(_fecha), lugar(_lugar) {}

void EventoIngenieria2027::mostrar() const {
	// Usa la función protegida con mutex para escribir en consola
	registrarEventoSeguro("Evento 2027: " + nombre + " | " + fecha + " | " + lugar);
}

void tareaEventos2027(std::vector<EventoIngenieria2027>& agenda) {
	for (const EventoIngenieria2027& ev : agenda) {
		ev.mostrar();
	}
}
