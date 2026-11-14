#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H
#include <stdexcept>
#include <exception>
#include <string>
#include <vector>
#include "dcomunicacion.h"
#include "exclucion.h"

inline void tareaTransmisionHilo(DispositivoComunicacion* dev, EstadisticasRed& est) {
	try {
		if (dev == nullptr) {
			throw std::invalid_argument("error: puntero nulo pasado al hilo.");
		}
		dev->transmitir();
		est.sumarExito();
		registrarEventoSeguro("transmision exitosa del dispositivo :   " + dev->getId() +
							  " (" + dev->getTipo() + ")");
	}
	catch (const std::exception& e) {
		est.sumarFallo();
		registrarEventoSeguro(std::string("excepcion en hilo:  ") + e.what());
	}
	catch (...) {
		est.sumarFallo();
		registrarEventoSeguro("ecepcion en el hilo de transmiision");
	}
}

inline void procesarErroresTransportados(const std::vector<std::exception_ptr>& errores) {
	for (size_t i = 0; i < errores.size(); ++i) {
		try {
			std::rethrow_exception(errores[i]);
		}
		catch (const std::exception& e) {
			registrarEventoSeguro(std::string("main recicibida de la excepcion del hilo de agenda :   ") + e.what());
		}
	}
}

#endif
