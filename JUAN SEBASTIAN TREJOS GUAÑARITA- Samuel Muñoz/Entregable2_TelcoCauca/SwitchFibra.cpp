#include "SwitchFibra.h"
#include <thread>
#include <chrono>

SwitchFibra::SwitchFibra(const std::string& _id, int _puertos)
    : DispositivoComunicacion(_id, "Switch Fibra Optica"), puertosSFP(_puertos) {}

void SwitchFibra::transmitir() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
