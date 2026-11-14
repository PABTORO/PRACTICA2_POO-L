#ifndef SWITCHFIBRA_H
#define SWITCHFIBRA_H

#include "DispositivoComunicacion.h"

class SwitchFibra : public DispositivoComunicacion {
private:
	int velocidadGbps;
public:
	SwitchFibra(const std::string& _id, int _vel);
	void transmitir() override;
};

#endif
