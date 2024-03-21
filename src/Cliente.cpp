#include "Cliente.h"
#include <iostream>

Cliente::Cliente(int id, string nom, string apellido){
    this->idCliente = id;
    this->nombre = nom;
    this->apellido = apellido;
}

int Cliente::getIdCliente(){
    return this->idCliente;
}

string Cliente:: getNombre(){
    return this->nombre;
}

string Cliente:: getApellido(){
    return this->apellido;
}

Cliente::~Cliente(){
}
