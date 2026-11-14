#ifndef DISPOSITIVOCOMUNICACION_H
#define DISPOSITIVOCOMUNICACION_H

#include <string>

// CLASE BASE ABSTRACTA (contrato polimorfico)
class DispositivoComunicacion {
protected:
	std::string id;
	std::string tipo;
public:
	DispositivoComunicacion(const std::string& _id, const std::string& _tipo);
	
	// Destructor virtual: indispensable para liberacion polimorfica en el Heap
	virtual ~DispositivoComunicacion();
	
	// Metodo virtual puro: define la interfaz obligatoria
	virtual void transmitir() = 0;
	
	std::string getId() const;
	std::string getTipo() const;
};

#endif
