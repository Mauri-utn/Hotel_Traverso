#ifndef MENUCLIENTES_H_INCLUDED
#define MENUCLIENTES_H_INCLUDED


#include "misFunciones.h"
const char* traerMes(int);
const char* traerGenero(char);
bool validarDni(const char *);
bool validarFechadeNac(int,int,int);
bool validarTarjeta(char*);
const char *FILE_CLIENTES     = "clientes.dat";
const char *FILE_MENORES      = "menores.dat";

    /// ////// ///
    /// CLASES ///
    /// ///// ///

    class Direccion{

private:
    char calle[30];
    int numero;
    int cp;
    char localidad[30];
    short piso;
public:
    Direccion(char*,int,int,char*,short);
    void mostrar();
    void cargar();
    ///GETS()
    const char* getCalle(){return calle;}
    int getNumero(){return numero;}
    int getCP(){return cp;}
    char* getLocalidad(){return localidad;}
    short getPiso(){return piso;}
    ///SETS()
    void setCalle(char*);
    void setNumero(int);
    void setCP(int);
    void setLocalidad(char*);
    void setPiso(short);
};

Direccion::Direccion(char street[30]="CASA S/NÚMERO",int num=0000,int codP=0000, char local[30]="aaaa",short p=0){
    strcpy(calle,street);
    numero=num;
    cp=codP;
    strcpy(localidad,local);
    piso=p;
}


void Direccion::setCalle(char*nuevaCalle){
strcpy(calle,nuevaCalle);
}
void Direccion::setNumero(int nuevoNumero){
numero=nuevoNumero;
}
void Direccion::setCP(int nuevoCp){
cp=nuevoCp;
}
void Direccion::setLocalidad(char* nuevaLocalidad){
strcpy(localidad,nuevaLocalidad);
}
void Direccion::setPiso(short nuevoPiso){
piso=nuevoPiso;
}

void Direccion::cargar(){

    cout << "CALLE: ";
    cin.ignore();
    cin.getline(calle,30);
    cout << "NÚMERO: ";
    cin  >> numero;
    cout << "CODIGO POSTAL: ";
    cin  >> cp;
    cout << "LOCALIDAD: ";
    cin.ignore();
    cin.getline(localidad,30);
    cout << "PISO: ";
    cin  >> piso;
}
void Direccion::mostrar(){

cout << "CALLE        --->"<< calle << endl;
cout << "NÚMERO       --->"<< numero << endl;
cout << "CODIGO POSTAL--->"<< cp << endl;
cout << "LOCALIDAD    --->"<< localidad << endl;
cout << "PISO         --->"<< piso << endl;
}

    /// CLASES FECHA ///
class Fecha{

private:
    int dia,mes,anio;
public:
    Fecha(int d=1,int m=1,int a=2000){
    dia=d;
    mes=m;
    anio=a;
    }
    void mostrar();
    void mostrarConBarra();
    void mostrarConPalabra();
    void cargar();
    void cargarVenc();
    void mostrarVenc();
    ///GETS()
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
   ///SETS()
    void setDia(int nuevoDia){
    dia=nuevoDia;
    }
    void setMes(int nuevoMes){
    mes=nuevoMes;
    }
    void setAnio(int nuevoAnio){
    anio=nuevoAnio;
    }
};

void Fecha::cargar(){

    cout << "DIA: ";
    cin  >> dia;
    cout << "MES: ";
    cin  >> mes;
    cout << "AÑO: ";
    cin >> anio;

}
void Fecha::cargarVenc(){
    cout << "Mes: ";
    cin  >> mes;
    cout << "Año: ";
    cin  >> anio ;
}
void Fecha::mostrarVenc(){

    cout << mes << "/" << anio <<endl;
}
void Fecha::mostrar(){
    cout << "DIA ---> "<< dia << endl;
    cout << "MES ---> "<< mes << endl;
    cout << "ANIO---> "<< anio << endl;
}


void Fecha::mostrarConBarra(){

    cout << dia << "/" << mes << "/" << anio << endl;

}

void Fecha::mostrarConPalabra(){

cout << dia << " de "<<traerMes(mes)<< " del "<< anio << endl;

}

