#ifndef NODO_H
#define NODO_H
#include <iostream>

class listaSimple;

class nodo
{
    friend class listaSimple;
    public:

        nodo(int xsalida,int ysalida ,int xllegada,int yllegada);
        nodo(int xsalida,int ysalida ,int xllegada,int yllegada, nodo * signodo);
        int x_salida;
    	int y_salida;
    	int x_llegada;
    	int y_llegada;

        nodo *siguiente;
};

#endif // NODO_H

