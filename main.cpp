/*
Suponga que hay una pantalla de 1080x920
y se trazan K líneas saliendo de un punto cualquiera en X=0 ó Y=0 y 
llegando a otro punto cualquiera en X=1079 ó Y=919.Escriba un algoritmo probabilista en C++ 
donde dada la lista de las K líneas trazadas determine cuáles números de 1 dígito se formaron
en la visualización 2D de dichas líneas. Debe seguir el estándar de código del curso,
ser  orientad o a objetos ,buscar la simplicidad del algoritmo y la forma en que demuestra que
el resultado es justificable
*/ 

#include <iostream>
#include "list.cpp"
#include <cstdlib>

using namespace std;
 // [(1,2,900,800)]   = una linea >> Forma en la que llega la lista

listaSimple llenadolista(int lineas){
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
	cout<<"lista llenada"<<endl;
	return listalineas;
}

void numeros(int n , listaSimple listalineas){
	cout<<"hola";
}

int main(){
	int lineas;
	cout<<"Ingresar numero de trazos"<<endl;
	cin>>lineas;
	cout<<"Llenando la lista con los trazos"<<endl;
	listaSimple listaLineas;
	listaLineas = llenadolista(lineas);
	int op=1;
	int n=0;
	do{
		cout<<"Que numero desea consultar?"<<endl;
		cin>>n;
		numeros(n,listaLineas);
		cout<<endl<<"1-Volver "<<endl<<"0-Salir"<<endl;
		cin>>op;
	}while(op!=0);
	return 0;
}