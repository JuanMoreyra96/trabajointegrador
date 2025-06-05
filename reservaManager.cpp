#include <iostream>
#include <string>
#include "fechaHora.h"
#include "reserva.h"
#include "reservaArchivo.h"
#include "reservaManager.h"
#include "paquetedeviajearchivo.h"
#include "paquetedeviaje.h"
#include "clientearchivo.h"
#include "cliente.h"
using namespace std;


void ReservaManager::CargarReserva(){

    Cliente cliente;
    clientearchivo cArchivo;
    Reserva reserva;
    ReservaArchivo pArchivo;
    PaqueteDeViajeArchivo paqueteArchivo;
    PaqueteDeViaje paquete;
    int idReserva, idCliente, idPaquete, cantidadViajeros, pos=0, cupos =0;
    FechaHora fecha;
    float precioTotal;
    bool deudaCancelada;
    string dniCliente;

    int cantRegistros = pArchivo.getCantidadRegistros();
    idReserva = cantRegistros+1;

    // CLIENTE
    do {
    cout << "Ingrese DNI del cliente: ";
    cin >> dniCliente;

    pos = cArchivo.buscar(dniCliente);
    if (pos==-1){
    cout << "No existe un cliente con ese DNI. Ingrese otro." << endl;
    }
    }  while (pos == -1);
    cliente = cArchivo.leer(pos);
    idCliente = cliente.getidCliente();

    // PAQUETE
    do {
    cout << "Ingrese ID de paquete: ";
    cin >> idPaquete;

    pos = paqueteArchivo.buscar(idPaquete);
    if (pos==-1){
    cout << "No existe un paquete con ese ID. Ingrese otro." << endl;
    }
    }  while (pos == -1);
    paquete = paqueteArchivo.leer(pos);
    idPaquete = paquete.getIdPaquete();


    // CUPOS
    do{
    cout << "Ingrese la cantidad de viajeros: ";
    cin >> cantidadViajeros;

    cupos = paquete.getTotalCupos() - paquete.getCuposOcupados() - cantidadViajeros;
    if (cupos < 0){
    cout << "No quedan suficientes cupos." << endl;
    }

    } while (cupos < 0);



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
    //paquete.setCuposOcupados(paquete.getCuposOcupados()+cantidadViajeros);
    int suma = paquete.getCuposOcupados() + cantidadViajeros;
    paqueteArchivo.
    paquete.setCuposOcupados(suma);
    cout << "suma" << suma << endl;
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
