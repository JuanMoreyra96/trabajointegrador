#pragma once

class FechaHora{
private:
    int _dia;
    int _mes;
    int _anio;
    int _hora;
    int _minuto;

public:
    FechaHora();
    FechaHora(int dia, int mes, int anio, int hora, int minuto);

    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinuto();

    void setDia(int dia);
    void setMes (int mes);
    void setAnio (int anio);
    void setHora (int hora);
    void setMinuto (int minuto);

    void Mostrar();
     int convertirADiasTotales(FechaHora fecha);
    int calcularDiferenciaDeDias(FechaHora fecha1, FechaHora fecha2);
    bool esBisiesto(int anio);
    int contarAniosBisiestos(int anio);
};

//prueba
