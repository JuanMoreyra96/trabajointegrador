#include "informesMenu.h"
#include "informes.h"
#include <iostream>
using namespace std;

void InformesMenu::Mostrar()
{
    int opcion;
    Informes informe;
    do
    {
        cout << "_____________________________________________" << endl;
        cout << "     MENU DE INFORMES                        " << endl;
        cout << "_____________________________________________" << endl;
        cout << "1. Mostrar clientes que adaudan pagos" << endl;
        cout << "2. Mostrar paquetes que necesitan mas publicidad" << endl;
        cout << "3. Mostrar recaudacion anual general en un anio " << endl;
        cout << "4. Mostrar el destino mas visitado en un anio" << endl;
        cout << "5. Recaudacion anual cliente" << endl;
        cout << "6. Recaudacion anual paquete" << endl;
        cout << "7. Mostrar el porcentaje de reservas en temporatada ALTA/BAJA en un anio." << endl;
        cout << "0- Volver al menu principal" << endl;

        cin >> opcion;

        switch(opcion)
        {
        case 1:
            informe.mostrarClientesQueAdeudan();
            break;
        case 2:
            informe.mostrarPaquetesParaPublicidad();
            break;
        case 3:
            informe.mostrarRecaudacionAnualGeneralPorAnio();
            break;
        case 4:
            informe.mostrarDestinoMasVisitadoEnAnio();
            break;
        case 5:
            informe.mostrarRecaudacionAnualDelCliente();
            break;
        case 6:
            informe.mostrarRecaudacionAnualDelPaquete();
            break;
        case 7:
            informe.mostrarPorcentajeTemporada();
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
