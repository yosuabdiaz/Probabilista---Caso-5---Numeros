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
#include <bits/stdc++.h>

using namespace std;
 // [(1,2,900,800)]   = una linea >> Forma en la que llega la lista


listaSimple llenadoLista(int lineas){
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

vector<int> sacardistribucion(listaSimple listaLineas){
	vector<int>distribucion;
	nodo* aux;
	aux = listaLineas.primero;
	int seccion1=0;
	int seccion2=0;
	int seccion3=0;
	int semitotal=0;
	while(aux!=NULL){
		if(aux->y_salida==0 and aux->x_salida <= 359){
			semitotal++;
			int x = aux->x_salida;
			//cout<<x<<endl;
			if(x <= 119){
				//cout<<x<<endl;
				seccion1++;
			}
			if(x >= 120 and x <= 240){
				//cout<<x<<endl;
				seccion2++;
			}
			if(x >= 241 and x <= 359){
				//cout<<x<<endl;
				seccion3++;
			}
		}
		aux=aux->siguiente;	
	}
	/*
	cout<<"semitotal: "<<semitotal<<endl;
	cout<<"seccion1: "<<seccion1<<endl;
	cout<<"seccion2: "<<seccion2<<endl;
	cout<<"seccion3: "<<seccion3<<endl;
	*/
	distribucion.push_back((int)((static_cast<double>(seccion1)/semitotal)*100));
	distribucion.push_back((int)((static_cast<double>(seccion2)/semitotal)*100));
	distribucion.push_back((int)((static_cast<double>(seccion3)/semitotal)*100));
	
	/*for (size_t i = 0; i < distribucionArriba.size(); i++) {
    	cout << distribucion[i] <<endl;
 	}*/
	aux = listaLineas.primero;
	seccion1=0;
	seccion2=0;
	seccion3=0;
	semitotal=0;
	while(aux!=NULL){
		if(aux->x_salida == 0){
			semitotal++;
			int y = aux->y_salida;
			//cout<<x<<endl;
			if(y <= 306){
				//cout<<x<<endl;
				seccion1++;
			}
			if(y >= 307 and y <= 613){
				//cout<<x<<endl;
				seccion2++;
			}
			if(y >= 614){
				//cout<<x<<endl;
				seccion3++;
			}
		}
		aux=aux->siguiente;	
	}
	distribucion.push_back((int)((static_cast<double>(seccion1)/semitotal)*100));
	distribucion.push_back((int)((static_cast<double>(seccion2)/semitotal)*100));
	distribucion.push_back((int)((static_cast<double>(seccion3)/semitotal)*100));
	return distribucion;
}


int main(){
	int lineas;
	cout<<"Ingresar numero de trazos"<<endl;
	cin>>lineas;
	cout<<"Llenando la lista con los trazos"<<endl;
	listaSimple listaLineas;
	listaLineas = llenadoLista(lineas);// lista de lineas = {(1,2,3,4),(1,2,3,4),(1,2,3,4),(1,2,3,4)}
	vector<int> distribucion;
	distribucion = sacardistribucion(listaLineas);
	for (size_t i = 0; i < distribucion.size(); i++) {
    	cout << distribucion[i] <<endl;
 	}
	return 0;
}