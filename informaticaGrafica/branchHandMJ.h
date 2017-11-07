//
//  branchHandMJ.h
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 2/11/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#ifndef branchHandMJ_h
#define branchHandMJ_h

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
#include "handMJ.h"
#include "branchMJ.h"

#include <GLUT/glut.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

class BranchHandMJ {
private:
    HandMJ handmj;
    BranchMJ branchmj;
    
public:
    BranchHandMJ();
    void drawPointsBH(float angle, float angle1);
    void drawEdgeBH(float angle, float angle1);
    void drawSolidBH(float angle, float angle1);
    void drawChessBH(float angle, float angle1);
};

#endif /* branchHandMJ_h */
