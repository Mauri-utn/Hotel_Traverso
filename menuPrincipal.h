#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED


//#include "cliente.h"
//#include "habitaciones.h"

int menuPrincipal(int);
#include "misFunciones.h"
#include "menuClientes.h"
#include "menuHabitaciones.h"


int menuPrincipal(int permisos){



    if(permisos==1){
    char opcion;
    while(true){
        borrarPantalla();
        fechaHora(); /// ver funcion actualizar segundo a segundo 
        cout << "---------PRINCIPAL---------" << endl;
        cout << "---------------------------" << endl;
        cout << "1) HABITACIONES    " << endl;
        cout << "2) CLIENTES        " << endl;
        cout << "3) EMPLEADOS       " << endl;
        cout << "4) MANTENIMIENTO   " << endl;
        cout << "5) LIMPIEZA        " << endl;
        cout << "6) CONFIGURACION   " << endl;
        cout << "0) Salir "<< endl;
        cout << endl << "Opción: ";
        cin >> opcion;
        borrarPantalla();
        switch(opcion){
      case '1':
      case 'a':
      case 'A':
          menuHabitaciones();
        break;
      case '2':
      case 'b':
      case 'B':
          menuClientes();
        break;
      case '3':
      case 'c':
      case 'C':
        break;
      case '4':
      case 'd':
      case 'D':
        break;
      case '5':
      case 'e':
      case 'E':
        break;
      case '6':
      case 'f':
      case 'F':
        break;
        case '0':
      return 0;
        break;
        default:
            break;
        }
        cout << endl;

      }
    }
    ///if(permisos==2)menuLimpieza();
    ///if(permisos==3)menuMantenimiento();
    return permisos;
}




#endif // MENUPRINCIPAL_H_INCLUDED
