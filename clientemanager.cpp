#include <iostream>
#include <string>
#include "cliente.h"
#include "clientearchivo.h"
#include "clientemanager.h"
using namespace std;

void clientemanager::cargarcliente()
{
    Cliente nuevoCliente;
    clientearchivo pArchivo;
    int idCliente;
    string nombre,apellido,direccion,email,dni, celular;
    bool estado;

//    cout << "ingrese el ID del cliente: ";
 //   cin >> idCliente;
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

    cout << "ingrese nombre: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "ingrese apellidos: ";
    getline(cin, apellido);

    cout << "ingrese direccion: ";
    getline(cin, direccion);

    cout << "ingrese email: ";
    getline(cin, email);

    cout << "ingrese telefono: ";
    cin >> celular;
    //Lo dejamos en activo por defecto
    estado = true;

    nuevoCliente = Cliente(dni,nombre,apellido, email, celular, estado, idCliente);

  if(pArchivo.guardar(nuevoCliente)){
        cout << "se guardo joya" << endl;
  }else{
        cout << "hubo un error al guardar" << endl;
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

  for(int i=0; i<cantidadRegistros; i++)
  {
    registro = pArchivo.leer(i);
    registro.Mostrar();
  }
}
void clientemanager::listarClientesActivos(){
  clientearchivo pArchivo;
  Cliente registro;
  int cantidadRegistros = pArchivo.getCantidadRegistros();

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

  for(int i=0; i<cantidadRegistros; i++)
  {
    registro = pArchivo.leer(i);
    if(!registro.getEstado()){
        registro.Mostrar();
    }
}
}

