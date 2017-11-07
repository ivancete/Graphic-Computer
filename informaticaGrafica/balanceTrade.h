//
//  balanceTrade.hpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 7/11/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#ifndef balanceTrade_h
#define balanceTrade_h

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
#include "branchHandMJ.h"
#include "baseStickMJ.h"

#include <GLUT/glut.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

class BalanceTrade {
    BranchHandMJ bh;
    BaseStickMJ bs;
    
public:
    BalanceTrade();
    void drawPointsBT(float angle1, float angle2, float translation);
    void drawEdgeBT(float angle1, float angle2, float translation);
    void drawSolidBT(float angle1, float angle2, float translation);
    void drawChessBT(float angle1, float angle2, float translation);
};

#endif /* balanceTrade_h */
