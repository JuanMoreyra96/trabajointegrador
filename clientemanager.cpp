#include <iostream>
#include <string>
#include "cliente.h"
#include "clientearchivo.h"
#include "clientemanager.h"
#include "validaciones.h"
#include <iomanip>
using namespace std;

void clientemanager::cargarcliente()
{
    Cliente nuevoCliente;
    clientearchivo pArchivo;
    Validaciones validar;
    int idCliente;
    string nombre,apellido,direccion,email,dni, celular;
    bool estado;

    int cantRegistros = pArchivo.getCantidadRegistros();
    idCliente = cantRegistros+1;
    // Aqui pedimos y verificamos que no exista un cliente con el mismo DNI ya registrado.
    do {
    cout << "Ingrese DNI del cliente: ";
    cin >> dni;

    int resultado = pArchivo.buscar(dni);
    if (resultado == -1 || resultado == -2) break;

    cout << "Ya existe un cliente con ese DNI. Ingrese otro." << endl;

    } while (true);

    do{
    cout << "ingrese nombre/s: ";
    cin.ignore();
    getline(cin, nombre);
    if(!validar.validarCadenaDeLetras(nombre) && !validar.validarLongitudCadena(nombre, 3, 50)){
        cout<<"El nombre debe contener entre 3 y 50 caracteres."<<endl;
    }
    }while(!validar.validarCadenaDeLetras(nombre) && !validar.validarLongitudCadena(nombre, 3, 50));


     do{
  cout << "ingrese apellido/s: ";
    getline(cin, apellido);
    if(!validar.validarCadenaDeLetras(apellido) && !validar.validarLongitudCadena(apellido, 3, 50)){
        cout<<"El apellido debe contener entre 3 y 50 caracteres."<<endl;
    }
    }while(!validar.validarCadenaDeLetras(apellido) && !validar.validarLongitudCadena(apellido, 3, 50));

     do{
    cout << "ingrese email: ";
    getline(cin, email);
    if(!validar.validarCadenaDeLetras(email) && !validar.validarLongitudCadena(email, 3, 50)){
        cout<<"El email debe contener entre 3 y 50 caracteres."<<endl;
    }
    }while(!validar.validarCadenaDeLetras(email) && !validar.validarLongitudCadena(email, 3, 50));


    do{
    cout << "ingrese celular: ";
    cin >> celular;
    if(!validar.validarLongitudCadena(celular, 3, 11)){
        cout<<"El celular debe contener entre 3 y 11 caracteres."<<endl;
    }
    }while(!validar.validarLongitudCadena(celular, 3, 11));


    //Lo dejamos en activo por defecto
    estado = true;

    nuevoCliente = Cliente(dni,nombre,apellido, email, celular, estado, idCliente);

  if(pArchivo.guardar(nuevoCliente)){
        cout << "se guardo correctamente." << endl;
  }else{
        cout << "Hubo un error al guardar." << endl;
    }
}


void clientemanager::mostrarCantidadRegistros(){
 clientearchivo pArchivo;
 int cantidadRegistros = pArchivo.getCantidadRegistros();
 cout << "La cantidad de registros son: " << cantidadRegistros << endl;
}


void clientemanager::listarTodos(){
  clientearchivo pArchivo;
  Cliente registro;
  int cantidadRegistros = pArchivo.getCantidadRegistros();
  //COLUMNAS
  cout << left
         << setw(5)  << "ID"
         << setw(12) << "DNI"
         << setw(15) << "Nombre"
         << setw(15) << "Apellido"
         << setw(25) << "Email"
         << setw(15) << "Celular"
         << setw(12) << "Estado"
         << endl;
  cout << string(99, '-') << endl;
  // FILAS
  for(int i=0; i<cantidadRegistros; i++)
  {
    registro = pArchivo.leer(i);
    registro.Mostrar();
  }
}


