#include <iostream>
#include <string>
#include "pagoManager.h"
#include "fechaHora.h"
#include "reserva.h"
#include "reservaArchivo.h"
#include "reservaManager.h"
#include "paquetedeviajearchivo.h"
#include "paquetedeviaje.h"
#include "clientearchivo.h"
#include "cliente.h"
#include "validaciones.h"
#include "pago.h"
#include "pagoArchivo.h"
using namespace std;

  void PagoManager::CargarPago(){
    Pago pago;
    PagoArchivo pArchivo;
    ReservaArchivo archivoReserva;
    Validaciones validar;

    int idPago, idReserva;
    float importe;
    FechaHora fecha;

    int cantRegistros = pArchivo.getCantidadRegistros();
    idPago = cantRegistros+1;

    int resultado;
    do {
    cout << "Ingrese el ID de la reserva: ";
    cin >> idReserva;

    resultado = archivoReserva.buscar(idReserva);
    if (resultado == -1 || resultado == -2){
        cout << "No existe una reserva con ese ID." << endl;
    }

    } while (resultado == -1 || resultado == -2);

    // validar cuanto le falta pagar para pagar el total

    do{
   cout << "Ingrese el importe pagado: ";
    importe = validar.pedirNumeroFloat();
    if(!validar.validarFloatPositivo(importe)){
        cout<<"Debe ingresar un importe valido."<<endl;
    }
    }while(!validar.validarFloatPositivo(importe));

    pago = Pago(idPago, idReserva, importe, fecha);
    // validar si hay mas pagos para la misma reserva y si la misma esta cancelada.
    if(pArchivo.guardar(pago))
    {
    cout << "Se guardo correctamente!" << endl;
    }
    else
    {
    cout << "Hubo un error inesperado." << endl;
    }
}


  void ListarPagosDeCliente(int dni){

  }

void PagoManager::MostrarCantidadRegistros(){
    PagoArchivo pArchivo;
    int cantidadRegistros = pArchivo.getCantidadRegistros();
    cout << "La cantidad de registros es: " << cantidadRegistros << endl;
}
void PagoManager::ListarTodos(){
  PagoArchivo pArchivo;
  Pago registro;
  int cantidadRegistros = pArchivo.getCantidadRegistros();

  for(int i=0; i<cantidadRegistros; i++)
  {
    registro = pArchivo.leer(i);
    registro.Mostrar();
  }
}
