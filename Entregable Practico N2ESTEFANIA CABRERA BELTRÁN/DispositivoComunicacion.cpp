#include "DispositivoComunicacion.h"
#include <stdexcept>

DispositivoComunicacion::DispositivoComunicacion(std::string _id, std::string _tipo)
	: id(_id), tipo(_tipo) {
	
	if (_id.empty()) {
		throw std::invalid_argument("ERROR: El id del dispositivo no puede estar vacio.");
	}
	if (_tipo.empty()) {
		throw std::invalid_argument("ERROR: El tipo del dispositivo no puede estar vacio.");
	}
}

std::string DispositivoComunicacion::getId() const {
	return id;
}

std::string DispositivoComunicacion::getTipo() const {
	return tipo;
}
