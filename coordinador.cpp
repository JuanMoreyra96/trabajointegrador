#include "coordinador.h"
#include <cstring>
#include <iostream>
#include <iomanip>
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


void Coordinador::Mostrar(std::string* idiomas) {
   int aux = 0;

    // Mostrar columnas fijas con ancho determinado
    cout << setw(5)  << _idCoordinador
         << setw(12) << getDni()
         << setw(15) << getNombre()
         << setw(15) << getApellido()
         << setw(35) << getEmail()
         << setw(15) << getCelular()
         << setw(10) << (getEstado() ? "Activo" : "Inactivo");

    // Idiomas: los concatenamos primero en un string
    string idiomasTexto = "";
    do {
        if (aux < 5 && _idiomas[aux] != -1) {
            if (!idiomasTexto.empty()) {
                idiomasTexto += ", ";
            }
            idiomasTexto += idiomas[_idiomas[aux] - 1];
        }
        aux++;
    } while (_idiomas[aux - 1] != -1 && aux < 5);

    cout << " " << idiomasTexto << endl;
}

