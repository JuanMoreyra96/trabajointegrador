#include "clientemanager.h"
#include <iostream>
using namespace std;

void clientemanager::cargarcliente()
{
    int dni, telefono;
    string nombre,apellido,direccion,email;
    bool reservado;

    cout << "ingrese dni del cliente: ";
    cin >> dni;
    cout << "ingrese nombre: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "ingrese apellidos: ";
    cin.ignore();
    getline(cin, apellido);

    cout << "ingrese direccion: ";
    cin.ignore();
    getline(cin, direccion);

    cout << "ingrese email: ";
    cin.ignore();
    getline(cin, email);

    cout << "ingrese telefono: ";
    cin >> telefono;

    cout << "Tiene reserva? : 1-Si / 0=No";
    cin >> reservado;

}


