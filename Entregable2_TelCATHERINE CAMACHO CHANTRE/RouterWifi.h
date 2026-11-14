#ifndef ROUTERWIFI_H
#define ROUTERWIFI_H

#include "DispositivoComunicacion.h"

class RouterWiFi : public DispositivoComunicacion {
private:
	int canalesActivos;
public:
	RouterWiFi(std::string _id, int _canales);
	void transmitir() override;
};

#endif
