#include "pagoMenu.h"
#include "pagoManager.h"
#include <iostream>
#include "pago.h"
using namespace std;

void PagoMenu::Mostrar()
{
    int opcion;
    PagoManager pagoManager;
    do
    {
        cout << "_____________________________________________" << endl;
        cout << "     MENU SISTEMA GESTION DE PAGOS      " << endl;
        cout << "_____________________________________________" << endl;
        cout << "1. Registar nuevo pago." << endl;
        cout << "2. Listar todos los pagos." << endl;
        cout << "3. Mostrar cantidad de registros" << endl;
        cout << "4. Listar pagos ordenados por ID de cliente" << endl;
        cout << "0- Volver al menu principal" << endl;

        cin >> opcion;

        switch(opcion)
        {
        case 1:
            pagoManager.CargarPago();
            break;
        case 2:
            pagoManager.ListarTodos();
            break;
        case 3:
            pagoManager.MostrarCantidadRegistros();
            break;
        case 4:
            pagoManager.ListarOrdenadosPorIDCliente();
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
