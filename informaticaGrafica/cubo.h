//
//  cubo.hpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 28/9/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#ifndef cubo_h
#define cubo_h

#include <stdio.h>
#include "vertex.h"
#include <vector>
#include <iostream>
#include <cmath>
#include "triangulos.h"
#include "material.h"

#include <GLUT/glut.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

using namespace std;

class Cubo : public Triangulos
{
public:
	Cubo();
	Cubo(int tama);
};

#endif /* cubo_hpp */
