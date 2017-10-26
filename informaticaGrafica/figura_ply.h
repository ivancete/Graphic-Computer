//
//  figura_ply.h
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 9/10/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#ifndef figura_ply_h
#define figura_ply_h

#include <stdio.h>
#include "vertex.h"
#include <vector>
#include <iostream>
#include <cmath>
#include "triangulos.h"
#include "file_ply_stl.h"

#include <GLUT/glut.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <stdio.h>

using namespace std;

class FiguraPly : public Triangulos
{
private:
    _file_ply File_ply;
    
public:
    FiguraPly();
    FiguraPly(string ubicacion);
    FiguraPly(vector<_vertex3f> v);
    void parcialRevolution(int n);
    void revolution(int n);
};

#endif /* figura_ply_h */
