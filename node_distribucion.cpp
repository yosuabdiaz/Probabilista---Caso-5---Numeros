#include "node_distribucion.h"

nodoDistribucion::nodoDistribucion(int id,int aA[4],int dI[6])
{
    numeroIdentificador = id;
    arribaAbajo[4] = aA[4];  
    derechaIzquierda[6] = dI[6];
    siguiente = NULL;
}

nodoDistribucion::nodoDistribucion(int id,int aA[4],int dI[6],nodoDistribucion* signodo){
    numeroIdentificador = id;
    arribaAbajo[4] = aA[4];  
    derechaIzquierda[6] = dI[6]; 
    siguiente = signodo; 
}
