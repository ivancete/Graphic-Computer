//
//  triangulos.hpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 28/9/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#ifndef triangulos_h
#define triangulos_h

#include <stdio.h>
#include "vertex.h"
#include <vector>
#include <iostream>
#include <cmath>
#include "objeto.h"
#include <GLUT/glut.h>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

using namespace std;

class Triangulos : public Objeto
{
	
protected:
	vector<_vertex3i> triangulos;
	
public:
	Triangulos();
	void draw_edges();  //Pinta Caras
	void draw_solid();  //Pinta Solido
	void draw_chess();  //Pinta Ajedrez
	void Circle (GLfloat radio, GLfloat cx, GLfloat cy,  GLfloat cz, GLint n, GLenum modo);
	void draw_circulos(float radio, int n, GLenum mo);
};

#endif /* triangulos_hpp */
