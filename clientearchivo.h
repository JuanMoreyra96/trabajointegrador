#pragma once
#include "cliente.h"
#include <string>

class clientearchivo{
    private:
        std::string _nombrearchivo;
    public:
        clientearchivo();
        clientearchivo(std::string _nombrearchivo);

        bool guardar(cliente registro);


};
