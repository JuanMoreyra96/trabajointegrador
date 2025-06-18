#include <iostream>
#include <string>
#include "fechaHora.h"
#include "paquetedeviaje.h"
#include "paquetedeviajearchivo.h"
#include "paquetedeviajemanager.h"
#include "coordinadorArchivo.h"
#include "coordinador.h"
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
    bool temporadaAlta, estado, seguir;
    int dia, mes, anio, hora, minutos;
    FechaHora fechaRegreso, fechaSalida;
    string vectorIdiomas[10] = {"Espaniol", "Ingles", "Portugues", "Frances", "Arabe","Aleman", "Ruso", "Chino", "Japones", "Hindi"};
    bool *vectorCoordinadoresDisponibles = nullptr;
    CoordinadorArchivo cArchivo;
    int cantidadCoordinadores = cArchivo.getCantidadRegistros();

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
    //Obtenemos la cantidad de coordinadores y creamos un vector booleano
    vectorCoordinadoresDisponibles = new bool[cantidadCoordinadores];

    //Vector Dinamico
    if( vectorCoordinadoresDisponibles == nullptr ) {
        cout << "Ocurrio un error inesperado: " << endl;
        return;
    }

    //Vector Dinamico seteando a todos los coordinadores disponibles
    for (int i=0 ; i<cantidadCoordinadores ; i++){
        vectorCoordinadoresDisponibles[i] = 1;
    }

    //Recorremos la cantidad de registros y seteamos en cero los coordinadores que tengan conflictos con las fechas propuestas.
    for(int i=0; i<cantRegistros; i++){
        paquete = pArchivo.leer(i);
        if((fechaSalida >= paquete.getFechaSalida() && fechaSalida <= paquete.getFechaRegreso())
        || (fechaRegreso >= paquete.getFechaSalida() && fechaRegreso <= paquete.getFechaRegreso())){
            vectorCoordinadoresDisponibles[paquete.getIdCoordinador1()] = 0;
            vectorCoordinadoresDisponibles[paquete.getIdCoordinador2()] = 0;
        }
    }

    //Mostramos todos los coordinadores disponibles
    for(int i=0 ; i<cantidadCoordinadores ; i++){
        if(vectorCoordinadoresDisponibles[i] == 1){
            Coordinador coordinador = cArchivo.leer(i);
            if(coordinador.getEstado()){
                coordinador.Mostrar(vectorIdiomas);
            }
        }
    }

    //Comprobar si el ID ingresado esta activo y puede realizar el viaje.

    do{
        seguir = true;
        cout<<"Ingrese el ID del coordinador numero 1: ";
        cin>>idCoordinador1;
        cin.ignore();
        int idPosCoordinador = cArchivo.buscar(idCoordinador1);
        if(idPosCoordinador == -1){
            cout<<"El id del coordinador no existe. Por favor, ingrese un ID Coordinador existente"<<endl;
            seguir = false;
        }else if(idPosCoordinador == -2){
            cout<<"Hubo un error inesperado"<<endl;
            seguir = false;
        }else{
            Coordinador coordinador = cArchivo.leer(idPosCoordinador);
            if(coordinador.getEstado() == false){
                cout<<"No se puede seleccionar dicho coordinador porque no esta activo: ";
                cout<<"ID: "<< coordinador.getIdCoordinador()<<" Dni: "<<coordinador.getDni();
                cout<<" Nombre: "<<coordinador.getApellido()<<", "<<coordinador.getNombre()<<endl;
                seguir = false;
            }else if(vectorCoordinadoresDisponibles[coordinador.getIdCoordinador()] == 0){
                cout<<"No se puede seleccionar dicho coordinador porque esta asignado a otro paquete: ";
                cout<<"ID: "<< coordinador.getIdCoordinador()<<" Dni: "<<coordinador.getDni();
                cout<<" Nombre: "<<coordinador.getApellido()<<", "<<coordinador.getNombre()<<endl;
                seguir = false;
            }
        }
    } while(!seguir);

    do{
        seguir = true;
        cout<<"Ingrese el ID del coordinador numero 2: ";
        cin>>idCoordinador2;
        cin.ignore();
        int idPosCoordinador = cArchivo.buscar(idCoordinador2);
        if(idCoordinador2 == idCoordinador1){
            cout<<"El ID de coordinador seleccionado ya fue asignado al paquete, por favor ingrese otro."<<endl;
            seguir = false;
        }
        else if(idPosCoordinador == -1){
            cout<<"El id del coordinador no existe. Por favor, ingrese un ID Coordinador existente"<<endl;
            seguir = false;
        }else if(idPosCoordinador == -2){
            cout<<"Hubo un error inesperado"<<endl;
            seguir = false;
        }else{
            Coordinador coordinador = cArchivo.leer(idPosCoordinador);
            if(coordinador.getEstado() == false){
                cout<<"No se puede seleccionar dicho coordinador porque no esta activo: ";
                cout<<"ID: "<< coordinador.getIdCoordinador()<<" Dni: "<<coordinador.getDni();
                cout<<" Nombre: "<<coordinador.getApellido()<<", "<<coordinador.getNombre()<<endl;
                seguir = false;
            }else if(vectorCoordinadoresDisponibles[coordinador.getIdCoordinador()] == 0){
                cout<<"No se puede seleccionar dicho coordinador porque esta asignado a otro paquete: ";
                cout<<"ID: "<< coordinador.getIdCoordinador()<<" Dni: "<<coordinador.getDni();
                cout<<" Nombre: "<<coordinador.getApellido()<<", "<<coordinador.getNombre()<<endl;
                seguir = false;
            }
        }
    } while(!seguir);


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

 //   void listarPaquetesActivos();
  void PaqueteDeViajeManager::listarPaquetesActivos()
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
    if(registro.getEstado()){
      registro.Mostrar();
    }
  }
 }

 void PaqueteDeViajeManager::darDeBaja(){
    PaqueteDeViajeArchivo pArchivo;
    int idPaquete;
    cout << "Ingrese el ID del paquete: ";
    cin >> idPaquete;

    int pos = pArchivo.buscar(idPaquete);
    if (pos == -1) {
        cout << "Paquete no encontrado." << endl;
        return;
    }
    if (pos == -2) {
        cout << "Error al acceder al archivo de paquetes de viajes." << endl;
        return;
    }

    PaqueteDeViaje paqueteABajar = pArchivo.leer(pos);

    if (paqueteABajar.getEstado()) {
       paqueteABajar.setEstado(false);
        if (pArchivo.guardar(paqueteABajar, pos)) {
            cout << "Paquete dado de baja exitosamente." << endl;
        } else {
            cout << "Error al actualizar el estado del paquete en el archivo." << endl;
        }
    } else {
        cout << "El paquete ya se encuentra en baja logica." << endl;
    }
 }
  void PaqueteDeViajeManager::darDeAlta(){
    PaqueteDeViajeArchivo pArchivo;
    int idPaquete;
    cout << "Ingrese el ID del paquete: ";
    cin >> idPaquete;

    int pos = pArchivo.buscar(idPaquete);
    if (pos == -1) {
        cout << "Paquete no encontrado." << endl;
        return;
    }
    if (pos == -2) {
        cout << "Error al acceder al archivo de paquetes de viajes." << endl;
        return;
    }

    PaqueteDeViaje paqueteAReactivar = pArchivo.leer(pos);

    if (!paqueteAReactivar.getEstado()) {
       paqueteAReactivar.setEstado(true);
        if (pArchivo.guardar(paqueteAReactivar, pos)) {
            cout << "Paquete reactivado exitosamente." << endl;
        } else {
            cout << "Error al actualizar el estado del paquete en el archivo." << endl;
        }
    } else {
        cout << "El paquete ya se encuentra activo." << endl;
    }
  }

