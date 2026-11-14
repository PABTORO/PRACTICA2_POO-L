#ifndef ROUTERWIFI_H
#define ROUTERWIFI_H
#include "dispositivocomunicacion.h"


class RouterWiFi : public DispositivoComunicacion {
private:
	int canalesActivos;
	
public:
	RouterWiFi(string _id, int _canales);
	void transmitir() override;
};

#endif

