#ifndef EVENTOINGENIERIA2027_H
#define EVENTOINGENIERIA2027_H

#include <string>
#include <vector>
#include <mutex>
#include <cstddef>


// Registro de un evento individual 
struct DatosEvento {
	std::string nombre;       
	std::string organizador;  
	std::string lugar;        // Ciudad / modalidad
	std::string periodo;      // Fecha o periodo 
};

// AGENDA CONCURRENTE DE EVENTOS DE INGENIERIA 2027

class EventoIngenieria2027 {
private:
	std::vector<DatosEvento> eventos;
	mutable std::mutex mtx_agenda;  // Protege 'eventos'
	
public:
	EventoIngenieria2027() = default;
	
	// Registra un evento. 
	void registrar(const std::string& nombre,
				   const std::string& organizador,
				   const std::string& lugar,
				   const std::string& periodo);
	
	// Cantidad de eventos registrados (thread-safe).
	std::size_t cantidad() const;
	
	// Funcion para el hilo dedicado: despliega la agenda completa.
	
	void procesarAgenda() const;
};

#endif 
