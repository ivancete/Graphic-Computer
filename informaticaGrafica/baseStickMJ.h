//
//  baseStickMJ.hpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 2/11/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#ifndef baseStickMJ_h
#define baseStickMJ_h

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
#include "baseMJ.h"
#include "stickMJ.h"

#include <GLUT/glut.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

class BaseStickMJ {
private:
    StickMJ stick;
    BaseMJ base;
    
public:
    BaseStickMJ();
    void drawPointsBS();
    void drawEdgeBS();
    void drawSolidBS();
    void drawChessBS();
};

#endif /* baseStickMJ_h */
