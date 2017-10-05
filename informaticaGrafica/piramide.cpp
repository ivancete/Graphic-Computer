//
//  piramide.cpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 28/9/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#include "piramide.h"

Piramide::Piramide()
{
	
}

Piramide::Piramide(int tama, int altura)
{
	int tamanio = tama / 2;
	
	int alt = altura / 2;
	
	vertices.push_back(_vertex3f(-tamanio, -alt, -tamanio));
	vertices.push_back(_vertex3f(tamanio, -alt, -tamanio));
	vertices.push_back(_vertex3f(tamanio, -alt, tamanio));
	vertices.push_back(_vertex3f(-tamanio, -alt, tamanio));
	vertices.push_back(_vertex3f(0, alt, 0));
	
	//Añadimos colores a los vertices
	
	colores.push_back(_vertex3f(1,0,0));
	colores.push_back(_vertex3f(0,1,0));
	colores.push_back(_vertex3f(0,0,1));
	colores.push_back(_vertex3f(1,1,0));
	colores.push_back(_vertex3f(0,0,0));
	
	
	triangulos.push_back(_vertex3i(0, 1, 4));
	
	triangulos.push_back(_vertex3i(0, 4, 3));
	
	triangulos.push_back(_vertex3i(2, 3, 4));
	
	triangulos.push_back(_vertex3i(1, 2, 4));
	
	triangulos.push_back(_vertex3i(3, 2, 1));
	
	triangulos.push_back(_vertex3i(3, 1, 0));
}
