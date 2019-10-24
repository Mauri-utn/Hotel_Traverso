#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <time.h>
#include <clocale>
using namespace std;
#include "menuPrincipal.h"
#include "menuClientes.h"
#include "misFunciones.h"
#include "menuHabitaciones.h"
#include "login_pass.h"


///PROTOTIPO DE FUNCIONES
void abrirArchivos();
void cClientes();
void cHabitaciones();
void cEmpleados();
void cMenores();
void cConsumos();
void cGastos();
bool validarLogin(char*);
bool validarContrasenia(char*);
int ingresar();
    /// ARCHIVOS
    ///const char *FILE_LOGIN = "usuarios.dat"; LOS LOGIN Y CONTRA SE AGREGARAN A LA CLASE EMPLEADOS PARA DIFERENCIARLOS


    const char *FILE_EMPLEADOS    = "empleados.dat";
    const char *FILE_CONSUMOS     = "consumos.dat";

void abrirArchivos(){


 cClientes();
 cHabitaciones();
 cEmpleados();
 cMenores();
 cConsumos();
 cGastos();
}
void cClientes(){
    FILE*C;
    C=fopen(FILE_CLIENTES,"ab");
    if(C==NULL)return;
    fclose(C);
    return;
}
void cHabitaciones(){
    FILE*H;
    H=fopen(FILE_HABITACIONES,"ab");
    if(H==NULL)return;
    fclose(H);
    return;
}
void cEmpleados(){
    FILE*E;
    E=fopen(FILE_EMPLEADOS,"ab");
    if(E==NULL)return;
    fclose(E);
    return;
}
void cMenores(){
    FILE*M;
    M=fopen(FILE_MENORES,"ab");
    if(M==NULL)return;
    fclose(M);
    return;
}
void cConsumos(){
    FILE*C;
    C=fopen(FILE_CONSUMOS,"ab");
    if(C==NULL)return;
    fclose(C);
    return;
}
void cGastos(){

    FILE*G;
    G=fopen(FILE_GASTOS,"ab");
    if(G==NULL)return;
    fclose(G);
    return;
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
abrirArchivos();
setlocale (LC_ALL, "spanish");
int login=1;
char cerrar[2];
 while(true){
    borrarPantalla();
    char opc;
    cout << "1)INGRESAR                     --->"<< endl;
    cout << "2)SALIR                        --->"<< endl;
    cout << "3)RECUPERAR CONTRASEÑA         --->"<<endl;
    cout << "4)CAMBIAR CONTRASEÑA           --->"<<endl;
    cout << "OPCIÓN: ";
    cin  >> opc;
    switch(opc){
      case '1':
      case 'a':
      case 'A':

    ///login=ingresar();
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

      case '3':
      case 'c':
      case 'C':
          menuLogins(opc);
        break;
      case '4':
      case 'd':
      case 'D':
          menuLogins(opc);
        break;
      default:
        break;
    }

 }

pausa();
return 0;
}

int ingresar(){
    char log[20];
    char pass[20];
    bool usuario=false;
    int contAdmin=0;
    int contUsuario=0;
    cout << "Usuario: ";
    cin.getline(log,20);
    cout << "Contraseña: ";
    cin.getline(pass,20);
    if ((strcmp(log,"admin")==0){


        }







}


/*
cout << "Login: ";
    cin.ignore();
    cin.getline(log,20);
    if (strcmp(log,"admin")==0){
    cout << "Contraseña: ";
    cin.ignore();
    cin.getline(pass,20);
    if(strcmp(pass,"7705")==0){
        return 1;
    } else {
    cout << "contraseña de admin incorrecta"<<endl;
    pausa();

    }
}
    if(usuario==false){
            //  login=validarLogin(log);
    }
    else {
        login=-1;
    }
    if ((login==-1)&&(usuario==false)){
        cout << "LOGIN NO REGISTRADO"<<endl;
        pausa();
    }
    if(login!=-1){
    cout << "Contraseña: ";
    cin.ignore();
    cin.getline(pass,20);
   //  contra=validarContrasenia(pass);
    }

    if(contra==-1){
        cout << "CONTRASEÑA INCORRECTA"<< endl;
        pausa();
    }
    if((login!=-1)&&(contra!=-1)){
        usuario=true;
    }

    cont++;
    if (cont==3){
        cout << "DEMASIADOS INTENTOS VUELVA A INTENTARLO MAS TARDE"<< endl;
        pausa();
        return -1;
         }*/

