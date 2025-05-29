#include "cliente.h"
#include "cstring"
#include "cliente.h"
using namespace std;

cliente::cliente(){
    strcpy(_idCliente, "");
    strcpy(_dni, "");
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_email, "");
    strcpy(_celular , "");
    _estado = false;
}
cliente::cliente(std::string idCliente,std::string dni,std::string nombre,std::string apellido,std::string email, std::string celular, bool estado){

    setidCliente(idCliente);
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setEmail(email);
    setCelular(celular);
    setEstado(estado);
}
std::string cliente::getidCliente(){return _idCliente;}
std::string cliente::getDni(){return _dni;}
std::string cliente::getNombre(){return _nombre;}
std::string cliente::getApellido(){return _apellido;}
std::string cliente::getCelular(){return _celular;}
std::string cliente::getEmail(){return _email;}
bool cliente::getEstado(){return _estado;}

void cliente::setidCliente(std::string idCliente){strcpy(_idCliente,idCliente.c_str());}
void cliente::setDni(std::string dni){strcpy(_dni,dni.c_str());}
void cliente::setNombre(std::string nombre){strcpy(_nombre,nombre.c_str());}
void cliente::setApellido(std::string apellido){strcpy(_apellido,apellido.c_str());}
void cliente::setEmail(std::string email){strcpy(_email,email.c_str());}
void cliente::setCelular(std::string celular){strcpy(_celular,celular.c_str());}
void cliente::setEstado(bool estado){_estado=estado;}

std::string cliente::toString(){
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
    str+=",";
    str+= to_string(_estado);


    return str;

}
