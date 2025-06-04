#pragma once
#include <string>
#include "persona.h"

class Coordinador: public Persona{

    private:
        int _idCoordinador;
        int _idiomas[5];

    public:
        Coordinador();
        Coordinador(std::string dni,std::string nombre,std::string apellido,std::string email, std::string celular, bool estado,int _idCoordinador,int* idiomas);
        int getIdCoordinador();
        void setIdCoordinador(int idCoordinador);
        int* getIdiomas();
        void setIdiomas (int* idiomas);
        void Mostrar();
};

