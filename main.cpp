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

vector<int> sacardistribucionV(listaSimple listaLineas){
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
	int primero = (int)((static_cast<double>(seccion1)/semitotal)*100);
	int segundo = (int)((static_cast<double>(seccion2)/semitotal)*100);
	int tercero = (int)((static_cast<double>(seccion3)/semitotal)*100);

	distribucion.push_back(primero);
	distribucion.push_back(primero+segundo);
	distribucion.push_back(100);
	
	/*for (size_t i = 0; i < distribucionArriba.size(); i++) {
    	cout << distribucion[i] <<endl;
 	}*/
		return distribucion;
}

vector<int> sacardistribucionH(listaSimple listaLineas){
	vector<int>distribucion;
	nodo* aux;
	aux = listaLineas.primero;
	int seccion1=0;
	int seccion2=0;
	int seccion3=0;
	int semitotal=0;
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
	int primero = (int)((static_cast<double>(seccion1)/semitotal)*100);
	int segundo = (int)((static_cast<double>(seccion2)/semitotal)*100);
	int tercero = (int)((static_cast<double>(seccion3)/semitotal)*100);

	distribucion.push_back(primero);
	distribucion.push_back(primero+segundo);
	distribucion.push_back(100);
	return distribucion;
}

bool probarVert(int pNum, int listaVert[]){
	bool val=true;
	switch(pNum){
		case 0:{
			int contador=0;
			for(int j=0;j<2;j++){
				int lineaRandomVert= rand()%100+1;
				if(lineaRandomVert<listaVert[0]&&contador!=1){
					contador++;
					val=true;
				}
				else if(lineaRandomVert<(listaVert[1])&&lineaRandomVert>(listaVert[0])&&contador!=2){
					contador= contador+2;
					val=true;
				}
				else if(lineaRandomVert<(listaVert[2])&& contador!=3&& lineaRandomVert>(listaVert[1])){
					contador= contador+3;
					val=true;
				}
				else{
					val=false;
				}		
			}
			break;
		}
		case 1:{
			int lineaRandomVert= rand()%100+1;
			if(lineaRandomVert<listaVert[0]){
				val=true;
			}
			else if(lineaRandomVert<(listaVert[1])&&lineaRandomVert>(listaVert[0])){
				val=true;
			}
			else if(lineaRandomVert<(listaVert[2])&& lineaRandomVert>(listaVert[1])){
				val=true;
			}
			else{
				val=false;
			}		
			break;
		}
		case 2:{
			int contador=0;
			for(int j=0;j<2;j++){
				int lineaRandomVert= rand()%100+1;
				if(lineaRandomVert<listaVert[0]&&contador!=1){
					contador++;
					val=true;
				}
				else if(lineaRandomVert<(listaVert[1])&&lineaRandomVert>(listaVert[0])&&contador!=2){
					contador= contador+2;
					val=true;
				}
				else if(lineaRandomVert<(listaVert[2])&& contador!=3&& lineaRandomVert>(listaVert[1])){
					contador= contador+3;
					val=true;
				}
				else{
					val=false;
				}		
			}
			break;
		}
		case 3:{
			int lineaRandomVert= rand()%100+1;
			if(lineaRandomVert<(listaVert[2])&&lineaRandomVert>(listaVert[1])){
				val=true;
			}
			else{
				val=false;
			}		
			break;
		}
		case 4:{
			int contador=0;
			for(int j=0;j<2;j++){
				int lineaRandomVert= rand()%100+1;
				if(lineaRandomVert<listaVert[0]&&contador!=1){
					contador++;
					val=true;
				}
				else if(lineaRandomVert<(listaVert[1])&&lineaRandomVert>(listaVert[0])&&contador!=2){
					contador= contador+2;
					val=true;
				}
				else if(lineaRandomVert<(listaVert[2])&& contador!=3&& lineaRandomVert>(listaVert[1])){
					contador= contador+3;
					val=true;
				}
				else{
					val=false;
				}		
			}
			break;
		}
		case 5:{
			int contador=0;
			for(int j=0;j<2;j++){
				int lineaRandomVert= rand()%100+1;
				if(lineaRandomVert<listaVert[0]&&contador!=1){
					contador++;
					val=true;
				}
				else if(lineaRandomVert<(listaVert[1])&&lineaRandomVert>(listaVert[0])&&contador!=2){
					contador= contador+2;
					val=true;
				}
				else if(lineaRandomVert<(listaVert[2])&& contador!=3&& lineaRandomVert>(listaVert[1])){
					contador= contador+3;
					val=true;
				}
				else{
					val=false;
					cout<<listaVert[0] <<endl;
				}		
			}
			break;
		}
		case 6:{
			int contador=0;
			for(int j=0;j<2;j++){
				int lineaRandomVert= rand()%100+1;
				if(lineaRandomVert<listaVert[0]&&contador!=1){
					contador++;
					val=true;
				}
				else if(lineaRandomVert<(listaVert[1])&&lineaRandomVert>(listaVert[0])&&contador!=2){
					contador= contador+2;
					val=true;
				}
				else if(lineaRandomVert<(listaVert[2])&& contador!=3&& lineaRandomVert>(listaVert[1])){
					contador= contador+3;
					val=true;
				}
				else{
					val=false;
				}		
			}
			break;
		}
		case 7:{
			int contador=0;
			for(int j=0;j<2;j++){
				int lineaRandomVert= rand()%100+1;
				if(lineaRandomVert<listaVert[0]&&contador!=1){
					contador++;
					val=true;
				}
				else if(lineaRandomVert<(listaVert[1])&&lineaRandomVert>(listaVert[0])&&contador!=2){
					contador= contador+2;
					val=true;
				}
				else if(lineaRandomVert<(listaVert[2])&& contador!=3&& lineaRandomVert>(listaVert[1])){
					contador= contador+3;
					val=true;
				}
				else{
					val=false;
				}		
			}
			break;
		}
		case 8:{
			int contador=0;
			for(int j=0;j<2;j++){
				int lineaRandomVert= rand()%100+1;
				if(lineaRandomVert<listaVert[0]&&contador!=1){
					contador++;
					val=true;
				}
				else if(lineaRandomVert<(listaVert[1])&&lineaRandomVert>(listaVert[0])&&contador!=2){
					contador= contador+2;
					val=true;
				}
				else if(lineaRandomVert<(listaVert[2])&& contador!=3&& lineaRandomVert>(listaVert[1])){
					contador= contador+3;
					val=true;
				}
				else{
					val=false;
				}		
			}
			break;
		}
		case 9:{
			int contador=0;
			for(int j=0;j<2;j++){
				int lineaRandomVert= rand()%100+1;
				if(lineaRandomVert<listaVert[0]&&contador!=1){
					contador++;
					val=true;
				}
				else if(lineaRandomVert<(listaVert[1])&&lineaRandomVert>(listaVert[0])&&contador!=2){
					contador= contador+2;
					val=true;
				}
				else if(lineaRandomVert<(listaVert[2])&& contador!=3&& lineaRandomVert>(listaVert[1])){
					contador= contador+3;
					val=true;
				}
				else{
					val=false;
				}		
			}
			break;
		}
	}
	return val;
}

