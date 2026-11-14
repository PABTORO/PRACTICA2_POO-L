#include "RouterWiFiE2.h"
using namespace std;

RouterWiFi::RouterWiFi(string _id, int _canales)
    : DispositivoComunicacion(_id, "Router WiFi 6"), canalesActivos(_canales) {}

void RouterWiFi::transmitir() override {
}