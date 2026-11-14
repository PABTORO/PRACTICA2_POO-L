#ifndef DISPOSITIVOCOMUNICACION_H
#define DISPOSITIVOCOMUNICACION_H
#include <iostream>
#include <string>
using namespace std;

class DispositivoComunicacion {
protected:
	string id;
	string tipo;
	
public:
	DispositivoComunicacion(string id, string tipo);
	
	virtual ~DispositivoComunicacion() = default;
	
	virtual void transmitir() = 0;
	
	string getId() const;
	string getTipo() const;
};

#endif
