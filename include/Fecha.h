#ifndef FECHA_H
#define FECHA_H

class Fecha{
    public:
        Fecha(int d, int m, int a);
        void mostrarFecha();
        virtual ~Fecha();
    protected:
    private:
        int dia;
        int mes;
        int anio;
};
#endif // FECHA_H
