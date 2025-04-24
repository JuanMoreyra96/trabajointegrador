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
        cout << "1- registar nuevo cliente" << endl;
        cout << "2- listar todos los clientes" << endl;
        cout << "3- buscar cliente por servicio contratado" << endl;
        cout << "4- mostrar cantidad registros" << endl;
        cout << "5- salir" << endl;

        cin >> opcion;

        switch(opcion)
        {
        case 1:
            cmanager.cargarcliente();
            //out << "1" << endl;
            break;
        case 2:
            cout << "2" << endl;
            break;
        case 3:
            cout << "3" << endl;
            break;
        case 4:
            cmanager.mostrarcantidadregistros();
            // cout << "4" << endl;
            break;
        case 5:
            return;
            break;

            default:
            cout << "Opcion invalida. Por favor, intente de nuevo" << endl;
            break;

        }
        system("cls");
    }
    while (opcion!=5);

}
