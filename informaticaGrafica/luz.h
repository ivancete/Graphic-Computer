//
//  luz.h
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 25/11/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#ifndef luz_h
#define luz_h

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

class Luz {
    
    GLenum id;
    bool direccional;
    _vertex4f posicion;
    GLfloat alfa;
    GLfloat beta;
    _vertex4f ambiental;
    _vertex4f difuso;
    _vertex4f especular;
    
public:
    Luz();
    void activar();
    void desactivar();
    void setID(const GLenum &i);
    void luces();
    void setDireccional(const bool &d);
    void setPosicion(const _vertex3f &p);
    void setDireccion(const GLfloat &a, const GLfloat &b);
    void setAmbiental(const _vertex4f &a);
    void setEspecular(const _vertex4f &e);
    void setDifusa(const _vertex4f &d);
};

#endif /* luz_h */