bool probarHor(int pNum,int listaHor[]){
	bool val=true;
	switch(pNum){
		case 0:{
			int contador=0;
			for(int j=0;j<2;j++){
				int lineaRandomHor= rand()%100+1;
				if(lineaRandomHor<listaHor[0]&&contador!=1){
					contador++;
					val=true;
				}
				else if(lineaRandomHor<(listaHor[1])&&lineaRandomHor>(listaHor[0])&&contador!=2){
					contador= contador+2;
					val=true;
				}
				else if(lineaRandomHor<(listaHor[2])&& contador!=3&& lineaRandomHor>(listaHor[1])){
					contador= contador+3;
					val=true;
				}
				else{
					val=false;
				}		
			}
			break;
		}
		case 2:{
			int contador=0;
			for(int j=0;j<3;j++){
				if(val==true){
					int lineaRandomHor= rand()%100+1;
					if((lineaRandomHor<listaHor[0])&&(contador!=1)){
						if(j==2&&contador<5){
							val=false;
						}
						else{
							contador++;
							val=true;
						}
					}
					else if(lineaRandomHor<(listaHor[1])&& contador!=2&&lineaRandomHor>listaHor[0]){
						if(j==2&&contador==3&&contador==5){
							val=false;
						}
						else{
							contador=contador+2;
							val=true;
						}
					}
					else if(lineaRandomHor<(listaHor[2])&& contador!=3&&lineaRandomHor>(listaHor[1])){
						if(j==2&&contador==4&&contador==5){
							val=false;
						}
						else{
							contador=contador+3;
							val=true;
						}
					}
					else{
						val=false;
					}
				}
				else{
					j=3;
				}
			}
			break;
		}
		case 3:{
			int contador=0;
			for(int j=0;j<3;j++){
				if(val==true){
					int lineaRandomHor= rand()%100+1;
					if((lineaRandomHor<listaHor[0])&&(contador!=1)){
						if(j==2&&contador<5){
							val=false;
						}
						else{
							contador++;
							val=true;
						}
					}
					else if(lineaRandomHor<(listaHor[1])&& contador!=2&&lineaRandomHor>listaHor[0]){
						if(j==2&&contador==3&&contador==5){
							val=false;
						}
						else{
							contador= contador+2;
							val=true;
						}
					}
					else if(lineaRandomHor<(listaHor[2])&& contador!=3&&lineaRandomHor>(listaHor[1])){
						if(j==2&&contador==4&&contador==5){
							val=false;
						}
						else{
							contador+=3;
							val=true;
						}
					}
					else{
						val=false;
					}
				}
				else{
					j=3;
				}
			}
			break;
		}
		case 4:{
			int lineaRandomHor= rand()%100+1;
			if(lineaRandomHor<(listaHor[1])&& lineaRandomHor>listaHor[0]){
				val=true;
			}
			else{
				val=false;
			}
			break;
		}
		case 5:{
			int contador=0;
			for(int j=0;j<3;j++){
				if(val==true){
					int lineaRandomHor= rand()%100+1;
					if((lineaRandomHor<listaHor[0])&&(contador!=1)){
						if(j==2&&contador<5){
							val=false;
						}
						else{
							contador++;
							val=true;
						}
					}
					else if(lineaRandomHor<(listaHor[1])&& contador!=2&&lineaRandomHor>listaHor[0]){
						if(j==2&&contador==3&&contador==5){
							val=false;
						}
						else{
							contador+=2;
							val=true;
						}
					}
					else if(lineaRandomHor<(listaHor[2])&& contador!=3&&lineaRandomHor>(listaHor[1])){
						if(j==2&&contador==4&&contador==5){
							val=false;
						}
						else{
							contador+=3;
							val=true;
						}
					}
					else{
						val=false;
					}
				}
				else{
					j=3;
				}
			}
			break;
		}
		case 6:{
			int contador=0;
			for(int j=0;j<2;j++){
				if(val==true){
					int lineaRandomHor= rand()%100+1;
					if(lineaRandomHor<(listaHor[1])&&lineaRandomHor>(listaHor[0])&&contador!=2){
						contador= contador+2;
						val=true;
					}
					else if(lineaRandomHor<(listaHor[2])&& contador!=3&& lineaRandomHor>(listaHor[1])){
						contador= contador+3;
						val=true;
					}
					else{
						val=false;
					}		
				}
			}
			break;
		}
		case 7:{
			int contador=0;
			for(int j=0;j<2;j++){
				if(val==true){
					int lineaRandomHor= rand()%100+1;
					if(lineaRandomHor<listaHor[0]&&contador!=1){
						contador++;
						val=true;
					}
					else if(lineaRandomHor<(listaHor[1])&&lineaRandomHor>(listaHor[0])&&contador!=2){
						contador= contador+2;
						val=true;
					}
					else{
						val=false;
					}		
				}
			}
			break;
		}
		case 8:{
			int contador=0;
			for(int j=0;j<3;j++){
				if(val==true){
					int lineaRandomHor= rand()%100+1;
					if((lineaRandomHor<listaHor[0])&&(contador!=1)){
						if(j==2&&contador<5){
							val=false;
						}
						else{
							contador++;
							val=true;
						}
					}
					else if(lineaRandomHor<(listaHor[1])&& contador!=2&&lineaRandomHor>listaHor[0]){
						if(j==2&&contador==3&&contador==5){
							val=false;
						}
						else{
							contador+=2;
							val=true;
						}
					}
					else if(lineaRandomHor<(listaHor[2])&& contador!=3&&lineaRandomHor>(listaHor[1])){
						if(j==2&&contador==4&&contador==5){
							val=false;
						}
						else{
							contador+=3;
							val=true;
						}
					}
					else{
						val=false;
					}
				}
				else{
					j=3;
				}
			}
			break;
		}
		case 9:{
			int contador=0;
			for(int j=0;j<2;j++){
				if(val==true){
					int lineaRandomHor= rand()%100+1;
					if(lineaRandomHor<listaHor[0]&&contador!=1){
						contador++;
						val=true;
					}
					else if(lineaRandomHor<(listaHor[1])&&lineaRandomHor>(listaHor[0])&&contador!=2){
						contador= contador+2;
						val=true;
					}
					else{
						val=false;
					}		
				}
			}
			break;
		}
	}
	return val;
}

