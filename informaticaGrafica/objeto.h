//
//  objeto.hpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 28/9/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#ifndef objeto_h
#define objeto_h

#include <stdio.h>
#include "vertex.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <GLUT/glut.h>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

typedef enum {VERTICES, ARISTAS, SOLID, CHESS, P_A, REVOLUTION, REVOLUTION_PARCIAL, NORMALFACES, NORMALVERTEX, FLAT, SMOOTH, DISABLELIGHT, ENABLELIGHT} rendering_mode;
typedef enum {CUBE, PYRAMID, OBJECT_PLY, OBJECT_REV, BASESTICKMJ, BRANCHHANDMJ, BALANCETRADE} object_type;
typedef enum {TUBE, CYLINDER, GLASS, GLASS_I, CONE, PEONZA} object_ply;

class Objeto {
	
protected:
	vector<_vertex3f> vertices;
	vector<_vertex3f> colores; 
	
public:
	Objeto();
	void draw_points();
};

#endif /* objeto_hpp */
