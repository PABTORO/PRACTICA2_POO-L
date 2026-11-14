#ifndef DISPOSITIVO_COMUNICACION_H
#define DISPOSITIVO_COMUNICACION_H

#include <string>

class DispositivoComunicacion {
protected:
	std::string id;
	std::string tipo;
	
public:
	DispositivoComunicacion(std::string _id, std::string _tipo);
	virtual ~DispositivoComunicacion() = default;
	
	// Se prohíbe la copia por valor: evita el Object Slicing.
	DispositivoComunicacion(const DispositivoComunicacion&) = delete;
	DispositivoComunicacion& operator=(const DispositivoComunicacion&) = delete;
	
	// Método virtual puro que impone el contrato polimórfico
	virtual void transmitir() = 0;
	
	std::string getId() const;
	std::string getTipo() const;
};

#endif 

