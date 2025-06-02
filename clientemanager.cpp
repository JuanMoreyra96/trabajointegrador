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

    cout << "ingrese el ID del cliente: ";
    cin >> idCliente;
    cout << "ingrese dni del cliente: ";
    cin >> dni;
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

    cout << "Tiene reserva? : 1-Si / 0=No (Si le deja un estado activo, No un estado inactivo) ";
    cin >> estado;

    nuevoCliente = Cliente(dni,nombre,apellido, email, celular, estado, idCliente);

  //cout << nuevoCliente.toString();
  //system("Pause");

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

