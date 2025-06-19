#pragma once

class ReservaManager{
private:

public:
  void CargarReserva();
  void MostrarCantidadRegistros();
  void ListarTodos(); // activos e inactivos
  void ListarReservasDeudaCancelada(); //solo reservas con deuda cancelada
  void BuscarReservasDeCliente(int dni);
  void listarTodasAlfabeticamentePorDestino();

};
