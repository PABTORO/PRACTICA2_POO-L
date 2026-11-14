#ifndef SWITCHFIBRA_H
#define SWITCHFIBRA_H
#include <thread>
#include <chrono>
#include "DispositivoComunicacion.h"

class SwitchFibra : public DispositivoComunicacion{
private:
	int puertos;
public:
	SwitchFibra(std::string _id, int _puertos)
		: DispositivoComunicacion(_id, "Switch Fibra Optica"), puertos(_puertos){}
	
	void transmitir() override{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
};
#endif
