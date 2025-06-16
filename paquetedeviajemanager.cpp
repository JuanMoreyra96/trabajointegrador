#include <iostream>
#include <string>
#include "fechaHora.h"
#include "paquetedeviaje.h"
#include "paquetedeviajearchivo.h"
#include "paquetedeviajemanager.h"
#include "validaciones.h"
#include <iomanip>
using namespace std;

void PaqueteDeViajeManager::cargarPaqueteDeViaje()
{
  PaqueteDeViaje paquete;
  PaqueteDeViajeArchivo pArchivo;
  Validaciones validar;
   int idPaquete, idCoordinador1, idCoordinador2, totalCupos, cuposOcupados;
   string destino, hotel, tipoTransporte;
   float precio;
   bool temporadaAlta, estado;
   int dia, mes, anio, hora, minutos;
   FechaHora fechaRegreso, fechaSalida;

    int cantRegistros = pArchivo.getCantidadRegistros();
    idPaquete = cantRegistros+1;

    do{
    cout<<"Ingrese el destino: ";
    cin.ignore();
    getline(cin, destino);
    if(!validar.validarCadenaDeLetras(destino) && !validar.validarLongitudCadena(destino, 3, 50)){
        cout<<"El destino debe contener entre 3 y 50 caracteres."<<endl;
    }
    }
    while(!validar.validarCadenaDeLetras(destino) && !validar.validarLongitudCadena(destino, 3, 50));


    do{
      cout << "Ingrese el hotel: ";
      getline(cin, hotel);
    if( !validar.validarCadenaDeLetras(hotel) && !validar.validarLongitudCadena(hotel, 3, 30)){
        cout<<"El hotel debe contener entre 3 y 30 caracteres."<<endl;
    }
    }while(!validar.validarCadenaDeLetras(hotel) && !validar.validarLongitudCadena(hotel, 3, 30));

    do{
  cout << "Ingrese el tipo de transporte (AVION, COLECTIVO O TREN): ";
  getline(cin, tipoTransporte);
    if(!validar.validarCadenaDeLetras(tipoTransporte) &&  !validar.validarLongitudCadena(tipoTransporte, 3, 20)){
        cout<<"El tipo de transporte debe contener entre 3 y 10 caracteres."<<endl;
    }
    }while(!validar.validarCadenaDeLetras(tipoTransporte) &&  !validar.validarLongitudCadena(tipoTransporte, 3, 20));

    do{
   cout << "Ingrese el precio por persona: ";
    precio = validar.pedirNumeroFloat();
    if(!validar.validarFloatPositivo(precio)){
        cout<<"El precio debe ser mayor a $0."<<endl;
    }
    }while(!validar.validarFloatPositivo(precio));

    do{
         cout << "Ingrese el total de cupos: ";
         totalCupos = validar.pedirNumero();

    if(!validar.validarIntPositivo(totalCupos)){
        cout<<"El total de cupos debe ser mayor a 0."<<endl;
    }
    }while(!validar.validarIntPositivo(totalCupos));

      do{
         cout << "Temporada: 1- Alta 0- Baja: ";
         cin >> temporadaAlta;

    if(!validar.validarBooleano(temporadaAlta)){
        cout<<"Ingrese 0 o 1 segun corresponda."<<endl;
    }
    }while(!validar.validarBooleano(temporadaAlta));

    do{
       cout<<"Ingrese la fecha de salida: ";
  cout<<"Dia: ";
  cin>> dia;
  cout<<"Mes: ";
  cin>> mes;
  cout<<"Anio: ";
  cin>> anio;
  cout<<"Hora: ";
  cin>>hora;
  cout<<"Minutos: ";
  cin>>minutos;

    if(!validar.validarFechaProxima(dia, mes, anio, hora, minutos)){
        cout<<"La fecha no debe ser anterior al dia actual."<<endl;
    }
    }while(!validar.validarFechaProxima(dia, mes, anio, hora, minutos));

    fechaSalida = FechaHora(dia, mes, anio, hora, minutos);

            do{
       cout<<"Ingrese la fecha de regreso: ";
  cout<<"Dia: ";
  cin>> dia;
  cout<<"Mes: ";
  cin>> mes;
  cout<<"Anio: ";
  cin>> anio;
  cout<<"Hora: ";
  cin>>hora;
  cout<<"Minutos: ";
  cin>>minutos;

    if(!validar.validarFechaProxima(dia, mes, anio, hora, minutos)
  && !validar.validarFechaPosterior(fechaSalida, dia, mes, anio, hora, minutos)
  ){
        cout<<"La fecha de regreso debe ser posterior a la de salida."<<endl;
    }
    }while(!validar.validarFechaProxima(dia, mes, anio, hora, minutos)
  && !validar.validarFechaPosterior(fechaSalida, dia, mes, anio, hora, minutos)
  );

  fechaRegreso = FechaHora(dia, mes, anio, hora, minutos);


  //Aqui mostrariamos los coordinadores que tengan disponibilidad en esas fechas
  // Funcion: Coordinador coordinadorDisponible(fechaSalida, fechaRegreso)
  cout << "Ingrese el ID de los coordinadores: ";
  cin>>idCoordinador1;
  cin>>idCoordinador2;
  estado = true;
  cuposOcupados = 0;
  /// aca ya se que esta todo ok
  /// reemplazmos al postulante con un nuevo objeto
  paquete = PaqueteDeViaje(idPaquete, idCoordinador1, idCoordinador2,
  destino, tipoTransporte, hotel,precio, totalCupos, cuposOcupados,
  temporadaAlta, fechaRegreso, fechaSalida, estado);

  if(pArchivo.guardar(paquete))
  {
    cout << "Se guardo correctamente!" << endl;
  }
  else
  {
    cout << "Hubo un error inesperado." << endl;
  }
}

 void PaqueteDeViajeManager::listarTodos()
 {
  PaqueteDeViajeArchivo pArchivo;
  PaqueteDeViaje registro;
  int cantidadRegistros = pArchivo.getCantidadRegistros();

    cout << setw(5)  << "ID"
         << setw(8)  << "Coord1"
         << setw(8)  << "Coord2"
         << setw(20) << "Destino"
         << setw(20) << "Hotel"
         << setw(13) << "Transporte"
         << setw(10) << "Precio"
         << setw(8)  << "Cupos"
         << setw(8)  << "Ocupados"
         << setw(10) << "Temporada"
         << " Salida - Regreso" << endl;

    cout << string(135, '-') << endl;
  for(int i=0; i<cantidadRegistros; i++)
  {
    registro = pArchivo.leer(i);

   registro.Mostrar();
  }
 }