const char* traerMes(int m){

switch(m){
    case 1:return "Enero";
    break;
    case 2:return "Febrero";
    break;
    case 3:return "Marzo";
    break;
    case 4:return "Abril";
    break;
    case 5:return "Mayo";
    break;
    case 6:return "Junio";
    break;
    case 7:return "Julio";
    break;
    case 8:return "Agosto";
    break;
    case 9:return "Septiembre";
    break;
    case 10:return "Octubre";
    break;
    case 11:return "Noviembre";
    break;
    case 12:return "Diciembre";
    break;
}

}
/// CLASE PERSONA /// SE USA PARA CARGAR UN MENOR DE EDAD Y PARTE DE UN CLIENTE
class Persona {

protected:

    char apellidos[50];
    char nombres[50];
    char genero;
    char dni[10];
    char nacionalidad[50];
    Fecha fechaNac;
public:
    void cargar();
    void mostrar();
    ///GETS()
    char* getApellido(){return apellidos;}
    char* getNombre(){return nombres;}
    char getGenero(){return genero;}
    char* getDni(){return dni;}
    const char* getNacionalidad(){return nacionalidad;}
    int getDiaNac(){return fechaNac.getDia();}
    int getMesNac(){return fechaNac.getMes();}
    int getAnioNac(){return fechaNac.getAnio();}

    /// SETS()
    void setApellido(char*);
    void setNombre(char*);
    void setGenero(char);
    void setDni(char*);
    void setNacionalidad(char*);
    void setDiaNac(int nDia){fechaNac.setDia(nDia);}
    void setMesNac(int nMes){fechaNac.setMes(nMes);}
    void setAnioNac(int nAnio){fechaNac.setAnio(nAnio);}
    ///FUNCIONES DE ARCHIVOS
    bool escribirDisco(int);
    bool leerDisco(int);




};

void Persona::setApellido(char *nuevoApellido){
strcpy(apellidos,nuevoApellido);
}
void Persona::setNombre(char *nuevoNombre){
strcpy(apellidos,nuevoNombre);
}
void Persona::setGenero(char nuevoGenero){
genero=nuevoGenero;
}
void Persona::setDni(char *nuevoDni){
strcpy(dni,nuevoDni);
}
void Persona::setNacionalidad(char *nuevaNacionalidad){
strcpy(nacionalidad,nuevaNacionalidad);
}

void Persona::cargar(){

    cout << "APELLIDO: ";
    cin.ignore();
    cin.getline(apellidos,50);
    cout << "NOMBRE: ";
    cin.getline(nombres,50);
    cout << "GÉNERO---> "<<endl;
    cout << "M)Mujer    "<<endl;
    cout << "H)Hombre   "<<endl;
    cout << "O)Otro     "<<endl;
    cout << "OPCIÓN---> ";
    cin  >> genero;
    cout << "DNI: ";
    cin.ignore();
    cin.getline(dni,10);
    while(!validarDni(dni)){
    borrarPantalla();
    char sel;
    cout << "EL DNI YA ESTA REGISTRADO"<<endl;
    cout << "salir(s)/cargar otro(c)"<< endl;
    cin  >> sel;
    switch (sel){
    case 's':
    case 'S':
    return;
    break;
    case 'c':
    case 'C':
    cout << "DNI: ";
    cin.ignore();
    cin.getline(dni,10);

    break;
default:
    mensajes(2);
    break;
        }
}
    cout << "NACIONALIDAD: ";
    cin.getline(nacionalidad,50);
    cout << "FECHA DE NACIMIENTO--->"<<endl;
    fechaNac.cargar();
    bool vof=validarFechadeNac(getDiaNac(),getMesNac(),getAnioNac());
    while (vof==false){
        borrarPantalla();
        cout <<"FECHA DE NACIMIENTO INVALIDA POR FAVOR VOLVER A INGRESAR!"<<endl;
        pausa();
        borrarPantalla();
        cout << "FECHA DE NACIMIENTO--->"<<endl;
        fechaNac.cargar();
        vof=validarFechadeNac(getDiaNac(),getMesNac(),getAnioNac());
    }

}

void Persona::mostrar(){

    cout << "APELLIDO            ---> "<< apellidos << endl;
    cout << "NOMBRE              ---> "<< nombres   << endl;
    cout << "GÉNERO              ---> "<< traerGenero(genero) << endl;
    cout << "DNI                 ---> "<< dni          << endl;
    cout << "NACIONALIDAD        ---> "<< nacionalidad << endl;
    cout << "FECHA DE NACIMIENTO ---> " ; fechaNac.mostrarConBarra();

}
const char* traerGenero(char g){

    switch(g){
    case 'm':
    case 'M':
    return "Mujer";
    break;
    case 'h':
    case 'H':
    return "Hombre";
    break;
    case 'o':
    case '0':
        return "Otro";
        break;
    }
}


    /// CLASE CLIENTE ///

