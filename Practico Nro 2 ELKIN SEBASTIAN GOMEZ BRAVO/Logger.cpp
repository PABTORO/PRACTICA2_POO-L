#include "Logger.h"
#include <iostream>
#include <thread>

std::mutex mtx_consola;

void registrarEventoSeguro(const std::string& mensaje){
	std::lock_guard<std::mutex> lock(mtx_consola);
	std::cout<<"[HILO "<<std::this_thread::get_id()<<"] "
		<< mensaje << std::endl;
}
