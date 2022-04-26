#include <iostream>
#include <cstring>
#include "VueloParaEncomienda.h"
using namespace std;

void VueloParaEncomienda::cargar(){
    cout << "  CODIGO DE AEROPUERTO PARTIDA: ";
    cin.getline(_codigoPartida,4);
    cout << "  CODIGO DE AEROPUERTO DESTINO: ";
    cin.getline(_codigoDestino,4);
    cout << "  FECHA DE EMBARQUE: " << endl ;
    _fechaEmbarque.cargar();
    cout << "  INDIQUE LA CAPACIDAD EN KG DEL AVION QUE SE UTILIZA:" << endl;
    cin >> _capacidad;
}
int VueloParaEncomienda::getidVuelo(){
    return _idVuelo;
}
void VueloParaEncomienda::mostrar(){
    cout << "ID DE VUELO : "  << _idVuelo << endl ;
    cout << "CAPACIDAD DEL VUELO : " << _capacidad << endl ;
    cout << "CODIGO DE DESTINO :" << _codigoDestino << endl ;
    cout << "CODIGO DE PARTIDA :" << _codigoPartida << endl ;
    cout << "FECHA DE EMBARQUE :" ;
    _fechaEmbarque.mostrar();
}
char *VueloParaEncomienda::getCodigoDestino(){
    return _codigoDestino;
}
float VueloParaEncomienda::getCapacidad(){
    return _capacidad;
}
void VueloParaEncomienda::setMatriculaAvion(char *matricula){
    strcpy(_matriculaAvion,matricula);
}
void VueloParaEncomienda::setIdVuelo(int idvuelo){
    _idVuelo=idvuelo;
}
void VueloParaEncomienda::setCodigoDestino(char *coddestino){
    strcpy(_codigoDestino,coddestino);
}
void VueloParaEncomienda::setCodigoPartida(char *codpartida){
    strcpy(_codigoPartida,codpartida);
}
void VueloParaEncomienda::setFechaEmbarque(Fecha fechaembarque){
    _fechaEmbarque=fechaembarque;
}
void VueloParaEncomienda::setCapacidad(float capacidad){
    _capacidad=capacidad;
}
bool VueloParaEncomienda::grabarEnDisco(int pos){
    bool guardo;
    FILE *p;
    p = fopen("Vueloparaencomienda.dat", "rb+");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(VueloParaEncomienda)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}
void VueloParaEncomienda::grabarEnDisco(){
    bool guardo;
    FILE *p;
    p = fopen("Vueloparaencomienda.dat", "ab");
    if( p == NULL ){
        return;
    }
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);

}
bool VueloParaEncomienda::leerDeDisco(int pos){
    bool lectura;
    FILE *p;
    p = fopen("Vueloparaencomienda.dat", "rb");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(VueloParaEncomienda)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}
