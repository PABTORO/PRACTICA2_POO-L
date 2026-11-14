#ifndef SWITCHFIBRA_H
#define SWITCHFIBRA_H
#include "DispositivoComunicacion.h"
#include <iostream>
#include <string>
using namespace std;

class SwitchFibra : public DispositivoComunicacion {
private:
	int puertosActivos;
	
public:
	SwitchFibra(string id, int puertosActivos);
	
	void transmitir() override;
};


#endif

