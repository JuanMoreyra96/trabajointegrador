#include <iostream>
#include <string>
#include "cliente.h"
#include "clientearchivo.h"
#include "clientemanager.h"
#include "validaciones.h"
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
    if(!validar.validarCadena(nombre, 3, 50)){
        cout<<"El nombre debe contener entre 3 y 50 caracteres."<<endl;
    }
    }while(!validar.validarCadena(nombre, 3, 50));


     do{
  cout << "ingrese apellido/s: ";
    getline(cin, apellido);
    if(!validar.validarCadena(apellido, 3, 50)){
        cout<<"El apellido debe contener entre 3 y 50 caracteres."<<endl;
    }
    }while(!validar.validarCadena(apellido, 3, 50));

     do{
 cout << "ingrese direccion: ";
    getline(cin, direccion);
    if(!validar.validarCadena(direccion, 3, 50)){
        cout<<"La direccion debe contener entre 3 y 50 caracteres."<<endl;
    }
    }while(!validar.validarCadena(direccion, 3, 50));


     do{
    cout << "ingrese email: ";
    getline(cin, email);
    if(!validar.validarCadena(email, 3, 50)){
        cout<<"El email debe contener entre 3 y 50 caracteres."<<endl;
    }
    }while(!validar.validarCadena(email, 3, 50));


    do{
    cout << "ingrese telefono: ";
    cin >> celular;
    if(!validar.validarCadena(celular, 3, 50)){
        cout<<"El celular debe contener entre 3 y 50 caracteres."<<endl;
    }
    }while(!validar.validarCadena(celular, 3, 50));


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

