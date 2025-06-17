#include "coordinadorMenu.h"
#include "coordinadorManager.h"
#include "coordinador.h"
#include <iostream>
using namespace std;

void CoordinadorMenu::mostrar()
{
    int opcion;
    CoordinadorManager cmanager;
    do
    {
        cout << "---------------------------------------------" << endl;
        cout << "|  MENU SISTEMA REGISTRO DE COORDINADORES   |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "1. Registar nuevo coordinador" << endl;
        cout << "2. Modificar coordinador" << endl;
        cout << "3. Listar todos los coordinadores" << endl;
        cout << "4. Listar coordinadores activos" << endl;
        cout << "5. Mostrar cantidad de registros" << endl;
        cout << "0- Volver al menu principal" << endl;

        cin >> opcion;

        switch(opcion)
        {
        case 1:
            cmanager.cargarCoordinador();
            break;
        case 2:
            cmanager.modificarCoordinador();
            break;
        case 3:
            cmanager.listarTodosCoordinadoresPorApellido();
            break;
        case 4:
            cmanager.listarCoordinadoresActivos();
            break;
        case 5:
            cmanager.mostrarCantidadRegistros();
            break;
        case 0:
            return;
            break;
        default:
            cout << "Opcion invalida. Por favor, intente de nuevo" << endl;
        break;

        }
        system("pause");
        system("cls");
    }
    while (true);

}
