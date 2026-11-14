#include <iostream>
#include <string>
#include "DispositivoComunicacion.h"
using namespace std;

DispositivoComunicacion::DispositivoComunicacion(string id, string tipo) {
	
	this-> id = id;
	this-> tipo = tipo;
}

string DispositivoComunicacion::getId() const {
	return id;
}

string DispositivoComunicacion::getTipo() const {
	return tipo;
}
