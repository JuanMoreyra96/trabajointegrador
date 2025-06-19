#ifndef RESERVAMANAGER_H_INCLUDED
#define RESERVAMANAGER_H_INCLUDED



class ReservaManager{
private:

public:
  void CargarReserva();
  void MostrarCantidadRegistros();
  void ListarTodos(); // activos e inactivos
  void ListarReservasDeudaCancelada(); //solo reservas con deuda cancelada
  void ListarReservasDeudaNoCancelada(); //solo reservas sin deuda cancelada
  void BuscarReservasDeCliente();
  void listarTodasAlfabeticamentePorDestino();
  void buscarReservasDeUnDestino();

};


#endif // RESERVAMANAGER_H_INCLUDED
