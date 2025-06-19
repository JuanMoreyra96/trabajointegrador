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
#include "paquetedeviajemanager.h"
#include "validaciones.h"
#include <iomanip>
using namespace std;


void ReservaManager::CargarReserva(){
    PaqueteDeViajeManager paqueteManager;
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
    Validaciones validar;
    // CLIENTE
    do {
    cout << "Ingrese DNI del cliente: ";
    cin >> dniCliente;

    if (!validar.validarCadenaDeNumeros(dniCliente)) {
        cout << "El DNI debe contener solo n�meros. Ingrese nuevamente." << endl;
        pos = -1;
    } else {
        pos = cArchivo.buscar(dniCliente);
        if (pos == -1) {
            cout << "No existe un cliente con ese DNI. Ingrese otro." << endl;
        }
    }

    } while (pos == -1);

    cliente = cArchivo.leer(pos);
    idCliente = cliente.getidCliente();
    //MOSTRAMOS SEGUN BUSQUEDA
    paqueteManager.buscarPaquetePorDestino(true);
    // PAQUETE
    do {
    cout << "Ingrese ID de paquete (solo aquellos con fecha de salida futura): ";
    cin >> idPaquete;

    pos = paqueteArchivo.buscar(idPaquete);

    if (pos == -1) {
        cout << "No existe un paquete con ese ID. Ingrese otro." << endl;
    }

        paquete = paqueteArchivo.leer(pos);  // Leer el paquete solo si existe

      // Validar que la fecha del paquete sea futura
        if (!validar.validarFechaProxima(
            paquete.getFechaSalida().getDia(),
            paquete.getFechaSalida().getMes(),
            paquete.getFechaSalida().getAnio(),
            paquete.getFechaSalida().getHora(),
            paquete.getFechaSalida().getMinuto())) {

        cout << "La fecha de salida del paquete ya ha pasado. Ingrese un ID de paquete futuro." << endl;
        pos = -1;  // Para forzar que el bucle vuelva a pedir un ID
    }

    } while (pos == -1);

    int ocupados = paquete.getCuposOcupados();
    idPaquete = paquete.getIdPaquete();

    // CUPOS
    do{
    cout << "Ingrese la cantidad de viajeros: ";
    cantidadViajeros = validar.pedirNumero();
      if(!validar.validarIntPositivo(cantidadViajeros)){
        cout<<"Ingrese un numero valido."<<endl;
        }else{
    cupos = paquete.getTotalCupos() - paquete.getCuposOcupados() - cantidadViajeros;
    int cuposLibres = paquete.getTotalCupos() - paquete.getCuposOcupados();
    if (cupos < 0){
        cout << "Solo quedan " << cuposLibres << " cupos libres." << endl;
        }
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
    }

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
 cout << left
         << setw(10) << "ID"
         << setw(12) << "Cliente"
         << setw(12) << "Paquete"
         << setw(20) << "Cant. Viajeros"
         << setw(15) << "Fecha"
         << setw(15) << "Precio Total"
         << setw(18) << "Deuda"
         << endl;

    cout << string(100, '-') << endl;
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
 cout << left
         << setw(10) << "ID"
         << setw(12) << "Cliente"
         << setw(12) << "Paquete"
         << setw(20) << "Cant. Viajeros"
         << setw(15) << "Fecha"
         << setw(15) << "Precio Total"
         << setw(18) << "Deuda"
         << endl;

    cout << string(100, '-') << endl;
    for(int i=0; i<cantidadRegistros; i++){
        registro = pArchivo.leer(i);
        if(registro.getDeudaCancelada()){
        registro.Mostrar();
        }
    }
}

void ReservaManager::listarTodasAlfabeticamentePorDestino(){
    ReservaArchivo rArchivo;
    Reserva registroReserva;
    PaqueteDeViajeArchivo pArchivo;
    PaqueteDeViaje registro;
    int cantidadRegistros = rArchivo.getCantidadRegistros();
    Reserva *vecReg = nullptr;
    string *nombresDestinos = nullptr;
    vecReg = new Reserva[cantidadRegistros];
    nombresDestinos = new string[cantidadRegistros];
    if( vecReg == nullptr || nombresDestinos == nullptr) {
        cout << "Ocurrio un error inesperado: " << endl;
        return;
    }

    for(int i=0; i<cantidadRegistros; i++){
        vecReg[i] = rArchivo.leer(i);
        int idPaquete = vecReg[i].getIidPaquete();
        int posicion = pArchivo.buscar(idPaquete);
        registro = pArchivo.leer(posicion);
        nombresDestinos[i] = registro.getDestino();
    }

    for (int i = 1; i < cantidadRegistros; i++) {
        Reserva reservaAux = vecReg[i];
        string destinoAux = nombresDestinos[i];
        int j = i - 1;

        while (j >= 0 && destinoAux < nombresDestinos[j]) {
            vecReg[j + 1] = vecReg[j];
            nombresDestinos[j+1]=nombresDestinos[j];
            j--;
        }
        nombresDestinos[j+1] = destinoAux;
        vecReg[j + 1] = reservaAux;
    }
  //COLUMNAS

            cout << left
         << setw(10) << "DESTINO"
         << setw(10) << "ID"
         << setw(12) << "Cliente"
         << setw(12) << "Paquete"
         << setw(20) << "Cant. Viajeros"
         << setw(15) << "Fecha"
         << setw(15) << "Precio Total"
         << setw(18) << "Deuda"
         << endl;
  cout << string(99, '-') << endl;

    for(int i=0; i<cantidadRegistros; i++){
       cout << setw(10) << left << nombresDestinos[i];
        vecReg[i].Mostrar();
    }

    delete []nombresDestinos;
    delete []vecReg;
}

 void ReservaManager::BuscarReservasDeCliente(){
    clientearchivo cArchivo;
    Cliente registro;
    Validaciones validar;
    ReservaArchivo rArchivo;
    Reserva registroReserva;
    int resultado, cantidadRegistros = rArchivo.getCantidadRegistros();
    string dni;

    do {
        cout << "Ingrese DNI del cliente: ";
        cin >> dni;

        if (!validar.validarCadenaDeNumeros(dni)) {
            cout << "❌ El DNI debe contener solo números. Ingrese nuevamente." << endl;
            resultado = -1;
        } else {
            resultado = cArchivo.buscar(dni);
            if (resultado == -1) {
                cout << "No existe un cliente con ese DNI. Ingrese otro." << endl;
            }
        }
    } while (resultado == -1);

    registro = cArchivo.leer(resultado);
    int idCliente = registro.getidCliente();
    string nombre = registro.getNombre();
    string apellido = registro.getApellido();
    bool encontrado = false;

    cout << "CLIENTE: " << nombre << " " << apellido << "\n" << endl;
    cout << left
         << setw(10) << "ID"
         << setw(12) << "Cliente"
         << setw(12) << "Paquete"
         << setw(20) << "Cant. Viajeros"
         << setw(15) << "Fecha"
         << setw(15) << "Precio Total"
         << setw(18) << "Deuda"
         << endl;

    cout << string(100, '-') << endl;

    for(int i = 0; i < cantidadRegistros; i++) {
        registroReserva = rArchivo.leer(i);
        if (registroReserva.getIdCliente() == idCliente) {
            registroReserva.Mostrar();
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No hay reservas del cliente buscado." << endl;
    }

    cout << endl;
}


 void ReservaManager::ListarReservasDeudaNoCancelada(){
 ReservaArchivo pArchivo;
    Reserva registro;
    int cantidadRegistros = pArchivo.getCantidadRegistros();
    cout << left
         << setw(10) << "ID"
         << setw(12) << "Cliente"
         << setw(12) << "Paquete"
         << setw(20) << "Cant. Viajeros"
         << setw(15) << "Fecha"
         << setw(15) << "Precio Total"
         << setw(18) << "Deuda"
         << endl;

    cout << string(100, '-') << endl;
    for(int i=0; i<cantidadRegistros; i++){
        registro = pArchivo.leer(i);
        if(!registro.getDeudaCancelada()){
        registro.Mostrar();
        }
    }
   }

 void ReservaManager::buscarReservasDeUnDestino(){
    PaqueteDeViajeArchivo pArchivo;
    ReservaArchivo rArchivo;
    Reserva registroReserva;
    string destino;
    Validaciones validar;
    int cantidadRegistros = rArchivo.getCantidadRegistros();
    int cantidadRegistrosPaquete = pArchivo.getCantidadRegistros();
    bool encontrado=false;
    do{
    cout<<"Ingrese el destino: ";
    cin.ignore();
    getline(cin, destino);
    if(!validar.validarCadenaDeLetras(destino) || !validar.validarLongitudCadena(destino, 2, 20)){
        cout<<"La busquda debe contener entre 2 y 20 caracteres."<<endl;
    }
    }
    while(!validar.validarCadenaDeLetras(destino) || !validar.validarLongitudCadena(destino, 2, 20));

    PaqueteDeViaje* vecPaquetes = new PaqueteDeViaje[cantidadRegistrosPaquete];

    if (vecPaquetes == nullptr) {
        cout << "No hay memoria suficiente." << endl;
        delete[] vecPaquetes;
        return;
    }
    pArchivo.guardarPaquetesPorDestino(vecPaquetes, cantidadRegistrosPaquete, destino);

    cout << left
         << setw(10) << "ID"
         << setw(12) << "Cliente"
         << setw(12) << "Paquete"
         << setw(20) << "Cant. Viajeros"
         << setw(15) << "Fecha"
         << setw(15) << "Precio Total"
         << setw(18) << "Deuda"
         << endl;

    cout << string(100, '-') << endl;

    for (int i = 0; i < cantidadRegistros; i++) {
    registroReserva = rArchivo.leer(i);
    int idReservaPaquete = registroReserva.getIidPaquete();

    for (int j = 0; j < cantidadRegistrosPaquete; j++) {
        if (vecPaquetes[j].getIdPaquete() == idReservaPaquete) {
            registroReserva.Mostrar();
            encontrado = true;
            }
        }
    }

    if (!encontrado) {
        cout << "No se encontraron reservas para el destino ingresado." << endl;
        }
 }

void ReservaManager::buscarReservasParaIdPaquete() {
    PaqueteDeViajeArchivo paqueteArchivo;
    PaqueteDeViaje paquete;
    ReservaArchivo rArchivo;
    Reserva registroReserva;
    int cantidadRegistros = rArchivo.getCantidadRegistros();
    int idPaquete, pos;
    bool encontrado = false;

    do {
        cout << "Ingrese ID de paquete: ";
        cin >> idPaquete;

        pos = paqueteArchivo.buscar(idPaquete);

        if (pos == -1) {
            cout << "No existe un paquete con ese ID. Ingrese otro." << endl;
        } else {
            paquete = paqueteArchivo.leer(pos);  // Leer solo si existe
        }

    } while (pos == -1);

    cout << left
         << setw(10) << "ID"
         << setw(12) << "Cliente"
         << setw(12) << "Paquete"
         << setw(20) << "Cant. Viajeros"
         << setw(15) << "Fecha"
         << setw(15) << "Precio Total"
         << setw(18) << "Deuda"
         << endl;

    cout << string(100, '-') << endl;

    for (int i = 0; i < cantidadRegistros; i++) {
        registroReserva = rArchivo.leer(i);
        if (registroReserva.getIidPaquete() == idPaquete) {
            registroReserva.Mostrar();
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No hay reservas registradas para ese paquete." << endl;
    }
}
