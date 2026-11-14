#include "EventoIngenieria2027.h"
#include <stdexcept>

EventoIngenieria2027::EventoIngenieria2027(const std::string& _nombre, const std::string& _org,
										   const std::string& _fecha, const std::string& _area)
	: nombre(_nombre), organizador(_org), fecha(_fecha), area(_area) {
	if (nombre.empty()) {
		throw std::invalid_argument("El evento debe tener nombre.");
	}
}

std::string EventoIngenieria2027::descripcion() const {
	return nombre + " | " + organizador + " | " + fecha + " | " + area;
}
