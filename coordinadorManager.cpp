#include <iostream>
#include <string>
#include <iomanip>
#include "coordinador.h"
#include "coordinadorArchivo.h"
#include "coordinadorManager.h"
#include "validaciones.h"
#include <iomanip>
using namespace std;


void CoordinadorManager::cargarCoordinador(){

    Coordinador registro;
    CoordinadorArchivo cArchivo;
    Validaciones validar;
    int idCoordinador, cantIdiomas = 0, codIdioma;
    int vecIdiomas[5]={};
    bool estado = 1, auxBool = false, seguir = false;
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


    do{
        cout << "Lista de idiomas disponibles:" << endl;
        cout << "1_Espaniol, 2_Ingles, 3_Portugues, 4_Frances, 5_Arabe, 6_Aleman, 7_Ruso, 8_Chino, 9_Japones, 10_Hindi"<<endl;

        if (cantIdiomas > 0) {
            cout << "Idiomas ya ingresados: ";
            for (int i = 0; i < cantIdiomas; i++) {
                cout << vectorIdiomas[vecIdiomas[i] - 1];
                if (i < cantIdiomas - 1) {
                    cout << ", ";
                }
            }
            cout << endl;
        }

        cout << "Ingrese el codigo del idioma (1 a 10): ";
        cin >> codIdioma;

        bool duplicado = false;
        for (int i = 0; i < cantIdiomas; i++) {
            if (vecIdiomas[i] == codIdioma) {
                duplicado = true;
                break;
            }
        }

        if (duplicado) {
            cout << "Ese idioma ya fue ingresado. No puede repetirlo." << endl;
        }else {
            vecIdiomas[cantIdiomas] = codIdioma;
            cantIdiomas++;

            if (cantIdiomas < 5) {
                cout << "�Quiere ingresar otro idioma? (0: No, 1: Si): ";
                cin >> seguir;
                cin.ignore();
                if (!seguir) vecIdiomas[cantIdiomas] = -1;
            } else {
                cout << "Se alcanzo el maximo de 5 idiomas." << endl;
            }
        }
    } while (cantIdiomas < 5 && seguir);

    registro = Coordinador(dni,nombre,apellido, email, celular, estado, idCoordinador, vecIdiomas);

    if(cArchivo.guardar(registro)){
        cout << "El coordinador se registro correctamente" << endl;
    }else{
        cout << "El coordinador no se pudo guardar" << endl;
    }

}


void CoordinadorManager::modificarCoordinador(){

    Coordinador registro;
    CoordinadorArchivo cArchivo;
    bool continuarModificacion = true;
    bool modificarEstados;
    string dni;

    do {
        cin.ignore();
        cout << "Ingrese DNI del coordinador sin punto: ";
        getline(cin, dni);
        int posicion = cArchivo.buscar(dni);

        switch(posicion){
        case -1:
        case -2:
            if(posicion == -2){
                cout << "Ocurrio un error inexperado, intente nuevamente." << endl;
            }else{
                cout << "No existe coordinador con el DNI ingresado."<< endl;
            }
            cout << "Presione: " << endl;
            cout << "1_ Para ingresar otro DNI. " << endl;
            cout << "0_ Para Salir. " << endl;
            cin >> continuarModificacion;
            cin.ignore();
            if(!continuarModificacion){
                return;
            }
            break;
        default:
            registro = cArchivo.leer(posicion);
            cout << "El coordinador: "<<registro.getDni()<<" - " <<registro.getApellido()<<", "<<registro.getNombre()<<". ";
            if(registro.getEstado()){
                cout << "Es un registro Activo." << endl;
                cout << "�Desea desactivarlo?" << endl;
            }else{
                cout << "Es un registro Desactivado. " << endl;
                cout << "�Desea activarlo?" << endl;
            }
            cout << "Presione: " << endl;
            cout << "1_ Si. " << endl;
            cout << "0_ No. " << endl;
            cin >> modificarEstados;
            cin.ignore();
            if (modificarEstados){
                if(registro.getEstado()){
                    registro.setEstado(false);
                }else{
                    registro.setEstado(true);
                }
                cArchivo.guardar(registro,posicion);
            }else{
                return;
            }
        }
    }while (!continuarModificacion);
}

void CoordinadorManager::mostrarCantidadRegistros(){
    CoordinadorArchivo cArchivo;
    int cantidadRegistros = cArchivo.getCantidadRegistros();
    cout << "La cantidad de registros son: " << cantidadRegistros << endl;
}


void CoordinadorManager::listarTodosCoordinadoresPorApellido(){
    string vectorIdiomas[10] = {"Espaniol", "Ingles", "Portugues", "Frances", "Arabe","Aleman", "Ruso", "Chino", "Japones", "Hindi"};
    CoordinadorArchivo cArchivo;
    int cantidadRegistros = cArchivo.getCantidadRegistros();
<<<<<<< Updated upstream
=======
    Coordinador *vecReg = nullptr;

    vecReg = new Coordinador[cantidadRegistros];
    if( vecReg == nullptr ) {
        cout << "Ocurrio un error inesperado: " << endl;
        return;
    }

    for(int i=0; i<cantidadRegistros; i++){
        vecReg[i] = cArchivo.leer(i);
    }

    for (int i = 1; i < cantidadRegistros; i++) {
        Coordinador actual = vecReg[i];
        int j = i - 1;

        while (j >= 0 && actual.getApellido() < vecReg[j].getApellido()) {
            vecReg[j + 1] = vecReg[j];
            j--;
        }
        vecReg[j + 1] = actual;
    }

    cout << left
         << setw(5)  << "ID"
         << setw(12) << "DNI"
         << setw(15) << "Nombre"
         << setw(15) << "Apellido"
         << setw(25) << "Email"
         << setw(15) << "Celular"
         << setw(12) << "Estado"
         << endl;
    cout << string(135, '-') << endl;
>>>>>>> Stashed changes

    for(int i=0; i<cantidadRegistros; i++){
        vecReg[i].Mostrar(vectorIdiomas);
    }

    delete []vecReg;
}


void CoordinadorManager::listarCoordinadoresActivos(){
    string vectorIdiomas[10] = {"Espaniol", "Ingles", "Portugues", "Frances", "Arabe","Aleman", "Ruso", "Chino", "Japones", "Hindi"};
    CoordinadorArchivo cArchivo;
    Coordinador *vecReg = nullptr;
    int cantidadRegistros = cArchivo.getCantidadRegistros();
<<<<<<< Updated upstream
=======

    vecReg = new Coordinador[cantidadRegistros];

    if( vecReg == nullptr ) {
        cout << "Ocurrio un error inesperado: " << endl;
        return;
    }

    for(int i=0; i<cantidadRegistros; i++){
        vecReg[i] = cArchivo.leer(i);
    }

    for (int i = 1; i < cantidadRegistros; i++) {
        Coordinador actual = vecReg[i];
        int j = i - 1;

        while (j >= 0 && actual.getApellido() < vecReg[j].getApellido()) {
            vecReg[j + 1] = vecReg[j];
            j--;
        }
        vecReg[j + 1] = actual;
    }

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
>>>>>>> Stashed changes

    for(int i=0; i<cantidadRegistros; i++){
        if(vecReg[i].getEstado()){
            vecReg[i].Mostrar(vectorIdiomas);
        }
    }

    delete []vecReg;

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

