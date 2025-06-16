#include <iostream>
#include <string>
#include "coordinador.h"
#include "coordinadorArchivo.h"
#include "coordinadorManager.h"
#include "validaciones.h"
#include <iomanip>
using namespace std;


void CoordinadorManager::cargarCoordinador()
{

    Coordinador registro;
    CoordinadorArchivo cArchivo;
    Validaciones validar;
    int idCoordinador, auxIdiomas = 0;
    int vecIdiomas[5]={};
    bool estado = 1, auxBool=false;
    string nombre,apellido,direccion,email,dni,celular;
    string vectorIdiomas[10] = {"Espaniol", "Ingles", "Portugues", "Frances", "Arabe","Aleman", "Ruso", "Chino", "Japones", "Hindi"};


    int cantRegistros = cArchivo.getCantidadRegistros();
    idCoordinador = cantRegistros++;
    cin.ignore();

    do {

        cout << "Ingrese DNI del coordinador sin punto: ";
        getline(cin, dni);
        int resultado = cArchivo.buscar(dni);

        switch(resultado)
        {
        case -1:
            auxBool = true;
            if (!validar.validarLongitudCadena(dni, 8, 9)) cout << "Ingresar DNI con 7/8 caracteres numericos" << endl;
            if (!validar.validarCadenaDeNumeros(dni)) cout << "Por favor solo ingresar numeros en el DNI." << endl;
            break;
        case -2:
            cout << "Ocurrio un error inexperado, intente nuevamente." << endl;
            auxBool = false;
            break;
        default:
            cout << "Ya existe un coordinador con ese DNI." << endl;
            cout << "Presione: " << endl;
            cout << "1_ Para ingresar otro DNI. " << endl;
            cout << "0_ Para Salir. " << endl;
            bool auxSwitch = false;
            cin >> auxSwitch;
            cin.ignore();
            if(auxSwitch == 1){
                auxBool = false;
            }else{
                return;
            }
        break;
        }
    } while (auxBool == false || !validar.validarLongitudCadena(dni, 8, 9) || !validar.validarCadenaDeNumeros(dni));


    do{
        cout<<"Ingrese nombre: ";
        getline(cin, nombre);
        if(!validar.validarCadenaDeLetras(nombre) || !validar.validarLongitudCadena(nombre, 3, 50)){
            cout<<"El nombre debe contener entre 3 y 50 caracteres y no admite numeros."<<endl;
        }
    } while(!validar.validarCadenaDeLetras(nombre) || !validar.validarLongitudCadena(nombre, 3, 50));


    do{
        cout<<"Ingrese apellido: ";
        getline(cin, apellido);
        if(!validar.validarCadenaDeLetras(apellido) || !validar.validarLongitudCadena(apellido, 3, 50)){
            cout<<"El apellido debe contener entre 3 y 50 caracteres y no admite numeros."<<endl;
        }
    } while(!validar.validarCadenaDeLetras(apellido) || !validar.validarLongitudCadena(apellido, 3, 50));


    do{
        cout<<"Ingrese direccion: ";
        getline(cin, direccion);
        if(!validar.validarLongitudCadena(direccion, 3, 50)){
            cout<<"La direccion debe contener entre 3 y 50 caracteres."<<endl;
        }
    } while(!validar.validarLongitudCadena(direccion, 3, 50));


    do{
        cout<<"Ingrese email: ";
        getline(cin, email);
        if(!validar.validarLongitudCadena(email, 3, 50) || !validar.validarCadenaEmail(email)){
            cout<<"El email debe contener entre 3 y 50 caracteres."<<endl;
        }
        if(!validar.validarCadenaEmail(email)){
            cout<<"Por favor ingrese un email valido."<<endl;
        }
    } while(!validar.validarLongitudCadena(email, 3, 50) || !validar.validarCadenaEmail(email));


    do{
        cout<<"Ingrese celular sin signos ni puntos: ";
        getline(cin, celular);
        if(!validar.validarLongitudCadena(celular, 10, 10) || !validar.validarCadenaDeNumeros(celular)){
            cout<<"El celular debe contener 10 caracteres numericos."<<endl;
        }
    } while(!validar.validarLongitudCadena(celular, 10, 10) || !validar.validarCadenaDeNumeros(celular));


    cout << "1_Espaniol, 2_Ingles, 3_Portugues, 4_Frances, 5_Arabe, 6_Aleman, 7_Ruso, 8_Chino, 9_Japones, 10_Hindi"<<endl;
    do{
        if (auxIdiomas==0){
            cout << "Ingrese codigo del idioma: ";
            cin >> vecIdiomas[auxIdiomas];
        }else{
            bool select;
            cout << "¿Quiere ingresar un nuevo idioma? 0: No, 1: Si "<< endl;
            cin >> select;
            if(select){
                int aux = 0;
                cout<< "Los idiomas ingresados son: ";
                while(aux < auxIdiomas){
                    cout<<vectorIdiomas[vecIdiomas[aux]-1];
                    aux++;
                    if(aux < auxIdiomas){
                        cout<<", ";
                    }
                };
                cout<< endl;
                cout<< "Ingrese el codigo idioma: ";
                cin >> vecIdiomas[auxIdiomas];
            }else{
                vecIdiomas[auxIdiomas] = -1;
            }
        }
        if(vecIdiomas[auxIdiomas] != -1){
            auxIdiomas++;
        }
    }while(vecIdiomas[auxIdiomas] != -1 && auxIdiomas < 5);

    registro = Coordinador(dni,nombre,apellido, email, celular, estado, idCoordinador, vecIdiomas);

    if(cArchivo.guardar(registro)){
        cout << "El coordinador se registro correctamente" << endl;
    }else{
        cout << "El coordinador no se pudo guardar" << endl;
    }
}


