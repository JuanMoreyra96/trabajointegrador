#include <iostream>
#include <string>
#include "fechaHora.h"
#include "reserva.h"
#include "reservaArchivo.h"
#include "reservaManager.h"
#include "paquetedeviajearchivo.h"
#include "paquetedeviaje.h"
using namespace std;


void ReservaManager::CargarReserva(){

    Reserva reserva;
    ReservaArchivo pArchivo;
    PaqueteDeViajeArchivo paqueteArchivo;
    PaqueteDeViaje paquete;
    int idReserva, idCliente, idPaquete, cantidadViajeros;
    FechaHora fecha;
    float precioTotal;
    bool deudaCancelada;

    int cantRegistros = pArchivo.getCantidadRegistros();
    idReserva = cantRegistros+1;

    cout << "Ingrese ID de cliente: ";
    cin >> idCliente;
    // validar que el cliente existe
    cout << "Ingrese ID de paquete: ";
    cin >> idPaquete;

    cout << "Ingrese la cantidad de viajeros: ";
    cin >> cantidadViajeros;
    //HACER METODO QUE RECUPERE FECHA Y HORA ACTUAL
    fecha = FechaHora();
    //manejo de precio
    int posicion = paqueteArchivo.buscar(idPaquete);
    paquete = paqueteArchivo.leer(posicion);
    float precioIndividual = paquete.getPrecio();
    precioTotal = precioIndividual * cantidadViajeros;
    cout << "Cancela la deuda? ";
    cin >> deudaCancelada;

    reserva=Reserva(idReserva, idCliente, idPaquete, cantidadViajeros, fecha, precioTotal, deudaCancelada);
    if(pArchivo.guardar(reserva)){
        cout << "Se guardo correctamente!" << endl;
    }
    else{
        cout << "Hubo un error inesperado." << endl;
    }
}


void ReservaManager::MostrarCantidadRegistros(){
    ReservaArchivo pArchivo;
    int cantidadRegistros = pArchivo.getCantidadRegistros();
    cout << "La cantidad de registros son: " << cantidadRegistros << endl;
}

void ReservaManager::ListarTodos(){
  ReservaArchivo pArchivo;
  Reserva registro;
  int cantidadRegistros = pArchivo.getCantidadRegistros();

  for(int i=0; i<cantidadRegistros; i++)
  {
    registro = pArchivo.leer(i);
    registro.Mostrar();
  }
}

void ReservaManager::ListarReservasDeudaCancelada(){
    ReservaArchivo pArchivo;
    Reserva registro;
    int cantidadRegistros = pArchivo.getCantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++){
        registro = pArchivo.leer(i);
        if(registro.getDeudaCancelada()){
        registro.Mostrar();
        }
    }
}

void ReservaManager::ModificarCantidadViajeros(){
    //FALTA DESARROLLAR
}
