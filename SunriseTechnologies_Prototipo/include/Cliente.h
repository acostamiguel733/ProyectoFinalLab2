#ifndef CLIENTE_H
#define CLIENTE_H
#include "Persona.h"

class Cliente:Persona{
    private:
        char _calle[25], _localidad[25], _provincia[25];
        int _altura;
    public:
        char *getDni();
        void cargar();
        void mostrar();
        void setCalle(char *);
        void setLocalidad(char*);
        void setProvincia(char*);
        void setAltura(int);
        bool grabarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);
};

#endif // CLIENTE_H
