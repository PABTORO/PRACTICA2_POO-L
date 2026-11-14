#ifndef SWITCHFIBRA_H
#define SWITCHFIBRA_H
#include "dispositivocomunicacion.h"

class SwitchFibra : public DispositivoComunicacion{
private:
	int puertos;
	
public:
	SwitchFibra(string _id, int _puertos);
	void transmitir() override;
	
};

#endif
