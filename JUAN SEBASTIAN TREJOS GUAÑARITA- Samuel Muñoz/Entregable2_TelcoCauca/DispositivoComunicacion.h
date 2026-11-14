#ifndef DISPOSITIVOCOMUNICACION_H
#define DISPOSITIVOCOMUNICACION_H

#include <string>

class DispositivoComunicacion {
protected:
    std::string id;
    std::string tipo;
public:
    DispositivoComunicacion(const std::string& _id, const std::string& _tipo);

    virtual ~DispositivoComunicacion();

    virtual void transmitir() = 0;

    std::string getId() const;
    std::string getTipo() const;
};

#endif
