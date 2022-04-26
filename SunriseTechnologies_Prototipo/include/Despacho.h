#ifndef DESPACHO_H
#define DESPACHO_H
#include "Cliente.h"
#include "Paquete.h"
#include "VueloParaEncomienda.h"

class Despacho{
    private:
        char _dni[9];
        int _idPaquete, _numVuelo, _numDespacho;
        float _importe;
    public:
        void mostrar();
        int getnumVuelo();
        int getIdPaquete();
        int getNumDespacho();
        void setNumDespacho(int);
        void setCliente(char *);
        void setPaquete(int);
        void setVueloparaencomienda(int);
        void setImporte(float );
        bool grabarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);
};

#endif // DESPACHO_H
