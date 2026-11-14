#include "DispositivoComunicacion.h"

DispositivoComunicacion::DispositivoComunicacion(std::string _id, std::string _tipo)
	: id(_id), tipo(_tipo) {}

std::string DispositivoComunicacion::getId() const {
	return id;
}

std::string DispositivoComunicacion::getTipo() const {
	return tipo;
}
