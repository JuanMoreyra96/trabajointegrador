#include <iostream>
#include <string>
#include "fechaHora.h"
#include "paquetedeviaje.h"
#include "paquetedeviajearchivo.h"
#include "paquetedeviajemanager.h"
#include "validaciones.h"
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
         cout << "¿El paquete pertenece a temporada baja o alta? 1- Alta 0- Baja: ";
         cin >> temporadaAlta;

    if(!validar.validarBooleano(temporadaAlta)){
        cout<<"El total de cupos debe ser mayor a 0."<<endl;
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

  for(int i=0; i<cantidadRegistros; i++)
  {
    registro = pArchivo.leer(i);

   registro.Mostrar();
  }
 }

 void PaqueteDeViajeManager::bajaLogicaPaqueteDeViaje(){
    PaqueteDeViajeArchivo pArchivo;
    int idBaja;
    cout << "Ingrese el ID del paquete a dar de baja (logica): ";
    cin >> idBaja;

    int pos = pArchivo.buscar(idBaja); // Busca la posición del cliente por ID
    if (pos == -1) {
        cout << "Cliente con ID " << idBaja << " no encontrado." << endl;
        return;
    }
    if (pos == -2) {
        cout << "Error al acceder al archivo de paquetes de viaje." << endl;
        return;
    }

    PaqueteDeViaje paqueteABajar = pArchivo.leer(pos); // Lee el registro
    if (paqueteABajar.getIdPaquete() == 0) { // Error en la lectura
        cout << "Error al leer los datos del paquete." << endl;
        return;
    }

    if (paqueteABajar.getEstado()) { // Si el paquete está actualmente activo
        paqueteABajar.darDeBaja(); // Usa el método de Paquete de viaje para cambiar el estado
        if (pArchivo.guardar(paqueteABajar, pos)) { // Guarda el registro modificado en la misma posición
            cout << "Paquete con ID " << idBaja << " dado de BAJA exitosamente." << endl;
        } else {
            cout << "Error al actualizar el estado del paquete en el archivo." << endl;
        }
    } else {
        cout << "El paquete con ID " << idBaja << " ya se encuentra en BAJA LOGICA." << endl;
    }
}


void PaqueteDeViajeManager::altaLogicaPaqueteDeViaje(){
    PaqueteDeViajeArchivo pArchivo;
    int idAlta;
    cout << "Ingrese el ID del cliente a dar de alta (logica): ";
    cin >> idAlta;

    int pos = pArchivo.buscar(idAlta); // Busca la posición del paquete de viaje por ID
    if (pos == -1) {
        cout << "Paquete de viaje con ID " << idAlta << " no encontrado." << endl;
        return;
    }

    if (pos == -2) {
        cout << "Error al acceder al archivo de Paquetes de Viajes." << endl;
        return;
    }

    PaqueteDeViaje PaqueteAActivar = pArchivo.leer(pos); // Lee el registro
    if (!PaqueteAActivar.getEstado()==0) { // Error en la lectura
        cout << "Error al leer los datos del paquete." << endl;
        return;
    }
    if (!PaqueteAActivar.getEstado()) { // Si el paquete está actualmente activo
        PaqueteAActivar.darDeAlta(); // Usa el método de paquete para cambiar el estado
        if (pArchivo.guardar(PaqueteAActivar, pos)) { // Guarda el registro modificado en la misma posición
            cout << "Paquete con ID " << idAlta<< " dado de ALTA exitosamente." << endl;
        } else {
            cout << "Error al actualizar el estado del paquete en el archivo." << endl;
        }
    } else {
        cout << "El paquete con ID " << idAlta << " ya se encuentra ACTIVO." << endl;
    }
}

void PaqueteDeViajeManager::listarPaquetesActivos(){
  PaqueteDeViajeArchivo pArchivo;
  PaqueteDeViaje registro;
  int cantidadRegistros = pArchivo.getCantidadRegistros();

  for(int i=0; i<cantidadRegistros; i++)
  {
    registro = pArchivo.leer(i);
    if(registro.getEstado()){
   registro.Mostrar();
    }
  }
}