class Cliente: public Persona  {
    private:
    char mail[50];
    int telefono;
    Direccion domicilio;
    char NroTarjeta[17],codSeguridad[5];
    Fecha vencimientoTarjeta;

    public:
    void cargar();
    void mostrar();
    ///GETS()
    const char* getMail(){return mail;}
    int getTelefono(){return telefono;}
    const char* getTarjeta(){return NroTarjeta;}
    const char* getCodSeguridad(){return codSeguridad;}
    int getMesVenc(){return vencimientoTarjeta.getMes();}
    int getAnioVenc(){return vencimientoTarjeta.getAnio();}



    /// SETS()
    void setMail(char*);
    void setTelefono(int);
    void setNroTarjeta(char*);
    void setCodigoSeguridad(char*);
    void setMesVenc(int nMes){vencimientoTarjeta.setMes(nMes);}
    void setAnioVenc(int nAnio){vencimientoTarjeta.setAnio(nAnio);}
    /// FUNCIONES CON ARCHIVOS
    bool escribirDisco(int);
    bool leerDisco(int);


};





void  Cliente::setMail(char *nuevoMail){
strcpy(mail,nuevoMail);
}
void  Cliente::setTelefono(int nuevoTelefono){
    telefono=nuevoTelefono;
}
void  Cliente::setNroTarjeta(char *nuevaTarjeta){
strcpy(NroTarjeta,nuevaTarjeta);
}
void  Cliente::setCodigoSeguridad(char *nuevoCS){
strcpy(codSeguridad,nuevoCS);
}

void Cliente::cargar(){
    Persona::cargar();
    cout << "MAIL: "; /// FALTA HACERLE VALIDACION
    cin.ignore();
    cin.getline(mail,50);
    cout << "TELEFONO: "; /// FALTA HACERLE VALIDACION
    cin  >> telefono;
    cout <<"DOMICILIO--->"<<endl; /// FALTA HACERLE VALIDACION
    domicilio.cargar();
    cout << "NRO.TARJETA: ";
    cin.ignore();
    cin.getline(NroTarjeta,30);
    while(!validarTarjeta(NroTarjeta)){
    borrarPantalla();
    char sel;
    cout << "LA TARJETA YA ESTA REGISTRADA"<<endl;
    cout << "salir(s)/cargar otra(c)      "<< endl;
    cin  >> sel;
    switch (sel){
    case 's':
    case 'S':
    return;
    break;
    case 'c':
    case 'C':
    cout << "NRO.TARJETA: ";
    cin.ignore();
    cin.getline(NroTarjeta,30);
    break;
default:
    mensajes(2);
    break;

    }
}
    cout << "CODIGO DE SEGURIDAD: ";
    cin.getline(codSeguridad,5);
    cout << "VENCIMIENTO TARJETA: ";
    vencimientoTarjeta.cargarVenc();

}



void Cliente::mostrar(){
    Persona::mostrar();
    cout << "MAIL                --->"<< mail << endl;
    cout << "TELEFONO            --->"<< telefono << endl;
    cout << "DOMICILIO           --->"<<endl;
    domicilio.mostrar();
    cout << "NRO.TARJETA         --->"<< NroTarjeta << endl;
    cout << "CÓDIGO DE SEGURIDAD --->"<< codSeguridad << endl;
    cout << "VENCIMIENTO TARJETA --->"; vencimientoTarjeta.mostrarVenc();
    cout << "#############################"<< endl;


}

///PROTOTIPO FUNCIONES GLOBALES

bool existeCliente(const char*);
bool existeMenor(const char*);
void buscarCliente (const char*);
int menuClientes();
void nuevoCliente(); /// crea un nuevo cliente y lo graba
int listarTodos(); /// menu para listar clientes segun opcion ingresada
/// TODOS LOS MENUS VAN CON INT PARA DIFERENCIARLOS DE OTRAS FUNCIONES ///
void listadoAlfabeticoMenores(); /// listado albafetico de menores
void listadoAlfabeticoCliente(); /// listado de A-Z
void listarClientes(); /// lista primero el mas viejo en el sistema
void copiarArchivoMemoriaCliente(Cliente *,long);
void ordenarVectorCliente(Cliente *,long);
void mostrarVectorCliente(Cliente *,long);
void heapsortClientes(Cliente *, long); /// prueba de ordenamiento por heapsort



