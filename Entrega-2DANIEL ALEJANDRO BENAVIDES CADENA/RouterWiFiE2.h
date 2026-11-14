#ifndef ROUTERWIFIE2_H
#define ROUTERWIFIE2_H
#include "DispositivosComunicacionE2.h"
using namespace std;

class RouterWiFi : public DispositivoComunicacion {
private:
    int canalesActivos;

public:
    RouterWiFi(string _id, int _canales);
    void transmitir() override;
};

#endif