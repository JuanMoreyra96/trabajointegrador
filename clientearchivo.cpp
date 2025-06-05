#include "clientearchivo.h"

clientearchivo::clientearchivo(){
_nombrearchivo = "clientes.dat";
}
clientearchivo::clientearchivo(std::string nombrearchivo){
_nombrearchivo = nombrearchivo;
}

bool clientearchivo::guardar(Cliente registro){
 FILE *pFile;
 bool result;
 pFile = fopen(_nombrearchivo.c_str(),"ab");

 if(pFile==nullptr){

    return false;
 }
 result = fwrite(&registro, sizeof(Cliente),1,pFile);
    fclose(pFile);

 return result;
}

int clientearchivo::buscar(int idCliente){
   FILE *pFile;
   Cliente registro;
   int posicion = 0;

   pFile = fopen(_nombrearchivo.c_str(), "rb");

   if (pFile == nullptr){
      return -2;
   }

   while(fread(&registro, sizeof(Cliente), 1, pFile) == 1){
      if (registro.getidCliente() == idCliente){
         fclose(pFile);
         return posicion;
      }
      posicion++;
   }

   fclose(pFile);
   return -1;
}

int clientearchivo::buscar(std::string dniCliente){
   FILE *pFile;
   Cliente registro;
   int posicion = 0;

   pFile = fopen(_nombrearchivo.c_str(), "rb");

   if (pFile == nullptr){
      return -2;
   }

   while(fread(&registro, sizeof(Cliente), 1, pFile) == 1){
      if (registro.getDni() == dniCliente){
         fclose(pFile);
         return posicion;
      }
      posicion++;
   }

   fclose(pFile);
   return -1;
}

bool clientearchivo::guardar(Cliente registro, int posicion){
  FILE *pFile;
  bool result;
   pFile = fopen(_nombrearchivo.c_str(), "rb+");
   if (pFile == nullptr){
      return false;
   }
   fseek(pFile, posicion * sizeof(Cliente) , SEEK_SET);
   result = fwrite(&registro, sizeof(Cliente), 1, pFile);
   fclose(pFile);
   return result;
}
int clientearchivo::getCantidadRegistros(){
  int total, cantidad;
  FILE* pFile;
  pFile = fopen(_nombrearchivo.c_str(), "rb");
  if(pFile == nullptr){
    return 0;
  }
  fseek(pFile, 0, SEEK_END);
  total = ftell(pFile);
  cantidad = total / sizeof(Cliente);
  fclose(pFile);
  return cantidad;
}
Cliente clientearchivo::leer(int pos){
  FILE *pFile;
  Cliente registro;
  pFile = fopen(_nombrearchivo.c_str(), "rb");
  if(pFile == nullptr){
    return registro;
  }
  fseek(pFile, sizeof(Cliente) * pos, SEEK_SET);
  fread(&registro, sizeof(Cliente), 1, pFile);
  fclose(pFile);
  return registro;
}

