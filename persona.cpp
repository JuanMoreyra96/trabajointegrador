#include <cstring>
#include "persona.h"
#include <iostream>
using namespace std;
Persona::Persona(){
    strcpy(_dni, "");
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_email, "");
    strcpy(_celular, "");
    _estado = false;
}
Persona::Persona(std::string dni, std::string nombre, std::string apellido, std::string email, std::string celular, bool estado){
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setEmail(email);
    setCelular(celular);
    setEstado(estado);
}
std::string Persona::getDni(){return _dni;}
std::string Persona::getNombre(){return _nombre;}
std::string Persona::getApellido(){return _apellido;}
std::string Persona::getEmail(){return _email;}
std::string Persona::getCelular(){return _celular;}
bool Persona::getEstado(){return _estado;}
void Persona::setDni(std::string dni){strcpy(_dni,dni.c_str());}
void Persona::setNombre(std::string nombre){strcpy(_nombre,nombre.c_str());}
void Persona::setApellido(std::string apellido){strcpy(_apellido,apellido.c_str());}
void Persona::setEmail(std::string email){strcpy(_email,email.c_str());}
void Persona::setCelular(std::string celular){strcpy(_celular,celular.c_str());}
void Persona::setEstado(bool estado){_estado=estado;}
void Persona::Mostrar(){
    cout<< "Datos de la persona: " << endl;
    cout<<"Dni: "<< _dni<< endl;
    cout<<"Nombre: "<< _nombre<< endl;
    cout<<"Apellido: "<< _apellido << endl;
    cout<<"Email: "<< _email << endl;
    cout<<"Celular: "<< _celular << endl;
    cout<<"Estado: "<< _estado << endl;
}


