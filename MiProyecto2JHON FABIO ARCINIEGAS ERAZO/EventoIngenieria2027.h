#ifndef EVENTOINGENIERIA2027_H
#define EVENTOINGENIERIA2027_H

#include <string>

// MODULO ESPECIAL: eventos de Ingenieria Electronica y Telecomunicaciones 2027
class EventoIngenieria2027 {
private:
	std::string nombre;
	std::string organizador;
	std::string fecha;
	std::string area;
public:
	EventoIngenieria2027(const std::string& _nombre, const std::string& _org,
						 const std::string& _fecha, const std::string& _area);
	std::string descripcion() const;
};

#endif
