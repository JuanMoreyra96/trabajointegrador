#include "clientemanager.h"
#include <iostream>
#include <string>
#include "cliente.h"
#include "clientearchivo.h"
using namespace std;

void clientemanager::cargarcliente()
{
    cliente nuevoCliente;
    clientearchivo pArchivo;


    int dni, telefono;
    string nombre,apellido,direccion,email;
    bool reservado;

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
    cin >> telefono;

    cout << "Tiene reserva? : 1-Si / 0=No";
    cin >> reservado;

    nuevoCliente = cliente(dni,nombre,apellido, telefono, direccion, email, reservado);

  //cout << nuevoCliente.toString();
  //system("Pause");

  if(pArchivo.guardar(nuevoCliente)){
        cout << "se guardo joya" << endl;
  }else{
        cout << "hubo un error al guardar" << endl;
    }


}

void clientemanager::mostrarcantidadregistros(){
    clientearchivo pArchivo;
    //int cantidadregistros = pArchivo.getcantidadregistros();

   // cout << "La canidad de registros son : " << cantidadregistros << endl;
}