void validarNumero(int distribucionVert[],int distribucionHor[]){
	bool forma=true;
	int num=0;
	for(num;num<10;num++){
		switch(num){
			case 0:{
				forma=probarVert(0,distribucionVert);
				if(forma==true){
					forma=probarHor(0,distribucionHor);
					if(forma==true){
						cout<<"Se puede formar el numero 0" <<endl;
					}
					else{
						cout<<"No se puede formar el numero 0" <<endl;
					}
				}
				else{
					cout<<"No se puede formar el numero 0" <<endl;
				}
				break;
			}
			case 1:{
				forma=probarVert(1,distribucionVert);
				if(forma==true){
					forma=probarHor(1,distribucionHor);
					if(forma==true){
						cout<<"Se puede formar el numero 1" <<endl;
					}
					else{
						cout<<"No se puede formar el numero 1" <<endl;
					}
				}
				else{
					cout<<"No se puede formar el numero 1" <<endl;
				}
				break;
			}
			case 2:{
				forma=probarVert(2,distribucionVert);
				if(forma==true){
					forma=probarHor(2,distribucionHor);
					if(forma==true){
						cout<<"Se puede formar el numero 2" <<endl;
					}
					else{
						cout<<"No se puede formar el numero 2" <<endl;
					}
				}
				else{
					cout<<"No se puede formar el numero 2" <<endl;
				}
				break;
			}
			case 3:{
				forma=probarVert(3,distribucionVert);
				if(forma==true){
					forma=probarHor(3,distribucionHor);
					if(forma==true){
						cout<<"Se puede formar el numero 3" <<endl;
					}
					else{
						cout<<"No se puede formar el numero 3" <<endl;
					}
				}
				else{
					cout<<"No se puede formar el numero 3" <<endl;
				}
				break;
			}
			case 4:{
				forma=probarVert(4,distribucionVert);
				if(forma==true){
					forma=probarHor(4,distribucionHor);
					if(forma==true){
						cout<<"Se puede formar el numero 4" <<endl;
					}
					else{
						cout<<"No se puede formar el numero 4" <<endl;
					}
				}
				else{
					cout<<"No se puede formar el numero 4" <<endl;
				}
				break;
			}
			case 5:{
				forma=probarVert(5,distribucionVert);
				if(forma==true){
					forma=probarHor(5,distribucionHor);
					if(forma==true){
						cout<<"Se puede formar el numero 5" <<endl;
					}
					else{
						cout<<"No se puede formar el numero 5" <<endl;
					}
				}
				else{
					cout<<"No se puede formar el numero 5" <<endl;
				}
				break;
			}
			case 6:{
				forma=probarVert(6,distribucionVert);
				if(forma==true){
					forma=probarHor(6,distribucionHor);
					if(forma==true){
						cout<<"Se puede formar el numero 6" <<endl;
					}
					else{
						cout<<"No se puede formar el numero 6" <<endl;
					}
				}
				else{
					cout<<"No se puede formar el numero 6" <<endl;
				}
				break;
			}
			case 7:{
				forma=probarVert(7,distribucionVert);
				if(forma==true){
					forma=probarHor(7,distribucionHor);
					if(forma==true){
						cout<<"Se puede formar el numero 7" <<endl;
					}
					else{
						cout<<"No se puede formar el numero 7" <<endl;
					}
				}
				else{
					cout<<"No se puede formar el numero 7" <<endl;
				}
				break;
			}
			case 8:{
				forma=probarVert(8,distribucionVert);
				if(forma==true){
					forma=probarHor(8,distribucionHor);
					if(forma==true){
						cout<<"Se puede formar el numero 8" <<endl;
					}
					else{
						cout<<"No se puede formar el numero 8" <<endl;
					}
				}
				else{
					cout<<"No se puede formar el numero 8" <<endl;
				}
				break;
			}
			case 9:{
				forma=probarVert(9,distribucionVert);
				if(forma==true){
					forma=probarHor(9,distribucionHor);
					if(forma==true){
						cout<<"Se puede formar el numero 9" <<endl;
					}
					else{
						cout<<"No se puede formar el numero 9" <<endl;
					}
				}
				else{
					cout<<"No se puede formar el numero 9" <<endl;
				}
				break;
			}
		}	
	}
}

int main(){

	int lineas;
	cout<<"Ingresar numero de trazos"<<endl;
	cin>>lineas;
	cout<<"Llenando la lista con los trazos"<<endl;
	listaSimple listaLineas;
	listaLineas = llenadoLista(lineas);// lista de lineas = {(1,2,3,4),(1,2,3,4),(1,2,3,4),(1,2,3,4)}



	vector<int> VectorVertical = sacardistribucionV(listaLineas);
	vector<int> VectorHorizontal = sacardistribucionH(listaLineas);
	int distrV[]={VectorVertical[0],VectorVertical[1],VectorVertical[2]};
	int distrH[]={VectorHorizontal[0],VectorHorizontal[1],VectorHorizontal[2]};
	validarNumero(distrV,distrH);
	

	
	return 0;
}
