#ifndef HILOS_H
#define HILOS_H
#include <vector>
#include <thread>
#include <functional>  
#include "dcomunicacion.h"
#include "exclucion.h"
#include "excepciones.h"

inline std::vector<std::thread> lanzarTransmisiones(
													const std::vector<DispositivoComunicacion*>& red,
													EstadisticasRed& est) {
	std::vector<std::thread> hilos;
	for (size_t i = 0; i < red.size(); ++i) {
		hilos.push_back(std::thread(tareaTransmisionHilo, red[i], std::ref(est)));
	}
	return hilos;
}
													
													
													inline void sincronizarHilos(std::vector<std::thread>& hilos) {
														for (auto& t : hilos) {
															if (t.joinable()) {
																t.join();
															}
														}
													}
#endif
