#ifndef SWITCHFIBRA_H
#define SWITCHFIBRA_H

#include "DispositivoComunicacion.h"

class SwitchFibra : public DispositivoComunicacion {
private:
	int velocidadGbps;
public:
	SwitchFibra(std::string _id, int _velocidad);
	void transmitir() override;
};

#endif
