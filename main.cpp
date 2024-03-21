#include <iostream>
#include <stdlib.h>
#include "Prestamo.h"
#define NUM 5
using namespace std;

int menu(){
    int op;
    cout << "-------------- MENU --------------\n ";
    cout << "1.Agregar clientes a la lista\n";
    cout << " 2.Agregar prestamo a la lista\n";
    cout << " 3.Hacer pagos de prestamos\n";
    cout << " 4.Mostrar lista de clientes\n";
    cout << " 5.Mostrar lista de prestamos\n";
    cout << " 6.Mostrar detalles del prestamo\n";
    cout << " 7.Salir\n";
    cout << "---------------------------------\n";
    cout << "Digite una opcion: ";
    cin >> op;
    cout << endl;
    return op;
}
Cliente* agregarCliente(){
    Cliente* cliente = NULL;
    string nom, apellido;
    int id;

    cout << "Digite el id del cliente: ";
    cin >> id;
    cout << "Digite el nombre del cliente: ";
    cin >> nom;
    cout << "Digite el apellido del cliente: ";
    cin >> apellido;
    cliente = new Cliente(id, nom, apellido);
    return cliente;
}
Cliente* buscarCliente(Cliente* lstClientes[NUM], int contaClientes, int id){
    bool encontrado = false;
    int contador= 0;
    Cliente* cliente = NULL;
    while(contador < contaClientes && !encontrado){
        if(lstClientes[contador]->getIdCliente() == id){
            encontrado = true;
            cliente = lstClientes[contador];
        }else{
            contador = contador + 1;
        }
    }
    return cliente;
}
Prestamo* agregarPrestamo(Cliente* lstClientes[NUM], int contaClientes, Cliente* cliente){
    int numPrestamo, d, m, anio;
    float montoAprob;
    Prestamo* prestamo = NULL;
    Fecha* fecha = NULL;

        cout << "Digite el numero del prestamo: ";
        cin >> numPrestamo;
        cout << "Digite la fecha en que se aprobo (dd/mm/aa): \n";
        cin >> d;
        cin >> m;
        cin >> anio;
        cout << "Digite el monto aprobado: $";
        cin >> montoAprob;
        fecha = new Fecha(d,m,anio);
        prestamo = new Prestamo(numPrestamo,cliente,fecha, montoAprob);

    return prestamo;
}
Prestamo* buscarPrestamo(Prestamo* lstPrestamos[NUM], int contaPrestamos, int numPrestamo){
    bool encontrado = false;
    int contador= 0;
    Prestamo* prestamo = NULL;
    while(contador < contaPrestamos && !encontrado){
        if(lstPrestamos[contador]->getNumeroPrestamo() == numPrestamo){
            encontrado = true;
            prestamo = lstPrestamos[contador];
        }else{
            contador = contador + 1;
        }
    }
    return prestamo;
}
Pago* hacerPago(Pago* lstPagos[NUM], int contaPagos, Prestamo* lstPrestamos[NUM], int contaPrestamos, Prestamo* prestamo){
    int numPrestamo, d, m, anio;
    float montoPago;
    Pago* pago = NULL;
    Fecha* fecha = NULL;

        cout << "Digite el monto de pago: $";
        cin >> montoPago;
        cout << "Digite la fecha del pago (dd/mm/aa): \n";
        cin >> d;
        cin >> m;
        cin >> anio;
        fecha = new Fecha(d,m,anio);
        pago = new Pago(fecha, montoPago);

        if(prestamo->hacerPago(pago)){
            cout << " -PAGO REALIZADO EXITOSAMENTE-\n";
        }else{
            cout << " -El PAGO NO PUDO REALIZARSE-\n";
        }
    return pago;
}
void mostrarlstClientes(Cliente* lstClientes[NUM], int contaClientes){
    if(contaClientes == 0){
        cout << "La lista de clientes esta vacia.\n";
    }else{
        cout << "Id\tNombre\t Apellido\n";
        for(int i=0; i < contaClientes;i++){
            cout << lstClientes[i]->getIdCliente() << "\t";
            cout << lstClientes[i]->getNombre() << "\t   ";
            cout << lstClientes[i]->getApellido() << "\n ";
        }
    }
}
void mostrarlstPrestamos(Prestamo* lstPrestamos[NUM], int contaPrestamos){
    if(contaPrestamos == 0){
        cout << "-La lista de prestamos esta vacia-\n";
    }else{
        cout << "nPrestamo\tNombre\tApellido\tfechaAprob\tMontoAprobado\n";
        for(int i=0; i < contaPrestamos; i++){
            cout << lstPrestamos[i]->getNumeroPrestamo() << "\t       ";
            cout << lstPrestamos[i]->getCliente()->getNombre() << "\t  ";
            cout << lstPrestamos[i]->getCliente()->getApellido() << "\t  ";
            lstPrestamos[i]->getFechaAprobacion()->mostrarFecha();
            cout << "\t    $";
            cout << lstPrestamos[i]->getMontoAprobado() << "\n";
        }
    }
}
void mostrarDetalles(Prestamo* lstPrestamos[NUM], int contaPrestamos, Pago* lstPagos[NUM], int contadorPagos, Prestamo* prestamo){

        cout << "--------------------------------------------------\n";
        cout << "Numero de Prestamo: " << prestamo->getNumeroPrestamo() << endl;
        cout << "Cliente: " << prestamo->getCliente()->getNombre() << " " << prestamo->getCliente()->getApellido() << endl;
        cout << "Fecha de aprobacion: ";
        prestamo->getFechaAprobacion()->mostrarFecha();
        cout << endl;
        cout << "Monto aprobado: $" << prestamo->getMontoAprobado() << endl;
        cout << "--------------------------------------------------\n";

        if(prestamo->getContadorPagos() == 0){
            cout << "NO HAY PAGOS REALIZADOS\n";
        }else{
            cout << "\nLista de Pagos: " << endl;
            lstPagos = prestamo->getLstPagos();
            cout << "FechaPago\tMontoPagado\n";
            for(int i=0; i < prestamo->getContadorPagos(); i++){
                lstPagos[i]->getFechaPago()->mostrarFecha();
                cout << "\t ";
                cout << "     $" << lstPagos[i]->getMontoPago() << endl;
            }
        }
}
int main(){
    int op=0, contaPagos=0, contaPrestamos=0, contaClientes=0;
    int numPrestamo=0, id=0;
    Pago* lstPagos[NUM];
    Prestamo* lstPrestamos[NUM];
    Cliente* lstClientes[NUM];
    Cliente* cliente = NULL;
    Prestamo* prestamo = NULL;

    do{
        system("cls");
        op = menu();
        switch(op){
            case 1:
                ///Agregar clientes
                if(contaClientes < NUM){
                    lstClientes[contaClientes] = agregarCliente();
                    contaClientes++;
                    cout << "\n--Cliente agregado satisfactoriamente!--\n";
                }else{
                    cout << "\nLa lista de clientes esta llena\n";
                }
                break;
            case 2:
                ///Agregar Prestamo
                cout << "Digite el id del cliente: ";
                cin >> id;
                cliente = buscarCliente(lstClientes, contaClientes, id);

                if(cliente != NULL){
                        if(contaPrestamos < NUM){
                        lstPrestamos[contaPrestamos] = agregarPrestamo(lstClientes, contaClientes, cliente);
                        contaPrestamos++;
                        cout << "\n--Prestamo agregado satisfactoriamente!--\n";
                    }else{
                        cout << "\nLa lista de prestamos esta llena\n";
                    }
                }else{
                    cout << "------------------------------------\n";
                    cout << "ERROR.NO SE HA ENCONTRADO EL CLIENTE\n";
                }
                break;
            case 3:
                ///Hacer Pagos
                cout << "Digite el numero de prestamo: ";
                cin >> numPrestamo;
                prestamo = buscarPrestamo(lstPrestamos, contaPrestamos, numPrestamo);

                if(prestamo != NULL){
                    if(contaPagos < NUM){
                        lstPagos[contaPagos] = hacerPago(lstPagos, contaPagos, lstPrestamos, contaPrestamos, prestamo);
                        contaPagos++;
                        cout << "\n--Pago agregado satisfactoriamente!--\n";
                    }else{
                        cout << "\nLa lista de pagos esta llena\n";
                    }
                }else{
                    cout << "-------------------------------------\n";
                    cout << "ERROR.NO SE HA ENCONTRADO EL PRESTAMO\n";
                }
                break;
            case 4:
                ///Mostrar lista de clientes
                mostrarlstClientes(lstClientes, contaClientes);
                break;
            case 5:
                ///Mostrar lista de Prestamos
                mostrarlstPrestamos(lstPrestamos, contaPrestamos);
                break;
            case 6:
                ///Mostrar detalles del prestamo
                cout << "Digite el numero del prestamo: ";
                cin >> numPrestamo;
                prestamo = buscarPrestamo(lstPrestamos, contaPrestamos, numPrestamo);

                if(prestamo == NULL){
                    cout << "----------- ERROR -----------\n";
                    cout << "No se ha encontrado el prestamo\n";
                }else{
                    mostrarDetalles(lstPrestamos, contaPrestamos, lstPagos, contaPagos, prestamo);
                }
                break;
            case 7:
                ///Salir
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "------- ERROR -------\n";
                cout << "OPCION NO DISPONIBLE." << endl;
                break;
        }
        system("pause");
    }while( op != 7);

    return 0;
}
