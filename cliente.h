#pragma once
#include <string>
#include "persona.h"
class Cliente: public Persona{
private:
    char _idCliente [3];
public:
    Cliente();
    Cliente(std::string dni,std::string nombre,std::string apellido,std::string email, std::string celular, bool estado,std::string idCliente);
        std::string getidCliente();
        void setidCliente(std::string idCliente);
        void Mostrar();
};


