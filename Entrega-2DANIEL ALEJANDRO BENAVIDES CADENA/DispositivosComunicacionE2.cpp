#include "DispositivosComunicacionE2.h"
using namespace std;

DispositivoComunicacion::DispositivoComunicacion(string _id, string _tipo)
    : id(_id), tipo(_tipo) {}

string DispositivoComunicacion::getId() const {
    return id;
}

string DispositivoComunicacion::getTipo() const {
    return tipo;
}