bool validarDni(const char*);
int contarRegistrosMenores();/// cuenta la cantidad de registros que hay en el archivo menores
int contarRegistrosClientes();/// cuenta la cantidad de registros que hay en el archivo clientes

bool grabarPersona(Persona);
bool grabarCliente(Cliente);
void copiarArchivoMemoria(Persona*,long);
void mostrarVectorPersona(Persona *, long );
void ordenarVectorPersona(Persona*, long );
int biciesto(int);

void cargarDias(int *, int );
/// FUNCIONES GLOBALES CLIENTES
void nuevoCliente(){
char selec;
cout << "1)CARGAR NUEVO CLIENTE "<< endl;
cout << "2)CARGAR MENOR DE EDAD "<< endl;
cin  >> selec;
Cliente reg;
Persona registro;
if (selec=='1'||selec=='a'||selec=='A'){

reg.cargar();
}
else if(selec=='2'||selec=='b'||selec=='B'){

registro.cargar();
}
if (selec=='1'||selec=='a'||selec=='A'){

if(grabarCliente(reg)){
        cout << "CLIENTE GRABADO CON ÉXITO"<< endl;
        pausa();
        return;

  }

}
if(selec=='2'||selec=='b'||selec=='B'){
if(grabarPersona(registro)){
        cout << "MENOR GRABADO CON ÉXITO"<< endl;
        pausa();
        return;
     }
  }

}

int contarRegistrosClientes(){
    FILE *F;
    F=fopen(FILE_CLIENTES,"rb");
    if(F==NULL){
        mensajes(1);
        pausa();
        return -1;
    }
    int tam,tamanioreg,cantidad;
    fseek (F,0,SEEK_END);
    tam=ftell(F);
    tamanioreg=sizeof(Cliente);
    cantidad=tam/tamanioreg;
    fclose(F);
    return cantidad;

}

bool grabarCliente(Cliente aux){

FILE*P;
P=fopen(FILE_CLIENTES,"ab");
if(P==NULL){
    mensajes(1);
    pausa();
    return false;
}
fwrite(&aux,sizeof(Cliente),1,P);
fclose(P);
return true;
}

void listadoAlfabeticoCliente(){

  long cant;
  cant=contarRegistrosClientes();
  if(cant==0){

        mensajes(2);
        pausa();
        return ;
    }
  Cliente *vec;
  vec=(Cliente*) malloc(cant*sizeof(Cliente));
  if(vec==NULL) return;

  copiarArchivoMemoriaCliente(vec,cant);
  ordenarVectorCliente(vec,cant);
  mostrarVectorCliente(vec,cant);// se muestra el vector ordenado
  borrarPantalla();
  free(vec);

}
void copiarArchivoMemoriaCliente(Cliente *v,long cant){
  FILE *P;
  P=fopen(FILE_CLIENTES,"rb");
  if(P==NULL){
      mensajes(1);
      return;
      }
    fread(v, sizeof(Cliente),cant,P);
  fclose(P);
  }

  void ordenarVectorCliente(Cliente *v, long cant){
  int i, j, posmin;
  Cliente aux;
  for(i=0;i<cant-1;i++){


      posmin=i;
      for(j=i+1;j<cant;j++){
       if(strcmp(v[posmin].getNombre(),v[j].getNombre())>0)
                posmin=j;

      }
      aux=v[i];
      v[i]=v[posmin];
      v[posmin]=aux;


    }
}

void mostrarVectorCliente(Cliente *v, long cant){
    int i;
    for(i=0; i<cant; i++){
        ///if(v[i].estado==true){
        v[i].mostrar();
        pausa();
        ///}
      }
}

void listarClientes(){
  long cant;
  cant=contarRegistrosClientes();
  if(cant==0){

        mensajes(2);
        pausa();
        return ;
    }
  Cliente *vec;
  ///vec=(Cliente*) malloc(cant*sizeof(Cliente));
  vec = new Cliente[cant];
  if(vec==NULL) return;

  copiarArchivoMemoriaCliente(vec,cant);
  /// ordenarVectorCliente(vec,cant);
  mostrarVectorCliente(vec,cant);/// se muestra el vector sin ordenar
  borrarPantalla();
  delete vec;



}

