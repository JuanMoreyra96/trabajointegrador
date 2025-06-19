#include "informes.h"
#include <iostream>
#include "fechaHora.h"
#include "paquetedeviaje.h"
#include "paquetedeviajearchivo.h"
#include "paquetedeviajemanager.h"
#include "validaciones.h"
#include "reservaArchivo.h"
#include "reserva.h"
#include "clientearchivo.h"
#include "cliente.h"
#include "pagoArchivo.h"
#include "pago.h"
#include <iomanip>
using namespace std;
void Informes::mostrarPaquetesParaPublicidad()
{
    FechaHora fechaActual;
    PaqueteDeViajeArchivo pArchivo;
    PaqueteDeViaje registro, paqueteMasCercano;
    int cantidadRegistros = pArchivo.getCantidadRegistros();
    Validaciones val;

    int diferenciaMenor = -1;
    bool encontrado = false;

    for (int i = 0; i < cantidadRegistros; i++)
    {
        registro = pArchivo.leer(i);
        FechaHora fechaDelRegistro = registro.getFechaSalida();

        // Filtrar: solo paquetes activos, futuros y con baja ocupación
        bool esValido = registro.getEstado() &&
                        val.validarFechaPosterior(
                            fechaActual,
                            fechaDelRegistro.getDia(),
                            fechaDelRegistro.getMes(),
                            fechaDelRegistro.getAnio(),
                            fechaDelRegistro.getHora(),
                            fechaDelRegistro.getMinuto()) &&
                        val.validarBajaOcupacion(
                            registro.getTotalCupos(),
                            registro.getCuposOcupados());

        if (esValido)
        {
            int diferencia = fechaActual.calcularDiferenciaDeDias(fechaActual, fechaDelRegistro);

            if (!encontrado || diferencia < diferenciaMenor)
            {
                diferenciaMenor = diferencia;
                paqueteMasCercano = registro;
                encontrado = true;
            }
        }
    }

    if (encontrado)
    {
        std::cout << "Paquete más cercano con baja ocupacion. Necesita mas publicidad!:\n";
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
        paqueteMasCercano.Mostrar();
    }
    else
    {
        std::cout << "No hay paquetes disponibles con baja ocupación y fecha futura.\n";
    }
}
void Informes::mostrarClientesQueAdeudan()
{
    ReservaArchivo rArchivo;
    clientearchivo cArchivo;
    PaqueteDeViajeArchivo paqueteArchivo;
    PagoArchivo pagoArchivo;

    Reserva registro;
    Cliente registroCliente;
    PaqueteDeViaje registroPaquete;
    Pago registroPago;

    int cantidadRegistros = rArchivo.getCantidadRegistros();
    int cantidadRegistrosPagos = pagoArchivo.getCantidadRegistros();

    cout << left
         << setw(10) << "Reserva"
         << setw(20) << "Destino"
         << setw(14) << "Precio Total"
         << setw(12) << "Adeuda"
         << setw(12) << "ID Cliente"
         << setw(12) << "DNI"
         << setw(15) << "Nombre"
         << setw(15) << "Apellido"
         << endl;

    cout << string(110, '-') << endl;  // Línea divisoria

    for (int i = 0; i < cantidadRegistros; i++)
    {
        registro = rArchivo.leer(i);

        if (!registro.getDeudaCancelada())
        {
            float sumaPagos = 0;

            registroCliente = cArchivo.leer(registro.getIdCliente());
            registroPaquete = paqueteArchivo.leer(registro.getIidPaquete());

            for (int j = 0; j < cantidadRegistrosPagos; j++)
            {
                registroPago = pagoArchivo.leer(j);
                if (registroPago.getIdReserva() == registro.getIdReserva())
                {
                    sumaPagos += registroPago.getImporte();
                }
            }

            float cuantoAdeuda = registro.getPrecioTotal() - sumaPagos;

            cout << left
                 << setw(10) << registro.getIdReserva()
                 << setw(20) << registroPaquete.getDestino()
                 << setw(14) << fixed << setprecision(2) << registro.getPrecioTotal()
                 << setw(12) << fixed << setprecision(2) << cuantoAdeuda
                 << setw(12) << registroCliente.getidCliente()
                 << setw(12) << registroCliente.getDni()
                 << setw(15) << registroCliente.getNombre()
                 << setw(15) << registroCliente.getApellido()
                 << endl;
        }
    }
}

