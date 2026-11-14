#include "EventoIngenieria2027.h"

EventoIngenieria2027::EventoIngenieria2027(std::string _nombre, std::string _descripcion, std::string _fecha)
	: nombre(_nombre), descripcion(_descripcion), fecha(_fecha) {}

std::string EventoIngenieria2027::getResumen() const {
	return "EVENTO 2027: " + nombre + " - " + descripcion + " (" + fecha + ")";
}
