#ifndef NODE_DISTRIBUCION_H
#define NODE_DISTRIBUCION_H
#include <iostream>

class listaSimpleD;

class nodoDistribucion
{
    friend class listaSimpleD;
    public:

        nodoDistribucion(int id,int aA[4],int dI[6]);
        nodoDistribucion(int id,int aA[4],int dI[6],nodoDistribucion* signodo);
       	int numeroIdentificador;
       	int arribaAbajo[4];
       	int derechaIzquierda[6];

        nodoDistribucion *siguiente;
};

#endif // NODE_H