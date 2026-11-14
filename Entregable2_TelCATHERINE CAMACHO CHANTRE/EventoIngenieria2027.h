#ifndef EVENTOINGENIERIA2027_H
#define EVENTOINGENIERIA2027_H

#include <string>
#include <vector>
using namespace std;

class EventoIngenieria2027 {
private:
	string nombre;
	string fecha;
	string lugar;
public:
	EventoIngenieria2027(string _nombre, string _fecha, string _lugar);
	void mostrar() const;
};

void tareaEventos2027(vector<EventoIngenieria2027>& agenda);

#endif
