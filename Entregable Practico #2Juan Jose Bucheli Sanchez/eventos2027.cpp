#include "eventos2027.h"
#include "mutex.h"
#include <stdexcept>

EventoIngenieria2027::EventoIngenieria2027(string _nombre, string _tema, string _fecha, string _lugar)
	: nombre(_nombre), tema(_tema), fecha(_fecha), lugar(_lugar){
	
}

string EventoIngenieria2027::resumen() const {
	return "| nombre: "+ nombre + " | Tema: " + tema + " | fecha: " + fecha + " | lugar: " + lugar;

}

void mostrarAgenda(const vector<EventoIngenieria2027>& eventos){
	try {
		for (const auto& ev : eventos){
			registrarEventoSeguro("Evento 2027: " + ev.resumen());
		}
	} catch (const exception& e){
		registrarEventoSeguro(string("Exceppcion en la agenda: ") + e.what());
	}
}
