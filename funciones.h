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

void FechaHora(){ /// MUESTRA FECHA Y HORA ACTUALES


    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    ///FECHA ACTUAL tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year
    cout << tmPtr->tm_mday <<"/"<<tmPtr->tm_mon+1<<"/"<<1900+tmPtr->tm_year<<endl;
    cout << tmPtr->tm_hour<<":"<<tmPtr->tm_min<<":"<<tmPtr->tm_sec<<endl;

}


class Fecha /// DEVUELVE FECHA Y HORA ACTUAL
{
private:
    int anio,mes,dia,hora,minuto;
    time_t tiempo;
    char cad[80];
    struct tm *tmPtr;
public:
    Fecha(int a,int b,int c,int d,int e)
    {
        anio=a;
        mes=b;
        dia=c;
        hora=d;
        minuto=e;
    }
    Fecha()
    {
        tiempo = time(NULL);
        tmPtr = localtime(&tiempo);

        anio=tmPtr->tm_year+1900;
        mes=tmPtr->tm_mon+1;
        dia=tmPtr->tm_mday;
        hora=tmPtr->tm_hour;
        minuto=tmPtr->tm_min;
        /*printf("FECHA ACTUAL \n%d/%d/%d %d:%d:%d", tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year, tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec);
        strftime(cad, 80, "%A %d de %B de %Y", tmPtr);
        printf("\n\n%s", cad);*/
    }
    int mostar_anio()
    {
        return anio;
    }
    int mostar_mes()
    {
        return mes;
    }
    int mostar_dia()
    {
        return dia;
    }
    int mostar_hora()
    {
        return hora;
    }
    int mostar_minuto()
    {
        return minuto;
    }
};

void mensajes(int opcion){ /// MENSAJES GENERALES

switch(opcion){
case 1:
    cout << "ERROR AL ABRIR ARCHIVO"<< endl;
    break;

}



}

#endif // FUNCIONES_H_INCLUDED
