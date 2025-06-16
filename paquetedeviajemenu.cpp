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
    cout << "3. Listar paquetes de viajes activos" << endl;
    cout << "4. Dar de baja un paquete de viaje" << endl;
    cout << "5. Reactivar paquete de viaje" << endl;
    cout << "6. Buscar paquetes por destino" << endl;
    cout << "7. Buscar paquetes por rango de precios" << endl;
    cout << "8. Buscar paquetes por fecha de salida" << endl;
    cout << "9. Buscar paquetes por fecha de regreso" << endl;
    cout << "10. Buscar por tipo de transporte"<< endl;
    cout << "11. Buscar por temporada"<< endl;
    cout << "12. Buscar paquete con cupos disponibles"<< endl;
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
                pManager.listarPaquetesActivos();
                break;
            case 4:
                pManager.darDeBaja();
                break;
            case 5:
                pManager.darDeAlta();
                break;
            case 6:
                pManager.buscarPaquetePorDestino();
                break;
            case 7:
                pManager.buscarPorRangoDePrecio();
                break;
            case 8:
                pManager.buscarPaquetePorFechaSalida();
                break;
            case 9:
                pManager.buscarPaquetePorFechaRegreso();
                break;
            case 10:
                pManager.buscarPorTransporte();
                break;
            case 11:
                pManager.buscarPorTemporada();
                break;
            case 12:
                pManager.buscarConCuposDisponibles();
            case 0:
                return;
                break;
            default:
                cout << "Opcion invalida. Por favor, intente de nuevo." << endl;
        }
        system("pause");
        system("cls");

    } while(opcion != 0);
}
