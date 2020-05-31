#ifndef LIST_H
#define LIST_H
#include "node.cpp"
#include <iostream>
#include <string>

using namespace std;


class listaSimple
{
    public:
        listaSimple();
        ~listaSimple();
        void InsertarInicio(int xsalida,int ysalida ,int xllegada,int yllegada);
        void InsertarFinal(int xsalida,int ysalida ,int xllegada,int yllegada);//METODO PARA LA COLA
        bool ListaVacia();
        void BorrarFinal();
        void BorrarInicio(); //METODO PARA LA COLA
        void BorrarPosicion(int pos);
        int Buscar(int pos);
        void MostrarObj();
        void Mostrar();
        void Siguiente();
        int largoLista();
        nodo* primero;
        nodo* actual;
};

#endif // LIST_H
