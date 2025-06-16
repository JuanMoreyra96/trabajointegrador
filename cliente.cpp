#include "Cliente.h"
#include <cstring>
#include <iostream>
#include <iomanip>
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
       cout << left
         << setw(5)  << _idCliente
         << setw(12) << getDni()
         << setw(15) << getNombre()
         << setw(15) << getApellido()
         << setw(25) << getEmail()
         << setw(15) << getCelular()
         << setw(12) << (getEstado() ? "ACTIVO" : "BAJA")
         << endl;
}

void Cliente::darDeBaja(){
 setEstado(false);
}
void Cliente::darDeAlta(){
 setEstado(true);
}




