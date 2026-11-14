#ifndef EVENTOINGENIERIA2027_H
#define EVENTOINGENIERIA2027_H
#include <string>

class EventoIngenieria2027{
private:
	std::string nombre;
	std::string descripcion;
	std::string fecha;
public:
	EventoIngenieria2027(std::string _nombre, std::string _descripcion, std::string _fecha);
	std::string getResumen() const;
};
#endif
