#include <iostream>
#include <string>
#include "fechaHora.h"
#include "paquetedeviaje.h"
#include "paquetedeviajearchivo.h"
#include "paquetedeviajemanager.h"
using namespace std;

void PaqueteDeViajeManager::cargarPaqueteDeViaje()
{
  PaqueteDeViaje paquete;
  PaqueteDeViajeArchivo pArchivo;

   int idPaquete, idCoordinador1, idCoordinador2, totalCupos, cuposOcupados;
   string destino, hotel, tipoTransporte;
   float precio;
   bool temporadaAlta, estado;
   int dia, mes, anio, hora, minutos;
   FechaHora fechaRegreso, fechaSalida;
  //  char _destino[50];
  //  char _tipoTransporte[20];
  //  char _hotel[30];


  cout << "Ingrese ID: ";
  cin >> idPaquete;
  cout<<"Ingrese el destino: ";
  cin.ignore();
  getline(cin, destino);
  //aqui validacion de extension de caracteres.
  cout << "Ingrese el hotel: ";
  getline(cin, hotel);
//aqui validacion de extension de caracteres.
  cout << "Ingrese el tipo de transporte (AVION, COLECTIVO O TREN): ";
  getline(cin, tipoTransporte);
//aqui validacion de extension de caracteres.

  cout << "Ingrese el precio por persona: ";
  cin >> precio;

  cout << "Ingrese el total de cupos: ";
  cin >> totalCupos;

  cout << "¿El paquete pertenece a temporada baja o alta? 1- Alta 0- Baja: ";
  cin >> temporadaAlta;

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
  fechaSalida = FechaHora(dia, mes, anio, hora, minutos);

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
  fechaRegreso = FechaHora(dia, mes, anio, hora, minutos);


  //Aqui mostraríamos los coordinadores que tengan disponibilidad en esas fechas
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

  paquete.Mostrar();

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

  for(int i=0; i<cantidadRegistros; i++)
  {
    registro = pArchivo.leer(i);

   registro.Mostrar();
  }
 }
