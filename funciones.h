#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void ponerVecEnCero(int*,int);
void ponerMatEnCero(float [20][3]);
void borrarPantalla();
void pausa();
void FechaHora();

void borrarPantalla()
{
#ifdef __unix__
    system("clear");
#elif defined(_WIN32) || defined(WIN32)
    system("cls");
#endif
}

void pausa()
{
#ifdef __unix__
    cin.get();
    cin.get();
#elif defined(_WIN32) || defined(WIN32)
    system("pause >nul");
#endif

}
void ponerVecEnCero(int*v,int tam){
int i;
for(i=0;i<tam;i++){
    v[i]=0;
}

};

void ponerMatEnCero(float mat[20][3]){

    int i,x;
    for(i=0;i<20;i++){
        for (x=0;x<3;x++){
                mat[i][x]=0;
            }

}

}

/*int Persona::contrarRegistros(const char*RUTA) DEVUELVE LA CANTIDAD DE REGISTROS 
{
    FILE *P;
    F=fopen(RUTA,"rb");
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

}*/


void FechaHora(){ 


    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    ///FECHA ACTUAL tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year
    cout << tmPtr->tm_mday <<"/"<<tmPtr->tm_mon+1<<"/"<<1900+tmPtr->tm_year<<endl;
    cout << tmPtr->tm_hour<<":"<<tmPtr->tm_min<<":"<<tmPtr->tm_sec<<endl;

}

#endif // FUNCIONES_H_INCLUDED
