#include "Cliente.h"
#include <cstring>
#include <iostream>

using namespace std;
Cliente::Cliente()
    : Persona(), _idCliente(0) {
}
Cliente::Cliente(std::string dni,std::string nombre,std::string apellido,std::string email, std::string celular, bool estado, int idCliente)
:Persona(dni,nombre,apellido,email,celular,estado){
    setidCliente(idCliente);
}
void Cliente::setidCliente(int idCliente){
    _idCliente = idCliente;
}
int Cliente::getidCliente(){
    return _idCliente;
}
void Cliente::Mostrar(){
    cout<<"Id: "<< _idCliente<< endl;
    cout<< "Datos del Cliente " << endl;
    cout<<"Dni: "<< getDni()<< endl;
    cout<<"Nombre: "<< getNombre()<< endl;
    cout<<"Apellido: "<< getApellido() << endl;
    cout<<"Email: "<< getEmail() << endl;
    cout<<"Celular: "<< getCelular() << endl;
    cout<<"Estado: "<< getEstado() << endl;
}




