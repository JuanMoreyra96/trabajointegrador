#include "paquetedeviajemenu.h"
#include "paquetedeviajemanager.h"
#include <iostream>
using namespace std;

void PaqueteDeViajeMenu::mostrar(){

    int opcion;
    PaqueteDeViajeManager pManager;
    do{
    cout << "========================================================" << endl;
    cout << "        SISTEMA DE GESTION DE PAQUETES DE VIAJES" << endl;
    cout << "========================================================" << endl;
    cout << "1. Registrar nuevo paquete de viaje" << endl;
    cout << "2. Listar todos los paquetes de viajes" << endl;

    cout << "0. Volver al menu principal" << endl;
    cout << "===============================" << endl;
    cout << "Ingrese una opcion: ";

    cin >> opcion;

    switch(opcion) {
            case 1:
                pManager.cargarPaqueteDeViaje();
                break;
            case 2:
                pManager.listarTodos();
                break;
            case 0:
                return;
                break;
            default:
                cout << "Opci�n inv�lida. Por favor, intente de nuevo." << endl;
        }

      cout << endl << endl;

    } while(opcion != 0);
}
