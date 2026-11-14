#ifndef ROUTERWIFI_H
#define ROUTERWIFI_H
#include "DispositivoComunicacion.h"
#include <iostream>
#include <string>
using namespace std;

class RouterWiFi : public DispositivoComunicacion {
private:
	int canalesActivos;
	
public:
	RouterWiFi(string id, int canalesActivos);
	
	void transmitir() override;
};

#endif

