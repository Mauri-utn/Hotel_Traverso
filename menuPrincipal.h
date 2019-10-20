#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

//#include "cliente.h"
//#include "habitaciones.h"

int menuPrincipal(int);
#include "misFunciones.h"


int menuPrincipal(int permisos){

    fechaHora();
    char opcion;
    while(true){
        borrarPantalla();
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
        break;
      case '2':
      case 'b':
      case 'B':
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



#endif // MENUPRINCIPAL_H_INCLUDED
