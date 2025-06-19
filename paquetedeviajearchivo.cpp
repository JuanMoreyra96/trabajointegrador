#include <iostream>
#include "Paquetedeviajearchivo.h"
#include "fechaHora.h"
#include "validaciones.h"
using namespace std;

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

std::string toUpper(std::string str) {
    for (int i = 0; str[i] != '\0'; i++) {
        // Si el caracter es una letra min�scula, lo convierte
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;  // Diferencia entre 'a' y 'A' en ASCII
        }
    }
    return str;
}


// ESTE METODO SIRVE PARA COINCIDENCIA ABSOLUTA DE CARACTERES
void PaqueteDeViajeArchivo::guardarPaquetesPorDestino(PaqueteDeViaje *v,int tam, std::string destino){
   PaqueteDeViajeArchivo pArchivo;
   PaqueteDeViaje reg;
   destino = toUpper(destino);
   int posicion;
   int cantidadRegistros = pArchivo.getCantidadRegistros();

    for(int i=0;i<cantidadRegistros;i++){
       reg = pArchivo.leer(i);
        if (toUpper(reg.getDestino()) == destino){
         v[i]=reg;
      }
    }
}
// ESTE BUSCA POR COINCIDENCIAS PARCIALES, AL COMEINZO, MEDIO O FINAL DEL TEXTO
// Para comprender, buscar como funciona substr(pos, len)
void PaqueteDeViajeArchivo::mostrarPaquetesPorDestinoParcial(std::string texto, bool soloProximos){
    FILE *pFile;
    PaqueteDeViaje reg;
    texto = toUpper(texto);
    FechaHora fechaActual;
    Validaciones validar;
    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr){
        cout << "No se pudo abrir el archivo";
        return;
    }

    while(fread(&reg, sizeof(PaqueteDeViaje), 1, pFile) == 1){
        std::string destinoActual = toUpper(reg.getDestino());

        bool coincide = false;
        int lenTexto = texto.size();
        int lenDestino = destinoActual.size();

        for (int i = 0; i <= lenDestino - lenTexto; i++) {
            if (destinoActual.substr(i, lenTexto) == texto) {
                coincide = true;
                break;
            }
        }
        if(soloProximos){
            if(validar.validarFechaProxima(
            reg.getFechaSalida().getDia(),
            reg.getFechaSalida().getMes(),
            reg.getFechaSalida().getAnio(),
            reg.getFechaSalida().getHora(),
            reg.getFechaSalida().getMinuto()
            )
            && coincide
            )
            {
             reg.Mostrar();
            }
        }else{
        if (coincide) {
            reg.Mostrar();
        }
        }
    }
    fclose(pFile);
}

void PaqueteDeViajeArchivo::buscarPorRangoPrecios(float precioMenor, float precioMayor){
   FILE *pFile;
   PaqueteDeViaje reg;
   float precio;
   pFile = fopen(_nombreArchivo.c_str(), "rb");
   if (pFile == nullptr){
      cout << "No se pudo abrir el archivo";
      return;
   }

   while(fread(&reg, sizeof(PaqueteDeViaje), 1, pFile) == 1){
      precio = reg.getPrecio();
      if (precio >= precioMenor && precio <= precioMayor){
         reg.Mostrar();
      }
   }
   fclose(pFile);
}

void PaqueteDeViajeArchivo::buscarRegistroPorFechaSalida(FechaHora fecha){
   FILE *pFile;
   PaqueteDeViaje reg;
   pFile = fopen(_nombreArchivo.c_str(), "rb");
   if (pFile == nullptr){
      cout << "No se pudo abrir el archivo";
      return;
   }

   while(fread(&reg, sizeof(PaqueteDeViaje), 1, pFile) == 1){
     if(reg.getFechaSalida().getDia() == fecha.getDia()
        && reg.getFechaSalida().getMes() == fecha.getMes()
        && reg.getFechaSalida().getAnio() == fecha.getAnio()
        ){
        reg.Mostrar();
        }
        }
        fclose(pFile);
}


void PaqueteDeViajeArchivo::buscarRegistroPorFechaRegreso(FechaHora fecha){
   FILE *pFile;
   PaqueteDeViaje reg;
   pFile = fopen(_nombreArchivo.c_str(), "rb");
   if (pFile == nullptr){
      cout << "No se pudo abrir el archivo";
      return;
   }

   while(fread(&reg, sizeof(PaqueteDeViaje), 1, pFile) == 1){
     if(reg.getFechaRegreso().getDia() == fecha.getDia()
        && reg.getFechaRegreso().getMes() == fecha.getMes()
        && reg.getFechaRegreso().getAnio() == fecha.getAnio()
        ){
        reg.Mostrar();
        }
        }
        fclose(pFile);
}

void PaqueteDeViajeArchivo::mostrarPaquetesPorTransporte(std::string transporte){
   FILE *pFile;
   PaqueteDeViaje reg;
   transporte = toUpper(transporte);

   pFile = fopen(_nombreArchivo.c_str(), "rb");
   if (pFile == nullptr){
      cout << "No se pudo abrir el archivo";
      return;
   }

   while(fread(&reg, sizeof(PaqueteDeViaje), 1, pFile) == 1){
      if (toUpper(reg.getTipoTransporte()) == transporte){
         reg.Mostrar();
      }
   }
   fclose(pFile);
}
