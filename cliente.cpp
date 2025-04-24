#include "cliente.h"
#include "cstring"
#include "cliente.h"
using namespace std;

cliente::cliente(){
    _dni = 0;
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    _telefono = 0;
    strcpy(_direccion, "");
    strcpy(_email, "");
    _reservado = false;
}
cliente::cliente(int dni, std::string nombre, std::string apellido,int telefono, std::string direccion,std::string email, bool reservado){
   /* _dni = dni;
    strcpy(_nombre, nombre.c_str());
    strcpy(_apellido, apellido.c_str());
    _telefono = telefono;
    strcpy(_direccion, direccion.c_str());
    strcpy(_email, email.c_str());
    _reservado = reservado;*/

    // asi queda mas retulizado el codigo
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setDireccion(direccion);
    setEmail(email);
    setReservado(reservado);
}
int cliente::getDni(){return _dni;}
std::string cliente::getNombre(){return _nombre;}
std::string cliente::getApellido(){return _apellido;}
int cliente::getTelefono(){return _telefono;}
std::string cliente::getDireccion(){return _direccion;}
std::string cliente::getEmail(){return _email;}
bool cliente::getReservado(){return _reservado;}

void cliente::setDni(int dni){_dni=dni;}
void cliente::setNombre(std::string nombre){strcpy(_nombre,nombre.c_str());}
void cliente::setApellido(std::string apellido){strcpy(_apellido,apellido.c_str());}
void cliente::setTelefono(int telefono){_telefono=telefono;}
void cliente::setDireccion(std::string direccion){strcpy(_direccion,direccion.c_str());}
void cliente::setEmail(std::string email){strcpy(_email,email.c_str());}
void cliente::setReservado(bool reservado){_reservado=reservado;}

std::string cliente::toString(){
    string str = "";
    str = to_string(_dni)+ ",";
    str+= _nombre;
    str+=",";
    str+= _apellido;
    str+= ",";
    str+= _direccion;
    str+= ",";
    str+= _email;
    str+= ",";
    str+= to_string(_telefono)+ ",";
    str+= to_string(_reservado);


    return str;

}
