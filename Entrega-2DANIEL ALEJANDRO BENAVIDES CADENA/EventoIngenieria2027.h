#ifndef EVENTOINGENIERIA2027_H
#define EVENTOINGENIERIA2027_H
#include <string>
#include <vector>
using namespace std;

class EventoIngenieria2027 {
private:
    vector<string> listaEventos;

public:
    EventoIngenieria2027();
    void agregarEvento(const string& evento);
    void procesarYDesplegarAgenda() const;
};

#endif