void Informes::mostrarDestinoMasVisitadoEnAnio()
{
    Validaciones validar;
    PaqueteDeViajeArchivo pArchivo;
    PaqueteDeViaje registroPaquete;
    FechaHora hoy;

    int cantidadRegistros = pArchivo.getCantidadRegistros();
    int anio;

    // Solicitar y validar año
    do
    {
        cout << "Ingrese el anio (actual o anios anteriores): ";
        anio = validar.pedirNumero();
        if (!validar.validarIntPositivo(anio))
        {
            cout << "Ingrese un anio válido." << endl;
        }
    }
    while (!validar.validarIntPositivo(anio) || anio > hoy.getAnio());

    // Contar cuántos paquetes del año cumplen con la condición de haber ya salido
    int cantidadDestinosEnAnio = 0;
    for (int i = 0; i < cantidadRegistros; i++)
    {
        registroPaquete = pArchivo.leer(i);
        FechaHora fechaSalida = registroPaquete.getFechaSalida();

        if (fechaSalida.getAnio() == anio &&
                (anio < hoy.getAnio() || !validar.validarFechaPosterior(hoy, fechaSalida.getDia(), fechaSalida.getMes(), fechaSalida.getAnio(), fechaSalida.getHora(), fechaSalida.getMinuto())
                ))
        {
            cantidadDestinosEnAnio++;
        }
    }

    if (cantidadDestinosEnAnio == 0)
    {
        cout << "No hay paquetes para el anio elegido cuya fecha de salida ya haya pasado." << endl;
        return;
    }

    int cantidadUnicaDestinos = 0;
    string* destinos = new string[cantidadDestinosEnAnio];
    int* acumulador = new int[cantidadDestinosEnAnio];

    if (destinos == nullptr || acumulador == nullptr)
    {
        cout << "No hay memoria suficiente." << endl;
        delete[] destinos;
        delete[] acumulador;
        return;
    }
    for(int i = 0; i < cantidadDestinosEnAnio; i++)
    {
        acumulador[i] = 0;
    }

    // Agrupar destinos y acumular cupos ocupados
    for (int i = 0; i < cantidadRegistros; i++)
    {
        registroPaquete = pArchivo.leer(i);
        FechaHora fechaSalida = registroPaquete.getFechaSalida();

        if (fechaSalida.getAnio() == anio &&
                (anio < hoy.getAnio() || !validar.validarFechaPosterior(hoy,
                        fechaSalida.getDia(),
                        fechaSalida.getMes(),
                        fechaSalida.getAnio(),
                        fechaSalida.getHora(),
                        fechaSalida.getMinuto()
                                                                       )))
        {

            string destinoActual = registroPaquete.getDestino();
            int cupos = registroPaquete.getCuposOcupados();

            bool encontrado = false;
            for (int j = 0; j < cantidadUnicaDestinos; j++)
            {
                if (destinos[j] == destinoActual)
                {
                    acumulador[j] += cupos;
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado)
            {
                destinos[cantidadUnicaDestinos] = destinoActual;
                acumulador[cantidadUnicaDestinos] = cupos;
                cantidadUnicaDestinos++;
            }
        }
    }

    // Buscar el destino con más cupos ocupados
    int mayorCantidadCuposOcupados = acumulador[0];
    string destinoMasCuposOcupados = destinos[0];

    for (int i = 1; i < cantidadUnicaDestinos; i++)
    {
        if (acumulador[i] > mayorCantidadCuposOcupados)
        {
            mayorCantidadCuposOcupados = acumulador[i];
            destinoMasCuposOcupados = destinos[i];
        }
    }

    // Mostrar el resultado
    cout << "En el año " << anio << ", el destino más visitado fue: "
         << destinoMasCuposOcupados << " con un total de "
         << mayorCantidadCuposOcupados << " cupos ocupados." << endl;

    // Liberar memoria
    delete[] destinos;
    delete[] acumulador;
}
void Informes::mostrarPorcentajeTemporada(){
    ReservaArchivo regReserva;
    PaqueteDeViajeArchivo regPaquete;
    Validaciones validar;

    Reserva reserva;
    PaqueteDeViaje paquete;
    FechaHora fecha;

    int cantTempAlta =0, cantTempBaja =0, anio;
    int totalReservasAnio = 0;
    int cantRegReserva = regReserva.getCantidadRegistros();
    int cantRegPaquete = regPaquete.getCantidadRegistros();

    do {
    cout << "Ingrese el anio (actual o anios anteriores): ";
    anio = validar.pedirNumero();
    if (!validar.validarIntPositivo(anio)) {
        cout << "Ingrese un anio válido." << endl;
    }
    } while (!validar.validarIntPositivo(anio));

    for (int i=0; i < cantRegReserva; i++){
        reserva = regReserva.leer(i);
        paquete = regPaquete.leer(reserva.getIidPaquete()-1);
        fecha = paquete.getFechaSalida();

        if (fecha.getAnio() == anio){
            if (paquete.getTemporadaAlta()){
                cantTempAlta += 1;
            }
            else {
                cantTempBaja += 1;
            }
        }
    }

    float porcAlta, porcBaja;
    totalReservasAnio = cantTempAlta + cantTempBaja;
    porcAlta = cantTempAlta*100/totalReservasAnio;
    porcBaja = cantTempBaja*100/totalReservasAnio;

    cout << "De un total de " << totalReservasAnio << " de reservas para el a�o " << anio << ", hubo un " << porcAlta << "% de reservas en temporada alta contra un " << porcBaja << "% de reservas en temporada baja." << endl;

}
void Informes::mostrarRecaudacionAnualGeneralPorAnio()
{
    Validaciones validar;
    FechaHora hoy;
    PagoArchivo pArchivo;
    Pago registroPago;
    int anio, i, m;
    float TotalVentaAnio = 0;
    float VecTotalMes[12] = {0};
    int cantidadRegistrosPagos = pArchivo.getCantidadRegistros();
    if (cantidadRegistrosPagos == 0)
    {
        cout << "No hay registros de pagos para analizar." << endl;
        cout << "\nPresione una tecla para volver al menu de informes..." << endl;
        system("pause");
        system("cls");
        return;
    }
    do
    {
        cout << "Ingrese el anio: ";
        cin >> anio;
        if (!validar.validarIntPositivo(anio))
        {
            cout << "El anio debe ser un numero positivo. Intente de nuevo." << endl;
        }
        else if (anio > hoy.getAnio())
        {
            cout << "El anio ingresado no puede ser mayor al anio actual (" << hoy.getAnio() << "). Intente de nuevo." << endl;
        }
    } while (!validar.validarIntPositivo(anio) || anio > hoy.getAnio());
    for (i = 0; i < cantidadRegistrosPagos; i++)
    {
        registroPago = pArchivo.leer(i);
        FechaHora fPago = registroPago.getFecha();
        if (fPago.getAnio() == anio)
        {
            TotalVentaAnio += registroPago.getImporte();
            if (fPago.getMes() >= 1 && fPago.getMes() <= 12) {
                VecTotalMes[fPago.getMes()] += registroPago.getImporte();
            }
        }
    }
    cout << "\n--- REPORTE DE RECAUDACION ANUAL ---" << endl;
    cout << "Las ventas totales para el anio " << anio << " son: $" << TotalVentaAnio << endl;
    cout << endl;
    string nombresMeses[] = {
        "","Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
    cout << left
         << setw(15) << "MES"
         << setw(20) << "RECAUDACION ($)"
         << endl;
    cout << string(35, '-') << endl;
    for (m = 1; m <= 12; m++)
    {
        cout << left
             << setw(15) << nombresMeses[m]
             << setw(20) << fixed << setprecision(2) << VecTotalMes[m] // Aplicar formato de moneda
             << endl;
    }
    cout << "\nPresione una tecla para volver al menu de informes..." << endl;
    system("pause");
    system("cls");
    return;
}

void Informes::mostrarRecaudacionAnualDelPaquete(){
    // Solicitar id de paquete y anio de dicha recaudacion
    int idPaquete;
    int anio;

    ReservaArchivo reservaArchivo;
    int reservaCantidadRegistro;
    Reserva *reservaVectorRegistro = nullptr;
    PagoArchivo pagoArchivo;
    int pagoCantidadRegistro;
    Pago *pagoVectorRegistro = nullptr;

    cout<<"Ingresa el ID del paquete para conocer su recaudacion anual";
    cin>>idPaquete;
    cin.ignore();


    cout<<"Ingresa el anio para conocer la recaudacion anual del paquete: "<< idPaquete<<endl;

    cout<<"Anio: "<<endl;
    cin>>anio;
    cin.ignore();
    //Verifico que los id de paquete y los anios son correctos

    // levantar todas las reservas relacionados al id de paquete
    reservaCantidadRegistro = reservaArchivo.getCantidadRegistros(),
    pagoCantidadRegistro = pagoArchivo.getCantidadRegistros();

    reservaVectorRegistro = new Reserva[reservaCantidadRegistro];
    pagoVectorRegistro = new Pago[pagoCantidadRegistro];

    if( reservaVectorRegistro == nullptr || pagoVectorRegistro == nullptr) {
        cout << "Ocurrio un error inesperado: " << endl;
        return;
    }

    for (int i=0 ; i<reservaCantidadRegistro ; i++){
        reservaVectorRegistro[i] = reservaArchivo.leer(i);
    }

    for (int i=0 ; i<pagoCantidadRegistro ; i++){
        pagoVectorRegistro[i] = pagoArchivo.leer(i);
    }


    // levantar todos los pagos que hagan referencia al id relacionado
    float recaudacionAnual = 0;
    for(int i=0 ; i < reservaCantidadRegistro; i++){
        if(reservaVectorRegistro[i].getIidPaquete() == idPaquete){
            for(int j=0 ; j<pagoCantidadRegistro; j++){
                if(pagoVectorRegistro[j].getFecha().getAnio() == anio
                   && pagoVectorRegistro[j].getIdReserva() == reservaVectorRegistro[i].getIdReserva()){
                    recaudacionAnual += pagoVectorRegistro[j].getImporte();
                }
            }
        }

    }

    // Mostrar el id del paquete con la suma del año.

    cout << "Para el idPaquete: "<< idPaquete <<" La suma total del año: "<<anio<<" es de: "<<recaudacionAnual<<endl;

}


void Informes::mostrarRecaudacionAnualDelCliente(){

    string dniCliente;
    int anio;

    Validaciones validar;
    clientearchivo clienteArchivo;
    Cliente cliente;
    int posicionClienteArchivo;
    ReservaArchivo reservaArchivo;
    int reservaCantidadRegistro;
    Reserva *reservaVectorRegistro = nullptr;
    PagoArchivo pagoArchivo;
    int pagoCantidadRegistro;
    Pago *pagoVectorRegistro = nullptr;

    /////////////////////////

    do{
        cout<<"Ingresa el DNI del cliente para conocer su recaudacion anual";
        cin >> dniCliente;
        if(!validar.validarCadenaDeNumeros(dniCliente)){
            cout << "El DNI debe contener solo números. Ingrese nuevamente." << endl;
        }else{
            posicionClienteArchivo = clienteArchivo.buscar(dniCliente);
            switch(posicionClienteArchivo){
                case -1:
                    cout << "No se encontro cliente para el dni ingresado. Por favor intente nuevamente" << endl;
                    break;
                case -2:
                    cout << "Ocurrio un error inexperado, intente nuevamente." << endl;
                    break;
                default:
                    cliente = clienteArchivo.leer(posicionClienteArchivo);
            }
        }
    }while(!validar.validarCadenaDeNumeros(dniCliente) || posicionClienteArchivo < 0);

    cout<<"Ingresa el anio para conocer la recaudacion anual del cliente: "<<cliente.getApellido()<<", "<<cliente.getNombre()<<endl;
    cout<<"Anio: "<<endl;
    cin>>anio;
    cin.ignore();
    //Verifico que los id de paquete y los anios son correctos

    // levantar todas las reservas relacionados al id de paquete
    reservaCantidadRegistro = reservaArchivo.getCantidadRegistros(),
    pagoCantidadRegistro = pagoArchivo.getCantidadRegistros();

    reservaVectorRegistro = new Reserva[reservaCantidadRegistro];
    pagoVectorRegistro = new Pago[pagoCantidadRegistro];

    if( reservaVectorRegistro == nullptr || pagoVectorRegistro == nullptr) {
        cout << "Ocurrio un error inesperado: " << endl;
        return;
    }

    for (int i=0 ; i<reservaCantidadRegistro ; i++){
        reservaVectorRegistro[i] = reservaArchivo.leer(i);
    }

    for (int i=0 ; i<pagoCantidadRegistro ; i++){
        pagoVectorRegistro[i] = pagoArchivo.leer(i);
    }


    // levantar todos los pagos que hagan referencia al id relacionado
    float recaudacionAnualCliente = 0;
    for(int i=0 ; i < reservaCantidadRegistro; i++){
        if(reservaVectorRegistro[i].getIdCliente() == cliente.getidCliente()){
            for(int j=0 ; j<pagoCantidadRegistro; j++){
                if(pagoVectorRegistro[j].getFecha().getAnio() == anio
                   && pagoVectorRegistro[j].getIdReserva() == reservaVectorRegistro[i].getIdReserva()){
                    recaudacionAnualCliente += pagoVectorRegistro[j].getImporte();
                }
            }
        }

    }

    cout << "Para el cliente: "<< cliente.getApellido()<<", "<<cliente.getNombre()<<" La suma total del año: "<<anio<<" es de: "<<recaudacionAnualCliente<<endl;

}