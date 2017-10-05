//
//  cubo.cpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 28/9/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#include "cubo.h"


Cubo::Cubo()
{
	
}

Cubo::Cubo(int tama)
{
	float tamanio = tama;
	
	vertices.push_back(_vertex3f(-tamanio, -tamanio, tamanio));
	vertices.push_back(_vertex3f(tamanio, -tamanio, tamanio));
	vertices.push_back(_vertex3f(tamanio, tamanio, tamanio));
	vertices.push_back(_vertex3f(-tamanio, tamanio, tamanio));
	vertices.push_back(_vertex3f(-tamanio, -tamanio, -tamanio));
	vertices.push_back(_vertex3f(tamanio, -tamanio, -tamanio));
	vertices.push_back(_vertex3f(tamanio, tamanio, -tamanio));
	vertices.push_back(_vertex3f(-tamanio, tamanio, -tamanio));
	
	//Añadimos colores a los vertices
	
	colores.push_back(_vertex3f(1,0,0));
	colores.push_back(_vertex3f(0,1,0));
	colores.push_back(_vertex3f(0,0,1));
	colores.push_back(_vertex3f(1,1,0));
	colores.push_back(_vertex3f(1,0,1));
	colores.push_back(_vertex3f(1,0.7,0.2));
	colores.push_back(_vertex3f(0.5,0.5,0.5));
	colores.push_back(_vertex3f(0.7,0.7,0.7));
	colores.push_back(_vertex3f(0.3,1,1));
	
	triangulos.push_back(_vertex3i(0, 1, 2));
	triangulos.push_back(_vertex3i(0, 2, 3));
	
	triangulos.push_back(_vertex3i(1, 2, 6));
	triangulos.push_back(_vertex3i(1, 6, 5));
	
	triangulos.push_back(_vertex3i(5, 6, 7));
	triangulos.push_back(_vertex3i(4, 5, 7));
	
	triangulos.push_back(_vertex3i(4, 0, 7));
	triangulos.push_back(_vertex3i(0, 7, 3));
	
	triangulos.push_back(_vertex3i(3, 2, 7));
	triangulos.push_back(_vertex3i(2, 6, 7));
	
	triangulos.push_back(_vertex3i(0, 1, 4));
	triangulos.push_back(_vertex3i(1, 5, 4));
}
