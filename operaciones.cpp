#ifndef OPERACIONES_CPP
#define OPERACIONES_CPP
#include "operaciones.h"
#include <cstdlib>
#include <iostream>

operaciones::operaciones(){
	
}

int operaciones::promedio(int total,int subtotal){
	int procentaje = ((int)((static_cast<double>(subtotal)/total)*100));
	return procentaje;
}
std::vector<int> operaciones::sacardistribucionV(listaSimple listaLineas){  
	vector<int> distribucion; //estructura para guardar la tabla de distribucion
	nodo* aux;//estructura para recorrer la lista
	aux = listaLineas.primero; //puntero en el inicio de la lista
	int subseccion1=0,subseccion2=0,subseccion3=0,semitotal=0; // ints para el conteo de lineas que funcionan
													  // para nuestro modelo
	while(aux!=NULL){
		if(aux->y_salida==0 and aux->x_salida <= 359){ // solo las lineas que salgan de la parte de arriba
													   // hasta el limite de la seccion a analizar
			semitotal++; // int para llevar el conteo de lineas que funcionan 
			int x = aux->x_salida; // int con el valor de salida de la x
			//MODELO: analizamos tres subsecciones , cada subseccion esta delimitado por un x para saber 
			//a cual pertenece la linea por su punto de salida 
			if(x <= 119){
				subseccion1++;
			}
			if(x >= 120 and x <= 240){
				subseccion2++;
			}
			if(x >= 241 and x <= 359){
				subseccion3++;
			}
		}
		aux=aux->siguiente;	
	}
	//ints con los procetajes que le toca a cada subseccion del numero de lineas que tiene cada subseccion
	int uno = promedio(semitotal,subseccion1);
	int dos = promedio(semitotal,subseccion2);
	int tres = promedio(semitotal,subseccion3);
    //inserta en la tabla de distribucion
	distribucion.push_back(uno);
	distribucion.push_back(uno+dos);
	distribucion.push_back(uno+dos+tres);
	
	//Muestra la tabla de distribucion
	/*cout<<"distribucion Vertical"<<endl;
	for (size_t i = 0; i < distribucion.size(); i++) {
    	cout << distribucion[i] <<endl;
 	}
 	/**/
	return distribucion;
}

std::vector<int> operaciones::sacardistribucionH(listaSimple listaLineas){
	vector<int> distribucion;//estructura para guardar la tabla de distribucion
	nodo* aux;//estructura para recorrer la lista
	aux = listaLineas.primero; //puntero en el inicio de la lista
	int subseccion1=0,subseccion2=0,subseccion3=0,semitotal=0; // ints para el conteo de lineas que funcionan
													           // para nuestro modelo
	while(aux!=NULL){ 
		if(aux->x_salida == 0){ //lee solo lineas que salga de la parte izquierda de la pantalla
			semitotal++;// int para llevar el conteo de lineas que funcionan 
			int y = aux->y_salida;
			if(y <= 306){
				subseccion1++;
			}
			if(y >= 307 and y <= 613){
				subseccion2++;
			}
			if(y >= 614){
				subseccion3++;
			}
		}
		aux=aux->siguiente;	
	}
	//ints con los procetajes que le toca a cada subseccion del numero de lineas que tiene cada subseccion
	int uno = promedio(semitotal,subseccion1);
	int dos = promedio(semitotal,subseccion2);
	int tres = promedio(semitotal,subseccion3);
    //inserta en la tabla de distribucion
	distribucion.push_back(uno);
	distribucion.push_back(uno+dos);
	distribucion.push_back(uno+dos+tres);
	
	//Muestra la tabla de distribucion
	/*cout<<"distribucion Horizontal"<<endl;
	for (size_t i = 0; i < distribucion.size(); i++) {
    	cout << distribucion[i] <<endl;
 	}
 	/**/
 	return distribucion;
}

bool operaciones::probarVert(int pNum, int listaVert[]){
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

bool operaciones::probarHor(int pNum,int listaHor[]){
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

void operaciones::validarNumero(int distribucionVert[],int distribucionHor[]){
	bool forma=true;
	for(int num=0;num<10;num++){
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
#endif 
