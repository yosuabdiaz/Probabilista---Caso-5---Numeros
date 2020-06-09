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
void validarNumero(int distribucionVert[],int distribucionHor[]){
	bool forma=true;
	int num=0;
	switch(num){
		case 0:{
			forma=probarVert(0,distribucionVert[]);
			if(forma==true){
				forma=probarHor(0,distribucionHor[]);
				if(forma==true){
					cout<<"Se puede formar el n�mero 0" <<endl;
				}
				else{
					cout<<"No se puede formar el n�mero 0" <<endl;
				}
			}
			else{
				cout<<"No se puede formar el n�mero 0" <<endl;
			}
			break;
		}
		case 1:{
			break;
		}
		case 2:{
			break;
		}
		case 3:{
			break;
		}
		case 4:{
			break;
		}
		case 5:{
			break;
		}
		case 6:{
			break;
		}
		case 7:{
			break;
		}
		case 8:{
			break;
		}
		case 9:{
			break;
		}
	}
}
/*
void buscarNumero(int distribucion[]){
	int numero=0;
	for(numero; numero<10;numero++){
		switch(numero){
			case 0:{
				cout<<"PRUEBA0"<<endl;
				int contador=0;
				for(int j=0;j<2;j++){
					int lineaRandomVert= rand()%100+1;
					if(lineaRandomVert<distribucion[0]&&contador!=1){
						contador++;
					}
					else if(lineaRandomVert<(distribucion[1]+distribucion[0])&& contador!=2&& lineaRandomVert>(distribucion[0])){
						contador= contador+2;
					}
					else if(lineaRandomVert<(distribucion[2]+distribucion[1]+distribucion[0])&& contador!=3&& lineaRandomVert>(distribucion[1]+distribucion[0])){
						contador= contador+3;
					}
					else{
					cout<<"No se puede formar el 0"<<endl;
						contador=-1
					}
					
				}
				
				contador=0;
				for(int j=0;j<2;j++){
					int lineaRandomHor= rand()%100+1;
					if((lineaRandomHor<distribucion[3])&&(contador!=1)){
						contador++;
						if(j=1){
							cout<<"Se puede formar el 0"<<endl;
						}
					}
					else if(lineaRandomHor<(distribucion[3]+distribucion[4])&& contador!=2){
						contador= contador+2;
						if(j=1){
							cout<<"Se puede formar el 0"<<endl;
						}
					}
					else if(lineaRandomHor<(distribucion[3]+distribucion[4]+distribucion[5])&& contador!=3){
						contador= contador+3;
						if(j=1){
							cout<<"Se puede formar el 0"<<endl;
						}

					}
					else{
					cout<<"No se puede formar el 0"<<endl;
						break;
					}
					
				}
			}
			case 1:{
				cout<<"PRUEBA1"<<endl;
				if(distribucion[0]+distribucion[1]+distribucion[2]!=0){
					cout<<"Se puede formar el 1"<<endl;
				}
				else{
					cout<<"No se puede formar el 1"<<endl;
				}
			}
			case 2:{
				cout<<"PRUEBA2"<<endl;
				int contador=0;
				for(int j=0;j<2;j++){
					int lineaRandomVert= rand()%100+1;
					if(lineaRandomVert<distribucion[0]&&contador!=1){
						contador++;
					}
					else if(lineaRandomVert<(distribucion[0]+distribucion[1])&& contador!=2){
						contador= contador+2;
					}
					else if(lineaRandomVert<(distribucion[2]+distribucion[1]+distribucion[0])&& contador!=3){
						contador= contador+3;
					}
					else{
					cout<<"No se puede formar el 2"<<endl;
					}
					
				}
				contador=0;
				for(int j=0;j<3;j++){
					int lineaRandomHor= rand()%100+1;
					if(lineaRandomHor<distribucion[3]&&contador!=1){
						if(j==2 && contador==9){
							cout<<"Se puede formar el 2"<<endl;
							break;
						}
						contador++;
					}
					else if(lineaRandomHor<(distribucion[3]+distribucion[4])&& contador!=2){
						if(j==2 && contador==8){
							cout<<"Se puede formar el 2"<<endl;
							break;
						}
						contador= contador+2;
					}
					else if(lineaRandomHor<(distribucion[3]+distribucion[4]+distribucion[5])&& contador!=7){
						if(j==2 && contador==3){
							cout<<"Se puede formar el 2"<<endl;
							break;
						}
						contador= contador+7;
					}
					else{
					cout<<"No se puede formar el 2"<<endl;
						break;
					}
					
				}
				}
			case 3:{
				cout<<"PRUEBA3"<<endl;
			int lineaRandomHor= rand()%100+1;
				if(lineaRandomHor<distribucion[3]){
					cout<<"No se puede formar el 3"<<endl;
					break;
				}	
			int contador=0;
			for(int j=0;j<3;j++){
				lineaRandomHor= rand()%100+1;
				if(lineaRandomHor<distribucion[3]&&contador!=1){
					if(j==2 && contador==9){
						cout<<"Se puede formar el 3"<<endl;
						break;
					}
					contador++;
				}
				else if(lineaRandomHor<(distribucion[3]+distribucion[4])&& contador!=2){
					if(j==2 && contador==8){
						cout<<"Se puede formar el 3"<<endl;
						break;
					}
					contador= contador+2;
				}
				else if(lineaRandomHor<(distribucion[3]+distribucion[4]+distribucion[5])&& contador!=7){
					if(j==2 && contador==3){
						cout<<"Se puede formar el 3"<<endl;
						break;
					}
					contador= contador+7;
				}
				else{
				cout<<"No se puede formar el 3"<<endl;
				break;
				}
					
				}
			}
			case 4:{
				cout<<"PRUEBA4"<<endl;
				int contador=0;
				for(int j=0;j<2;j++){
					int lineaRandomVert= rand()%100+1;
					if(lineaRandomVert<distribucion[0]&&contador!=1){
						contador++;
					}
					else if(lineaRandomVert<(distribucion[2]+distribucion[1]+distribucion[0])&& contador!=3){
						contador= contador+3;
					}
					else{
					cout<<"No se puede formar el 4"<<endl;
						break;
					}
					
				}
				int lineaRandomHor= rand()%100+1;
				if(lineaRandomHor<(distribucion[3]+distribucion[4])){
					cout<<"Se puede formar el 4"<<endl;
					break;
					}
				else{
				cout<<"No se puede formar el 4"<<endl;
					break;
				}	
				}
			case 5:{
				cout<<"PRUEBA5"<<endl;
				int contador=0;
				for(int j=0;j<2;j++){
					int lineaRandomVert= rand()%100+1;
					if(lineaRandomVert<distribucion[0]&&contador!=1){
						contador++;
					}
					else if(lineaRandomVert<(distribucion[0]+distribucion[1])&& contador!=2){
						contador= contador+2;
					}
					else if(lineaRandomVert<(distribucion[2]+distribucion[1]+distribucion[0])&& contador!=3){
						contador= contador+3;
					}
					else{
					cout<<"No se puede formar el 5"<<endl;
						break;
					}
					
				}
				contador=0;
				for(int j=0;j<3;j++){
					int lineaRandomHor= rand()%100+1;
					if(lineaRandomHor<distribucion[3]&&contador!=1){
						if(j==2 && contador==9){
							cout<<"Se puede formar el 5"<<endl;
							break;
						}
						contador++;
					}
					else if(lineaRandomHor<(distribucion[3]+distribucion[4])&& contador!=2){
						if(j==2 && contador==8){
							cout<<"Se puede formar el 5"<<endl;
							break;
						}
						contador= contador+2;
					}
					else if(lineaRandomHor<(distribucion[3]+distribucion[4]+distribucion[5])&& contador!=7){
						if(j==2 && contador==3){
							cout<<"Se puede formar el 5"<<endl;
							break;
						}
						contador= contador+7;
					}
					else{
					cout<<"No se puede formar el 5"<<endl;
						break;
					}
					
				}
			}
			case 6:{
				cout<<"PRUEBA6"<<endl;
				int contador=0;
				for(int j=0;j<2;j++){
					int lineaRandomVert= rand()%100+1;
					if(lineaRandomVert<distribucion[0]&&contador!=1){
						contador++;
					}
					else if(lineaRandomVert<(distribucion[1]+distribucion[0])&& contador!=2){
						contador= contador+2;
					}
					else if(lineaRandomVert<(distribucion[2]+distribucion[1]+distribucion[0])&& contador!=3){
						contador= contador+3;
					}
					else{
					cout<<"No se puede formar el 6"<<endl;
						break;
					}
					
				}

				contador=0;
				for(int j=0;j<2;j++){
					int lineaRandomHor= rand()%100+1;
					if(lineaRandomHor<(distribucion[3]+distribucion[4])&& contador!=2){
						cout<<"Se puede formar el 6"<<endl;
						break;
						contador= contador+2;
					}
					else if(lineaRandomHor<(distribucion[3]+distribucion[4]+distribucion[5])&& contador!=7){
						cout<<"Se puede formar el 6"<<endl;
						break;
						contador= contador+7;
					}
					else{
					cout<<"No se puede formar el 6"<<endl;
						break;
					}
					
				}
			}
			case 7:{
				cout<<"PRUEBA7"<<endl;
			int contador=0;
			for(int j=0;j<2;j++){
					int lineaRandomVert= rand()%100+1;
					if(lineaRandomVert<distribucion[0]&&contador!=1){
						contador++;
					}
					else if(lineaRandomVert<(distribucion[0]+distribucion[1])&& contador!=2){
						contador= contador+2;
					}
					else if(lineaRandomVert<(distribucion[2]+distribucion[1]+distribucion[0])&& contador!=3){
						contador= contador+3;
					}
					else{
					cout<<"No se puede formar el 7"<<endl;
						break;
					}
					
				}
				contador=0;
				for(int j=0;j<3;j++){
					int lineaRandomHor= rand()%100+1;
					if(lineaRandomHor<distribucion[3]&&contador!=1){
						if(j==2 && contador==9){
							cout<<"Se puede formar el 7"<<endl;
							break;
						}
						contador++;
					}
					else if(lineaRandomHor<(distribucion[3]+distribucion[4])&& contador!=2){
						if(j==2 && contador==8){
							cout<<"Se puede formar el 7"<<endl;
							break;
						}
						contador= contador+2;
					}
					else{
					cout<<"No se puede formar el 7"<<endl;
						break;
					}
					
				}
			}
			case 8:{
				cout<<"PRUEBA8"<<endl;
			int contador=0;
			for(int j=0;j<2;j++){
					int lineaRandomVert= rand()%100+1;
					if(lineaRandomVert<distribucion[0]&&contador!=1){
						contador++;
					}
					else if(lineaRandomVert<(distribucion[0]+distribucion[1])&& contador!=2){
						contador= contador+2;
					}
					else if(lineaRandomVert<(distribucion[2]+distribucion[1]+distribucion[0])&& contador!=3){
						contador= contador+3;
					}
					else{
					cout<<"No se puede formar el 8"<<endl;
						break;
					}
					
				}
				contador=0;
				for(int j=0;j<3;j++){
					int lineaRandomHor= rand()%100+1;
					if(lineaRandomHor<distribucion[3]&&contador!=1){
						if(j==2 && contador==9){
							cout<<"Se puede formar el 8"<<endl;
							break;
						}
						contador++;
					}
					else if(lineaRandomHor<(distribucion[3]+distribucion[4])&& contador!=2){
						if(j==2 && contador==8){
							cout<<"Se puede formar el 8"<<endl;
							break;
						}
						contador= contador+2;
					}
					else if(lineaRandomHor<(distribucion[3]+distribucion[4]+distribucion[5])&& contador!=7){
						if(j==2 && contador==3){
							cout<<"Se puede formar el 8"<<endl;
							break;
						}
						contador= contador+7;
					}
					else{
					cout<<"No se puede formar el 8"<<endl;
						break;
					}
					
				}
			}
			case 9:{
				cout<<"PRUEBA9"<<endl;
			int contador=0;
			for(int j=0;j<2;j++){
					int lineaRandomVert= rand()%100+1;
					if(lineaRandomVert<distribucion[0]&&contador!=1){
						contador++;
					}
					else if(lineaRandomVert<(distribucion[0]+distribucion[1])&& contador!=2){
						contador= contador+2;
					}
					else if(lineaRandomVert<(distribucion[2]+distribucion[1]+distribucion[0])&& contador!=3){
						contador= contador+3;
					}
					else{
					cout<<"No se puede formar el 9"<<endl;
						break;
					}
					
				}
				contador=0;
				for(int j=0;j<3;j++){
					int lineaRandomHor= rand()%100+1;
					if(lineaRandomHor<distribucion[3]&&contador!=1){
						if(j==2 && contador==9){
							cout<<"Se puede formar el 9"<<endl;
							break;
						}
						contador++;
					}
					else if(lineaRandomHor<(distribucion[3]+distribucion[4])&& contador!=2){
						if(j==2 && contador==8){
							cout<<"Se puede formar el 9"<<endl;
							break;
						}
						contador= contador+2;
					}
					else{
					cout<<"No se puede formar el 9"<<endl;
						break;
					}
					
				}
			}
	}
	}
}
*/

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
