#include "Pago.h"
#include "Fecha.h"


Pago::Pago(Fecha* fPago,float montoP){
    this->fechaPago = fPago;
    this->montoPago = montoP;
}

Fecha* Pago::getFechaPago(){
    return this->fechaPago;
}

float Pago::getMontoPago(){
    return this->montoPago;
}

Pago::~Pago(){
}
