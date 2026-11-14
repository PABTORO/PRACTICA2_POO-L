#ifndef EVENTOS2027_H
#define EVENTOS2027_H
#include <string>
#include <vector>

using namespace std;

class EventoIngenieria2027 {
private:
	string nombre;
	string tema;
	string fecha;
	string lugar;
	
public:
	EventoIngenieria2027(string _nombre, string _tema, string _fecha, string _lugar);
	string resumen() const;
	
};

void mostrarAgenda(const vector<EventoIngenieria2027>& eventos);

#endif

