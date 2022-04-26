#ifndef DIRENTREGA_H
#define DIRENTREGA_H


class DirEntrega{
    private:
        char _calle[25], _localidad[25], _provincia[25];
        int _altura, _despacho;
    public:
        int getDespacho();
        void cargar();
        void mostrar();
        void setDni(char *);
        void setCalle(char *);
        void setLocalidad(char*);
        void setProvincia(char*);
        void setAltura(int);
        void setDespacho(int);
        bool grabarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);

};

#endif // DIRENTREGA_H
