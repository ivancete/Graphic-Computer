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
#include "material.h"

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
    vector<_vertex3f> normalFaces;
    vector<_vertex3f> normalVertex;
    vector<pair<_vertex3f, _vertex3f> > dibujar_normales_triangulo;
    vector<pair<_vertex3f, _vertex3f> > dibujar_normales_vertices;
    Material material;
	
public:
	Triangulos();
	void draw_edges();  //Pinta Caras
	void draw_solid();  //Pinta Solido
	void draw_chess();  //Pinta Ajedrez
	void Circle (GLfloat radio, GLfloat cx, GLfloat cy,  GLfloat cz, GLint n, GLenum modo);
	void draw_circulos(float radio, int n, GLenum mo);
    void normal_faces();
    void normal_vertex();
    void draw_normal_faces();
    void draw_normal_vertex();
    void draw_solid_light();
    void dibujar_suavizado_plano();
    void dibujar_suavizado_gouraud();
};

#endif /* triangulos_hpp */
