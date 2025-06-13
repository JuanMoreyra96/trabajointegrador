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
        int buscar(std::string dniCoordinador);
        bool guardar(Coordinador registro, int posicion);
        int getCantidadRegistros();
        Coordinador leer(int pos);
};
