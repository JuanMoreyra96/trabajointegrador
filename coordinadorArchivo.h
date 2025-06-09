#pragma once
#include "coordinador.h"
#include <string>

class CoordinadorArchivo{
    private:
        std::string _nombrearchivo;
    public:
        CoordinadorArchivo();
        CoordinadorArchivo(std::string _nombrearchivo);

        bool guardar(Coordinador registro);
        int buscar(int idCoordinador);
        bool guardar(Coordinador registro, int posicion);
        int getCantidadRegistros();
        Coordinador leer(int pos);
};
