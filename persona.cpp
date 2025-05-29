#include "cstring"
#include "persona.h"
using namespace std;

persona::persona(){
    strcpy(_dni, "");
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_email, "");
    strcpy(_celular, "");
    _estado = false;
}
persona::persona(std::string dni, std::string nombre, std::string apellido, std::string email, std::string celular, bool estado){

    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setEmail(email);
    setCelular(celular);
    setEstado(estado);
}
std::string persona::getDni(){return _dni;}
std::string persona::getNombre(){return _nombre;}
std::string persona::getApellido(){return _apellido;}
std::string persona::getEmail(){return _email;}
std::string persona::getCelular(){return _celular;}
bool persona::getEstado(){return _estado;}

void persona::setDni(std::string dni){strcpy(_dni,dni.c_str());}
void persona::setNombre(std::string nombre){strcpy(_nombre,nombre.c_str());}
void persona::setApellido(std::string apellido){strcpy(_apellido,apellido.c_str());}
void persona::setEmail(std::string email){strcpy(_email,email.c_str());}
void persona::setCelular(std::string celular){strcpy(_celular,celular.c_str());}
void persona::setEstado(bool estado){_estado=estado;}

std::string persona::toString(){
    string str = "";
    str = _dni;
    str+=",";
    str+= _nombre;
    str+=",";
    str+= _apellido;
    str+= ",";
    str+= _email;
    str+= ",";
    str+= _celular;
    str+= ",";
    str+= to_string(_estado);


    return str;

}
