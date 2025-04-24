#include "clientearchivo.h"

clientearchivo::clientearchivo(){
_nombrearchivo = "clientes.dat";
}
clientearchivo::clientearchivo(std::string nombrearchivo){
_nombrearchivo = nombrearchivo;
}

bool clientearchivo::guardar(cliente registro){

 FILE *pFile;
 bool result;
 pFile = fopen(_nombrearchivo.c_str(),"ab");

 if(pFile==nullptr){

    return false;
 }
 result = fwrite(&registro, sizeof(cliente),1,pFile);
    fclose(pFile);

 return result;





}
