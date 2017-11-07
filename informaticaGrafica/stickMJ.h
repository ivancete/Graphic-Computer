//
//  stickMJ.hpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 2/11/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#ifndef stickMJ_h
#define stickMJ_h

#include <vector>
#include "stdio.h"
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "vertex.h"
#include "objeto.h"
#include "triangulos.h"
#include "cubo.h"
#include "piramide.h"
#include "figura_ply.h"

#include <GLUT/glut.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

class StickMJ {
private:
    FiguraPly cilindro;
    
public:
    StickMJ();
    void drawPointsStick();
    void drawEdgeStick();
    void drawSolidStick();
    void drawChessStick();
};

#endif /* stickMJ_h */
