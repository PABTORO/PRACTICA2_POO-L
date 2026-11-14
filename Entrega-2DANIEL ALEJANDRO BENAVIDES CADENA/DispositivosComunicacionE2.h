#ifndef DISPOSITIVOCOMUNICACIONE2_H
#define DISPOSITIVOCOMUNICACIONE2_H

#include <string>

using namespace std;

class DispositivoComunicacion {
protected:
    string id;
    string tipo;

public:
    DispositivoComunicacion(string _id, string _tipo);
    virtual ~DispositivoComunicacion() = default;

    virtual void transmitir() = 0;

    string getId() const;
    string getTipo() const;
};

#endif