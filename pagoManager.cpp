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
#include <iomanip>
using namespace std;

  void PagoManager::CargarPago(){
    Pago pago;
    PagoArchivo pArchivo;
    Reserva reservaAPagar;
    ReservaArchivo archivoReserva;
    Validaciones validar;

    int idPago, idReserva;
    float importe;
    FechaHora fecha;

    int cantRegistros = pArchivo.getCantidadRegistros();
    idPago = cantRegistros+1;

    int posicion;
    do {
    cout << "Ingrese el ID de la reserva: ";
    cin >> idReserva;

    posicion = archivoReserva.buscar(idReserva);
    if (posicion == -1 || posicion == -2){
        cout << "No existe una reserva con ese ID." << endl;
    }

    } while (posicion == -1 || posicion == -2);
    // validar cuanto le falta pagar para pagar el total

    float precioTotal;
    reservaAPagar = archivoReserva.leer(posicion);
    if(reservaAPagar.getDeudaCancelada()){
      cout << "Ya se pago el total de esta reserva. " << endl;
    }
    else
        {
         precioTotal = reservaAPagar.getPrecioTotal();
    float importesPagados;

    importesPagados = pArchivo.sumarPagosPorReserva(idReserva);
    float faltaPagar;
    faltaPagar = precioTotal - importesPagados;
    cout << "El precio total de la reserva es $" << precioTotal << endl;
    cout << "El cliente adeuda $" << faltaPagar << endl;

    do{
    cout << "Ingrese el importe recibido: ";
    importe = validar.pedirNumeroFloat();
    if(!validar.validarFloatPositivo(importe) || importe > faltaPagar){
        cout<<"Debe ingresar un importe valido."<<endl;
    }
    }while(!validar.validarFloatPositivo(importe)|| importe > faltaPagar );

    pago = Pago(idPago, idReserva, importe, fecha);
    if(pArchivo.guardar(pago))
    {
    cout << "Se guardo correctamente!" << endl;

    if(precioTotal == importesPagados + importe){
        reservaAPagar.setDeudaCancelada(true);
        archivoReserva.guardar(reservaAPagar, posicion);
    }
    }
    else
    {
    cout << "Hubo un error inesperado." << endl;
    }
    }

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
  cout << left
         << setw(10) << "ID PAGO"
         << setw(12) << "ID RESERVA"
         << setw(10) << "IMPORTE"
         << "FECHA DE PAGO" << endl;

  cout << string(50, '-') << endl;
  for(int i=0; i<cantidadRegistros; i++)
  {
    registro = pArchivo.leer(i);
    registro.Mostrar();
  }
}

void PagoManager::ListarOrdenadosPorIDCliente() {
    PagoArchivo pArchivo;
    Pago registro;
    ReservaArchivo rArchivo;
    Reserva registroReserva;
    clientearchivo cArchivo;
    Cliente registroCliente;

    int cantidadRegistros = pArchivo.getCantidadRegistros();
    int cantidadRegistrosReserva = rArchivo.getCantidadRegistros();
    int cantidadRegistrosCliente = cArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidadRegistrosCliente; i++) {
        registroCliente = cArchivo.leer(i);
        int idCliente = registroCliente.getidCliente();
        string dni = registroCliente.getDni();
        bool tienePagos = false;  // <--- FLAG

        cout << "CLIENTE: " << idCliente << " . DNI: " << dni << endl;
        cout << left
             << setw(10) << "ID PAGO"
             << setw(12) << "ID RESERVA"
             << setw(10) << "IMPORTE"
             << "FECHA DE PAGO" << endl;

        cout << string(50, '-') << endl;

        for (int j = 0; j < cantidadRegistrosReserva; j++) {
            registroReserva = rArchivo.leer(j);
            if (registroReserva.getIdCliente() == idCliente) {
                int idReserva = registroReserva.getIdReserva();

                for (int k = 0; k < cantidadRegistros; k++) {
                    registro = pArchivo.leer(k);
                    if (registro.getIdReserva() == idReserva) {
                        registro.Mostrar();
                        tienePagos = true;  // <--- Se encontró un pago
                    }
                }
            }
        }

        if (!tienePagos) {
            cout << "Este cliente no tiene pagos registrados." << endl;
        }

        cout << endl;
    }
}
