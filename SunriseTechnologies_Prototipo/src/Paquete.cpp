#include <iostream>
#include <cstring>
#include "Paquete.h"
using namespace std;

void Paquete::cargar(){
    cout << "  INGRESE EL ALTO : "  ;
    cin >> _alto;
    if(_alto<=0){
        return;
    }
    cout << "  INGRESE EL LARGO : "  ;
    cin >> _largo;
    if(_largo<=0){
        return;
    }
    cout << "  INGRESE EL ANCHO : "  ;
    cin >> _ancho;
    if(_ancho<=0){

    }
    cout << "  INGRESE EL PESO : "  ;
    cin >> _peso;
    if(_peso<=0){
        return;
    }
}
void Paquete::mostrar(){
    cout << "ID PAQUETE : " << _idPaquete << endl;
    cout << "ALTO : " << _alto << endl ;
    cout << "LARGO : " << _largo << endl ;
    cout << "ANCHO : " << _ancho << endl ;
    cout << "PESO : " << _peso << endl ;
}
int Paquete::getIdpaquete(){
    return _idPaquete;
}
int Paquete::getAlto(){
    return _alto;
}
int Paquete::getLargo(){
    return _largo;
}
int Paquete::getAncho(){
    return _ancho;
}
float Paquete::getPeso(){
    return _peso;
}
void Paquete::setIdpaquete(int idpaquete){
    _idPaquete=idpaquete;
}
void Paquete::setAlto(int alto){
    _alto=alto;
}
void Paquete::setLargo(int largo){
    _largo=largo;
}
void Paquete::setAncho(int ancho){
    _ancho=ancho;
}
void Paquete::setPeso(float peso){
    _peso=peso;
}
bool Paquete::grabarEnDisco(int pos){
    bool guardo;
    FILE *p;
    p = fopen("Paquete.dat", "rb+");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Paquete)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}
void Paquete::grabarEnDisco(){
    FILE *p;
    p = fopen("Paquete.dat", "ab");
    if( p == NULL ){
        return;
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);

}
bool Paquete::leerDeDisco(int pos){
    bool lectura;
    FILE *p;
    p = fopen("Paquete.dat", "rb");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Paquete)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}

