#ifndef VUELOPARAENCOMIENDA_H
#define VUELOPARAENCOMIENDA_H
#include "Fecha.h"

class VueloParaEncomienda{
    private:
        char _matriculaAvion[6];
        int _idVuelo;
        char _codigoDestino[4];
        char _codigoPartida[4];
        Fecha _fechaEmbarque;
        float _capacidad;
    public:
        void cargar();
        void mostrar();
        char *getCodigoDestino();
        float getCapacidad();
        int getidVuelo();
        void setMatriculaAvion(char *);
        void setIdVuelo(int);
        void setCodigoDestino(char *);
        void setCodigoPartida(char *);
        void setFechaEmbarque(Fecha);
        void setCapacidad(float );
        bool grabarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);
};

#endif // VUELOPARAENCOMIENDA_H
