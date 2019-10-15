#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

const char* traerMes(int);
const char* traerGenero(char);

class Direccion{

private:
    char calle[30];
    int numero;
    int cp;
    char localidad [30];
    short piso;
public:
    Direccion(char*,int,int,char*,short);
    void mostrar();
    void cargar();
    ///GETS()
    const char* getCalle(){return calle};
    int getNumero(){return numero};
    int getCP(){return cp};
    const char* getLocalidad();{return localidad}
    short getPiso();{return piso}
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
void Fecha::mostrar(){
    cout << "DIA ---> "<< dia << endl;
    cout << "MES ---> "<< mes << endl;
    cout << "ANIO---> "<< anio << endl;
}

void Fecha::mostrarConBarra(){

    cout << dia << "/" << mes << "/" << anio << endl;

}

void mostrarConPalabra(){

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

class Persona {

protected:

    char apellidos[50];
    char nombres[50];
    char genero;
    char dni[15];
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
    /// SETS()
    void setApellido(char*);
    void setNombre(char*);
    void setGenero(char);
    void setDni(char*);
    void setNacionalidad(char*);

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


#endif // CLIENTES_H_INCLUDED
