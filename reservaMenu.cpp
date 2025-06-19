#include "reservaMenu.h"
#include "reservaManager.h"
#include <iostream>
#include "reserva.h"
using namespace std;

void ReservaMenu::Mostrar()
{
    int opcion;
    ReservaManager reservaManager;
    do
    {
        cout << "_____________________________________________" << endl;
        cout << "     MENU SISTEMA GESTION DE RESERVAS       " << endl;
        cout << "_____________________________________________" << endl;
        cout << "1. Registar nueva reserva." << endl;
        cout << "2. Listar todas las reservas." << endl;
        cout << "3. Listar reservas con deuda cancelada." << endl;
        cout << "4. Listar reservas con deuda no cancelada." << endl;
        cout << "5. Mostrar cantidad de registros" << endl;
        cout << "6- Listar las reservas ordenadas alfabeticamente por destino.." << endl;
        cout << "7- Buscar todas las reservas de un cliente."<<endl;
        cout << "0- Volver al menu principal" << endl;

        cin >> opcion;

        switch(opcion)
        {
        case 1:
            reservaManager.CargarReserva();
            break;
        case 2:
            reservaManager.ListarTodos();
            break;
        case 3:
            reservaManager.ListarReservasDeudaCancelada();
            break;
        case 4:
            reservaManager.ListarReservasDeudaNoCancelada();
            break;            
        case 5:
            reservaManager.MostrarCantidadRegistros();
            break;
        case 6:
            reservaManager.listarTodasAlfabeticamentePorDestino();
            break;
        case 7:
            reservaManager.BuscarReservasDeCliente();
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
