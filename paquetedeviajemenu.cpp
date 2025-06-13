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
    cout << "3. Cambiar estado baja un paquete de viaje por ID" << endl;
    cout << "4. Cambiar estado a alta un paquete de viaje por ID" << endl;
    cout << "5. Listar paquetes activos" << endl;
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
            case 3:
                pManager.bajaLogicaPaqueteDeViaje();
                break;
            case 4:
                pManager.altaLogicaPaqueteDeViaje();
            case 5:
                pManager.listarPaquetesActivos();
            case 0:
                return;
                break;
            default:
                cout << "Opcion invalida. Por favor, intente de nuevo." << endl;
        }

      cout << endl << endl;

    } while(opcion != 0);
}
