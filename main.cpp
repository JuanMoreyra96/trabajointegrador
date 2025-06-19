#include <iostream>
using namespace std;
#include "cliente.h"
#include "clientemenu.h"
#include "reservaMenu.h"
#include "paquetedeviajemenu.h"
#include "coordinadorMenu.h"
#include "pagoMenu.h"
#include "informesMenu.h"
int main()
{
    int opc;
    clientemenu MenuClientes;
    PaqueteDeViajeMenu MenuPaquetes;
    ReservaMenu MenuReservas;
    CoordinadorMenu MenuCoordinadores;
    PagoMenu MenuPagos;
    InformesMenu MenuInformes;
    while(true){
        system("cls");
        cout << "****** ABML EMPRESA DE TURISMO******" << endl;
        cout << "1. MENU CLIENTES" << endl;
        cout << "2. MENU PAQUETES DE VIAJES" << endl;
        cout << "3. MENU RESERVAS" << endl;
        cout << "4. MENU PAGOS" << endl;
        cout << "5. MENU COORDINADORES" << endl;
        cout << "6. MENU INFORMES" << endl;
        cout << "0. FIN DEL PROGRAMA" << endl;
        cout << "************************" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: MenuClientes.mostrar();
                    break;
            case 2: MenuPaquetes.mostrar();
                    break;
            case 3: MenuReservas.Mostrar();
                    break;
            case 4: MenuPagos.Mostrar();
                    break;
            case 5: MenuCoordinadores.mostrar();
                    break;
            case 6: MenuInformes.Mostrar();
                    break;
            case 0: return 0;
                    break;
            default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;

        }
        system("pause");
    }
    return 0;

}
