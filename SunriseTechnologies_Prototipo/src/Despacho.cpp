#include <iostream>
#include <cstring>
#include "Despacho.h"
using namespace std;
void Despacho::mostrar(){
    cout << "  DNI DEL CLIENTE " << _dni << endl;
    cout << "  ID PAQUETE: " << _idPaquete << endl;
    cout << "  NUMERO DE VUELO: " << _numVuelo << endl;
    cout << "  IMPORTE A PAGAR : " << _importe << endl ;
}
int Despacho::getNumDespacho(){
    return _numDespacho;
}
int Despacho::getnumVuelo(){
    return _numVuelo;
}
int Despacho::getIdPaquete(){
    return _idPaquete;
}

void Despacho::setNumDespacho(int  num){
    _numDespacho=num;
}
void Despacho::setCliente(char  *cliente){
    strcpy(_dni,cliente);
}
void Despacho::setPaquete(int paquete){
    _idPaquete=paquete;
}
void Despacho::setVueloparaencomienda(int vuelo){
    _numVuelo=vuelo;
}
void Despacho::setImporte(float imp){
    _importe=imp;
}
bool Despacho::grabarEnDisco(int pos){
    bool guardo;
    FILE *p;
    p = fopen("despacho.dat", "rb+");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Despacho)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;

}
void Despacho::grabarEnDisco(){
    FILE *p;
    p = fopen("despacho.dat", "ab");
    if( p == NULL ){
        return;
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}
bool Despacho::leerDeDisco(int pos){
    bool lectura;
    FILE *p;
    p = fopen("despacho.dat", "rb");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Despacho)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}


