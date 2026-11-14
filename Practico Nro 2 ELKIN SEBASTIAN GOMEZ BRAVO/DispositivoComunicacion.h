#ifndef DISPOSITIVOCOMUNICACION_H
#define DISPOSITIVOCOMUNICACION_H
#include <string>

class DispositivoComunicacion{
protected:
	std::string id;
	std::string tipo;
public:
	DispositivoComunicacion(std::string _id, std::string _tipo)
		: id(_id), tipo(_tipo) {}
	virtual ~DispositivoComunicacion(){}
	virtual void transmitir() = 0;
	std::string getId() const{return id;}
	std::string getTipo() const{return tipo;}
};
#endif