void CoordinadorManager::mostrarCantidadRegistros(){
    CoordinadorArchivo cArchivo;
    int cantidadRegistros = cArchivo.getCantidadRegistros();
    cout << "La cantidad de registros son: " << cantidadRegistros << endl;
}


void CoordinadorManager::listarTodos(){
    string vectorIdiomas[10] = {"Espaniol", "Ingles", "Portugues", "Frances", "Arabe","Aleman", "Ruso", "Chino", "Japones", "Hindi"};
    CoordinadorArchivo cArchivo;
    Coordinador registro;
    int cantidadRegistros = cArchivo.getCantidadRegistros();
    cout << setw(5)  << "ID"
         << setw(12) << "DNI"
         << setw(15) << "Nombre"
         << setw(15) << "Apellido"
         << setw(25) << "Email"
         << setw(15) << "Celular"
         << setw(10) << "Estado"
         << " Idiomas" << endl;

    cout << string(120, '-') << endl;
    for(int i=0; i<cantidadRegistros; i++){
        registro = cArchivo.leer(i);
        registro.Mostrar(vectorIdiomas);
    }
}


void CoordinadorManager::listarCoordinadoresActivos(){
    string vectorIdiomas[10] = {"Espaniol", "Ingles", "Portugues", "Frances", "Arabe","Aleman", "Ruso", "Chino", "Japones", "Hindi"};
    CoordinadorArchivo cArchivo;
    Coordinador registro;
    int cantidadRegistros = cArchivo.getCantidadRegistros();
 cout << setw(5)  << "ID"
         << setw(12) << "DNI"
         << setw(15) << "Nombre"
         << setw(15) << "Apellido"
         << setw(25) << "Email"
         << setw(15) << "Celular"
         << setw(10) << "Estado"
         << " Idiomas" << endl;

    cout << string(120, '-') << endl;
    for(int i=0; i<cantidadRegistros; i++){
        registro = cArchivo.leer(i);
        if(registro.getEstado()){
            registro.Mostrar(vectorIdiomas);
        }
    }
}


void CoordinadorManager::listarCoordinadoresInactivos(){
    string vectorIdiomas[10] = {"Espaniol", "Ingles", "Portugues", "Frances", "Arabe","Aleman", "Ruso", "Chino", "Japones", "Hindi"};
    CoordinadorArchivo cArchivo;
    Coordinador registro;
    int cantidadRegistros = cArchivo.getCantidadRegistros();
 cout << setw(5)  << "ID"
         << setw(12) << "DNI"
         << setw(15) << "Nombre"
         << setw(15) << "Apellido"
         << setw(25) << "Email"
         << setw(15) << "Celular"
         << setw(10) << "Estado"
         << " Idiomas" << endl;

    cout << string(120, '-') << endl;
    for(int i=0; i<cantidadRegistros; i++){
        registro = cArchivo.leer(i);
        if(!registro.getEstado()){
            registro.Mostrar(vectorIdiomas);
        }
    }
}

