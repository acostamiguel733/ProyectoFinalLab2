#include <iostream>
#include <cstring>
#include "Cliente.h"
#include "Persona.h"
using namespace std;

void Cliente::cargar(){
    Persona::cargar();
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
void Cliente::mostrar(){
    Persona::mostrar();
    cout << "CALLE : " << _calle << endl ;
    cout << "ALTURA :" << _altura << endl ;
    cout << "LOCALIDAD :" << _localidad << endl ;
    cout << "PROVINCIA :" << _provincia << endl ;
}
char *Cliente::getDni(){
    return _dni;
}
void Cliente::setCalle(char *calle){
    strcpy(_calle,calle);
}
void Cliente::setLocalidad(char* localidad){
    strcpy(_localidad, localidad);
}
void Cliente::setProvincia(char* provincia){
    strcpy(_provincia,provincia);
}
void Cliente::setAltura(int altura){
    _altura=altura;
}
bool Cliente::grabarEnDisco(int pos){
    bool guardo;
    FILE *p;
    p = fopen("Cliente.dat", "rb+");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Cliente)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}
void Cliente::grabarEnDisco(){
    FILE *p;
    p = fopen("Cliente.dat", "ab");
    if( p == NULL ){
        return;
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}
bool Cliente::leerDeDisco(int pos){
    bool lectura;
    FILE *p;
    p = fopen("Cliente.dat", "rb");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Cliente)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}

