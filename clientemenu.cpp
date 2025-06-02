#include "clientemenu.h"
#include "clientemanager.h"
#include <iostream>
#include "cliente.h"
using namespace std;
void clientemenu::mostrar()
{
    int opcion;
    clientemanager cmanager;
    do
    {
        cout << "_____________________________________________" << endl;
        cout << "     MENU SISTEMA REGISTRO DE CLIENTES       " << endl;
        cout << "_____________________________________________" << endl;
        cout << "1- Registar nuevo cliente" << endl;
        cout << "2- listar todos los clientes" << endl;
        cout << "3- Listar clientes activos" << endl;
        cout << "4- Mostrar cantidad de registros" << endl;
        cout << "5- salir" << endl;

        cin >> opcion;

        switch(opcion)
        {
        case 1:
            cmanager.cargarcliente();
            break;
        case 2:
            cmanager.listarTodos();
            break;
        case 3:
            cmanager.listarClientesActivos();
            break;
        case 4:
            cmanager.mostrarCantidadRegistros();
            break;
        case 5:
            return;
            break;

            default:
            cout << "Opcion invalida. Por favor, intente de nuevo" << endl;
            break;

        }
        system("pause");
        system("cls");
    }
    while (opcion!=5);

}
