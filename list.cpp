#include "list.h"
#include "node.h"
#include <iostream>
#include <string.h>
using namespace std;


listaSimple::listaSimple()
{
    primero = actual = NULL;
}

listaSimple::~listaSimple()
{
   nodo* aux;
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   actual = NULL;
}



bool listaSimple::ListaVacia(){
    return primero == NULL;
}

int listaSimple::largoLista(){
    int cont=0;

    nodo* aux;
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

void listaSimple::InsertarInicio(int xsalida,int ysalida ,int xllegada,int yllegada)
{
   if (ListaVacia())
     primero = new nodo(xsalida,ysalida,xllegada,yllegada);
   else
     primero=new nodo(xsalida,ysalida,xllegada,yllegada,primero);
}

void listaSimple::InsertarFinal(int xsalida,int ysalida ,int xllegada,int yllegada)
{
   if (ListaVacia())
     primero = new nodo(xsalida,ysalida,xllegada,yllegada);
   else
     {
         nodo* aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodo(xsalida,ysalida,xllegada,yllegada);
      }
}



void listaSimple::Mostrar()
{
   nodo *aux;
   aux = primero;
   while(aux) {
      cout<< "Cordenadas de inicio: ("<<aux->x_salida<<","<<aux->y_salida<<") y Cordenadas de llegada: ("<<aux->x_llegada<<","<<aux->y_llegada<<")\n";
      aux = aux->siguiente;
   }
   cout << endl;
}


void listaSimple::Siguiente()
{
   if(actual) actual = actual->siguiente;
}
