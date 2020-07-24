//#Clase: operaciones
#ifndef OPERACIONES_H
#define OPERACIONES_H
#include <vector>
#include "lista.h"

class operaciones {
	public: 
		operaciones();
		std::vector<int> sacardistribucionV(listaSimple listaLineas);
		std::vector<int> sacardistribucionH(listaSimple listaLineas);
		int promedio(int total,int subtotal);
		bool probarVert(int  pNum , int listaVert[]);
		bool probarHor(int  pNum , int listaHor[]);
		void validarNumero(int distribucionVert[],int distribucionHor[]);
};
#endif
