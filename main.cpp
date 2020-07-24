#include <iostream> //salida por consola
#include "lista.h" //estructura de datos
#include "operaciones.h" //sacar tabla se probabilidad
#include <vector> //estructura de datos


int main(int argc, char** argv) {
	
	listaSimple listaLineas; // estructura especial con nodo con el punto de salida y llegada de la linea
	listaLineas = listaLineas.llenadoLista(200); //se puede cambiar el numero de lineas a insertar 
	//listaLineas.Mostrar(); //permite ver las lineas creadas
	
	vector<int> tablaProbabilidadLineaVertical;
	vector<int> tablaProbabilidadLineaHorizontal;
	//Sacar la tabla de probabilidad segun el modelo nuestro: 
	
	operaciones proceso;
	tablaProbabilidadLineaVertical = proceso.sacardistribucionV(listaLineas);
	tablaProbabilidadLineaHorizontal = proceso.sacardistribucionH(listaLineas);
	
	int listatablaProbabilidadLineaHorizontal[]={tablaProbabilidadLineaHorizontal[0],tablaProbabilidadLineaHorizontal[1],tablaProbabilidadLineaHorizontal[2]};
	int listatablaProbabilidadLineaVertical[]={tablaProbabilidadLineaVertical[0],tablaProbabilidadLineaVertical[1],tablaProbabilidadLineaVertical[2]};
	
	proceso.validarNumero(listatablaProbabilidadLineaVertical,listatablaProbabilidadLineaHorizontal);	
	return 0;
}
