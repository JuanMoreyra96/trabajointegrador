#include "coordinador.h"
#include <cstring>
#include <iostream>
using namespace std;

Coordinador::Coordinador(){
}


Coordinador::Coordinador(std::string dni,std::string nombre,std::string apellido,std::string email, std::string celular, bool estado, int idCoordinador, int* idiomas)
:Persona(dni,nombre,apellido,email,celular,estado){
    setIdCoordinador(idCoordinador);
    setIdiomas(idiomas);
}


int Coordinador::getIdCoordinador() {
    return _idCoordinador;
}


void Coordinador::setIdCoordinador(int idCoordinador) {
    _idCoordinador = idCoordinador;
}


int* Coordinador::getIdiomas() {
    return _idiomas; // Retorna puntero al array interno
}


void Coordinador::setIdiomas(int* idiomas) {
    for (int i = 0; i < 5; ++i) {
        _idiomas[i] = idiomas[i];
    }
}


void Coordinador::Mostrar() {
    cout <<"ID del Coordinador: " << _idCoordinador << endl;
    cout<<"Dni: "<< getDni()<< endl;
    cout<<"Nombre: "<< getNombre()<< endl;
    cout<<"Apellido: "<< getApellido() << endl;
    cout<<"Email: "<< getEmail() << endl;
    cout<<"Celular: "<< getCelular() << endl;
    cout<<"Idiomas: ";
    for (int i = 0; i < 5; ++i) {
        cout << _idiomas[i];
        if(i<4){
             cout<< ", ";
        }else{
             cout<< endl;
        }
    }
    cout<<"Estado: "<< getEstado() << endl;
    cout << endl;
}

