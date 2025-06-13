#pragma once
#include <string>
#include "persona.h"
class Cliente: public Persona{
private:
    int _idCliente;
public:
    Cliente();
    Cliente(std::string dni,std::string nombre,std::string apellido,std::string email, std::string celular, bool estado,int idCliente);
        int getidCliente();
        void setidCliente(int idCliente);
        void Mostrar();
        void darDeBaja();
};