void PaqueteDeViajeManager::buscarPaquetePorDestino(){
    PaqueteDeViajeArchivo pArchivo;
    string destino;
     Validaciones validar;
    do{
    cout<<"Ingrese el destino: ";
    cin.ignore();
    getline(cin, destino);
    if(!validar.validarCadenaDeLetras(destino) || !validar.validarLongitudCadena(destino, 2, 20)){
        cout<<"La busquda debe contener entre 2 y 20 caracteres."<<endl;
    }
    }
    while(!validar.validarCadenaDeLetras(destino) || !validar.validarLongitudCadena(destino, 2, 20));

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
    // aqui mostramos coincidencias aproximadas
    pArchivo.mostrarPaquetesPorDestinoParcial(destino);
  }

void PaqueteDeViajeManager::buscarPorRangoDePrecio(){
    PaqueteDeViajeArchivo pArchivo;
    float precioMenor, precioMayor;
    Validaciones validar;
       do{
   cout << "Ingrese el precio minimo: ";
    precioMenor = validar.pedirNumeroFloat();
    if(!validar.validarFloatPositivo(precioMenor)){
        cout<<"El precio debe ser mayor a $0."<<endl;
    }
    }while(!validar.validarFloatPositivo(precioMenor));

       do{
   cout << "Ingrese el precio maximo: ";
    precioMayor = validar.pedirNumeroFloat();
    if(!validar.validarFloatPositivo(precioMayor) || precioMayor < precioMenor){
        cout<<"El precio debe ser mayor al ingresado como minimo."<<endl;
    }
    }while(!validar.validarFloatPositivo(precioMayor)  || precioMayor < precioMenor );

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
    pArchivo.buscarPorRangoPrecios(precioMenor, precioMayor);
}

