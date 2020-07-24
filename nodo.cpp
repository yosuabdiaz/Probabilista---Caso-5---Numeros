#ifndef NODO_CPP
#define NODO_CPP
#include "nodo.h"


nodo::nodo(int xsalida,int ysalida ,int xllegada,int yllegada)
{
    x_salida = xsalida;
    y_salida = ysalida;
    x_llegada = xllegada;
    y_llegada = yllegada;

    siguiente = NULL;
}

nodo::nodo(int xsalida,int ysalida ,int xllegada,int yllegada, nodo * signodo){
    x_salida = xsalida;
    y_salida = ysalida;
    x_llegada = xllegada;
    y_llegada = yllegada;
    siguiente = signodo; 
}
#endif
