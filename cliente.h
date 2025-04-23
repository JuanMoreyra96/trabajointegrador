#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <string>
 class cliente{
     private:
        int _dni;
        char _nombre[30];
        char _apellido[30];
        int _telefono;
        char _direccion[30];
        char _email[30];
        bool _reservado;
        //fecha fechareserva //(composision) usamos un objeto de una clase como propiedad de otra.
     public:
        cliente();
        cliente(int dni, std::string nombre, std::string apellido,int telefono, std::string direccion,std::string email, bool reservado);

        int getDni();
        std::string getNombre();
        std::string getApellido();
        int getTelefono();
        std::string getDireccion();
        std::string getEmail();
        bool getReservado();

        void setDni(int dni);
        void setNombre(std::string nombre);
        void setApellido(std::string apellido);
        void setTelefono(int telefono);
        void setDireccion(std::string direccion);
        void setEmail(std::string email);
        void setReservado(bool reservado);

        std::string toString();

    };

#endif // CLIENTE_H_INCLUDED
