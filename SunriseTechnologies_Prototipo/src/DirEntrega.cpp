#include "DirEntrega.h"
#include <iostream>
#include <cstring>
#include "Cliente.h"
#include "Persona.h"
using namespace std;

void DirEntrega::cargar(){
    cin.ignore();
    cout << "  INGRESE EL NOMBRE DE LA CALLE : "  ;
    cin.getline(_calle,25);
    cout << "  INGRESE LA ALTURA : " ;
    cin >> _altura;
    cin.ignore();
    cout << "  INGRESE LA LOCALIDAD : "  ;
    cin.getline(_localidad,25);
    cout << "  INGRESE LA PROVINCIA : " ;
    cin.getline(_provincia,25);

}
void DirEntrega::mostrar(){
    cout << "CALLE : " << _calle << endl ;
    cout << "ALTURA :" << _altura << endl ;
    cout << "LOCALIDAD :" << _localidad << endl ;
    cout << "PROVINCIA :" << _provincia << endl ;
    cout << "ID DESPACHO :" << _despacho << endl ;
}
int DirEntrega::getDespacho(){
    return _despacho;
}
void DirEntrega::setDespacho(int num){
    _despacho=num;
}
void DirEntrega::setCalle(char *calle){
    strcpy(_calle,calle);
}
void DirEntrega::setLocalidad(char* localidad){
    strcpy(_localidad, localidad);
}
void DirEntrega::setProvincia(char* provincia){
    strcpy(_provincia,provincia);
}
void DirEntrega::setAltura(int altura){
    _altura=altura;
}
bool DirEntrega::grabarEnDisco(int pos){
    bool guardo;
    FILE *p;
    p = fopen("DireccionDeEntrega.dat", "rb+");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(DirEntrega)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}
void DirEntrega::grabarEnDisco(){
    FILE *p;
    p = fopen("DireccionDeEntrega.dat", "ab");
    if( p == NULL ){
        return;
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}
bool DirEntrega::leerDeDisco(int pos){
    bool lectura;
    FILE *p;
    p = fopen("DireccionDeEntrega.dat", "rb");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(DirEntrega)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}

