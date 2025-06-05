#include "Paquetedeviajearchivo.h"

PaqueteDeViajeArchivo::PaqueteDeViajeArchivo(){
  _nombreArchivo = "paquetesdeviaje.dat";
}

PaqueteDeViajeArchivo::PaqueteDeViajeArchivo(std::string nombreArchivo){
  _nombreArchivo = nombreArchivo;
}

bool PaqueteDeViajeArchivo::guardar(PaqueteDeViaje registro){
  FILE *pFile;
  bool result;

  pFile = fopen(_nombreArchivo.c_str(), "ab");

  if(pFile == nullptr){
    return false;
  }

  result = fwrite(&registro, sizeof(PaqueteDeViaje), 1, pFile);

  fclose(pFile);

  return result;
}

bool PaqueteDeViajeArchivo::guardar(PaqueteDeViaje registro, int posicion){
   FILE *pFile;
   bool result;
   pFile = fopen(_nombreArchivo.c_str(), "rb+");
   if (pFile == nullptr){
      return false;
   }
   fseek(pFile, posicion * sizeof(PaqueteDeViaje) , SEEK_SET);
   result = fwrite(&registro, sizeof(PaqueteDeViaje), 1, pFile);
   fclose(pFile);
   return result;

}

int PaqueteDeViajeArchivo::getCantidadRegistros(){
  int total, cantidad;
  FILE* pFile;
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  if(pFile == nullptr){
    return 0;
  }
  fseek(pFile, 0, SEEK_END);
  total = ftell(pFile);
  cantidad = total / sizeof(PaqueteDeViaje);
  fclose(pFile);
  return cantidad;
}


PaqueteDeViaje PaqueteDeViajeArchivo::leer(int pos){
  FILE *pFile;
  PaqueteDeViaje reg;
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  if(pFile == nullptr){
    return reg;
  }
  fseek(pFile, sizeof(PaqueteDeViaje) * pos, SEEK_SET);
  fread(&reg, sizeof(PaqueteDeViaje), 1, pFile);
  fclose(pFile);
  return reg;
}

int PaqueteDeViajeArchivo::buscar(int idPaquete){
   FILE *pFile;
   PaqueteDeViaje reg;
   int posicion = 0;
   pFile = fopen(_nombreArchivo.c_str(), "rb");

   if (pFile == nullptr){
      return -2;
   }

   while(fread(&reg, sizeof(PaqueteDeViaje), 1, pFile) == 1){
      if (reg.getIdPaquete() == idPaquete){
         fclose(pFile);
         return posicion;
      }
      posicion++;
   }

   fclose(pFile);
   return -1;
}

void modificarCuposOcupados(int cuposOcupados){

}
