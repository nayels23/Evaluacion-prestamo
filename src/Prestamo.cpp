#include "Prestamo.h"
#include "Cliente.h"
#include "Fecha.h"
#include "Pago.h"

Prestamo::Prestamo(){
    this->numeroPrestamo = 0;
    this->montoAprobado = 0;
    this->saldoPendiente = 0;
    this->contarPagos = 0;
}

Prestamo::Prestamo(int numPresta,Cliente* cli, Fecha* fechaAprob, float montoAprob){
    this->numeroPrestamo = numPresta;
    this->cliente = cli;
    this->fechaAprobacion = fechaAprob;
    this->montoAprobado = montoAprob;
    this->saldoPendiente = this->montoAprobado;
    this->contarPagos = 0;
}

int Prestamo::getNumeroPrestamo(){
    return this->numeroPrestamo;
}

void Prestamo::setNumeroPrestamo(int numPrest){
    this->numeroPrestamo = numPrest;
}

Cliente* Prestamo::getCliente(){
    return this->cliente;
}

void Prestamo::setCliente(Cliente* cli){
    this->cliente = cli;
}

void Prestamo::setFechaAprobacion(Fecha* fechaAp){
    this->fechaAprobacion = fechaAp;
}

Fecha* Prestamo::getFechaAprobacion(){
    return this->fechaAprobacion;
}

void Prestamo::setMontoAprobado(float montoAprob){
    this->montoAprobado = montoAprob;
}

float Prestamo::getMontoAprobado(){
    return this->montoAprobado;
}

bool Prestamo::hacerPago(Pago* hacerP){
    bool pagoHecho = false;
    if(this->saldoPendiente >= hacerP->getMontoPago()){
        this->saldoPendiente = this->saldoPendiente - hacerP->getMontoPago();
        this->lstPagos[this->contarPagos] = hacerP;
        this->contarPagos++;
        pagoHecho = true;
    }
    return pagoHecho;
}

Pago** Prestamo::getLstPagos(){
    return this->lstPagos;
}

float Prestamo::getSaldoPendiente(){
    return this->saldoPendiente;
}

int Prestamo::getContadorPagos(){
    return this->contarPagos;
}

Prestamo::~Prestamo(){
    //dtor
}
