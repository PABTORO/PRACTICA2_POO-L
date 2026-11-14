#ifndef DISPOSITIVOCOMUNICACION_H
#define DISPOSITIVOCOMUNICACION_H

#include <string>


class DispositivoComunicacion {
protected:
	std::string id;
	std::string tipo;
public:
	DispositivoComunicacion(std::string _id, std::string _tipo);
	virtual ~DispositivoComunicacion() = default;
	virtual void transmitir() = 0;
	std::string getId() const;
	std::string getTipo() const;
};

#endif
