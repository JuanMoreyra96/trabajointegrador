#include <iostream>
#include <string>
#include "fechaHora.h"
#include "reserva.h"
#include "reservaArchivo.h"
#include "reservaManager.h"
using namespace std;


void ReservaManager::CargarReserva(){

    Reserva reserva;
    ReservaArchivo pArchivo;

    int idReserva, idCliente, idPaquete, cantidadViajeros,dia, mes, anio, hora, minuto;
    FechaHora fecha;
    float precioTotal;
    bool deudaCancelada;

    cout << "Ingrese ID de reserva: ";
    cin >> idReserva;

    cout << "Ingrese ID de cliente: ";
    cin >> idCliente;

    cout << "Ingrese ID de paquete: ";
    cin >> idPaquete;

    cout << "Ingrese la cantidad de viajeros: ";
    cin >> cantidadViajeros;

    cout << "Ingrese la fecha de la reserva: "; // podemos tomar la hora y el dia actual y guardarlo automaticamente
    cout<<"Ingrese la fecha de regreso: ";
    cout<<"Dia: ";
    cin>> dia;
    cout<<"Mes: ";
    cin>> mes;
    cout<<"Anio: ";
    cin>> anio;
    cout<<"Hora: ";
    cin>>hora;
    cout<<"Minutos: ";
    cin>>minuto;
    fecha = FechaHora(dia, mes, anio, hora, minuto);

    cout << "Ingrese el precio del paquete: ";
    cin >> precioTotal;

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
