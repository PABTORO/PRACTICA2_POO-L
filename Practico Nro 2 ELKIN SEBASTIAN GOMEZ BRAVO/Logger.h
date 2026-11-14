#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <mutex>

extern std::mutex mtx_consola;

void registrarEventoSeguro(const std::string& mensaje);

#endif
