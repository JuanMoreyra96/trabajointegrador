#ifndef PAQUETEDEVIAJEMANAGER_H_INCLUDED
#define PAQUETEDEVIAJEMANAGER_H_INCLUDED

class PaqueteDeViajeManager{
private:

public:
  void cargarPaqueteDeViaje();
  void mostrarCantidadRegistros();
  void listarTodos(); // activos e inactivos
  void listarPaquetesActivos(); //solo activos: que todavia no se hicieron
  //void listarPaquetesInactivos();
  // void listarPaquetesPasados --> no confundir con inactivos
  void modificarCuposOcupadosEnPaquete();
};
#endif
