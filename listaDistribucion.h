#include "node_distribucion.cpp"
#include <iostream>
#include <string>

using namespace std;

class listaSimpleD{
    public:
        listaSimpleD();
        void InsertarFinal(int id,int aA[4],int dI[6]);
        bool ListaVacia();
        void Mostrar();
        void Siguiente();
        int largoLista();
        nodoDistribucion* primero;
        nodoDistribucion* actual;
};