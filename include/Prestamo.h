#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Cliente.h"
#include "Fecha.h"
#include "Pago.h"
#define TAML 5

class Prestamo{
    public:
        Prestamo();
        Prestamo(int numPresta,Cliente* cli, Fecha* fechaAprob, float montoAprob);
        int getNumeroPrestamo();
        void setNumeroPrestamo(int numPrest);
        Cliente* getCliente();
        void setCliente(Cliente* cli);
        void setFechaAprobacion(Fecha* fechaAp);
        Fecha* getFechaAprobacion();
        void setMontoAprobado(float montoAprob);
        float getMontoAprobado();
        bool hacerPago(Pago* hacerP);
        Pago** getLstPagos();
        float getSaldoPendiente();
        int getContadorPagos();
        virtual ~Prestamo();
    protected:
    private:
        int numeroPrestamo;
        Cliente* cliente;
        Fecha* fechaAprobacion;
        float montoAprobado;
        Pago* lstPagos[TAML];
        float saldoPendiente;
        int contarPagos;
};
#endif // PRESTAMO_H
