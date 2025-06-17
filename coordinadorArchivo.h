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
        bool guardar(Coordinador registro, int posicion);
        int buscar(int idCoordinador);
        int buscar(std::string dniCoordinador);
        int getCantidadRegistros();
        Coordinador leer(int pos);
};
