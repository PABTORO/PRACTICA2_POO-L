#include "DispositivoComunicacion.h"

DispositivoComunicacion::DispositivoComunicacion(const std::string& _id, const std::string& _tipo)
	: id(_id), tipo(_tipo) {}

DispositivoComunicacion::~DispositivoComunicacion() {}

std::string DispositivoComunicacion::getId() const { return id; }

std::string DispositivoComunicacion::getTipo() const { return tipo; }
