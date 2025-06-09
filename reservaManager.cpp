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
    int ocupados = paquete.getCuposOcupados();
    cout << "ocupados= " << ocupados << endl;
    idPaquete = paquete.getIdPaquete();


    // CUPOS
    do{
    cout << "Ingrese la cantidad de viajeros: ";
    cin >> cantidadViajeros;

    cupos = paquete.getTotalCupos() - paquete.getCuposOcupados() - cantidadViajeros;
    int cuposLibres = paquete.getTotalCupos() - paquete.getCuposOcupados();
    if (cupos < 0){
        cout << "Solo quedan " << cuposLibres << " cupos libres." << endl;
        }
    } while (cupos < 0);
    int suma = paquete.getCuposOcupados() + cantidadViajeros;
    paquete.setCuposOcupados(suma);

     if(paqueteArchivo.guardar(paquete, pos))
    {
        cout << "Se han actualizado los cupos ocupados! (" << suma << ")" << endl;
        }
    else
    {
        cout << "Hubo un error inesperado." << endl;


    // FECHA
    fecha = FechaHora();


    // PRECIO RESERVA
    int posicion = paqueteArchivo.buscar(idPaquete);
    paquete = paqueteArchivo.leer(posicion);
    float precioIndividual = paquete.getPrecio();
    precioTotal = precioIndividual * cantidadViajeros;
    deudaCancelada=0;

    // GUARDAR LA RESERVA
    reserva=Reserva(idReserva, idCliente, idPaquete, cantidadViajeros, fecha, precioTotal, deudaCancelada);

    }

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
