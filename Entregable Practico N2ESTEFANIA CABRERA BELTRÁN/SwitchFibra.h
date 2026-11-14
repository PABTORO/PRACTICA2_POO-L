#ifndef SWITCHFIBRA_H
#define SWITCHFIBRA_H

#include "DispositivoComunicacion.h"
#include <string>

// SUBCLASE CONCRETA: Switch de fibra óptica

class SwitchFibra : public DispositivoComunicacion {
private:
	int puertos;           
	double velocidadGbps;  
	
public:
	// Lanza std::invalid_argument si puertos o velocidad no son positivos.
	SwitchFibra(const std::string& _id, int _puertos, double _velocidadGbps);
	
	~SwitchFibra() override = default;
	
	void transmitir() override;
	
	int getPuertos() const;
	double getVelocidadGbps() const;
};

#endif 
