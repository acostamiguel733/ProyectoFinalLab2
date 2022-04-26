#ifndef PAQUETE_H
#define PAQUETE_H


class Paquete{
    private:
        int _alto, _largo, _ancho, _idPaquete;
        float _peso;
    public:
        void cargar();
        void mostrar();
        int getIdpaquete();
        int getAlto();
        int getLargo();
        int getAncho();
        float getPeso();
        void setIdpaquete(int );
        void setAlto(int);
        void setLargo(int);
        void setAncho(int);
        void setPeso(float);
        bool grabarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);
};

#endif // PAQUETE_H
