#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
using namespace std;

class Cliente{
    public:
        Cliente(int id, string nom, string apellido);
        int getIdCliente();
        string getNombre();
        string getApellido();
        virtual ~Cliente();
    protected:
    private:
        int idCliente;
        string nombre;
        string apellido;
};
#endif // CLIENTE_H