void PaqueteDeViajeManager::buscarPaquetePorFechaSalida(){
  PaqueteDeViajeArchivo pArchivo;
  FechaHora fecha;
  int dia, mes, anio, hora, minutos;
  Validaciones validar;

      do{
       cout<<"Ingrese la fecha: ";
  cout<<"Dia: ";
  cin>> dia;
  cout<<"Mes: ";
  cin>> mes;
  cout<<"Anio: ";
  cin>> anio;
  hora = 0;
  minutos = 0;
    if(!validar.validarFechaCorrecta(dia, mes, anio, hora, minutos)){
        cout<<"Ingrese una fecha valida entre 2010 y 2030."<<endl;
    }
    }while(!validar.validarFechaCorrecta(dia, mes, anio, hora, minutos));

    fecha = FechaHora(dia, mes, anio, hora, minutos);
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
    pArchivo.buscarRegistroPorFechaSalida(fecha);
}

void PaqueteDeViajeManager::buscarPaquetePorFechaRegreso(){
  PaqueteDeViajeArchivo pArchivo;
  FechaHora fecha;
  int dia, mes, anio, hora, minutos;
  Validaciones validar;

      do{
       cout<<"Ingrese la fecha: ";
  cout<<"Dia: ";
  cin>> dia;
  cout<<"Mes: ";
  cin>> mes;
  cout<<"Anio: ";
  cin>> anio;
  hora = 0;
  minutos = 0;
    if(!validar.validarFechaCorrecta(dia, mes, anio, hora, minutos)){
        cout<<"Ingrese una fecha valida entre 2010 y 2030."<<endl;
    }
    }while(!validar.validarFechaCorrecta(dia, mes, anio, hora, minutos));

    fecha = FechaHora(dia, mes, anio, hora, minutos);
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
    pArchivo.buscarRegistroPorFechaRegreso(fecha);
}

void PaqueteDeViajeManager::buscarPorTransporte(){
    PaqueteDeViajeArchivo pArchivo;
    string transporte;
    Validaciones validar;
    do{
    cout<<"Ingrese el transporte: AVION, COLECTIVO O TREN  : ";
    cin.ignore();
    getline(cin, transporte);
    if(!validar.validarCadenaDeLetras(transporte) || !validar.validarTransporte(transporte)){
        cout<<"La busquda debe contener entre 2 y 20 caracteres."<<endl;
    }
    }
    while(!validar.validarCadenaDeLetras(transporte) || !validar.validarTransporte(transporte));

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
    // aqui mostramos coincidencias aproximadas
    pArchivo.mostrarPaquetesPorTransporte(transporte);
}

void PaqueteDeViajeManager::buscarPorTemporada(){
    PaqueteDeViaje registro;
    PaqueteDeViajeArchivo pArchivo;
    bool temporada;
    int cantidadRegistros = pArchivo.getCantidadRegistros();
    Validaciones validar;
    do{
      cout << "Temporada: 1- Alta 0- Baja: ";
      cin >> temporada;

    if(!validar.validarBooleano(temporada)){
        cout<<"Ingrese 0 o 1 segun corresponda."<<endl;
    }
    }while(!validar.validarBooleano(temporada));

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
      if (registro.getTemporadaAlta() == temporada){
         registro.Mostrar();
      }
    }
}

