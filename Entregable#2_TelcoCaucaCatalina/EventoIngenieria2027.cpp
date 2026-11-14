#include "EventoIngenieria2027.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
EventoIngenieria2027::EventoIngenieria2027() {
	
	eventos.push_back("Andina Link Expo 2027 - Cartagena, Colombia");
	eventos.push_back("IEEE Colombian Caribbean Conference C3 2027 - Cartagena, Colombia");
	eventos.push_back("IV Congreso Internacional de Ciencia e Ingenieria CICI 2027 - Colombia");
	
}
	
void EventoIngenieria2027::mostrarEventos(mutex& mtx) {
	
	lock_guard<mutex> bloqueo(mtx);
	
	cout << endl;
	cout << "===== EVENTOS DE INGENIERIA 2027 =====" << endl;
	
	for (string& evento : eventos) {
		cout << evento << endl;
	}
}

