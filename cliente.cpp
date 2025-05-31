#include "Cliente.h"
#include <cstring>
#include <iostream>
using namespace std;
Cliente::Cliente()
:Persona(), _idCliente (""){
}
Cliente::Cliente(std::string dni,std::string nombre,std::string apellido,std::string email, std::string celular, bool estado, std::string idCliente)
:Persona(dni,nombre,apellido,email,celular,estado){
    setidCliente(idCliente);
}
void Cliente::setidCliente(std::string idCliente){
    strcpy(_idCliente,idCliente.c_str());
}
std::string Cliente::getidCliente(){
    return _idCliente;
}
void Cliente::Mostrar(){
    cout<<"Dni: "<< _idCliente<< endl;
    cout<< "Datos del Cliente " << endl;
    cout<<"Dni: "<< getDni()<< endl;
    cout<<"Nombre: "<< getNombre()<< endl;
    cout<<"Apellido: "<< getApellido() << endl;
    cout<<"Email: "<< getEmail() << endl;
    cout<<"Celular: "<< getCelular() << endl;
    cout<<"Estado: "<< getEstado() << endl;
}