void PaqueteDeViajeManager::buscarConCuposDisponibles(){
  PaqueteDeViajeArchivo pArchivo;
  PaqueteDeViaje registro;
  int cantidadRegistros = pArchivo.getCantidadRegistros();

  for(int i=0; i<cantidadRegistros; i++)
  {
    registro = pArchivo.leer(i);
    int resta = registro.getTotalCupos() - registro.getCuposOcupados();
    if(resta > 0){
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
      registro.Mostrar();
      cout << "Cupos disponibles: " << resta << endl;
    }

  }
}
void PaqueteDeViajeManager::listarDeMasAMenosProximo(){
   PaqueteDeViajeArchivo pArchivo;
    PaqueteDeViaje registro;
    int cantidadRegistros = pArchivo.getCantidadRegistros();
    FechaHora hoy;
    Validaciones validar;
    int contadorFechasProximas=0;
    for(int i=0; i<cantidadRegistros;i++){
      registro = pArchivo.leer(i);
      if(validar.validarFechaPosterior(
        hoy, registro.getFechaSalida().getDia(),
        registro.getFechaSalida().getMes(),
        registro.getFechaSalida().getAnio(),
        registro.getFechaSalida().getHora(),
        registro.getFechaSalida().getMinuto()

      ))
      {
        contadorFechasProximas++;
      }
    }
 if (contadorFechasProximas == 0) {
        cout << "No hay paquetes con fechas próximas." << endl;
        return;
    }
    int* vecDias = new int[contadorFechasProximas];
    int* vecIdPaquete = new int[contadorFechasProximas];
    string* vecDestino = new string[contadorFechasProximas];

    // Segundo recorrido: llenar los vectores
    int aux = 0;
    for (int i = 0; i < cantidadRegistros; i++) {
        registro = pArchivo.leer(i);
        if (validar.validarFechaPosterior(
                hoy,
                registro.getFechaSalida().getDia(),
                registro.getFechaSalida().getMes(),
                registro.getFechaSalida().getAnio(),
                registro.getFechaSalida().getHora(),
                registro.getFechaSalida().getMinuto())) {

            int dias = hoy.calcularDiferenciaDeDias(registro.getFechaSalida(), hoy);
            vecDias[aux] = dias;
            vecIdPaquete[aux] = registro.getIdPaquete();
            vecDestino[aux] = registro.getDestino();
            aux++;
        }
    }

    // Ordenar de menor a mayor por vecDias
    for (int i = 0; i < contadorFechasProximas - 1; i++) {
        for (int j = i + 1; j < contadorFechasProximas; j++) {
            if (vecDias[i] > vecDias[j]) {
                vecDias[i] = vecDias[j];
                vecIdPaquete[i] = vecIdPaquete[j];
                vecDestino[i]= vecDestino[j];
            }
        }
    }

    // Mostrar resultados
    cout << left << setw(15) << "ID PAQUETE"
         << setw(25) << "DESTINO"
         << "DIAS PARA SALIDA" << endl;
    cout << string(60, '-') << endl;

    for (int i = 0; i < contadorFechasProximas; i++) {
        cout << left << setw(15) << vecIdPaquete[i]
             << setw(25) << vecDestino[i]
             << vecDias[i] << " dias" << endl;
    }

    // Liberar memoria
    delete[] vecDias;
    delete[] vecIdPaquete;
    delete[] vecDestino;

}
void PaqueteDeViajeManager::listarPorPrecio() {
    PaqueteDeViajeArchivo pArchivo;
    PaqueteDeViaje registro;
    int cantidadRegistros = pArchivo.getCantidadRegistros();

    if (cantidadRegistros == 0) {
        cout << "No hay paquetes cargados." << endl;
        return;
    }

    float* vecPrecios = new float[cantidadRegistros];
    int* vecIdPaquetes = new int[cantidadRegistros];

    // Validar memoria
    if (vecPrecios == nullptr || vecIdPaquetes == nullptr) {
        cout << "No hay memoria suficiente." << endl;
        delete[] vecPrecios;
        delete[] vecIdPaquetes;
        return;
    }
    float auxPrecio;
    int auxId;
    // Llenar vectores
    for (int i = 0; i < cantidadRegistros; i++) {
        registro = pArchivo.leer(i);
        vecPrecios[i] = registro.getPrecio();
        vecIdPaquetes[i] = registro.getIdPaquete();
    }

    // Ordenar por precio
    for (int i = 0; i < cantidadRegistros - 1; i++) {
        int posmin = i;
        for (int j = i + 1; j < cantidadRegistros; j++) {
            if (vecPrecios[j] < vecPrecios[posmin]) {
                posmin = j;
            }
        }

        // Intercambiar precios
       auxPrecio = vecPrecios[i];
        vecPrecios[i] = vecPrecios[posmin];
        vecPrecios[posmin] = auxPrecio;

        // Intercambiar IDs correspondientes
        auxId = vecIdPaquetes[i];
        vecIdPaquetes[i] = vecIdPaquetes[posmin];
        vecIdPaquetes[posmin] = auxId;
    }
    // Mostramos resultados
    cout << left << setw(15) << "ID PAQUETE"
     << setw(10) << "PRECIO"
     << "DESTINO" << endl;

    cout << string(50, '-') << endl;

    for (int i = 0; i < cantidadRegistros; i++) {

    int posicion = pArchivo.buscar(vecIdPaquetes[i]);
    registro = pArchivo.leer(posicion);
    cout << left << setw(15) << registro.getIdPaquete()
         << "$" << setw(9) << fixed << setprecision(2) << registro.getPrecio()
         << registro.getDestino() << endl;
    }

    // Liberar memoria
    delete[] vecPrecios;
    delete[] vecIdPaquetes;
}

