#ifndef ESTADISTICASRED_H
#define ESTADISTICASRED_H
#include <mutex>

class EstadisticasRed{
private:
	std::mutex mtx;
	int exitosas;
	int fallidas;
public:
	EstadisticasRed() : exitosas(0), fallidas(0){}
	
	void sumarExitosa(){
		std::lock_guard<std::mutex> lock(mtx);
		exitosas++;
	}
	void sumarFallida(){
		std::lock_guard<std::mutex> lock(mtx);
		fallidas++;
	}
	int getExitosas(){
		std::lock_guard<std::mutex> lock(mtx);
		return exitosas;
	}
	int getFallidas(){
		std::lock_guard<std::mutex> lock(mtx);
		return fallidas;
	}
};
#endif
