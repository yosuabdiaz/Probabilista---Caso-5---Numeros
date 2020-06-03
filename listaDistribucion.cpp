
#include "listaDistribucion.h"
#include "node_distribucion.h"
#include <iostream>
#include <string.h>
using namespace std;

listaSimpleD::listaSimpleD()
{
    primero = actual = NULL;
}


bool listaSimpleD::ListaVacia(){
    return primero == NULL;
}

int listaSimpleD::largoLista(){
    int cont=0;

    nodoDistribucion* aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }

}


void listaSimpleD::InsertarFinal(int id,int aA[4],int dI[6])
{
   if (ListaVacia())
     primero = new nodoDistribucion(id,aA,dI);
   else
     {
         nodoDistribucion* aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodoDistribucion(id,aA,dI);
      }
}



void listaSimpleD::Mostrar()
{
   nodoDistribucion *aux;
   aux = primero;
   while(aux) {
      cout<<"Arriba y Abajo"<<endl;
      for (int i=0; i<4;i++){
        cout<<aux->arribaAbajo[i]<<"-";
      }

      cout<<endl<<"Derecha y Izquierda"<<endl;
      for (int i=0; i<6;i++){
        cout<<aux->derechaIzquierda[i]<<"-";
      }      
      aux = aux->siguiente;
   }
   cout << endl;
}


void listaSimpleD::Siguiente()
{
   if(actual) actual = actual->siguiente;
}
