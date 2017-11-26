//
//  material.h
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 25/11/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#ifndef material_h
#define material_h

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

class Material {
private:
    _vertex4f ambiental;
    _vertex4f difusa;
    _vertex4f especular;
    GLfloat brillo;
    bool tieneTextura;
    //Textura *textura;
public:
    Material();
    void setAmbiental(const _vertex4f &a);
    void setDifusa(const _vertex4f &d);
    void setEspecular(const _vertex4f &e);
    void setBrillo(const GLfloat &b);
    void activar();
};
#endif /* material_h */
