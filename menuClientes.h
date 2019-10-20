#ifndef MENUCLIENTES_H_INCLUDED
#define MENUCLIENTES_H_INCLUDED


#include "funciones.h"
///PROTOTIPO FUNCIONES GLOBALES
const char* traerMes(int);
const char* traerGenero(char);
bool existe(const char*);
void buscarCliente (const char*);


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
    const char* getLocalidad(){return localidad;}
    short getPiso(){return piso;}
    ///SETS()
    void setCalle(char*);
    void setNumero(int);
    void setCP(int);
    void setLocalidad(char*);
    void setPiso(short);
};

Direccion::Direccion(char street[30]="CASA S/NÚMERO",int num=0000,int codP=0000,char local[30]="aaaa",short p=0){
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
void Direccion::setLocalidad(int nuevaLocalidad){
localidad=nuevaLocalidad;
}
void Direccion::setPiso(int nuevoPiso){
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

void
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
    const char* getApellido(){return apellidos;}
    const char* getNombre(){return nombres;}
    char getGenero(){return genero;}
    const char* getDni(){return dni;}
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
    bool grabarPersona();
    void listadoAlfabetico();
    int contarRegistros();


};

void Persona::setApellido(char *nuevoApellido){
strcpy(apellidos,nuevoApellido);
}
void Persona::setNombre(char *nuevoNombre){
strcpy(apellidos,nuevoApellido);
}
void Persona::setGenero(char nuevoGenero){
genero=nuevoGenero;
}
void Persona::setDni(char *nuevoDni){
strcpy(dni,nuevoDni);
}
void Persona::setNacionalidad(char *nuevoNacionalidad){
strcpy(nacionalidad,nuevoNacionalidad);
}

void Persona::cargar(){

    cout << "APELLIDO: ";
    cin.ignore();
    cin.getline(apellidos,50);
    cout << "NOMBRE: ";
    cin.ignore();
    cin.getline(nombres,50);
    cout << "GÉNERO---> "<<endl;
    cout << "M)Mujer    "<<endl;
    cout << "H)Hombre   "<<endl;
    cout << "O)Otro     "<<endl;
    cout << "OPCIÓN---> ";
    cin  >> genero;
    cout << "DNI: ";
    cin.ignore();
    cin.getline(dni,15);
    cout << "NACIONALIDAD: ";
    cin.ignore();
    cin.getline(nacionalidad,50);
    cout << "FECHA DE NACIMIENTO--->"<<endl;
    fechaNac.cargar();

}

void Persona::mostrar(){

    cout << "APELLIDO            ---> "<< apellidos << endl;
    cout << "NOMBRE              ---> "<< nombres   << endl;
    cout << "GÉNERO              ---> "<< traerGenero(genero) << endl;
    cout << "DNI                 ---> "<< dni          << endl;
    cout << "NACIONALIDAD        ---> "<< nacionalidad << endl;
    cout << "FECHA DE NACIMIENTO ---> "<< fechaNac.mostrarConBarra() << endl;

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

bool Persona::grabarPersona(){

FILE*P;
P=fopen(FILE_MENORES,"ab");
if(P==NULL){
    mensaje(1);
    pausa();
    return false;
}
fwrite(this,sizeof(Persona),1,P);
fclose(P);
return true;
}

void Persona::ListadoAlfabetico(){

  long cant;
  cant=contarRegistros(FILE_PERSONA);
  if(cant==0){

        mensaje(2);
        pausa();
        return ;
    }
  Persona *vec;
  vec=(Persona*) malloc(cant*sizeof(Paciente));
  if(vec==NULL) return;

  copiarArchivoMemoria(vec,cant);
  ordenarVector(vec,cant);
  mostrarVector(vec,cant);// se muestra el vector ordenado
  pausa();
  borrarPantalla();
  free(vec);

}

void mostrarVector(Persona *v, long cant){
    int i;
    for(i=0; i<cant; i++){
        if(v[i].estado==true){
        v[i].mostrar();
        pausa();
        }
    }
}

void copiarArchivoMemoria(Persona*v,long cant){
  FILE *P;
  P=fopen(FILE_MENORES,"rb");
  if(P==NULL){
      mensaje(1);
      return;
      }
    fread(v, sizeof(Persona),cant,P);
  fclose(P);
  }

void ordenarVector(Persona*v, long cant){
  int i, j, posmin;
  Persona aux;
  for(i=0;i<cant-1;i++){


      posmin=i;
      for(j=i+1;j<cant;j++){
        if(strcmp(v[posmin].getNombre,v[j].getNombre)>0)
                posmin=j;
      }
      aux=v[i];
      v[i]=v[posmin];
      v[posmin]=aux;
    }
  }







int Persona::contrarRegistros(){
    FILE *P;
    F=fopen(FILE_MENORES,"rb");
    if(F==NULL)
    {
        mensaje(1);
        pausa();
        return -1;
    }
    int tam,tamanioreg,cantidad;
    fseek (F,0,SEEK_END);
    tam=ftell(P);
    tamanioreg=sizeof(Persona);
    cantidad=tam/tamanioreg;
    fclose(P);
    return cantidad;

}




/// CLASE CLIENTE ///

class Cliente:Persona {
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
    Direccion getDomicilio{return domicilio};


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
void  Cliente::setTelefono(char *nuevoTelefono){
strcpy(telefono,nuevoTelefono);
}
void  Cliente::setNroTarjeta(char *nuevaTarjeta){
strcpy(tarjeta,nuevaTarjeta);
}
void  Cliente::setCodigoSeguridad(char *nuevoCS){
strcpy(codSeguridad,CS);
}

void Cliente::cargar(){
    Persona::cargar();
    cout << "MAIL: ";
    cin.ignore();
    cin.getline(mail,50);
    cout << "TELEFONO: ";
    cin.ignore();
    cin.getline(telefono,30);
    cout <<"DOMICILIO--->"<<endl;
    domicilio.cargar();
    cout << "NRO.TARJETA: ";
    cin.ignore();
    cin.getline(NroTarjeta,30);
    cout << "CODIGO DE SEGURIDAD: ";
    cin.ignore();
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
    cout << "VENCIMIENTO TARJETA --->"<< vencimientoTarjeta << endl;
    cout << "#############################"<< endl;
    pausa();

}
/// FUNCIONES PARA COMBINAR CON HABITACIONES
bool existe(const char*doc){
FILE*P;
P=fopen(FILE_CLIENTES,"rb");
if(P==NULL){

    mensaje(1);
    pausa();
    return false;
}
Cliente aux;
while(fread(this,sizeof(Cliente),1,P)==1){
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

    mensaje(1);
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




#endif // MENUCLIENTES_H_INCLUDED
