#pragma once
#include "cliente.h"
#include <string>

class clientearchivo{
    private:
        std::string _nombrearchivo;
    public:
        clientearchivo();
        clientearchivo(std::string _nombrearchivo);

        bool guardar(Cliente registro);
        int buscar(int idCliente);
        int buscar(std::string dniCliente);
        bool guardar(Cliente registro, int posicion);
        int getCantidadRegistros();
        Cliente leer(int pos);
};
