//
//  objeto.cpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 28/9/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//
#include "objeto.h"

Objeto::Objeto()
{
	
}

void Objeto::draw_points()
{
	glColor3f(0,1,0);
	glPointSize(4);
	
	glBegin(GL_POINTS);
	for (int i=0;i<vertices.size();i++){
		
		glVertex3fv((GLfloat *) &vertices[i]);
	}
	glEnd();
}