void clientemanager::listarTodosAlfabeticamentePorApellido(){
    clientearchivo pArchivo;
    Cliente registro;
    int cantidadRegistros = pArchivo.getCantidadRegistros();
    Cliente *vecReg = nullptr;

    vecReg = new Cliente[cantidadRegistros];
    if( vecReg == nullptr ) {
        cout << "Ocurrio un error inesperado: " << endl;
        return;
    }

    for(int i=0; i<cantidadRegistros; i++){
        vecReg[i] = pArchivo.leer(i);
    }

    for (int i = 1; i < cantidadRegistros; i++) {
        Cliente clienteAux = vecReg[i];
        int j = i - 1;

        while (j >= 0 && clienteAux.getApellido() < vecReg[j].getApellido()) {
            vecReg[j + 1] = vecReg[j];
            j--;
        }
        vecReg[j + 1] = clienteAux;
    }



  //COLUMNAS
  cout << left
         << setw(5)  << "ID"
         << setw(12) << "DNI"
         << setw(15) << "Nombre"
         << setw(15) << "Apellido"
         << setw(25) << "Email"
         << setw(15) << "Celular"
         << setw(12) << "Estado"
         << endl;
  cout << string(99, '-') << endl;

    for(int i=0; i<cantidadRegistros; i++){
        vecReg[i].Mostrar();
    }

    delete []vecReg;
}


void clientemanager::listarClientesActivos(){
  clientearchivo pArchivo;
  Cliente registro;
  int cantidadRegistros = pArchivo.getCantidadRegistros();
  //COLUMNAS
  cout << left
         << setw(5)  << "ID"
         << setw(12) << "DNI"
         << setw(15) << "Nombre"
         << setw(15) << "Apellido"
         << setw(25) << "Email"
         << setw(15) << "Celular"
         << setw(12) << "Estado"
         << endl;
  cout << string(99, '-') << endl;
  // FILAS
  for(int i=0; i<cantidadRegistros; i++)
  {
    registro = pArchivo.leer(i);
    if(registro.getEstado()){
   registro.Mostrar();
    }
  }
}


void clientemanager::listarClientesInactivos(){
  clientearchivo pArchivo;
  Cliente registro;
  int cantidadRegistros = pArchivo.getCantidadRegistros();
  //COLUMNAS
  cout << left
         << setw(5)  << "ID"
         << setw(12) << "DNI"
         << setw(15) << "Nombre"
         << setw(15) << "Apellido"
         << setw(25) << "Email"
         << setw(15) << "Celular"
         << setw(12) << "Estado"
         << endl;
  cout << string(99, '-') << endl;
  // FILAS
  for(int i=0; i<cantidadRegistros; i++)
  {
    registro = pArchivo.leer(i);
    if(!registro.getEstado()){
        registro.Mostrar();
    }
    }
}


void clientemanager::bajaLogicaCliente(){
    clientearchivo pArchivo;
    string dni;
    cout << "Ingrese el DNI del cliente a dar de baja (logica): ";
    cin >> dni;

    int pos = pArchivo.buscar(dni); // Busca la posición del cliente por ID
    if (pos == -1) {
        cout << "Cliente con ID " << dni << " no encontrado." << endl;
        return;
    }
    if (pos == -2) {
        cout << "Error al acceder al archivo de clientes." << endl;
        return;
    }

    Cliente clienteABajar = pArchivo.leer(pos); // Lee el registro

    if (clienteABajar.getEstado()) { // Si el cliente está actualmente activo
        clienteABajar.darDeBaja(); // Usa el método de Cliente para cambiar el estado
        if (pArchivo.guardar(clienteABajar, pos)) { // Guarda el registro modificado en la misma posición
            cout << "Cliente con DNI " << dni << " dado de BAJA exitosamente." << endl;
        } else {
            cout << "Error al actualizar el estado del cliente en el archivo." << endl;
        }
    } else {
        cout << "El cliente con DNI " << dni << " ya se encuentra en BAJA LOGICA." << endl;
    }
}


void clientemanager::altaLogicaCliente(){
    clientearchivo pArchivo;
    string dni;
    cout << "Ingrese el DNI del cliente a reactivar: ";
    cin >> dni;

    int pos = pArchivo.buscar(dni); // Busca la posición del cliente por ID
    if (pos == -1) {
        cout << "Cliente con DNI " << dni << " no encontrado." << endl;
        return;
    }
    if (pos == -2) {
        cout << "Error al acceder al archivo de clientes." << endl;
        return;
    }

    Cliente clienteAActivar = pArchivo.leer(pos); // Lee el registro

    if (!clienteAActivar.getEstado()) {
        clienteAActivar.darDeAlta();
        if (pArchivo.guardar(clienteAActivar, pos)) { // Guarda el registro modificado en la misma posición
            cout << "Cliente con DNI " << dni << " dado de alta exitosamente." << endl;
        } else {
            cout << "Error al actualizar el estado del cliente en el archivo." << endl;
        }
    } else {
        cout << "El cliente con DNI " << dni << " ya se encuentra activo." << endl;
    }
}


