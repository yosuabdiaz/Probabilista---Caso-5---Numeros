/*
Suponga que hay una pantalla de 1080x920
y se trazan K líneas saliendo de un punto cualquiera en X=0 ó Y=0 y 
llegando a otro punto cualquiera en X=1079 ó Y=919.Escriba un algoritmo probabilista en C++ 
donde dada la lista de las K líneas trazadas determine cuáles números de 1 dígito se formaron
en la visualización 2D de dichas líneas. Debe seguir el estándar de código del curso,
ser  orientad o a objetos ,buscar la simplicidad del algoritmo y la forma en que demuestra que
el resultado es justificable
*/ 
#include <cstdlib>
#include <iostream>
#include "list.cpp"
#include "node.h"
#include "listaDistribucion.cpp"
#include "node_distribucion.h"


using namespace std;
 // [(1,2,900,800)]   = una linea >> Forma en la que llega la lista

int* generarArreglo(int id,int tipo,int ancho,int alto){
	if(tipo==0){
		int* arr = new int[4]; 
		return arr;
	}else{
		int* arr = new int[6]; 
		return arr;
	}

}

bool esLateralDerecho(nodo* linea,int alto,int ancho){
	//ver si el punto de salida es desde la derecha tomando en cuanta el ancho y alto 
}
bool esLateralIzquierdo(nodo* linea,int alto,int ancho){
	//ver si el punto de salida es desde la izquierda tomando en cuanta el ancho y alto	
}
bool esLaterialSuperior(nodo* linea,int alto,int ancho){
	//ver si el punto de salida es desde arriba tomando en cuanta el alto y alto
}
bool esLaterialInferior(nodo* linea,int alto,int ancho){
	//ver si el punto de salida es desde abajo tomando en cuanta el ancho y alto
}

listaSimpleD llenadoDistribucion(int ancho, int alto){
	listaSimpleD listaDistribucion;	
	listaDistribucion.InsertarFinal(0,generarArreglo(0,0,ancho,alto),generarArreglo(0,1,ancho,alto)); //0 para arriba y abajo - 1 para derecha e izquierda
	listaDistribucion.InsertarFinal(1,generarArreglo(1,0,ancho,alto),generarArreglo(1,1,ancho,alto));
	listaDistribucion.InsertarFinal(285,generarArreglo(285,0,ancho,alto),generarArreglo(285,1,ancho,alto));
	listaDistribucion.InsertarFinal(3,generarArreglo(3,0,ancho,alto),generarArreglo(3,1,ancho,alto));
	listaDistribucion.InsertarFinal(4,generarArreglo(4,0,ancho,alto),generarArreglo(4,1,ancho,alto));
	listaDistribucion.InsertarFinal(6,generarArreglo(6,0,ancho,alto),generarArreglo(6,1,ancho,alto));
	listaDistribucion.InsertarFinal(79,generarArreglo(79,0,ancho,alto),generarArreglo(79,1,ancho,alto));
	cout<<"lista de distribucion llenada"<<endl;
	return listaDistribucion;
}
listaSimple llenadoLista(int lineas){
	listaSimple listalineas;
	for (int i=0;i<lineas;i++){
		int random= rand()%6+1; 
		int y = rand()%920+1;
		int x = rand()%1080+1;
		int y_llegada = rand()%920+1;
		int x_llegada = rand()%1080+1;
		switch(random)
		{
			case 1:{
				listalineas.InsertarFinal(x,0,x_llegada,920);
				break;
				}
			case 2:{
				listalineas.InsertarFinal(x,0,0,y_llegada);
				break;
				}
			case 3:{
				listalineas.InsertarFinal(x,0,1080,y_llegada);
				break;
				}
			case 4:{
				listalineas.InsertarFinal(0,y,1080,y_llegada);
				break;
			}
			case 5:{
				listalineas.InsertarFinal(0,y,x_llegada,920);
				break;
			}
			case 6:{
				listalineas.InsertarFinal(1080,y,x_llegada,920);
			}
			
		}
	}
	cout<<"lista de lineas llenada"<<endl;
	return listalineas;
}

int main(){
	
	int lineas;
	cout<<"Ingresar numero de trazos"<<endl;
	cin>>lineas;
	cout<<"Llenando la lista con los trazos"<<endl;
	listaSimple listaLineas;
	listaLineas = llenadoLista(lineas);// lista de lineas = {(1,2,3,4),(1,2,3,4),(1,2,3,4),(1,2,3,4)}
	
	int ancho,alto;
	cout<<"Cual seria el alto:"<<endl;
	cin>>alto;
	cout<<"Cual seria el ancho"<<endl;
	cin>>ancho;
	listaSimpleD listaDistribucion;
	listaDistribucion = llenadoDistribucion(ancho,alto);// lista de distribucion  = {(id,arr[],arr[])};
	
	nodo* aux1;
	aux1 = listaLineas.primero;
		
	while(aux1!=NULL){ // recorre la lista de lineas
		aux1 = aux1->siguiente;	
	}
	return 0;
}