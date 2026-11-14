#include "TareaTransmision.h"
#include "Registro.h"
#include <stdexcept>
#include <string>
#include <mutex>

void tareaTransmisionHilo(DispositivoComunicacion* dev, int& exitosas) {
    try {
        if (dev == nullptr) {
            throw std::invalid_argument("ERROR: Puntero nulo pasado al hilo.");
        }

        dev->transmitir();
        registrarEventoSeguro("Transmision exitosa del dispositivo: " + dev->getId()
                              + " (" + dev->getTipo() + ")");

        {
            std::lock_guard<std::mutex> lock(mtx_contador);
            ++exitosas;
        }
    }
    catch (const std::exception& e) {
        registrarEventoSeguro(std::string("EXCEPCION EN HILO: ") + e.what());
    }
}
