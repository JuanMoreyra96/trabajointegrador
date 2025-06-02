#include "clientemanager.h"
#include <iostream>
#include <string>
#include "cliente.h"
#include "clientearchivo.h"
using namespace std;

void clientemanager::cargarcliente()
{
    //hola
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

    cout << "Tiene reserva? : 1-Si / 0=No";
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

//void clientemanager::mostrarcantidadregistros(){
//    clientearchivo pArchivo;
//}





