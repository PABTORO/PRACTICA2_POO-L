#ifndef EVENTOINGENIERIA2027_H
#define EVENTOINGENIERIA2027_H
#include <iostream>
#include <string>
#include <vector>
#include <mutex>

using namespace std;

class EventoIngenieria2027 {
	
private:
	vector<string> eventos;
	
public:
	EventoIngenieria2027();
	
	void mostrarEventos(mutex& mtx);
};

#endif

