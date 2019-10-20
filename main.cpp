#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <time.h>
#include <clocale>
using namespace std;
#include "menuPrincipal.h"
//#include "cliente.h"
#include "misFunciones.h"
//#include "habitaciones.h"


///PROTOTIPO DE FUNCIONES
void crearArchivos();
void cClientes();
void cHabitaciones();
void cEmpleados();
void cMenores();
void cConsumos();
bool validarLogin(char*);
bool validarContrasenia(char*);
    /// ARCHIVOS
    ///const char *FILE_LOGIN = "usuarios.dat"; LOS LOGIN Y CONTRA SE AGREGARAN A LA CLASE EMPLEADOS PARA DIFERENCIARLOS
    const char *FILE_CLIENTES = "clientes.dat";
    const char *FILE_HABITACIONES = "habitaciones.dat";
    const char *FILE_EMPLEADOS = "empleados.dat";
    const char *FILE_MENORES = "menores.dat";
    const char *FILE_CONSUMOS = "consumos.dat";

void crearArchivos(){


 ///cClientes();
 ///cHabitaciones();
 ///cEmpleados();
 ///cMenores();
 ///cConsumos();

}


/*class Login{
private:
    char login[20];
    char contrasenia[20];
public:
    void cargar();
    void mostrar();
    ///GETS()
    const char* getLogin(){return login;}
    const char* getContrasenia (){return contrasenia;}
    ///SETS
    void setLogin(char*);
    void setContrasenia(char*);

};*/


int main(){
setlocale (LC_ALL, "spanish");
char log[20];
char pass[20];
bool usuario=false;
int login,contra;
char cerrar[2];
 while(true){
    borrarPantalla();
    char opc;
    cout << "1)INGRESAR--->"<< endl;
    cout << "2)<---SALIR"<< endl;
    cout << "OPCIÓN: ";
    cin  >> opc;
    switch(opc){
      case '1':
      case 'a':
      case 'A':
          while(usuario==false){
    cout << "Login: ";
    cin.getline(log,20);
    cout << "Contraseña: ";
    cin.ignore();
    cin.getline(pass,20);
//    login=validarLogin(log);
  //  contra=validarContrasenia(pass);
    if((login!=-1)&&(contra!=-1)){
        usuario=true;
    }
    if (login==-1){
        cout << "LOGIN NO REGISTRADO"<<endl;
        pausa();

    }

    if(contra==-1){
        cout << "CONTRASEÑA INCORRECTA"<< endl;
        pausa();
    }
    } /// fin verificacion de usuario

    menuPrincipal(login);

    break;
      case '2':
      case 'b':
      case 'B':
          cout << "¿Seguro que quiere cerrar el programa?"<< endl;
            cout << "si-no: ";
            cin  >>  cerrar;
            if (strcmp(cerrar,"si")==0){
                return 0;
            }

          break;
    }

 }

pausa();
return 0;
}
