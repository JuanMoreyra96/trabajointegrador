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
        cout << "1. Registar nuevo cliente" << endl;
        cout << "2. listar todos los clientes" << endl;
        cout << "3. listar todos los clientes alfabeticamente" << endl;
        cout << "4. Listar clientes activos" << endl;
        cout << "5. Mostrar cantidad de registros" << endl;
        cout << "6. Dar de baja cliente" << endl;
        cout << "7. Reactivar cliente." << endl;
        cout << "0- Volver al menu principal" << endl;

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
            cmanager.listarTodosAlfabeticamentePorApellido();
            break;
        case 4:
            cmanager.listarClientesActivos();
            break;
        case 5:
            cmanager.mostrarCantidadRegistros();
            break;
        case 6:
            cmanager.bajaLogicaCliente();
            break;
        case 7:
            cmanager.altaLogicaCliente();
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
    while (opcion!=5);

}
