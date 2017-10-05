//
//  piramide.hpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 28/9/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#ifndef piramide_h
#define piramide_h

#include <stdio.h>
#include "vertex.h"
#include <vector>
#include <iostream>
#include <cmath>
#include "triangulos.h"

#include <GLUT/glut.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

class Piramide : public Triangulos {
	
public:
	Piramide();
	Piramide(int tama, int altura);
};

#endif /* piramide_hpp */