void heapsortClientes(Cliente *v, long cant){

    for(k=n;k>0;k--)
    {
        for(i=1;i<=k;i++)
        {
            item=A[i];
            j=i/2;
            while(j>0 && A[j]<item)
            {
                A[i]=A[j];
                i=j;
                j=j/2;
            }
            A[i]=item;
        }
        temp=A[1];
        A[1]=A[k];
        A[k]=temp;
    }


}

/// FUNCIONES PARA COMBINAR CON HABITACIONES
bool existeCliente(const char*doc){
FILE*P;
P=fopen(FILE_CLIENTES,"rb");
if(P==NULL){

    mensajes(1);
    pausa();
    return false;
}
if(contarRegistrosClientes()==0){
    fclose(P);
 return false;
}
Cliente aux;
while(fread(&aux,sizeof(Cliente),1,P)==1){
    if (strcmp(doc,aux.getDni())==0){

        fclose(P);
        return true;
    }
     }
fclose(P);
return false;

}

void buscarCliente(const char*doc){
FILE*P;
P=fopen(FILE_CLIENTES,"rb");
if(P==NULL){

    mensajes(1);
    pausa();
    return;
}
Cliente aux;

while(fread(&aux,sizeof(Cliente),1,P)==1){
    if (strcmp(doc,aux.getDni())==0){

    /// lo que quieras
        fclose(P);
        return;
    }
     }
fclose(P);
return;

}
/// FIN FUNCIONES PARA COMBINAR CON HABITACIONES


/// FUNCIONES GLOBALES MENORES ///

bool grabarPersona(Persona aux){

FILE*P;
P=fopen(FILE_MENORES,"ab");
if(P==NULL){
    mensajes(1);
    pausa();
    return false;
}
fwrite(&aux,sizeof(Persona),1,P);
fclose(P);
return true;
}

void listadoAlfabeticoMenores(){

  long cant;
  cant=contarRegistrosMenores();
  if(cant==0){

        mensajes(2);
        pausa();
        return ;
    }
  Persona *vec;
  vec=(Persona*) malloc(cant*sizeof(Persona));
  if(vec==NULL) return;

  copiarArchivoMemoria(vec,cant);
  ordenarVectorPersona(vec,cant);
  mostrarVectorPersona(vec,cant);// se muestra el vector ordenado
  pausa();
  borrarPantalla();
  free(vec);

}
void copiarArchivoMemoria(Persona *v,long cant){
  FILE *P;
  P=fopen(FILE_MENORES,"rb");
  if(P==NULL){
      mensajes(1);
      return;
      }
    fread(v, sizeof(Persona),cant,P);
  fclose(P);
  }

  void ordenarVectorPersona(Persona *v, long cant){
  int i, j, posmin;
  Persona aux;
  for(i=0;i<cant-1;i++){


      posmin=i;
      for(j=i+1;j<cant;j++){
       if(strcmp(v[posmin].getNombre(),v[j].getNombre())>0)
                posmin=j;

      }
      aux=v[i];
      v[i]=v[posmin];
      v[posmin]=aux;


    }
}

void mostrarVectorPersona(Persona *v, long cant){
    int i;
    for(i=0; i<cant; i++){
        ///if(v[i].estado==true){
        v[i].mostrar();
        pausa();
        ///}
      }
}

int contarRegistrosMenores(){
    FILE *F;
    F=fopen(FILE_MENORES,"rb");
    if(F==NULL){
        mensajes(1);
        pausa();
        return -1;
    }
    int tam,tamanioreg,cantidad;
    fseek (F,0,SEEK_END);
    tam=ftell(F);
    tamanioreg=sizeof(Persona);
    cantidad=tam/tamanioreg;
    fclose(F);
    return cantidad;

}

