#include <iostream>
#include <string>
#include "coordinador.h"
#include "coordinadorArchivo.h"
#include "coordinadorManager.h"
using namespace std;


void CoordinadorManager::cargarCoordinador()
{
    Coordinador registro;
    CoordinadorArchivo pArchivo;
    int idCoordinador;
    int idiomas[5]={};
    string nombre,apellido,direccion,email,dni, celular;
    bool estado = 1;

    cout << "ingrese el ID del coordinador: ";
    cin >> idCoordinador;
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

    cout << "ingrese el codigo del primer idioma: ";
    cin >> idiomas[0];

    cout << "ingrese el codigo del segundo idioma: ";
    cin >> idiomas[1];

    registro = Coordinador(dni,nombre,apellido, email, celular, estado, idCoordinador, idiomas);

  if(pArchivo.guardar(registro)){
        cout << "El coordinador se registro correctamente" << endl;
  }else{
        cout << "El coordinador no se pudo guardar" << endl;
    }
}


void CoordinadorManager::mostrarCantidadRegistros(){
    CoordinadorArchivo pArchivo;
    int cantidadRegistros = pArchivo.getCantidadRegistros();
    cout << "La cantidad de registros son: " << cantidadRegistros << endl;
}


void CoordinadorManager::listarTodos(){
    CoordinadorArchivo pArchivo;
    Coordinador registro;
    int cantidadRegistros = pArchivo.getCantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++){
        registro = pArchivo.leer(i);
        registro.Mostrar();
    }
}


void CoordinadorManager::listarCoordinadoresActivos(){
    CoordinadorArchivo pArchivo;
    Coordinador registro;
    int cantidadRegistros = pArchivo.getCantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++){
        registro = pArchivo.leer(i);
        if(registro.getEstado()){
            registro.Mostrar();
        }
    }
}


void CoordinadorManager::listarCoordinadoresInactivos(){
    CoordinadorArchivo pArchivo;
    Coordinador registro;
    int cantidadRegistros = pArchivo.getCantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++){
        registro = pArchivo.leer(i);
        if(!registro.getEstado()){
            registro.Mostrar();
        }
    }
}

