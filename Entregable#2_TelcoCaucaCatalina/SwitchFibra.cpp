#include "SwitchFibra.h"
#include "DispositivoComunicacion.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

SwitchFibra::SwitchFibra(string id, int puertosActivos)
	: DispositivoComunicacion(id, "Switch de Fibra") {
	
	this-> puertosActivos = puertosActivos;
}

void SwitchFibra::transmitir() {
	this_thread::sleep_for(chrono::milliseconds(180));
}
