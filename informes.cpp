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
void Informes::mostrarPaquetesParaPublicidad() {
    FechaHora fechaActual;
    PaqueteDeViajeArchivo pArchivo;
    PaqueteDeViaje registro, paqueteMasCercano;
    int cantidadRegistros = pArchivo.getCantidadRegistros();
    Validaciones val;

    int diferenciaMenor = -1;
    bool encontrado = false;

    for (int i = 0; i < cantidadRegistros; i++) {
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

        if (esValido) {
            int diferencia = fechaActual.calcularDiferenciaDeDias(fechaActual, fechaDelRegistro);

            if (!encontrado || diferencia < diferenciaMenor) {
                diferenciaMenor = diferencia;
                paqueteMasCercano = registro;
                encontrado = true;
            }
        }
    }

    if (encontrado) {
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
    } else {
        std::cout << "No hay paquetes disponibles con baja ocupación y fecha futura.\n";
    }
}
void Informes::mostrarClientesQueAdeudan() {
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

    for (int i = 0; i < cantidadRegistros; i++) {
        registro = rArchivo.leer(i);

        if (!registro.getDeudaCancelada()) {
            float sumaPagos = 0;

            registroCliente = cArchivo.leer(registro.getIdCliente());
            registroPaquete = paqueteArchivo.leer(registro.getIidPaquete());

            for (int j = 0; j < cantidadRegistrosPagos; j++) {
                registroPago = pagoArchivo.leer(j);
                if (registroPago.getIdReserva() == registro.getIdReserva()) {
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
