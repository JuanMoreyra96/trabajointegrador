#pragma once
#include <string>
class Persona{
     private:
        char _dni[9];
        char _nombre[50];
        char _apellido[50];
        char _email[50];
        char _celular[10];
        bool _estado;
     public:
        Persona();
        Persona(std::string dni, std::string nombre, std::string apellido,std::string email, std::string celular, bool estado);
        std::string getDni();
        std::string getNombre();
        std::string getApellido();
        std::string getEmail();
        std::string getCelular();
        bool getEstado();
        void setDni(std::string dni);
        void setNombre(std::string nombre);
        void setApellido(std::string apellido);
        void setEmail(std::string email);
        void setCelular(std::string celular);
        void setEstado(bool estado);
        void Mostrar();
        bool Cargar();
    };
