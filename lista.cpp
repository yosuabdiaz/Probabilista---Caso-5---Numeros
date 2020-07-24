#ifndef LISTA_CPP
#define LISTA_CPP
#include "lista.h"
#include "nodo.h"
#include <iostream>
#include <string.h>
#include <cstdlib>

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
//funcion: llenar el espacio de 920,1080 de lienas a base de valores random
listaSimple listaSimple::llenadoLista(int lineas){
	listaSimple listalineas;
	for (int i=0;i<lineas;i++){
		int random= rand()%6+1; 
		int y = rand()%919+0;
		int x = rand()%1079+0;
		int y_llegada = rand()%919+0;
		int x_llegada = rand()%1079+0;
		switch(random)
		{
			case 1:{
				listalineas.InsertarFinal(x,0,x_llegada,919);
				break;
				}
			case 2:{
				listalineas.InsertarFinal(x,0,0,y_llegada);
				break;
				}
			case 3:{
				listalineas.InsertarFinal(x,0,1079,y_llegada);
				break;
				}
			case 4:{
				listalineas.InsertarFinal(0,y,1079,y_llegada);
				break;
			}
			case 5:{
				listalineas.InsertarFinal(0,y,x_llegada,919);
				break;
			}
			case 6:{
				listalineas.InsertarFinal(1079,y,x_llegada,919);
			}
			
		}
	}
	cout<<"lista de lineas llenada"<<endl;
	//listalineas.Mostrar();
	return listalineas;
}
#endif
