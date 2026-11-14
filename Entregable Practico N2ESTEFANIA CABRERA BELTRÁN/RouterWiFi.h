#ifndef ROUTERWIFI_H
#define ROUTERWIFI_H

#include "DispositivoComunicacion.h"
#include <string>


// SUBCLASE CONCRETA: Router WiFi 6 

class RouterWiFi : public DispositivoComunicacion {
private:
	int canalesActivos;  // Canales activos 
	
public:
	// Lanza std::invalid_argument si canales está fuera de rango.
	RouterWiFi(const std::string& _id, int _canales);
	
	~RouterWiFi() override = default;
	
	void transmitir() override;
	
	int getCanalesActivos() const;
};

#endif 