bool existeMenor(const char*docu){
    FILE*P;
    P=fopen(FILE_CLIENTES,"rb");
    if(P==NULL){

    mensajes(1);
    pausa();
    return false;
    }
    if(contarRegistrosMenores()==0){
        fclose(P);
        return false;
    }

    Cliente aux;
    while(fread(&aux,sizeof(Cliente),1,P)==1){
    if (strcmp(docu,aux.getDni())==0){

        fclose(P);
        return true;
        }
     }
    fclose(P);
    return false;

}
int listarTodos(){

char opcion;
while(true){
    borrarPantalla();
    cout << "LISTADO DE CLIENTES" << endl;
    cout << "-------------------" << endl;
    cout << "1) Listado alfabetico clientes" << endl;
    cout << "2) Listado por antiguedad clientes    " << endl;
    cout << "3) Listado Heapsort." << endl;
    ///cout << "4) PUNTO C." << endl;
    ///cout << "5) PUNTO D." << endl;
    cout << "0) volver al menú clientes"<< endl;
    cout << endl << "Opción: ";
    cin >> opcion;
    borrarPantalla();
    switch(opcion){
      case '1':
      case 'a':
      case 'A':
        listadoAlfabeticoCliente();
      break;
      case '2':
      case 'b':
      case 'B':
        listarClientes();
      break;
      case '3':
      case 'c':
      case 'C':
        heapsortClientes();
      break;
      case '0':
        return 0;
      break;
    }
    cout << endl;

  }

}



int menuClientes(){
char op;
while(true){
    borrarPantalla();
    cout << "-----------CLIENTES----------" << endl;
    cout << "-----------------------------" << endl;
    cout << "1) NUEVO CLIENTE             " << endl; /// se carga nuevo cliente y menores de edad
    cout << "2) MODIFICAR CLIENTE.        " << endl;/// modifica el campo que le indiquemos
    cout << "3) BUSCAR CLIENTE            " << endl; /// busca y muestra un cliente segun lo que se ingrese por teclado
    cout << "4) MOSTRAR TODOS LOS CLIENTES" << endl; /// muestra todos ordenados alfabeticamente o segun se indique por teclado
    cout << "0) Salir "<< endl;
    cout << endl << "Opción: ";
    cin >> op;
    borrarPantalla();
    switch(op){
      case '1':
      case 'a':
      case 'A':
      nuevoCliente();
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
          listarTodos();
        break;
      case '0':
        return 0;
      break;
    }
    cout << endl;

  }


}


/// VALIDACIONES ///


bool validarFechadeNac(int _dia,int _mes, int _anio){

    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    ///FECHA ACTUAL tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year

    if(_dia<0||_mes<0||_anio<0)return false;
    if(_anio>1900+tmPtr->tm_year||_anio<1900)return false;
    int *vecdias;
    const int meses=12;
    int a;
    a=biciesto(_anio);
    if(a==1){
        vecdias=(int*)malloc(meses*sizeof(int));
        cargarDias(vecdias,1);
        if(_dia>vecdias[_mes-1]){
            free(vecdias);
            return false;
        }
    }
    else{
        vecdias=(int*)malloc(meses*sizeof(int));
        cargarDias(vecdias,0);
        if(_dia>vecdias[_mes-1]){
            free(vecdias);
            return false;
        }
    }
    if (_anio==1900+tmPtr->tm_year){
        if (_mes>tmPtr->tm_mon+1)
            return false;
        if(_mes==tmPtr->tm_mon+1){
            if(_dia>tmPtr->tm_mday){
                return false;
            }
        }
    }
    return true;
}
int biciesto(int a){

    if ((a%4==0&&a%100!=0)||a%400==0)
        return 1;
    else
        return 0;
}
void cargarDias(int *dias, int opc){
    if (opc==1){
        dias[0]=31;
        dias[1]=29;
        dias[2]=31;
        dias[3]=30;
        dias[4]=31;
        dias[5]=30;
        dias[6]=31;
        dias[7]=31;
        dias[8]=30;
        dias[9]=31;
        dias[10]=30;
        dias[11]=31;
    }
    else{
        dias[0]=31;
        dias[1]=28;
        dias[2]=31;
        dias[3]=30;
        dias[4]=31;
        dias[5]=30;
        dias[6]=31;
        dias[7]=31;
        dias[8]=30;
        dias[9]=31;
        dias[10]=30;
        dias[11]=31;
    }
}

bool validarDni(const char *doc){



if(existeCliente(doc)){

    return false;
}
if(existeMenor(doc)){
    return false;
}

return true;
}

bool validarTarjeta(char *tarjeta){
FILE*P;
P=fopen(FILE_CLIENTES,"rb");
if(P==NULL){
    mensajes(1);
    pausa();
    return false;
}
if(contarRegistrosClientes()==0){

    fclose(P);
    return true;
}
Cliente aux;
while(fread(&aux,sizeof(Cliente),1,P)==1){

    if(strcmp(tarjeta,aux.getTarjeta())==0){
            fclose(P);
            return false;
    }

}
fclose(P);
return true;

}





#endif // MENUCLIENTES_H_INCLUDED
