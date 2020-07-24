#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"
#include <iostream>
#include <string>

using namespace std;


class listaSimple
{
    public:
        listaSimple();
        ~listaSimple();
        void InsertarFinal(int xsalida,int ysalida ,int xllegada,int yllegada);//METODO PARA LA COLA
        bool ListaVacia();
        void Mostrar();
        void Siguiente();
        int largoLista();
        nodo* primero;
        nodo* actual;
        listaSimple llenadoLista(int lineas);
};

#endif // LISTA_H
