#include "reservaArchivo.h"

ReservaArchivo::ReservaArchivo(){
  _nombreArchivo = "reserva.dat";
}

ReservaArchivo::ReservaArchivo(std::string nombreArchivo){
    _nombreArchivo=nombreArchivo;
}

int ReservaArchivo::buscar(int idReserva){
   FILE *pFile;
   Reserva reg;
   int posicion = 0;
   pFile = fopen(_nombreArchivo.c_str(), "rb");

   if (pFile == nullptr){
      return -2;
   }

   while(fread(&reg, sizeof(Reserva), 1, pFile) == 1){
      if (reg.getIdReserva() == idReserva){
         fclose(pFile);
         return posicion;
      }
      posicion++;
   }

   fclose(pFile);
   return -1;
}

bool ReservaArchivo::guardar(Reserva registro){
  FILE *pFile;
  bool result;

  pFile = fopen(_nombreArchivo.c_str(), "ab");

  if(pFile == nullptr){
    return false;
  }

  result = fwrite(&registro, sizeof(Reserva), 1, pFile);

  fclose(pFile);

  return result;
}

bool ReservaArchivo::guardar(Reserva registro, int posicion){
   FILE *pFile;
   bool result;
   pFile = fopen(_nombreArchivo.c_str(), "rb+");
   if (pFile == nullptr){
      return false;
   }
   fseek(pFile, posicion * sizeof(Reserva) , SEEK_SET);
   result = fwrite(&registro, sizeof(Reserva), 1, pFile);
   fclose(pFile);
   return result;

}

int ReservaArchivo::getCantidadRegistros(){
  int total, cantidad;
  FILE* pFile;
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  if(pFile == nullptr){
    return 0;
  }
  fseek(pFile, 0, SEEK_END);
  total = ftell(pFile);
  cantidad = total / sizeof(Reserva);
  fclose(pFile);
  return cantidad;


}

Reserva ReservaArchivo::leer(int pos){
  FILE *pFile;
  Reserva reg;
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  if(pFile == nullptr){
    return reg;
  }
  fseek(pFile, sizeof(Reserva) * pos, SEEK_SET);
  fread(&reg, sizeof(Reserva), 1, pFile);
  fclose(pFile);
  return reg;
}
