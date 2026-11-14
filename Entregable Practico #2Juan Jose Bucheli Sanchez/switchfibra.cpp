#include "switchfibra.h"
#include <thread>
#include <chrono>

SwitchFibra::SwitchFibra(string _id, int _puertos): DispositivoComunicacion(_id, "Switch fibra"), puertos(_puertos) {
	
}

void SwitchFibra::transmitir() {
	this_thread::sleep_for(chrono::milliseconds(100));
}
