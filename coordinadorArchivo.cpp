#include "coordinadorArchivo.h"

CoordinadorArchivo::CoordinadorArchivo(){
    _nombrearchivo = "coordinadores.dat";
}


CoordinadorArchivo::CoordinadorArchivo(std::string nombrearchivo){
    _nombrearchivo = nombrearchivo;
}


bool CoordinadorArchivo::guardar(Coordinador registro){
    FILE *pFile;
    bool result;
    pFile = fopen(_nombrearchivo.c_str(),"ab");

    if(pFile==nullptr){
        return false;
    }

    result = fwrite(&registro, sizeof(Coordinador),1,pFile);
    fclose(pFile);
    return result;
}


int CoordinadorArchivo::buscar(int idCoordinador){
    FILE *pFile;
    Coordinador registro;
    int posicion = 0;

    pFile = fopen(_nombrearchivo.c_str(), "rb");

    if (pFile == nullptr){
        return -2;
    }

    while(fread(&registro, sizeof(Coordinador), 1, pFile) == 1){
        if (registro.getIdCoordinador() == idCoordinador){
            fclose(pFile);
            return posicion;
        }
        posicion++;
    }

    fclose(pFile);
    return -1;
}


bool CoordinadorArchivo::guardar(Coordinador registro, int posicion){
    FILE *pFile;
    bool result;
    pFile = fopen(_nombrearchivo.c_str(), "rb+");

    if (pFile == nullptr){
        return false;
    }

    fseek(pFile, posicion * sizeof(Coordinador) , SEEK_SET);
    result = fwrite(&registro, sizeof(Coordinador), 1, pFile);
    fclose(pFile);
    return result;
}


int CoordinadorArchivo::getCantidadRegistros(){
    int total, cantidad;
    FILE* pFile;
    pFile = fopen(_nombrearchivo.c_str(), "rb");

    if(pFile == nullptr){
        return 0;
    }

    fseek(pFile, 0, SEEK_END);
    total = ftell(pFile);
    cantidad = total / sizeof(Coordinador);
    fclose(pFile);
    return cantidad;
}


Coordinador CoordinadorArchivo::leer(int pos){
    FILE *pFile;
    Coordinador registro;
    pFile = fopen(_nombrearchivo.c_str(), "rb");

    if(pFile == nullptr){
        return registro;
    }

    fseek(pFile, sizeof(Coordinador) * pos, SEEK_SET);
    fread(&registro, sizeof(Coordinador), 1, pFile);
    fclose(pFile);
    return registro;
}

