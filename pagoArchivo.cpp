#include "pagoArchivo.h"
#include <iostream>
using namespace std;


PagoArchivo::PagoArchivo(){
  _nombreArchivo = "pagos.dat";
}

PagoArchivo::PagoArchivo(std::string nombreArchivo){
    _nombreArchivo=nombreArchivo;
}

int PagoArchivo::buscar(int idPago){
   FILE *pFile;
   Pago reg;
   int posicion = 0;
   pFile = fopen(_nombreArchivo.c_str(), "rb");

   if (pFile == nullptr){
      return -2;
   }

   while(fread(&reg, sizeof(Pago), 1, pFile) == 1){
      if (reg.getIdPago() == idPago){
         fclose(pFile);
         return posicion;
      }
      posicion++;
   }

   fclose(pFile);
   return -1;
}

float PagoArchivo::sumarPagosPorReserva(int idReserva){
   FILE *pFile;
   Pago reg;
   float suma = 0;
   pFile = fopen(_nombreArchivo.c_str(), "ab+");

   if (pFile == nullptr){
      cout << "No se pudo abrir el archivo.";
      return -2;
   }

   while(fread(&reg, sizeof(Pago), 1, pFile) == 1){
      if (reg.getIdReserva() == idReserva){
         suma += reg.getImporte();
      }
   }
   fclose(pFile);
   return suma;
}

bool PagoArchivo::guardar(Pago registro){
  FILE *pFile;
  bool result;

  pFile = fopen(_nombreArchivo.c_str(), "ab");

  if(pFile == nullptr){
    return false;
  }

  result = fwrite(&registro, sizeof(Pago), 1, pFile);

  fclose(pFile);

  return result;
}

bool PagoArchivo::guardar(Pago registro, int posicion){
   FILE *pFile;
   bool result;
   pFile = fopen(_nombreArchivo.c_str(), "rb+");
   if (pFile == nullptr){
      return false;
   }
   fseek(pFile, posicion * sizeof(Pago) , SEEK_SET);
   result = fwrite(&registro, sizeof(Pago), 1, pFile);
   fclose(pFile);
   return result;

}

int PagoArchivo::getCantidadRegistros(){
  int total, cantidad;
  FILE* pFile;
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  if(pFile == nullptr){
    return 0;
  }
  fseek(pFile, 0, SEEK_END);
  total = ftell(pFile);
  cantidad = total / sizeof(Pago);
  fclose(pFile);
  return cantidad;
}

Pago PagoArchivo::leer(int pos){
  FILE *pFile;
  Pago reg;
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  if(pFile == nullptr){
    return reg;
  }
  fseek(pFile, sizeof(Pago) * pos, SEEK_SET);
  fread(&reg, sizeof(Pago), 1, pFile);
  fclose(pFile);
  return reg;
}
